# CMake 최소 요구 버전
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 언어 설정
project(bin_analysis_tool C)

# 실행 파일 생성
add_executable(bin_analysis_tool src/main.c src/analyzer.c)

# 헤더 파일 경로 설정
target_include_directories(bin_analysis_tool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

