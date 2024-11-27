section .text
bits 64
default rel
global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    mov rsi, rcx
    imul rsi, rdx
    xor rbx, rbx ; this represents the index, xor to start at index 0

convert:
    cmp rbx, rsi ; compare current index to total number of pixels
    jge finish ; if index is greater than or equal to number of pixels, jump to finish
    
    ; r8 is the base address, rbx is the index, and 4 is the size of each element
    mov eax, dword [r8 + rbx * 4] ; address element = r8 (BASE ADDRESS) + rbx (CURRENT INDEX) * 4 (SIZE OF EACH ELEMENT)
    
    cvtsi2ss xmm0, eax ; convert eax (int) into float
    mov eax, 255 ; load divisor
    cvtsi2ss xmm1, eax ;convert the divisor into float
    divss xmm0, xmm1 ; divide pixel value by 255
    movss dword [r9 + rbx * 4], xmm0 ; store result in float array (same addressing logic as above)
    inc rbx ; increment to the next index
    jmp convert ; jump to convert, repeat for next pixel

finish:
    ret
