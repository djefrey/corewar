.name "CHARGE!"
.comment "C'mon soldiers"

# r1 = ID
# r2 = loop counter
# r3 = copy
# r4 = write addr
# r5 = '4'
# r6 = result
# r16 = '0'

start:      sti r1, %:live, %1
            sti r1, %:cloner, %1
            sti r1, %:attack, %1
            ld %4, r5
            ld %0, r16
            fork %:cloner

live:       live %123
            zjmp %:live

cloner:     live %123
            fork %:init
            zjmp %:cloner

# 58 = size of :init -> :end
# 58 + 2 = 60

init:       ld %0, r2
attack:     live %123
            ldi %:init, r2  r3
            add r2, r5, r4
            sti r3, %:end, r4
            and r2, %60, r6
            xor r6, %60, r6
            zjmp %:end
            add r2, r5, r2
            ld %0, r6
            zjmp %:attack
end: