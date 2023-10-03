## 시스템해킹 실습 예제 - pwnable #1[fd]

``` pwnable 접속 ```
<pre>
    ```ssh fd@pwnable.kr -p2222```  
    pw : guest
</pre>


```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[32]; // 전역변수 buf 선언 
int main(int argc, char* argv[], char* envp[]){
        if(argc<2){ // 명령줄에 명령어 1개만 입력시에 
                printf("pass argv[1] a number\n");
                return 0;
        } // 실행할 때 프로그램명 외의 인자가 없으면 해당 문장 출력 후 종료.
          // 실행할 때 프로그램명과 함께 인자를 입력값에 넣어주어야 함.

        int fd = atoi( argv[1] ) - 0x1234; // 문자열을 정수형으로 변환
                                           //0 = 4660 - 4660 
        int len = 0;
        len = read(fd, buf, 32); // fd 에 0 이 할당되면 buf 활성화 
        if(!strcmp("LETMEWIN\n", buf)){ // 입력받은 값과 첫 매개변수 비교 같으면 1 다르면 0 반환
                printf("good job :)\n");
                system("/bin/cat flag");
                exit(0);
        }
        printf("learn about Linux file IO\n");                
        return 0;
 
}



```

<hr>

### Solution 

*  ```./fd 4660```
    * ./fd 로 실행만 먼저 해주면 ```if(argv <2 )```에 의 해 인자를 전달해달라는 메세지가 뜸
    * read함수 의 첫번째 매개변수인 fd 값이 0이 들어가야 비로소 표준입력으로 인식되어   
    키보드로 입력하는 값을 buf에 저장되게 됨.
    * fd 에 0이 들어가려면 atoi(argv[1]) - 0x1234 가 0이 되어야 함.
    * 0x1234 는 10진 정수로 4660 이므로 ./fd 4660 을 입력하면  무언가를 입력할 수 있게 됨.

* ```LETMEWIN``` 
    * 입력이 가능해진 버퍼에 위의 문자열을 입력하면 
    !strcmp함수를 돌아 flag 파일의 플래그값 까지 보여주고 
    프로그램을 종료함.
    * 틀린 문자열을 입력하면 if문의 조건을 만족하지 않기 때문에  
    ```learn about ```어쩌구 메세지가 뜸.

<hr>

### 사전지식

* main 함수의 인자 
    * argc 
        * main 함수에 전달되는 명령줄 인자의 개수
        * ex)```./fd 4660```이면 2  
          ex) ```./test arg1 arg2 arg3```이면 4
    * argv (포인터 배열)
        * main 함수에 전달되는 명령줄 인자의 배열
        * argv[1]은 프로그램의 이름이 저장됨
        * 그 이후의 인덱스에는 명령줄에 전달한 각 인자들이 저장됨
        * 그래서 #solution 에서의 argv[1]에는 4660 이 저장됨
    * envp 
        * 환경변수를 저장
        * 보통 이배열은 사용하지 않아도 되고 
        * 일반적으로는 argv인자만 사용됨



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


<hr>






