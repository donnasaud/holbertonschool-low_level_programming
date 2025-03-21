global _start

section .text
_start:
    ; sys_write syscall
    mov rax, 1          ; syscall number for write
    mov rdi, 1          ; stdout file descriptor
    mov rsi, msg        ; address of the message
    mov rdx, len        ; message length
    syscall

    ; sys_exit syscall
    mov rax, 60         ; syscall number for exit
    xor rdi, rdi        ; exit code 0
    syscall

section .rodata
msg: db "Hello, World", 10  ; "Hello, World" + newline (ASCII 10)
len: equ $ - msg            ; calculate message length

