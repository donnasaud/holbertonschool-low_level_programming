section .data
    hello_msg db "Hello, World", 10
    msg_len equ $ - hello_msg

section .text
    global _start

_start:
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; stdout
    mov rsi, hello_msg  ; message address
    mov rdx, msg_len    ; message length
    syscall

    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; status: 0
    syscall

