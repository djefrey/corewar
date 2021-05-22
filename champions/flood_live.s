.name "Flood Live"
.comment "Try to flood the live counter"

start:          sti r1, %:live, %1
                sti r1, %:live_n_clone, %1
                ld %0, r2
                fork %:live_n_clone

live:           live %123
                ld %0, r3
                zjmp %:live

live_n_clone:   live %123
                xor r2, %1, r2
                zjmp %:clone_to_live
                fork %:live_n_clone
                ld %0, r3
                zjmp %:live_n_clone

clone_to_live:  fork %:live
                ld %0, r3
                zjmp %:live_n_clone