$ set def drb0:[steve.cpm68k.v102a.al40.oldas68]
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) DIR.C [-.as68]DIR.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) EXPR.C [-.as68]EXPR.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) MAIN.C [-.as68]MAIN.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) MISC.C [-.as68]MISC.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) PASS1A.C [-.as68]PASS1A.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) PASS2.C [-.as68]PASS2.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) SYMT.C [-.as68]SYMT.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) VERSION.C [-.as68]VERSION.C
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) AS68.H [-.as68]AS68.H
$ diff/ign=(blank,spac,comm)/comm=(slash,semi) COUT.H [-.as68]COUT.H