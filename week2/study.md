# assignment 

## c언어 -> 어셈블리어로 컴파일해서 보는 법

* ```gcc -S test.c -o test.S```

하거나

* ``` gcc -o test test.c```
로 컴파일을 해놓고 ```objdump``` 라는 명령어를 사용해도 됨

* ```objdump -d ./test```
하고 gdb로 열어보기 

* ```gdb ./test``` -> ```disas main```

* main 함수를 disassemble 함.
    * 기계어 -> 어셈블리어 : disassemble
    * 어셈블리어 -> 기계어 : assemble 
