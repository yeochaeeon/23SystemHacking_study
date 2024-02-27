add_library( ELFanalysis ELFanalysis.c )

target_compile_options( ELFanalysis PUBLIC -g -Wall )
target_include_directories( ELFanalysis PUBLIC "${PROJECT_SOURCE_DIR}/include" )

