.intel_syntax noprefix

.global write
.global read
.global open
.global close
.global __stack_chk_fail

write:
mov rax, 1
syscall
ret

read:
mov rax, 0
syscall
ret

open:
mov rax, 2
syscall
ret

close:
mov rax, 3
syscall
ret

__stack_chk_fail:
mov rax, 60
mov rdi, 1
syscall
ret
