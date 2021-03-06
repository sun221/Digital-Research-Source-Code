/*
	Copyright 1982
	Alcyon Corporation
	8716 Production Ave.
	San Diego, Ca.  92121
*/

/*char *version "@(#) fabs - jan 11, 1983";*/

/* 
 *	Floating Point Absolute :
 *		Fast Floating Point Package
 *
 *		double
 *		fabs(farg)
 *		double farg;
 *
 *	Returns : absolute Floating point number
 */

long
fabs(f)
long f;
{
	f = f & 0xffffff7f;		/* turn off sign bit */
	return(f);
}
