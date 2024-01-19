# Typing Game

> ### 200번의 다른 단어들이 주어진다. 이 단어를 똑같이 입력하면 플래그를 얻을 수 있다.


<hr>

# Solution

* python 으로 익스플로잇 코드를 작성하여 해결할 수 있다.


```python 
from pwn import *

r = remote("ctf.keeper.or.kr", 1004) 

for i in range(200):
    r.recvline() 
    r.recvuntil(b': ')
    answer = r.recvuntil(b"\n").strip().decode()

    r.sendline(answer)

r.interactive()
```

### 코드 설명

- `remote(“  ”  ,  ”   “)`
    - 원격 서버를 대상으로 할 때 사용하는 함수이다.
    - 대상 서버를 실제로 공격하기 위해 사용한다.
    - 주소와 포트번호를 인자로 가지며 이 함수를 통해 서버에 접속할 수 있다.
- `r.recvline()`
    - r 이 출력하는 데이터를 개행 문자를 만날 때까지 받는다.
- `r.recvuntil(b': ')`
    - ‘: ‘ 를 만날 때까지 데이터를 받는다.
    - ‘: ‘ 까지 모두 받는다
    - 네트워크 통신에서 데이터는 바이트 단위로 주고받기 때문에  바이트 문자열 리터럴을 사용해 명시적으로 바이트 형식으로 데이터를 처리한다.
- `answer = r.recvuntil(b"\n").strip().decode()`
    - `r. recvuntil()` : 줄바꿈 문자가 나타날 때까지 데이터를 수신한다.
    - `.strip()` :  수신한 데이터의 양쪽 끝에 있의 공백 문자를 제거한다.
    - `.decode()` : 수신한 데이터를 디코딩해 문자열로 변환한다.
    - 바이트 형식으로 수신한 데이터를 문자열로 변환하는 과정이 필요하다.
    - 위 방식으로 받은 데이터를 answer 변수에 저장한다.
- `r.sendline(answer)`
    - answer을 입력한다.
- `r.interactive()`
    - 셸을 획득했거나, 직접 입력을 주면서 출력을 확인하고 싶을 때 쓰는 함수이다
    - 호출하고 나면 터미널로 프로세스에 데이터를 입력하고 , 프로세스의 출력을 확인할 수 있다.

