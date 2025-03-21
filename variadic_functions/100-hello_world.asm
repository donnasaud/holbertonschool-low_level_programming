global main      ; Changed from _start

section .text
main:
    ; sys_write syscall
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, len
    syscall

    ; sys_exit syscall
    mov rax, 60
    xor rdi, rdi
    syscall

section .rodata
msg: db "Hello, World", 10
len: equ $ - msg

