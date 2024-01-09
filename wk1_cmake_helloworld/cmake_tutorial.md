## What is cmake? 
* cmake = Cross Platform Make 
* open source build tool
* 빌드프로그램이 아니라 빌드 파일을 생성하는 프로그램.

<hr>

## What is make & makefile ? 

* 여러가지 소스 파일의 의존성을 정리하고 빌드 순서를 만들어 
최종적으로 실행하는 프로그램을 만드는 프로그램 빌드 도구.
* 파일의 종속 관계를 파악해 makefile 에 기술된 대로 컴파일 명령이나 shell명령을 순차적으로 수행함.
* 근데 make 는 툴이고,  
* makefile은 프로그램을 빌드하기 위해 make 문법에 맞춰 작성하는 문서. 
    * makefile 의 구성요소
        * target(목적파일) : 명령어 수행 후 나온 결과를 저장함
        * dependency (의존성, 의존파일 ) : 목적파일을 만들기 위한 재료 파일
        * command (명령어 ) : 실행 되어야 할 명령어들
        * macro : 코드를 단순화 시킴.
<hr>

## 용어정리 

* Compile = 오브젝트 파일을 만드는 과정 (*.obj)
* Link = 헤더파일(*.h) 과 오브젝트 파일들을 모으고 연결하는 과정
* Build = Compile , Link 로 실행파일 (*.exe, *.out, *.elf) 을 만드는 과정
* Incremental build ?
    * 큰 프로젝트에서 처음에는 모두 빌드를 진행하되, 
    이후 수정된 파일에 대해서는 그 소스파일과 연관된 것들만 빌드하는 빌드방식.

<hr>

## How to Use CMake? 

* 프로젝트 최상위 디렉토리에 CMakeList.txt 라는 파일이 존재해야함.
1. 그래서 먼저 CMakeList.txt 파일을 작성한다. 
   * 이 파일에서 빌드 항목, 방법, 테스트/패키지 정의
   * 빌드파일을 생성하는데 필요한 정보들이 들어있음. 

* 이후 빌드를 진행함. 
* 빌드파일들을 생성할 때, 프로젝트 소스 파일들이 존재하는 디렉토리가 아닌 다른 디렉토리에 빌드파일을 생성할 것 !
   * helloworld 프로젝트 디렉토리 안에서 ```mkdir build```로 build 디렉토리 생성    

2.  build 디렉토리로 이동해서 ```cmake .. ``` 입력
    * ```..``` 은 최상위 CMakeLists.txt가 존재하는 경로의 상대경로이다.
    * 빌드시스템을 구성하는 과정
    * 'CMakeLists.txt' 파일을 읽어 필요한 빌드 설정을 결정함. 

3. 이후 ```make``` 명령어를 입력한다. 
    * 이 과정에서는 Build, 즉 Compile 과 Link 가 진행됨.
* Makefile 과 실행파일이 생성된 것을 볼 수 있다.

4. 동일하게 ```./파일이름``` 명령어로 실행파일을 실행한다. 

<hr>

## CMakeLists.txt 의 내용

* ```cmake_minimum_required()``` 
    * 프로젝트에서 사용될 cmake의 최소 버전을 명시

* ```project()```
    * 프로젝트의 정보를 명시
    * 이름, Version, Description, Homepage URL, Languages 도 추가가능.
    * languagues는 'C' or 'CXX' 로 명시.
    * 그 외의 옵션들도 있음.

* ```add_executable()```
    * 생성할 실행 파일을 추가하는 명령이다.
    * argument : (만들 실행파일 이름 필요한 소스 나열...)
 
  
