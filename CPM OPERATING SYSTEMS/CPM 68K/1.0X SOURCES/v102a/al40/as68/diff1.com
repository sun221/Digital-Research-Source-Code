$ set def drb0:[steve.cpm68k.v102a.al40.as68]
$ assign  drb0:[steve.cpm68k.v102a.al40.oldas68] old
$ diff DIR.C old:DIR.C
$ diff EXPR.C old:EXPR.C
$ diff MAIN.C old:MAIN.C
$ diff MISC.C old:MISC.C
$ diff PASS1A.C old:PASS1A.C
$ diff PASS2.C old:PASS2.C
$ diff SYMT.C old:SYMT.C
$ diff VERSION.C old:VERSION.C
$ diff AS68.H old:AS68.H
$ diff COUT.H old:COUT.H