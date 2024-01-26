# Week3 Write-Up 

### 메모리 구조

- 코드
- 데이터 - 데이터 / bss
- 힙 - malloc, new(cpp) 
- 스택 - 지역변수를 위한 공간, 함수마다 하나씩 존재, 

### stack

- base - rbp
- top - rsp 
- main 함수가 실행중일 때 rbp 는 그대로 , rsp 는 위치가 계속 바뀜

- pop 할때, 효율성 때문에 굳이 값을 지우지 않고 rsp 만 내림....
- 추후 새로운 값을 push 할 때 값이 덮어짐ㅁㅁ...
- stack구조상에서 위로 갈수록 낮은 주소 , 아래가 높은주소 


### gdb command 

- si : 브레이크포인트 걸고 난 후 실행할 때 함수 안으로 들어가는 명령어 
- pop rbp
- ret = pop rip

- x/x - 16진수로 보기 
- x/s - string으로 보기 
- x/i- instruction(command) 보기  



