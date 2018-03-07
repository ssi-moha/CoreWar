2
gobepc:	st r1,:buff
Creation Param r 
Creation Param : 
LABEL gobepc
CMD st
PAR r1
PAR :buff
	st r6,-4
Creation Param r 
Creation Param - 
LABEL (null)
CMD st
PAR r6
PAR -4
	ld :buff,r1
Creation Param : 
Creation Param r 
LABEL (null)
CMD ld
PAR :buff
PAR r1
debut:	ld %0,r7
Creation Param % 
Creation Param r 
LABEL debut
CMD ld
PAR %0
PAR r7
	zjmp %:suite
Creation Param % 
LABEL (null)
CMD zjmp
PAR %:suite
goboucle0:	live %66
Creation Param % 
LABEL goboucle0
CMD live
PAR %66
		ldi %-5,r3,r1
Creation Param % 
Creation Param r 
Creation Param r 
LABEL (null)
CMD ldi
PAR %-5
PAR r3
PAR r1
		sti r1,%-173,r3
Creation Param r 
Creation Param % 
Creation Param r 
LABEL (null)
CMD sti
PAR r1
PAR %-173
PAR r3
		add r3,r4,r3
Creation Param r 
Creation Param r 
Creation Param r 
LABEL (null)
CMD add
PAR r3
PAR r4
PAR r3
		xor r5,r3,r6
Creation Param r 
Creation Param r 
Creation Param r 
LABEL (null)
CMD xor
PAR r5
PAR r3
PAR r6
		zjmp %:finboucle0
Creation Param % 
LABEL (null)
CMD zjmp
PAR %:finboucle0
		ld %0,r7
Creation Param % 
Creation Param r 
LABEL (null)
CMD ld
PAR %0
PAR r7
		zjmp %:goboucle0
Creation Param % 
LABEL (null)
CMD zjmp
PAR %:goboucle0
finboucle0:	xor r3,r3,r3
Creation Param r 
Creation Param r 
Creation Param r 
LABEL finboucle0
CMD xor
PAR r3
PAR r3
PAR r3
		zjmp %-207
Creation Param % 
LABEL (null)
CMD zjmp
PAR %-207
buff:	st r1,r1	
Creation Param r 
Creation Param r 
LABEL buff
CMD st
PAR r1
PAR r1
suite:	sti r1,%:livel,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL suite
CMD sti
PAR r1
PAR %:livel
PAR %1
livel:	live %66
Creation Param % 
LABEL livel
CMD live
PAR %66
	sti r2,%:debut,%-60
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r2
PAR %:debut
PAR %-60
	ld %4,r4
Creation Param % 
Creation Param r 
LABEL (null)
CMD ld
PAR %4
PAR r4
	st r2,512
Creation Param r 
Creation Param 5 
LABEL (null)
CMD st
PAR r2
PAR 512
go:	ld %48,r5
Creation Param % 
Creation Param r 
LABEL go
CMD ld
PAR %48
PAR r5
	sti r1,%:goboucle0,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:goboucle0
PAR %1
	sti r1,%:goboucle1,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:goboucle1
PAR %1
	sti r1,%:live0,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:live0
PAR %1
	sti r1,%:live1,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:live1
PAR %1
	sti r1,%:live2,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:live2
PAR %1
	sti r1,%:live3,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:live3
PAR %1
	sti r1,%:live4,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:live4
PAR %1
live0:	live %66
Creation Param % 
LABEL live0
CMD live
PAR %66
live1:	live %66
Creation Param % 
LABEL live1
CMD live
PAR %66
live2:	live %66
Creation Param % 
LABEL live2
CMD live
PAR %66
live3:	live %66
Creation Param % 
LABEL live3
CMD live
PAR %66
live4:	live %66
Creation Param % 
LABEL live4
CMD live
PAR %66
	zjmp %:live0
Creation Param % 
LABEL (null)
CMD zjmp
PAR %:live0
	xor r3,r3,r3
Creation Param r 
Creation Param r 
Creation Param r 
LABEL (null)
CMD xor
PAR r3
PAR r3
PAR r3
	sti r1,%:livex,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:livex
PAR %1
livex:	live %66
Creation Param % 
LABEL livex
CMD live
PAR %66
	fork %:live0
Creation Param % 
LABEL (null)
CMD fork
PAR %:live0
	sti r1,%:boucle,%1
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:boucle
PAR %1
	sti r1,%:boucle,%9
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:boucle
PAR %9
	sti r1,%:boucle,%17
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:boucle
PAR %17
	sti r1,%:boucle,%25
Creation Param r 
Creation Param % 
Creation Param % 
LABEL (null)
CMD sti
PAR r1
PAR %:boucle
PAR %25
boucle:	live %66
Creation Param % 
LABEL boucle
CMD live
PAR %66
	fork %:goboucle0
Creation Param % 
LABEL (null)
CMD fork
PAR %:goboucle0
	live %66
Creation Param % 
LABEL (null)
CMD live
PAR %66
	fork %:boucle
Creation Param % 
LABEL (null)
CMD fork
PAR %:boucle
	live %66
Creation Param % 
LABEL (null)
CMD live
PAR %66
	fork %:goboucle1
Creation Param % 
LABEL (null)
CMD fork
PAR %:goboucle1
	live %66
Creation Param % 
LABEL (null)
CMD live
PAR %66
	zjmp %:goboucle0
Creation Param % 
LABEL (null)
CMD zjmp
PAR %:goboucle0
goboucle1:	live %66
Creation Param % 
LABEL goboucle1
CMD live
PAR %66
		ldi %-5,r3,r1
Creation Param % 
Creation Param r 
Creation Param r 
LABEL (null)
CMD ldi
PAR %-5
PAR r3
PAR r1
		sti r1,%17,r3
Creation Param r 
Creation Param % 
Creation Param r 
LABEL (null)
CMD sti
PAR r1
PAR %17
PAR r3
		add r3,r4,r3
Creation Param r 
Creation Param r 
Creation Param r 
LABEL (null)
CMD add
PAR r3
PAR r4
PAR r3
		xor r5,r3,r6
Creation Param r 
Creation Param r 
Creation Param r 
LABEL (null)
CMD xor
PAR r5
PAR r3
PAR r6
		zjmp %:finboucle1
Creation Param % 
LABEL (null)
CMD zjmp
PAR %:finboucle1
		ld %0,r7
Creation Param % 
Creation Param r 
LABEL (null)
CMD ld
PAR %0
PAR r7
		zjmp %:goboucle1
Creation Param % 
LABEL (null)
CMD zjmp
PAR %:goboucle1
finboucle1:	xor r3,r3,r3
Creation Param r 
Creation Param r 
Creation Param r 
LABEL finboucle1
CMD xor
PAR r3
PAR r3
PAR r3
		zjmp %1
Creation Param % 
LABEL (null)
CMD zjmp
PAR %1
CMD 2 PAR r1 SIZE OCTET 3
CMD 2 PAR :buff SIZE OCTET 5
CMD 2 PAR r6 SIZE OCTET 3
CMD 2 PAR -4 SIZE OCTET 5
CMD 1 PAR :buff SIZE OCTET 4
CMD 1 PAR r1 SIZE OCTET 5
CMD 1 PAR %0 SIZE OCTET 6
CMD 1 PAR r7 SIZE OCTET 7
CMD 8 PAR %:suite SIZE OCTET 3
CMD 0 PAR %66 SIZE OCTET 5
CMD 9 PAR %-5 SIZE OCTET 4
CMD 9 PAR r3 SIZE OCTET 5
CMD 9 PAR r1 SIZE OCTET 6
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %-173 SIZE OCTET 5
CMD 10 PAR r3 SIZE OCTET 6
CMD 3 PAR r3 SIZE OCTET 3
CMD 3 PAR r4 SIZE OCTET 4
CMD 3 PAR r3 SIZE OCTET 5
CMD 7 PAR r5 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 4
CMD 7 PAR r6 SIZE OCTET 5
CMD 8 PAR %:finboucle0 SIZE OCTET 3
CMD 1 PAR %0 SIZE OCTET 6
CMD 1 PAR r7 SIZE OCTET 7
CMD 8 PAR %:goboucle0 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 4
CMD 7 PAR r3 SIZE OCTET 5
CMD 8 PAR %-207 SIZE OCTET 3
CMD 2 PAR r1 SIZE OCTET 3
CMD 2 PAR r1 SIZE OCTET 4
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:livel SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 0 PAR %66 SIZE OCTET 5
CMD 10 PAR r2 SIZE OCTET 3
CMD 10 PAR %:debut SIZE OCTET 5
CMD 10 PAR %-60 SIZE OCTET 7
CMD 1 PAR %4 SIZE OCTET 6
CMD 1 PAR r4 SIZE OCTET 7
CMD 2 PAR r2 SIZE OCTET 3
CMD 2 PAR 512 SIZE OCTET 5
CMD 1 PAR %48 SIZE OCTET 6
CMD 1 PAR r5 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:goboucle0 SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:goboucle1 SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:live0 SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:live1 SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:live2 SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:live3 SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:live4 SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 0 PAR %66 SIZE OCTET 5
CMD 0 PAR %66 SIZE OCTET 5
CMD 0 PAR %66 SIZE OCTET 5
CMD 0 PAR %66 SIZE OCTET 5
CMD 0 PAR %66 SIZE OCTET 5
CMD 8 PAR %:live0 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 4
CMD 7 PAR r3 SIZE OCTET 5
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:livex SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 0 PAR %66 SIZE OCTET 5
CMD 11 PAR %:live0 SIZE OCTET 3
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:boucle SIZE OCTET 5
CMD 10 PAR %1 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:boucle SIZE OCTET 5
CMD 10 PAR %9 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:boucle SIZE OCTET 5
CMD 10 PAR %17 SIZE OCTET 7
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %:boucle SIZE OCTET 5
CMD 10 PAR %25 SIZE OCTET 7
CMD 0 PAR %66 SIZE OCTET 5
CMD 11 PAR %:goboucle0 SIZE OCTET 3
CMD 0 PAR %66 SIZE OCTET 5
CMD 11 PAR %:boucle SIZE OCTET 3
CMD 0 PAR %66 SIZE OCTET 5
CMD 11 PAR %:goboucle1 SIZE OCTET 3
CMD 0 PAR %66 SIZE OCTET 5
CMD 8 PAR %:goboucle0 SIZE OCTET 3
CMD 0 PAR %66 SIZE OCTET 5
CMD 9 PAR %-5 SIZE OCTET 4
CMD 9 PAR r3 SIZE OCTET 5
CMD 9 PAR r1 SIZE OCTET 6
CMD 10 PAR r1 SIZE OCTET 3
CMD 10 PAR %17 SIZE OCTET 5
CMD 10 PAR r3 SIZE OCTET 6
CMD 3 PAR r3 SIZE OCTET 3
CMD 3 PAR r4 SIZE OCTET 4
CMD 3 PAR r3 SIZE OCTET 5
CMD 7 PAR r5 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 4
CMD 7 PAR r6 SIZE OCTET 5
CMD 8 PAR %:finboucle1 SIZE OCTET 3
CMD 1 PAR %0 SIZE OCTET 6
CMD 1 PAR r7 SIZE OCTET 7
CMD 8 PAR %:goboucle1 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 3
CMD 7 PAR r3 SIZE OCTET 4
CMD 7 PAR r3 SIZE OCTET 5
CMD 8 PAR %1 SIZE OCTET 3


 TEST WRITE HEADER
Jumper !
en fait C forker !
INSTRUCTION NUM 3
HEXAAAAAAAAAAAAAAAAAAA 70 112
/*****************************************************/ st
TMP TYPE 1
TMP TYPE 12
lllll st
lllll st
IIIIIIIIIIIIIIIIIIIIII
hhhh st
hhhh st
hhhh ld
hhhh ld
hhhh zjmp
hhhh live
hhhh ldi
hhhh sti
hhhh add
hhhh xor
hhhh zjmp
hhhh ld
hhhh zjmp
hhhh xor
hhhh zjmp
le i : 73
J 73 I 73
IND-----------------------------------------------------------------------LABEL SIZE 73
XXXXXXXXXXXXXXXXXXX 73
INSTRUCTION NUM 3
HEXAAAAAAAAAAAAAAAAAAA 70 112
/*****************************************************/ st
TMP TYPE 1
TMP TYPE 4
NBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB 65532
INSTRUCTION NUM 2
HEXAAAAAAAAAAAAAAAAAAA d0 208
/*****************************************************/ ld
TMP TYPE 12
lllll st
lllll ld
lllllkkkk st
lllllkkkk st
IIIIIIIIIIIIIIIIIIIIII
hhhh ld
hhhh ld
hhhh zjmp
hhhh live
hhhh ldi
hhhh sti
hhhh add
hhhh xor
hhhh zjmp
hhhh ld
hhhh zjmp
hhhh xor
hhhh zjmp
le i : 63
J 63 I 63
IND-----------------------------------------------------------------------LABEL SIZE 63
XXXXXXXXXXXXXXXXXXX 63
TMP TYPE 1
INSTRUCTION NUM 2
HEXAAAAAAAAAAAAAAAAAAA 90 144
/*****************************************************/ ld
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 0
OCTET 0
OCTET 0
OCTET 0
OCTET 0
TMP TYPE 1
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 10
lllll st
lllll zjmp
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
IIIIIIIIIIIIIIIIIIIIII
hhhh zjmp
hhhh live
hhhh ldi
hhhh sti
hhhh add
hhhh xor
hhhh zjmp
hhhh ld
hhhh zjmp
hhhh xor
hhhh zjmp
hhhh st
le i : 55
J 55 I 55
LABEL SIZE 55
XXXXXXXXXXXXXXXXXXX 55
DDDDDDDjjjj 2 zjmpo dirsize 1ooo
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 10
HEXAAAAAAAAAAAAAAAAAAA 94 148
/*****************************************************/ ldi
TMP TYPE 2
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 64 100
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 2
TMP TYPE 1
INSTRUCTION NUM 4
HEXAAAAAAAAAAAAAAAAAAA 54 84
/*****************************************************/ add
TMP TYPE 1
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 8
HEXAAAAAAAAAAAAAAAAAAA 54 84
/*****************************************************/ xor
TMP TYPE 1
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 10
lllll st
lllll zjmp
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
IIIIIIIIIIIIIIIIIIIIII
hhhh zjmp
hhhh ld
hhhh zjmp
le i : 13
J 13 I 13
LABEL SIZE 13
XXXXXXXXXXXXXXXXXXX 13
DDDDDDDjjjj 2 zjmpo dirsize 1ooo
INSTRUCTION NUM 2
HEXAAAAAAAAAAAAAAAAAAA 90 144
/*****************************************************/ ld
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 0
OCTET 0
OCTET 0
OCTET 0
OCTET 0
TMP TYPE 1
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 10
lllll st
lllll zjmp
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
J 65499 I -37
LABEL SIZE 65499
XXXXXXXXXXXXXXXXXXX 65499
DDDDDDDjjjj 2 zjmpo dirsize 1ooo
INSTRUCTION NUM 8
HEXAAAAAAAAAAAAAAAAAAA 54 84
/*****************************************************/ xor
TMP TYPE 1
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 2
INSTRUCTION NUM 3
HEXAAAAAAAAAAAAAAAAAAA 50 80
/*****************************************************/ st
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
le i : 7
J 7 I 7
LABEL SIZE 7
XXXXXXXXXXXXXXXXXXX 7
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
J 65462 I -74
LABEL SIZE 65462
XXXXXXXXXXXXXXXXXXX 65462
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 2
HEXAAAAAAAAAAAAAAAAAAA 90 144
/*****************************************************/ ld
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 4
OCTET 4
OCTET 0
OCTET 0
OCTET 0
TMP TYPE 1
INSTRUCTION NUM 3
HEXAAAAAAAAAAAAAAAAAAA 70 112
/*****************************************************/ st
TMP TYPE 1
TMP TYPE 4
NBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB 512
INSTRUCTION NUM 2
HEXAAAAAAAAAAAAAAAAAAA 90 144
/*****************************************************/ ld
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 48
OCTET 48
OCTET 0
OCTET 0
OCTET 0
TMP TYPE 1
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
J 65446 I -90
LABEL SIZE 65446
XXXXXXXXXXXXXXXXXXX 65446
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
hhhh sti
hhhh sti
hhhh sti
hhhh sti
hhhh live
hhhh live
hhhh live
hhhh live
hhhh live
hhhh zjmp
hhhh xor
hhhh sti
hhhh live
hhhh fork
hhhh sti
hhhh sti
hhhh sti
hhhh sti
hhhh live
hhhh fork
hhhh live
hhhh fork
hhhh live
hhhh fork
hhhh live
hhhh zjmp
le i : 150
J 150 I 150
LABEL SIZE 150
XXXXXXXXXXXXXXXXXXX 150
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
hhhh sti
hhhh sti
hhhh sti
le i : 35
J 35 I 35
LABEL SIZE 35
XXXXXXXXXXXXXXXXXXX 35
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
hhhh sti
hhhh sti
hhhh live
le i : 33
J 33 I 33
LABEL SIZE 33
XXXXXXXXXXXXXXXXXXX 33
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
hhhh sti
hhhh live
hhhh live
le i : 31
J 31 I 31
LABEL SIZE 31
XXXXXXXXXXXXXXXXXXX 31
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
hhhh live
hhhh live
hhhh live
le i : 29
J 29 I 29
LABEL SIZE 29
XXXXXXXXXXXXXXXXXXX 29
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh live
hhhh live
hhhh live
hhhh live
le i : 27
J 27 I 27
LABEL SIZE 27
XXXXXXXXXXXXXXXXXXX 27
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 10
lllll st
lllll zjmp
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
ggggg
ggggg
ggggg
ggggg
ggggg
J 65511 I -25
LABEL SIZE 65511
XXXXXXXXXXXXXXXXXXX 65511
DDDDDDDjjjj 2 zjmpo dirsize 1ooo
INSTRUCTION NUM 8
HEXAAAAAAAAAAAAAAAAAAA 54 84
/*****************************************************/ xor
TMP TYPE 1
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
le i : 7
J 7 I 7
LABEL SIZE 7
XXXXXXXXXXXXXXXXXXX 7
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 12
/*****************************************************/ fork
TMP TYPE 10
lllll st
lllll fork
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
J 65491 I -45
LABEL SIZE 65491
XXXXXXXXXXXXXXXXXXX 65491
DDDDDDDjjjj 2 forko dirsize 1ooo
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
hhhh sti
hhhh sti
le i : 28
J 28 I 28
LABEL SIZE 28
XXXXXXXXXXXXXXXXXXX 28
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
hhhh sti
le i : 21
J 21 I 21
LABEL SIZE 21
XXXXXXXXXXXXXXXXXXX 21
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk sti
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
hhhh sti
le i : 14
J 14 I 14
LABEL SIZE 14
XXXXXXXXXXXXXXXXXXX 14
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 68 104
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 10
lllll st
lllll sti
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
IIIIIIIIIIIIIIIIIIIIII
hhhh sti
le i : 7
J 7 I 7
LABEL SIZE 7
XXXXXXXXXXXXXXXXXXX 7
DDDDDDDjjjj 2 stio dirsize 1ooo
TMP TYPE 2
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 12
/*****************************************************/ fork
TMP TYPE 10
lllll st
lllll fork
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
J 65316 I -220
LABEL SIZE 65316
XXXXXXXXXXXXXXXXXXX 65316
DDDDDDDjjjj 2 forko dirsize 1ooo
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 12
/*****************************************************/ fork
TMP TYPE 10
lllll st
lllll fork
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
ggggg
ggggg
ggggg
J 65523 I -13
LABEL SIZE 65523
XXXXXXXXXXXXXXXXXXX 65523
DDDDDDDjjjj 2 forko dirsize 1ooo
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 12
/*****************************************************/ fork
TMP TYPE 10
lllll st
lllll fork
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk live
lllllkkkk fork
lllllkkkk live
IIIIIIIIIIIIIIIIIIIIII
hhhh fork
hhhh live
hhhh zjmp
le i : 11
J 11 I 11
LABEL SIZE 11
XXXXXXXXXXXXXXXXXXX 11
DDDDDDDjjjj 2 forko dirsize 1ooo
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 10
lllll st
lllll zjmp
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
J 65292 I -244
LABEL SIZE 65292
XXXXXXXXXXXXXXXXXXX 65292
DDDDDDDjjjj 2 zjmpo dirsize 1ooo
INSTRUCTION NUM 1
/*****************************************************/ live
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 66
OCTET 66
OCTET 0
OCTET 0
OCTET 0
INSTRUCTION NUM 10
HEXAAAAAAAAAAAAAAAAAAA 94 148
/*****************************************************/ ldi
TMP TYPE 2
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 11
HEXAAAAAAAAAAAAAAAAAAA 64 100
/*****************************************************/ sti
TMP TYPE 1
TMP TYPE 2
TMP TYPE 1
INSTRUCTION NUM 4
HEXAAAAAAAAAAAAAAAAAAA 54 84
/*****************************************************/ add
TMP TYPE 1
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 8
HEXAAAAAAAAAAAAAAAAAAA 54 84
/*****************************************************/ xor
TMP TYPE 1
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 10
lllll st
lllll zjmp
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk live
lllllkkkk fork
lllllkkkk live
lllllkkkk fork
lllllkkkk live
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
IIIIIIIIIIIIIIIIIIIIII
hhhh zjmp
hhhh ld
hhhh zjmp
le i : 13
J 13 I 13
LABEL SIZE 13
XXXXXXXXXXXXXXXXXXX 13
DDDDDDDjjjj 2 zjmpo dirsize 1ooo
INSTRUCTION NUM 2
HEXAAAAAAAAAAAAAAAAAAA 90 144
/*****************************************************/ ld
TMP TYPE 2
NNNNNNNBBBBBBBBBBB 0
OCTET 0
OCTET 0
OCTET 0
OCTET 0
TMP TYPE 1
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 10
lllll st
lllll zjmp
lllllkkkk st
lllllkkkk st
lllllkkkk ld
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk live
lllllkkkk ldi
lllllkkkk sti
lllllkkkk add
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk ld
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk zjmp
lllllkkkk st
lllllkkkk sti
lllllkkkk live
lllllkkkk sti
lllllkkkk ld
lllllkkkk st
lllllkkkk ld
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk live
lllllkkkk zjmp
lllllkkkk xor
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk sti
lllllkkkk live
lllllkkkk fork
lllllkkkk live
lllllkkkk fork
lllllkkkk live
lllllkkkk fork
lllllkkkk live
lllllkkkk zjmp
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
ggggg
J 65499 I -37
LABEL SIZE 65499
XXXXXXXXXXXXXXXXXXX 65499
DDDDDDDjjjj 2 zjmpo dirsize 1ooo
INSTRUCTION NUM 8
HEXAAAAAAAAAAAAAAAAAAA 54 84
/*****************************************************/ xor
TMP TYPE 1
TMP TYPE 1
TMP TYPE 1
INSTRUCTION NUM 9
/*****************************************************/ zjmp
TMP TYPE 2

LABEL gobepc
INSTR st SIZE 5 
PAR r1 TYPE 1
PAR :buff TYPE 12

LABEL (null)
INSTR st SIZE 5 
PAR r6 TYPE 1
PAR -4 TYPE 4

LABEL (null)
INSTR ld SIZE 5 
PAR :buff TYPE 12
PAR r1 TYPE 1

LABEL debut
INSTR ld SIZE 7 
PAR %0 TYPE 2
PAR r7 TYPE 1

LABEL (null)
INSTR zjmp SIZE 3 
PAR %:suite TYPE 10

LABEL goboucle0
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR ldi SIZE 6 
PAR %-5 TYPE 2
PAR r3 TYPE 1
PAR r1 TYPE 1

LABEL (null)
INSTR sti SIZE 6 
PAR r1 TYPE 1
PAR %-173 TYPE 2
PAR r3 TYPE 1

LABEL (null)
INSTR add SIZE 5 
PAR r3 TYPE 1
PAR r4 TYPE 1
PAR r3 TYPE 1

LABEL (null)
INSTR xor SIZE 5 
PAR r5 TYPE 1
PAR r3 TYPE 1
PAR r6 TYPE 1

LABEL (null)
INSTR zjmp SIZE 3 
PAR %:finboucle0 TYPE 10

LABEL (null)
INSTR ld SIZE 7 
PAR %0 TYPE 2
PAR r7 TYPE 1

LABEL (null)
INSTR zjmp SIZE 3 
PAR %:goboucle0 TYPE 10

LABEL finboucle0
INSTR xor SIZE 5 
PAR r3 TYPE 1
PAR r3 TYPE 1
PAR r3 TYPE 1

LABEL (null)
INSTR zjmp SIZE 3 
PAR %-207 TYPE 2

LABEL buff
INSTR st SIZE 4 
PAR r1 TYPE 1
PAR r1 TYPE 1

LABEL suite
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:livel TYPE 10
PAR %1 TYPE 2

LABEL livel
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r2 TYPE 1
PAR %:debut TYPE 10
PAR %-60 TYPE 2

LABEL (null)
INSTR ld SIZE 7 
PAR %4 TYPE 2
PAR r4 TYPE 1

LABEL (null)
INSTR st SIZE 5 
PAR r2 TYPE 1
PAR 512 TYPE 4

LABEL go
INSTR ld SIZE 7 
PAR %48 TYPE 2
PAR r5 TYPE 1

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:goboucle0 TYPE 10
PAR %1 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:goboucle1 TYPE 10
PAR %1 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:live0 TYPE 10
PAR %1 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:live1 TYPE 10
PAR %1 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:live2 TYPE 10
PAR %1 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:live3 TYPE 10
PAR %1 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:live4 TYPE 10
PAR %1 TYPE 2

LABEL live0
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL live1
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL live2
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL live3
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL live4
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR zjmp SIZE 3 
PAR %:live0 TYPE 10

LABEL (null)
INSTR xor SIZE 5 
PAR r3 TYPE 1
PAR r3 TYPE 1
PAR r3 TYPE 1

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:livex TYPE 10
PAR %1 TYPE 2

LABEL livex
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR fork SIZE 3 
PAR %:live0 TYPE 10

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:boucle TYPE 10
PAR %1 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:boucle TYPE 10
PAR %9 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:boucle TYPE 10
PAR %17 TYPE 2

LABEL (null)
INSTR sti SIZE 7 
PAR r1 TYPE 1
PAR %:boucle TYPE 10
PAR %25 TYPE 2

LABEL boucle
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR fork SIZE 3 
PAR %:goboucle0 TYPE 10

LABEL (null)
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR fork SIZE 3 
PAR %:boucle TYPE 10

LABEL (null)
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR fork SIZE 3 
PAR %:goboucle1 TYPE 10

LABEL (null)
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR zjmp SIZE 3 
PAR %:goboucle0 TYPE 10

LABEL goboucle1
INSTR live SIZE 5 
PAR %66 TYPE 2

LABEL (null)
INSTR ldi SIZE 6 
PAR %-5 TYPE 2
PAR r3 TYPE 1
PAR r1 TYPE 1

LABEL (null)
INSTR sti SIZE 6 
PAR r1 TYPE 1
PAR %17 TYPE 2
PAR r3 TYPE 1

LABEL (null)
INSTR add SIZE 5 
PAR r3 TYPE 1
PAR r4 TYPE 1
PAR r3 TYPE 1

LABEL (null)
INSTR xor SIZE 5 
PAR r5 TYPE 1
PAR r3 TYPE 1
PAR r6 TYPE 1

LABEL (null)
INSTR zjmp SIZE 3 
PAR %:finboucle1 TYPE 10

LABEL (null)
INSTR ld SIZE 7 
PAR %0 TYPE 2
PAR r7 TYPE 1

LABEL (null)
INSTR zjmp SIZE 3 
PAR %:goboucle1 TYPE 10

LABEL finboucle1
INSTR xor SIZE 5 
PAR r3 TYPE 1
PAR r3 TYPE 1
PAR r3 TYPE 1

LABEL (null)
INSTR zjmp SIZE 3 
PAR %1 TYPE 2

en fait C forker !                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
