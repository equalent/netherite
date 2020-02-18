#include <uv.h>
#include <stdlib.h>
#include <CL/cl.h>

#define OPENCL_LIB_NAME "opencl.dll"

typedef struct {
	cl_platform_id id;
	char profile[17];
	char version[128];
	char name[128];
	char vendor[128];
	char extensions[512];
	cl_ulong timer;
} clPlatform;

typedef cl_int(*clGetPlatformIDs_t)(cl_uint, cl_platform_id*, cl_uint*);
typedef cl_int(*clGetPlatformInfo_t)(cl_platform_id, cl_platform_info, size_t, void*, size_t*);

void test_opencl(uv_lib_t* lib) {
	void* fn1;
	void* fn2;
	auto dlres = uv_dlsym(lib, "clGetPlatformIDs", &fn1);
	if (dlres == 0) {
		dlres = uv_dlsym(lib, "clGetPlatformInfo", &fn2);
		clGetPlatformInfo_t pfn_clGetPlatformInfo = (clGetPlatformInfo_t)fn2;
		clGetPlatformIDs_t pfn_clGetPlatformIDs = (clGetPlatformIDs_t)fn1;
		cl_platform_id* platformIDs = (cl_platform_id*)malloc(sizeof(cl_platform_id) * 1024);
		cl_uint num_platforms = 0;

		auto cl_res = pfn_clGetPlatformIDs(1024, platformIDs, &num_platforms);
		if (cl_res == CL_SUCCESS) {
			clPlatform* platforms = malloc(sizeof(clPlatform) * num_platforms);
			for (cl_uint i = 0; i < num_platforms; i++) {
				platforms[i].id = platformIDs[i];

				pfn_clGetPlatformInfo(platformIDs[i], CL_PLATFORM_PROFILE, 17, &(platforms[i].profile), NULL);
				pfn_clGetPlatformInfo(platformIDs[i], CL_PLATFORM_VERSION, 128, &(platforms[i].version), NULL);
				pfn_clGetPlatformInfo(platformIDs[i], CL_PLATFORM_NAME, 128, &(platforms[i].name), NULL);
				pfn_clGetPlatformInfo(platformIDs[i], CL_PLATFORM_VENDOR, 128, &(platforms[i].vendor), NULL);
				pfn_clGetPlatformInfo(platformIDs[i], CL_PLATFORM_EXTENSIONS, 512, &(platforms[i].extensions), NULL);
			}


			return;
		}
	}


	uv_dlclose(lib);
}

int main() {
	uv_lib_t* lib = (uv_lib_t*)malloc(sizeof(uv_lib_t));
	auto res = uv_dlopen(OPENCL_LIB_NAME, lib);
	if (res == 0) {
		test_opencl(lib);
	}
	return 0;
}