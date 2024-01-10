.global main
main : 
  mov $0x10, %rax
  mov $0x20, %rbx
  add %rbx, %rax
  sub %rbx, %rax
  mov $5, %rcx
  mov $3, %rdx
  imul %rdx, %rcx 
