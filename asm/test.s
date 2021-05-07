# test.s for corewar
#
# lolilol

.name "le meilleur"
.comment "lolilol mdr xptdr"

l2:
str r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %:live
