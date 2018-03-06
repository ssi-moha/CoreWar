#
# Warrior qui a gagne
# l'annee derniere
#     VOALA
#
.name		"Celebration Funebre v0.99pl42"
.comment	"Jour J"

		ld   %0,r3		
label:		zjmp %:avantdebt
avantdebt:	sti   r1,%:code,%1
		code: zjmp %:label



