/*
 * seal.c --- seal message
 * 
 * $Source$
 * $Author$
 * $Header$
 * 
 * Copyright 1991 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 *
 */

#include <gssapi.h>

OM_uint32 gss_seal(minor_status, context, conf_req_flag, qop_req, 
		   input_message_buffer, conf_state, output_message_buffer)
	OM_uint32	*minor_status;
	gss_ctx_id_t	context;
	int		conf_req_flag;
	int		qop_req;
	gss_buffer_t	input_message_buffer;
	int		*conf_state;
	gss_buffer_t	output_message_buffer;
{
	krb5_data	inbuf, outbuf;
	
	*minor_status = 0;

	inbuf.length = input_message_buffer->length;
	inbuf.data = input_message_buffer->value;
	if (conf_req_flag) {
		int	priv_flags = 0;
		int		eblock_size;
		char		*i_vector;

		if (context->flags & GSS_C_SEQUENCE_FLAG)
			priv_flags = KRB5_PRIV_DOSEQUENCE|KRB5_PRIV_NOTIME;
		/*
		 * Initialize the initial vector.
		 */
		eblock_size =
			krb5_keytype_array[context->session_key->keytype]->
				system->block_length;
		if (!(i_vector=malloc(eblock_size))) {
			return(GSS_S_FAILURE);
		}
		memset(i_vector, 0, eblock_size);
		if (*minor_status = krb5_mk_priv(&inbuf, ETYPE_DES_CBC_CRC,
						 context->session_key,
						 &context->my_address,
						 &context->his_address,
						 context->my_seq_num,
						 priv_flags,
						 0, /* no rcache */
						 i_vector,
						 &outbuf))
			return(GSS_S_FAILURE);
		if (*minor_status = gss_make_token(minor_status,
						   GSS_API_KRB5_TYPE,
						   GSS_API_KRB5_PRIV,
						   outbuf.length,
						   outbuf.data,
						   output_message_buffer)) {
			xfree(outbuf.data);
			return(GSS_S_FAILURE);
		}
		if (conf_state)
			*conf_state = 1;
		if (context->flags & GSS_C_SEQUENCE_FLAG)
			context->my_seq_num++;
		return(GSS_S_COMPLETE);
	} else {
		int	safe_flags = 0;

		if (context->flags & GSS_C_SEQUENCE_FLAG)
			safe_flags = KRB5_SAFE_DOSEQUENCE|KRB5_SAFE_NOTIME;
		if (*minor_status = krb5_mk_safe(&inbuf,
						 CKSUMTYPE_RSA_MD4_DES,
						 context->session_key,
						 &context->my_address,
						 &context->his_address,
						 context->my_seq_num,
						 safe_flags,
						 0, /* no rcache */
						 &outbuf))
			return(GSS_S_FAILURE);
		if (*minor_status = gss_make_token(minor_status,
						   GSS_API_KRB5_TYPE,
						   GSS_API_KRB5_SAFE,
						   outbuf.length,
						   outbuf.data,
						   output_message_buffer)) {
			xfree(outbuf.data);
			return(GSS_S_FAILURE);
		}
		if (conf_state)
			*conf_state = 0;
		if (context->flags & GSS_C_SEQUENCE_FLAG)
			context->my_seq_num++;
		return(GSS_S_COMPLETE);
	}
}

#ifdef notdef
/*
 * XXX This is done inefficiently; the token in gss_sign does not need
 * to include the text of the data, just a cryptographic checksum to
 * act as a checksum.  Nevertheless, this is a quick and dirty way to
 * get it to work.  When we fix this so that it works for real, we
 * will need to let gss_verify accept both, and change the servers
 * first. 
 */

OM_uint32 gss_sign(minor_status, context, qop_req, 
		   input_message_buffer, output_message_buffer)
	OM_uint32	*minor_status;
	gss_ctx_id_t	context;
	int		qop_req;
	gss_buffer_t	input_message_buffer;
	gss_buffer_t	output_message_buffer;
{
	return(gss_seal(minor_status, context, 0, qop_req, 
			input_message_buffer, NULL, output_message_buffer));
}

#endif
