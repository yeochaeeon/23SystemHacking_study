## What is cmake? 

* cmake = Cross Platform Make 
* open source build tool
* 빌드프로그램이 아니라 빌드 파일을 생성하는 프로그램.

<hr>

## What is make & makefile ? 

* 여러가지 소스 파일의 의존성을 정리하고 빌드 순서를 만들어 
최종적으로 실행하는 프로그램을 만드는 프로그램 빌드 도구.

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
   * 이 파일에서 빌드 항목, 방법, 테스트/패키지 정의
   * 빌드파일을 생성하는데 필요한 정보들이 들어있음.
* 빌드파일들을 생성할 때, 
프로젝트 소스 파일들이 존재하는 디렉토리가 아닌 다른 디렉토리에 
빌드파일을 생성할 것 !
* build 디렉토리로 이동해서 ```cmake .. ``` 입력
    * ```..``` 은 최상위 CMakeLists.txt가 존재하는 경로의 상대경로이다.
* 이후 ```make``` 명령어를 입력하면, 빌드가 진행됨.
* Makefile 이 생성된 것을 볼 수 있다. 

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
    * 
