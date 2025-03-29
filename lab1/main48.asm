bits 32
global _main
extern _printf
extern _ExitProcess@4

section .data
    A1 dw 0x1234
    A2 dw 0x5678
    A3 dw 0x9ABC
    B1 dw 0xDEAD
    B2 dw 0xBEEF
    B3 dw 0xCAFE
    C1 dw 0
    C2 dw 0
    C3 dw 0

    fmt_hex db "Результат в 16-ричной системе: 0x%04X%04X%04X", 13, 10, 0
    fmt_dec db "Результат в 10-ричной системе: %lu", 13, 10, 0

section .text
_main:

    mov ax, [A1]
    add ax, [B1]
    mov [C1], ax

    mov ax, [A2]
    adc ax, [B2]
    mov [C2], ax

    mov ax, [A3]
    adc ax, [B3]
    mov [C3], ax

    ; HEX
    movzx eax, word [C3]
    push eax
    movzx eax, word [C2]
    push eax
    movzx eax, word [C1]
    push eax
    push fmt_hex
    call _printf
    add esp, 16

    ; DEC
    mov eax, [C1]
    push eax
    push fmt_dec
    call _printf
    add esp, 8

    push 0
    call _ExitProcess@4