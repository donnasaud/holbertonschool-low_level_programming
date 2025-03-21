section .data
    ; Define the string to be printed
    message db 'Hello, World', 0xA  ; 0xA is the newline character
    len equ $ - message            ; Calculate the length of the string

section .text
    global _start                  ; Entry point for the program

_start:
    ; System call: write(1, message, len)
    mov rax, 1                     ; syscall number for write (1)
    mov rdi, 1                     ; file descriptor (1 = stdout)
    mov rsi, message               ; pointer to the message
    mov rdx, len                   ; length of the message
    syscall                        ; invoke the system call

    ; System call: exit(0)
    mov rax, 60                    ; syscall number for exit (60)
    xor rdi, rdi                   ; exit code (0)
    syscall                        ; invoke the system call
