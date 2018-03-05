#
# Warrior qui a gagne
# l'annee derniere
#     VOALA
#
.name		"Celebration Funebre v0.99pl42"
.comment	"Jour J"

		ld   %0,r3		
label:		zjmp %:avantdebt
		zjmp %0				# pour eviter ecrasement
						# de l'instruction suivante
avantdebt:	sti   r1,%:code,%1  # 		# mets a jour le live
		sti   r1,%:code,%15 # 		# mets a jour le live
		sti   r1,%:code,%29 # 		# mets a jour le live
		sti   r1,%:code,%43 # 		# mets a jour le live
		sti   r1,%:code,%57 # 		# mets a jour le live
		sti   r1,%:code,%71 # 		# mets a jour le live
		
code:	live %42
		ldi  %0,%:code,r15		#set des octets 1-4
		ld   %-194,r14			# $A -6 -0
		ld   %0,r2			#
		zjmp %:label			#



