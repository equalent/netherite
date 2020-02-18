add_executable(cltest cltest.c)

target_link_libraries(cltest uv_a OpenCL)