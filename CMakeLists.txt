cmake_minimum_required(VERSION 3.0)

project(Netherite C)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Binaries)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Binaries)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(MSVC)
	add_compile_options(
		"$<$<CONFIG:Debug>:/MDd>"
		"$<$<CONFIG:RelWithDebInfo>:/MT>"
		"$<$<CONFIG:Release>:/MT>"
		"$<$<CONFIG:MinSizeRel>:/MT>"
	)
endif()

option(NE_USE_OPENCL "Build Netherite with OpenCL support" ON)
option(NE_USE_AVX "Build Netherite with AVX support" ON)

add_subdirectory(ThirdParty)
add_subdirectory(Source)