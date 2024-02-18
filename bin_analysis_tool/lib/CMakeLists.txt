add_library( LoadFile LoadFile.c )

target_compile_options( LoadFile PUBLIC -g -Wall )
#target_include_directories( LoadFile PUBLIC "${PROJECT_SOURCE_DIR}/include" )
