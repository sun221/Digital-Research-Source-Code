/*
	Copyright 1982
	Alcyon Corporation
	8716 Production Ave.
	San Diego, Ca.  92121
*/

#include "cgen.h"
#include "cskel.h"

/* sucomp - Sethy-Ullman expression complexity measure computation*/
/*		This is a heuristic computation of the Sethy-Ullman numbers*/
/*		for expressions.  This gives an approximation of the complexity*/
/*		of the expression.  The code generation scheme works best if*/
/*		the most complex expressions are done first.*/
sucomp(tp,nregs,flag)				/* returns - none*/
struct tnode *tp;					/* pointer to tree*/
int nregs;							/* number of registers left*/
int flag;							/* 1=>set values in tree, 0=>return*/
{
	register int su, sur, op, i;
	register struct tnode *ltp, *rtp;

	nregs = dreg(nregs);
	if( binop(op=tp->t_op) ) {
		ltp = tp->t_left;
		rtp = tp->t_right;
	}
	else if( unaryop(op) )
		ltp = tp->t_left;
	switch( op ) {

	case CLONG:
		if( tp->t_lvalue >= 0x8000L || tp->t_lvalue <= 0xffff8000L ) {
			su = SU_ADDR;
			break;
		}
		i = tp->t_lvalue;
	case CINT:
		if( op == CINT )
			i = tp->t_value;
		if( i == 0 )
			su = SU_ZERO;
		else if( i == 1 )
			su = SU_ONE;
		else if( i >= 1 && i <= QUICKVAL )
			su = SU_SMALL;
		else if( i >= -128 && i <= 127 )
			su = SU_QUICK;
		else
			su = SU_CONST;
		break;

	case COMMA:
		su = max(sucomp(rtp,nregs,flag),sucomp(ltp,nregs,flag));
		su = max(su,SU_EASY);
		break;

	case ADDR:
		su = sucomp(ltp,nregs,flag);
		break;

	case CFLOAT:
	case DCLONG:
	case AUTOINC:
	case AUTODEC:
		su = SU_ADDR;
		break;

	case SYMBOL:
		if( tp->t_sc != REGISTER )
			su = SU_ADDR;
		else if( isdreg(tp->t_reg) )
			su = SU_REG;
		else
			su = SU_AREG;
		break;

	case LDIV:
	case LMOD:
	case LMULT:
	case CALL:
		sucomp(rtp,nregs,flag);
	case NACALL:
		sucomp(ltp,nregs,flag);
		su = SU_VHARD;				/*very hard*/
		break;

	default:
		su = sucomp(ltp,nregs,flag);
		if( binop(op) ) {
			if( su <= SU_ADDR )
				su = max(su,sucomp(rtp,nregs,flag));
			else {
				sur = sucomp(rtp,nregs+1,flag);
				if( sur > SU_ADDR && nregs > HICREG )
					su = max(su,SU_HARD);
			}
			su = max(SU_EASY,su);
		}
		else if( su <= SU_XREG )
			su = max(SU_EASY,su);
		if( isfloat(tp->t_type) )
			su = SU_VHARD;
		break;
	}
	if( flag )
		tp->t_su = su;
	return(su);
}
