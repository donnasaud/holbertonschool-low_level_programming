section .data
    msg db "Hello, World", 10 ; 10 is ASCII newline '\n'
    len equ $ - msg           ; length of the string

section .text
    global _start

_start:
    mov rax, 1          ; syscall number for sys_write
    mov rdi, 1          ; file descriptor: 1 = stdout
    mov rsi, msg        ; pointer to the message
    mov rdx, len        ; message length
    syscall             ; make syscall

    ; Exit the program
    mov rax, 60         ; syscall number for sys_exit
    xor rdi, rdi        ; status 0
    syscall

