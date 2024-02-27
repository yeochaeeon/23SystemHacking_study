project( bin_analysis_tool )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_subdirectory( libs )

add_executable( bin_analysis_tool bin_analysis_tool.c )
target_compile_options( bin_analysis_tool PUBLIC -g -Wall )
target_link_libraries( bin_analysis_tool LoadBinaryFile ELFanalysis )
target_include_directories( bin_analysis_tool PUBLIC "${PROJECT_SOURCE_DIR}/include" )
set_target_properties( bin_analysis_tool PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

