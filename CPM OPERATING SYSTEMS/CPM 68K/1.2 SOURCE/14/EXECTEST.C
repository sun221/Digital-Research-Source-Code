/* 
	exectest.c This program tests to see if execl function works as
	specified.		
	execl calls execgood for small model ;
	      calls execgoob for big model ;

	program written by	Bill Fitler
	program modified by 	Ken Chai	22-Dec-83

*/

#include	"bugdefs.h"
#include	<stdio.h>

GLOBAL	char model[10] ;
	char bugnum[80] ;
	char progname[10] ;
	char *chptr ;

	char *strcpy() ;

main()
{

	strcpy(bugnum,"exectest: \ttest of execl function\n\t\t\t") ;
	printf("\nBegin test of execl function\n");

	if (sizeof(chptr)==2) strcpy(model,"small" );
	else		      strcpy(model,"big") ;

	if (!strcmp(model,"small") )
		strcpy(progname,"execgood") ;
	else
		strcpy(progname,"execgoob") ;

	execl(progname,progname,"test's","good","for",model,"model",\
(char *) 0);

} /* exectest.c */
                                                                             l,"model",\
(char *) 0);

} /* exectest.c */
                                                                             l,"model",\
(char *) 0);

} /* exectest.c */
                                                                             