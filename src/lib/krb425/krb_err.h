/*
 * $Source$
 * $Author$
 * $Id$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
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
 * krb_err.h for krb425
 */

#ifndef KRB5_KRB_ERR_H__
#define KRB5_KRB_ERR_H__

#define KRBET_KSUCCESS                           ((int)39525376)
#define KRBET_KDC_NAME_EXP                       ((int)39525377)
#define KRBET_KDC_SERVICE_EXP                    ((int)39525378)
#define KRBET_KDC_AUTH_EXP                       ((int)39525379)
#define KRBET_KDC_PKT_VER                        ((int)39525380)
#define KRBET_KDC_P_MKEY_VER                     ((int)39525381)
#define KRBET_KDC_S_MKEY_VER                     ((int)39525382)
#define KRBET_KDC_BYTE_ORDER                     ((int)39525383)
#define KRBET_KDC_PR_UNKNOWN                     ((int)39525384)
#define KRBET_KDC_PR_N_UNIQUE                    ((int)39525385)
#define KRBET_KDC_NULL_KEY                       ((int)39525386)
#define KRBET_KRB_RES11                          ((int)39525387)
#define KRBET_KRB_RES12                          ((int)39525388)
#define KRBET_KRB_RES13                          ((int)39525389)
#define KRBET_KRB_RES14                          ((int)39525390)
#define KRBET_KRB_RES15                          ((int)39525391)
#define KRBET_KRB_RES16                          ((int)39525392)
#define KRBET_KRB_RES17                          ((int)39525393)
#define KRBET_KRB_RES18                          ((int)39525394)
#define KRBET_KRB_RES19                          ((int)39525395)
#define KRBET_KDC_GEN_ERR                        ((int)39525396)
#define KRBET_GC_TKFIL                           ((int)39525397)
#define KRBET_GC_NOTKT                           ((int)39525398)
#define KRBET_KRB_RES23                          ((int)39525399)
#define KRBET_KRB_RES24                          ((int)39525400)
#define KRBET_KRB_RES25                          ((int)39525401)
#define KRBET_MK_AP_TGTEXP                       ((int)39525402)
#define KRBET_KRB_RES27                          ((int)39525403)
#define KRBET_KRB_RES28                          ((int)39525404)
#define KRBET_KRB_RES29                          ((int)39525405)
#define KRBET_KRB_RES30                          ((int)39525406)
#define KRBET_RD_AP_UNDEC                        ((int)39525407)
#define KRBET_RD_AP_EXP                          ((int)39525408)
#define KRBET_RD_AP_NYV                          ((int)39525409)
#define KRBET_RD_AP_REPEAT                       ((int)39525410)
#define KRBET_RD_AP_NOT_US                       ((int)39525411)
#define KRBET_RD_AP_INCON                        ((int)39525412)
#define KRBET_RD_AP_TIME                         ((int)39525413)
#define KRBET_RD_AP_BADD                         ((int)39525414)
#define KRBET_RD_AP_VERSION                      ((int)39525415)
#define KRBET_RD_AP_MSG_TYPE                     ((int)39525416)
#define KRBET_RD_AP_MODIFIED                     ((int)39525417)
#define KRBET_RD_AP_ORDER                        ((int)39525418)
#define KRBET_RD_AP_UNAUTHOR                     ((int)39525419)
#define KRBET_KRB_RES44                          ((int)39525420)
#define KRBET_KRB_RES45                          ((int)39525421)
#define KRBET_KRB_RES46                          ((int)39525422)
#define KRBET_KRB_RES47                          ((int)39525423)
#define KRBET_KRB_RES48                          ((int)39525424)
#define KRBET_KRB_RES49                          ((int)39525425)
#define KRBET_KRB_RES50                          ((int)39525426)
#define KRBET_GT_PW_NULL                         ((int)39525427)
#define KRBET_GT_PW_BADPW                        ((int)39525428)
#define KRBET_GT_PW_PROT                         ((int)39525429)
#define KRBET_GT_PW_KDCERR                       ((int)39525430)
#define KRBET_GT_PW_NULLTKT                      ((int)39525431)
#define KRBET_SKDC_RETRY                         ((int)39525432)
#define KRBET_SKDC_CANT                          ((int)39525433)
#define KRBET_KRB_RES58                          ((int)39525434)
#define KRBET_KRB_RES59                          ((int)39525435)
#define KRBET_KRB_RES60                          ((int)39525436)
#define KRBET_INTK_W_NOTALL                      ((int)39525437)
#define KRBET_INTK_BADPW                         ((int)39525438)
#define KRBET_INTK_PROT                          ((int)39525439)
#define KRBET_KRB_RES64                          ((int)39525440)
#define KRBET_KRB_RES65                          ((int)39525441)
#define KRBET_KRB_RES66                          ((int)39525442)
#define KRBET_KRB_RES67                          ((int)39525443)
#define KRBET_KRB_RES68                          ((int)39525444)
#define KRBET_KRB_RES69                          ((int)39525445)
#define KRBET_INTK_ERR                           ((int)39525446)
#define KRBET_AD_NOTGT                           ((int)39525447)
#define KRBET_KRB_RES72                          ((int)39525448)
#define KRBET_KRB_RES73                          ((int)39525449)
#define KRBET_KRB_RES74                          ((int)39525450)
#define KRBET_KRB_RES75                          ((int)39525451)
#define KRBET_NO_TKT_FIL                         ((int)39525452)
#define KRBET_TKT_FIL_ACC                        ((int)39525453)
#define KRBET_TKT_FIL_LCK                        ((int)39525454)
#define KRBET_TKT_FIL_FMT                        ((int)39525455)
#define KRBET_TKT_FIL_INI                        ((int)39525456)
#define KRBET_KNAME_FMT                          ((int)39525457)
extern int init_krb_err_tbl();
extern int krb_err_base;

#endif /* __KRB5_KRB_ERR_H__ */
