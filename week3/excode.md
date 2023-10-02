## 시스템해킹 실습 예제 - pwnable #1_[fd]
```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[32]; // 전역변수 buf 선언 
int main(int argc, char* argv[], char* envp[]){
        if(argc<2){
                printf("pass argv[1] a number\n");
                return 0;
        } // 실행할 때 인자가 없으면 해당 문장 출력 후 종료.
          // 실행할 때 인자를 함께 입력값에 넣어주어야 함. 
        int fd = atoi( argv[1] ) - 0x1234; //
        int len = 0;
        len = read(fd, buf, 32);
        if(!strcmp("LETMEWIN\n", buf)){
                printf("good job :)\n");
                system("/bin/cat flag");
                exit(0);
        }
        printf("learn about Linux file IO\n");                
        return 0;
 
}

```
### 사전지식

*  fd (file discriptor)
    * 특정 파일에 대한 접근을 하기위한 handle로 사용되는 
    * 시스템으로부터 할당받은 파일을 대표하는 0이아닌 정수의 값.
    * 프로세스에서 실행되는 파일들의 목록을 관리해주는 테이블의 인덱스 값
    * | 번호 | 설명 | 이름 | 파일스트림 |
      |-------|-----|-------|------------| 
      | 0 | 표준입력 | STDIN_FILENO | stdin |
      | 1 |표준출력 | STDOUT_FILENO | stdout |
      | 2 | 표준에러 | STDERR_FILENO | stderr |

 * atoi() 함수 
    * 10진 정수 문자열 -> 정수 로 변환하는 함수
    * 10진 정수 숫자 문자 앞의 공백 문자는 자동제거됨
    * 공백 및 10진 정수 문자가 아닌 문자로 시작하면 0을 반환 


* read() 함수
    * open()함수로 열기를 한 파일의 내용을 읽음
    * 형태 : ssize_t read (int fd, void *buf, size_t nbytes) <- 인자 3개

* strcmp() 함수
    * 매개변수로 들어온 두 개의 문자열을 비교하여 같으면 0 , 다르면 1을 반환.
    * 위 코드에서는 ```!strcmp```라서 반대로 같으면 1, 다르면 0을 반환함.

### Solution 

*  
