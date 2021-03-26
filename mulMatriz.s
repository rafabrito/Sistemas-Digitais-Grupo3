.global mulMatriz

mulMatriz:
	push    {r4, r5, r6, r7, r8, r9, r10, r11, lr}
        sub     sp, sp, #4                      @ Reserva espaço na pilha para um item
        cmp     r0, #1                          @ Compara se r0 == 1
        str     r3, [sp]                        @ Armazena 4-bytes na memória
        cmpge   r1, #1                          @ Compara se r1 >= 1
        blt     end
        lsl     lr, r1, #2
        mov     r3, #0

for1:                                           @ Loop 1
        ldr     r7, [sp, #40]
        ldr     r9, [sp]                        @ Carrega 4-bytes no registrador r9
        mul     r4, r3, r1
        mov     r11, #0
        add     r10, r7, r4, lsl #2

for2:                                           @ Loop 2 
        ldr     r5, [r10, r11, lsl #2]
        mov     r4, #0
        mov     r6, r9

for3:                                           @ Loop 3 
        ldr     r7, [r2, r4, lsl #2]
        ldr     r12, [r6], lr
        add     r4, r4, #1                      @ b++
        cmp     r1, r4                          @ if b < lin
        mla     r8, r12, r7, r5
        mov     r5, r8
        str     r8, [r10, r11, lsl #2]
        bne     for3
        add     r11, r11, #1                    @ j++
        add     r9, r9, #4
        cmp     r11, r1                         @ if j < col
        bne     for2
        add     r3, r3, #1                      @ i++
        add     r2, r2, lr
        cmp     r3, r0                          @ if i < lin
        bne     for1

end:
        mov     r0, #0
        add     sp, #4                          @ Remove o item salvo na pilha
        pop     {r4, r5, r6, r7, r8, r9, r10, r11, lr}
        bx      lr
