/*
 * $Source$
 * $Author$
 *
 * Copyright 1985, 1986, 1987, 1988, 1990 by the Massachusetts Institute
 * of Technology.
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
 * This routine computes the DES key schedule given a key.  The
 * permutations and shifts have been done at compile time, resulting
 * in a direct one-step mapping from the input key to the key
 * schedule.
 *
 * Also checks parity and weak keys.
 *
 * Watch out for the subscripts -- most effectively start at 1 instead
 * of at zero.  Maybe some bugs in that area.
 *
 * DON'T change the data types for arrays and such, or it will either
 * break or run slower.  This was optimized for Uvax2.
 *
 * In case the user wants to cache the computed key schedule, it is
 * passed as an arg.  Also implies that caller has explicit control
 * over zeroing both the key schedule and the key.
 *
 * All registers labeled imply Vax using the Ultrix or 4.2bsd compiler.
 *
 * Originally written 6/85 by Steve Miller, MIT Project Athena.
 */

#if !defined(lint) && !defined(SABER)
static char rcsid_key_sched_c[] =
"$Id$";
#endif	/* !lint & !SABER */

#include <stdio.h>

#include <krb5/krb5.h>
#include "des_int.h"
#include "key_perm.h"

extern int mit_des_debug;

typedef char key[64];
/* the following are really void but cc86 doesnt allow it */
static void make_key_sched PROTOTYPE((key, mit_des_key_schedule));

int
mit_des_key_sched(k,schedule)
    register mit_des_cblock k;	/* r11 */
    mit_des_key_schedule schedule;
{
    /* better pass 8 bytes, length not checked here */

    register i, j, n;		/* i = r10, j = r9, n = r8 */
    register unsigned int temp;	/*  r7 */
    register char *p_char;	/* r6 */
    key k_char;
    i = 8;
    n = 0;
    p_char = k_char;

#if defined(lint) || defined(SABER)
    n = n;				/* fool it in case of VAXASM */
#endif
#ifdef DEBUG
    if (mit_des_debug)
	fprintf(stderr,"\n\ninput key, left to right = ");
#endif

    if (!mit_des_check_key_parity(k))	/* bad parity --> return -1 */
	return(-1);

    do {
	/* get next input key byte */
#ifdef DEBUG
	if (mit_des_debug)
	    fprintf(stderr,"%02x ",*k & 0xff);
#endif
	temp = (unsigned int) ((unsigned char) *k++);
	j = 8;

	do {
#ifndef VAXASM
	    *p_char++ = (int) temp & 01;
	    temp = temp >> 1;
#else
	    asm("bicb3	$-2,r7,(r8)+[r6]");
	    asm("rotl	$-1,r7,r7");
#endif
	} while (--j > 0);
    } while (--i > 0);

#ifdef DEBUG
    if (mit_des_debug) {
	p_char = k_char;
	fprintf(stderr,"\nKey bits, from zero to 63");
	for (i = 0; i <= 7; i++) {
	    fprintf(stderr,"\n\t");
	    for (j = 0; j <=7; j++)
		fprintf(stderr,"%d ",*p_char++);
	}
    }
#else
#ifdef lint
    p_char = p_char;
#endif
#endif

    /* check against weak keys */
    k -= sizeof(mit_des_cblock);

    if (mit_des_is_weak_key(k))
	return(-2);

    make_key_sched(k_char,schedule);

    /* if key was good, return 0 */
    return 0;
}

static void
make_key_sched(Key,Schedule)
    register key Key;		/* r11 */
    mit_des_key_schedule Schedule;
{
    /*
     * The key has been converted to an array to make this run faster;
     * on a microvax 2, this routine takes about 3.5ms.  The code and
     * size of the arrays has been played with to get it as fast as
     * possible.
     *
     * Don't change the order of the declarations below without
     * checking the assembler code to make sure that things are still
     * where it expects them.
     */

    /* r10, unroll by AUTH_DES_ITER */
    register int iter = AUTH_DES_ITER ;
    register unsigned long *k;	 /* r9 */
    register int *kp;		 /* r8 */
    register unsigned long temp; /* r7 */

    kp = (int *) key_perm;
    k  = (unsigned long *) Schedule;

    do {
	/*
	 * create the Key schedule
	 *
	 * put into lsb first order (lsb is bit 0)
	 */

	/*
	 * On the uvax2, this C code below is as fast as straight
	 * assembler, so just use C code below.
	 */
	temp = 0;
#ifdef LSBFIRST
#define BIT(x)	x
#else
#ifdef notdef
#define BIT(x) rev_swap_bit_pos_0(x)
#else
#define BIT(x)	x
#endif
#endif
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(0));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(1));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(2));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(3));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(4));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(5));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(6));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(7));

	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(8));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(9));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(10));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(11));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(12));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(13));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(14));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(15));

	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(16));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(17));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(18));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(19));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(20));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(21));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(22));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(23));

	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(24));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(25));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(26));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(27));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(28));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(29));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(30));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(31));

	*k++ = temp;
	temp = 0;

	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(0));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(1));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(2));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(3));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(4));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(5));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(6));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(7));

	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(8));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(9));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(10));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(11));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(12));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(13));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(14));
	if ((unsigned) Key[(int) *kp++]) temp |= (1<< BIT(15));

	*k++ = temp;

    } while (--iter > 0);

#ifdef DEBUG
    if (mit_des_debug) {
	char *n;
	int q;
	fprintf(stderr,"\nKey Schedule, left to right");
	for (i = 0; i < AUTH_DES_ITER; i++) {
	    n = (char *) &Schedule[i];
	    fprintf(stderr,"\n");
	    for (q = 0; q <= 7; q++)
		fprintf(stderr,"%02x ",*n++ & 0xff);
	}
	fprintf(stderr,"\n");
    }
#endif
}
