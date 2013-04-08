#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif
#define MAX_SOURCE_SIZE (0x100000)

cl_uint num_platforms;
cl_platform_id *platform;
cl_uint num_devices;
cl_device_id *device_id;
cl_context *context;
cl_command_queue *queue;
cl_program *program;
cl_kernel *kernel;
cl_mem *mem_obj;

char *source_str;
size_t source_size;

bool GPU_INIT = false;
bool MEM_INIT = false;


void checkErr(cl_int errNum, const char * name){
	if (errNum != CL_SUCCESS) {
		fprintf( stderr, "ERROR: %s ( %i)\n",name,errNum );
		if(errNum == CL_INVALID_CONTEXT) fprintf(stderr, "CONTEXT");
    	exit(EXIT_FAILURE);
    	}
}

// Get platform and device information
void initPlatform(cl_platform_id **platform,cl_uint num_platforms){
	cl_int errNum;
	//QUERING IS MISSING
	*platform =  (cl_platform_id*)malloc(sizeof(cl_platform_id));
	errNum = clGetPlatformIDs(1, *platform, &num_platforms);
	checkErr(errNum,"PLATFORM INIT");
}
void initDevice(cl_platform_id *platform, cl_device_id **device_id, cl_uint num_devices){
	//QUERING IS MISSING
	cl_int errNum;
	*device_id = (cl_device_id*)malloc(sizeof(cl_device_id));
 	errNum = clGetDeviceIDs( *platform, CL_DEVICE_TYPE_DEFAULT, 1, 
            *device_id, &num_devices);
	checkErr(errNum,"DEVICE");
}

    // Create an OpenCL context
void initContext(cl_context **context, cl_device_id *device_id){
	cl_int errNum;
	*context = (cl_context *)malloc(sizeof(context));
	**context = clCreateContext( NULL, 1, device_id, NULL, NULL, &errNum);
	checkErr(errNum,"CONTEXT INIT");
	/*fprintf(stderr,"Successfully created a context\n");*/
}
    // Create a command queue
void initCommandQueue(cl_command_queue **queue,cl_context *context,cl_device_id *device_id){

	cl_int errNum;
	*queue = (cl_command_queue*) malloc(sizeof(cl_command_queue));
	**queue = clCreateCommandQueue(*context, *device_id, 0, &errNum);
	checkErr(errNum,"QUEUE INIT");
}

void CreateProgram(){
	// Create a program from the kernel source
	int errNum;
	program = (cl_program *)malloc(sizeof(cl_program));
	*program = clCreateProgramWithSource(*context, 1, 
			(const char **)&source_str, (const size_t *)&source_size, &errNum);
	checkErr(errNum,"CREATE PROGRAM");
}

void BuildProgram(){
	//Building the program
	int errNum;
	/*char* build_log; size_t log_size;*/
	/*errNum = clGetProgramBuildInfo(*program, *device_id, CL_PROGRAM_BUILD_LOG |CL_PROGRAM_BUILD_STATUS , 0, NULL, &log_size);*/
	/*build_log = (char* )malloc((log_size+1));*/

	// Second call to get the log
	/*errNum = clGetProgramBuildInfo(*program, *device_id, CL_PROGRAM_BUILD_LOG|CL_PROGRAM_BUILD_STATUS, log_size, build_log, NULL);*/
	/*build_log[log_size] = '\0';*/
	/*printf("--- Build log ---\n ");*/
	/*fprintf(stderr, "%s\n", build_log);*/
	/*free(build_log);*/
	errNum = clBuildProgram(*program, 1, device_id, NULL, NULL, NULL);
	char* build_log;
	size_t log_size;
	// First call to know the proper size
	clGetProgramBuildInfo(*program, *device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
	build_log = (char*) malloc( sizeof(char)*(log_size+1));
	// Second call to get the log
	clGetProgramBuildInfo(*program, *device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL);
	build_log[log_size] = '\0';
	fprintf(stderr,"%s",build_log);
	free(build_log);
	checkErr(errNum, "BUILD PROGRAM");

}
void CreateKernel(){
	//Creating the kernel
	int errNum;
	kernel = (cl_kernel*)malloc(sizeof(cl_kernel));
	*kernel = clCreateKernel(*program, "simple_return", &errNum);
	checkErr(errNum, "CREATE KERNEL");
}

void CreateBuffers(size_t port_vec_size,void *portvec,size_t helvars_size, void *helvars,size_t kinvars_size,void *kinvars,size_t comp_size, void *comp){

	if(MEM_INIT==false){
		/*cl_mem_flags f1 = CL_MEM_READ_ONLY|CL_MEM_COPY_HOST_PTR;*/
		/*cl_mem_flags f2 = CL_MEM_READ_WRITE|CL_MEM_COPY_HOST_PTR;*/
		/*cl_mem_flags f1 = CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR;*/
		cl_mem_flags f2 = CL_MEM_WRITE_ONLY|CL_MEM_USE_HOST_PTR;
		/*cl_mem_flags f1 = CL_MEM_READ_ONLY|CL_MEM_USE_HOST_PTR;*/
		/*cl_mem_flags f1 = CL_MEM_READ_WRITE|CL_MEM_ALLOC_HOST_PTR;*/
		cl_mem_flags f1 = CL_MEM_READ_WRITE|CL_MEM_USE_HOST_PTR;
		/*cl_mem_flags f1 = CL_MEM_READ_ONLY;*/
		/*cl_mem_flags f1 = CL_MEM_READ_WRITE;*/
		cl_int errNum;
		/* ---------------- vectors_ mem ---------------- */
		mem_obj[0] 
		= clCreateBuffer(*context, f1, port_vec_size, portvec, &errNum);
		checkErr(errNum,"MEMORY ALLOCATION1");

		/* ---------------- helvars_ mem ---------------- */
		/* test local memory*/

		mem_obj[1] 
			= clCreateBuffer(*context, f2, helvars_size, helvars, &errNum);
		checkErr(errNum,"MEMORY ALLOCATION2");

		/* ---------------- kinvars_ mem ---------------- */
		/*mem_obj[2] */
		/*= clCreateBuffer(*context, f1, kinvars_size, kinvars, &errNum);*/
		/*checkErr(errNum,"MEMORY ALLOCATION3");*/

		/* ---------------- result mem ---------------- */
		/*mem_obj[3] */
		/*= clCreateBuffer(*context, f2, comp_size, comp, &errNum);*/
		/*checkErr(errNum,"MEMORY ALLOCATIO4");*/

		// Setting kernel arguments
		errNum = clSetKernelArg(*kernel, 0, sizeof(cl_mem), (void *)&mem_obj[0]);
		checkErr(errNum,"KERNEL ARG SET0");

		/*errNum = clSetKernelArg(*kernel, 2, sizeof(cl_mem), (void *)&mem_obj[2]);*/
		/*checkErr(errNum,"KERNEL ARG SET1");*/

		/*errNum = clSetKernelArg(*kernel, 3, sizeof(cl_mem), (void *)&mem_obj[3]);*/
		/*checkErr(errNum,"KERNEL ARG SET2");*/

		errNum = clSetKernelArg(*kernel, 1, sizeof(cl_mem), (void *)&mem_obj[1]);
		checkErr(errNum,"KERNEL ARG SET3");

		MEM_INIT = true;
		/*printf("Memory succesfully initialised");*/
	}

}

void read_kernel_src(const char *file,char **source,size_t *size){
	FILE *fp;
	fp = fopen(file, "r");
	if (!fp) {
		fprintf(stderr, "Failed to load kernel.\n");
		exit(EXIT_FAILURE);
	}

	*source = (char*)malloc(MAX_SOURCE_SIZE);
	*size = fread( *source, 1, MAX_SOURCE_SIZE, fp);

	fclose( fp );
}



void gpuinit(){
	if(GPU_INIT == false){

		initPlatform(&platform,num_platforms);

		initDevice(platform,&device_id,num_devices);

		initContext(&context,device_id);

		initCommandQueue(&queue,context,device_id);

		const char *file ="kernel.c";
		read_kernel_src(file,&source_str,&source_size);
		
		CreateProgram();

		BuildProgram();

		CreateKernel();

		mem_obj = (cl_mem*)malloc(4*sizeof(cl_mem));

		GPU_INIT = true;
	}
}
cl_platform_id *getPlatform(){
	return platform;
}
cl_device_id *getDevice(){
	return device_id;
}
cl_context *getContext(){
	return context;
}
cl_command_queue *getCommandQueue(){
	return queue;
}
cl_program *get_program(){
	return program;
}
cl_kernel *get_kernel(){
	return kernel;
}
cl_mem *get_mem(){
	return mem_obj;
}
