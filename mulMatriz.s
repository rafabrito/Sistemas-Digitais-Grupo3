.global mulMatriz

mulMatriz:
        push    {r4, r5, r6, r7, r8, r9, r10, r11, lr}
        sub     sp, sp, #4
        cmp     r0, #1
        str     r3, [sp]                        @ 4-byte Spill
        cmpge   r1, #1
        blt     end
        lsl     lr, r1, #2
        mov     r3, #0

for1:                                @ => This Loop Header: Depth=1
        ldr     r7, [sp, #40]
        ldr     r9, [sp]                        @ 4-byte Reload
        mul     r4, r3, r1
        mov     r11, #0
        add     r10, r7, r4, lsl #2

for2:                                @   Parent Loop 2 Depth=1
        ldr     r5, [r10, r11, lsl #2]
        mov     r4, #0
        mov     r6, r9

for3:                                @   Parent Loop 3 Depth=1
        ldr     r7, [r2, r4, lsl #2]
        ldr     r12, [r6], lr
        add     r4, r4, #1                  @ b++
        cmp     r1, r4                  @ if b < lin
        mla     r8, r12, r7, r5
        mov     r5, r8
        str     r8, [r10, r11, lsl #2]
        bne     for3
        add     r11, r11, #1                 @ j++
        add     r9, r9, #4
        cmp     r11, r1                 @ if j < col
        bne     for2
        add     r3, r3, #1                  @ i++
        add     r2, r2, lr
        cmp     r3, r0                  @ if i < lin
        bne     for1

end:
        mov     r0, #0
        add     sp, #4
        pop     {r4, r5, r6, r7, r8, r9, r10, r11, lr}
        bx      lr
