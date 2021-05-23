.name "Self Replicant"
.comment "CtrlC CtrlV"

# r1 = ID
# r2 = loop counter
# r3 = offset
# r4 = copy
# r5 = size of prog.
# r6 = test + math
# r7 = test

#
# NOTE: This one is not functionnal
# Check out Charge!
#

start:                  ld %:end, r5
                        sti r1, %:live, %1
                        add r5, r5, r3

live:                   live %123

ctrl_c:                 ldi %:start, r2, r4
ctrl_v:                 sti r4, r3, r2

check_off_eq_end:       sub r5, r2, r6
                        zjmp %:clone

check_off_min_end_neg:  ld %-1, r7
                        and r6, r7, r6
                        xor r6, r7, r6
                        zjmp %:clone

move_offset:            ld %4, r6
                        add r2, r6, r2
                        ld %0, r6
                        zjmp %:live

# WARNING: update the offset in r7 if clone is modified

clone:                  ld %100, r6
                        ld %:ctrl_v, r7
                        add r6, r3, r6
                        add r6, r7, r6
                        sti r6, %:fork, %1
fork:                   fork %1
                        add r3, r5, r3
                        ld %0, r2
                        zjmp %:live

end: