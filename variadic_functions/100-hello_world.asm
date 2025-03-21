section .data
    hello_msg db "Hello, World", 10  ; 10 is newline '\n'
    msg_len equ $ - hello_msg

section .text
    global _start

_start:
    ; write syscall: sys_write(fd=1, buf=hello_msg, count=msg_len)
    mov rax, 1          ; syscall number for write
    mov rdi, 1          ; file descriptor (stdout)
    mov rsi, hello_msg  ; pointer to message
    mov rdx, msg_len    ; message length
    syscall

    ; exit syscall: sys_exit(status=0)
    mov rax, 60         ; syscall number for exit
    xor rdi, rdi        ; exit code 0
    syscall

