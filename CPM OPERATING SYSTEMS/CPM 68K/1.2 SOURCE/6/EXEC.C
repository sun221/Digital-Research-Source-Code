/***************************************************************************
 *									    
 *			    E x e c   F u n c t i o n			    
 *			    -------------------------			    
 *	Copyright 1982 by Digital Research Inc.  All rights reserved.	    
 *									    
 *	The execl function is called from anywhere to pass control to  	    
 *	another program from the the executing C program.		    
 *	Note that the stream files are closed via '_cleanup()'.		    
 *									    
 *	Calling Sequence:						    
 *									    
 *		execl(name,arg0,arg1,...,argn,NULLPTR);			    
 *									    
 *	Where:								    
 *		name, arg0, arg1...argn are pointers to character strings   
 *									    
 ****************************************************************************/
#include "portab.h"
#include "osif.h"
#include "osiferr.h"
#include "errno.h"
#include "ctype.h"

UWORD	execl(name,arg0)			/* CLEAR FUNCTION ***********/
	UBYTE *name,*arg0;			/* pointers arguments      */
{						/*			   */
  REG	UBYTE **args;				/* used to index into args */
	UBYTE cmdline[128];			/* CP/M command line area  */
  REG	WORD  i;				/***************************/
						/*			   */
	_cleanup();				/* Close all (stream) files*/
						/* now build cmdline 	   */
	strcpy(cmdline+1,name);			/* Copy name portion	   */
#if PCDOS == 0					/* Don't do for PCDOS	   */
	for(i = strlen(cmdline+1); --i >= 0; )	/* uppercase command name  */
	  cmdline[i+1] = toupper(cmdline[i+1]);	/*			   */
#endif						/***************************/
	args = &arg0;				/* Copy args		   */
	args++;					/* arg0 is a dup of the    */
						/*	      command name */
	while(*args != NULLPTR)			/***************************/
	  {					/*			   */
            strcat(cmdline+1," ");		/* Add a blank		   */
	    strcat(cmdline+1,*args++);		/* Add next arg		   */
	  }					/***************************/
#if PCDOS					/* handle differently ifso */
	_pc_chain(cmdline);			/* special home grown func */
#else						/* O.S. handles it?	   */
	cmdline[0] = strlen(cmdline+1);		/* Compute length	   */
	__OSIF(SETDMA,cmdline);			/* DMA -> Command line	   */
	__OSIF(P_CHAIN,0);			/* chain to program        */
#endif						/*			   */
	RETERR(FAILURE,ENOENT);			/* error: file not found   */
}						/***************************/
                                                                                                          *****************/
                                                                                                          *****************/
                                                                                                          