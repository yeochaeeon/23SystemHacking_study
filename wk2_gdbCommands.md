# gdbCommands

> ## gdb실행

* gdb 실행 : `gdb ./test`
    * 프로세스 실행 : `r`
    * 브레이크 포인트 걸기 : `b *main`
    * 한 줄씩 실행하기 : `ni`
    * register 정보 보기 : `info reg`
    * 특정 register 보기 : `info reg rax`
    * 실행할 때 마다 정보 띄우기 : `display/x $rax`
    * 메모리 값 확인 
        * `x/i` : 명령어 형식 
        * `x/s` : 문자열 형식
        * `x/x` : 16진수 형식
    * 실행 하다가 함수 내부로 진입하기 : `si`


> ## 문법 변환 

* 어셈블리 문법 변환 : `set disassembly-flavor att`(at&t) or `set disassembly-flavor intel`(intel)

* 특정 문법으로 고정하고 싶을 때 
    * `echo "set disassembly-flavor att >> ~/.gdbinit`
    * `show disassembly-flavor` 로 확인 가능 ! 
