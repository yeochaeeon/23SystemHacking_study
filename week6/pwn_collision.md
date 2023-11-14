## pwnable #2[collision]

```ssh col@pwnable.kr -p2222 (pw:guest)```

```c
unsigned long hashcode = 0x21DD09EC;
unsigned long check_password(const char* p){
        int* ip = (int*)p;
        int i;
        int res=0;
        for(i=0; i<5; i++){
                res += ip[i];
        }
        return res;
}

int main(int argc, char* argv[]){
        if(argc<2){
                printf("usage : %s [passcode]\n", argv[0]);
                return 0;
        }
        if(strlen(argv[1]) != 20){
                printf("passcode length should be 20 bytes\n");
                return 0;
        }

        if(hashcode == check_password( argv[1] )){
                system("/bin/cat flag");
                return 0;
        }
        else
                printf("wrong passcode.\n");
        return 0;
}
```

<hr>

### solution 

* fd와 동일하게 인자의 개수가 2개보다 적으면 종료됨. 
* 두번째 인자의 길이가 20bytes가 아니면 종료됨.
* 두번째인자가 위의 hashcode와 같으면 flag 출력됨. 

* argv[1] 로 입력된 값이 check_password() 함수를 지나 return 된 값(res)이 hashcode와 같으면 됨.
* ```int *ip = (int *)p ```
    * p 배열이 int형으로 형변환 되었기 때문에 (4byte씩 x 5번) 읽어들인다.
* ```for (i = 0; i<5; i++){res += ip[i];} return res;```
    * ip배열의 index[0] 부터 index[4] 까지 모두 더한 값이 hasscode인 "0x21DD09EC" 이어야 함.
    * 연산을 해주어야 함
    * hashcode값 : 0x21DD09EC = (0x6C5CEC8) * 4 + 6C5CECC 
    * 이를 little-endian 방식으로 변환하여 조합한 명령어 : 
    ```./col `python -c 'print "\xC8\xCE\xC5\x06"*4+"\xcc\xce\xc5\x06"'` ```


* ```flag : daddy! I just managed to create a hash collision :)```

### 사전지식 

* little-endian 방식 입력
    * ??
