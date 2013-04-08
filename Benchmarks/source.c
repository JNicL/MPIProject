#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif
#include "complex.h"

#include <sys/time.h>


#define USE_GPU

typedef struct ComplexType{
	double re,im;
}ComplexType;


cl_int errNum;
cl_command_queue *getCommandQueue();
cl_mem *get_mem();
cl_kernel *get_kernel();
void CreateBuffers(size_t port_vec_size,void *portvec,size_t helvars_size, void *helvars,size_t kinvars_size,void *kinvars,size_t comp_size, void *comp);

int main(){
	gpuinit();
	cl_command_queue *queue = getCommandQueue();

	int num_CC_in = 1000;
	int num_CC_out = 4;
	complex *CC = (complex *)malloc(num_CC_in*sizeof(complex));
	ComplexType *CCRes = (ComplexType *)malloc(num_CC_out*sizeof(ComplexType));

	CreateBuffers(num_CC_in*sizeof(ComplexType),CC,num_CC_out*sizeof(ComplexType),CCRes,0,NULL,0,NULL);
	cl_mem *mem_obj = get_mem();
	cl_kernel *kernel = get_kernel();
	const size_t globalWorkSize[1] ={1024};
	const size_t localWorkSize[1] = {1024};
	struct timeval t0,t1,t2,t3;


	/**//*printf("%d,%d\n",sizeof(complex),sizeof(ComplexType));*/

	complex c1 = 1.0+ I *2.0;
	ComplexType *c2 = (ComplexType*)&c1;
	/**//*printf("%f,%f\n",c2->re,c2->im);*/
	/**//*gettimeofday(&t2, 0);*/
	/**//*long elapsed2 = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;*/

	/**//*printf("%ld\n",elapsed2);*/

	/**//*printf("Please press <ENTER> to continue.");*/
	/**//*while(getchar() != '\n');*/

	/**//**//**//*checkErr(errNum,"MAP BUFFER");*/

	int i;
	int runs;
	for(i = 0; i < num_CC_in;i++){
		CC[i] = 0.999999999+I * 3.0;
	} 
	/*clFinish(*queue);*/

#ifdef USE_GPU
	runs = 60;
	int q;
	for (q = 0; q<runs;q++){

	gettimeofday(&t0, 0);
	for(i = 0; i < runs; i++){
	/*clEnqueueMapBuffer(*queue,mem_obj[0],CL_TRUE,CL_MAP_WRITE,0,num_CC*sizeof(ComplexType),0,NULL,NULL,&errNum);*/


	clEnqueueUnmapMemObject(*queue,mem_obj[0],CC,0,NULL,NULL);
	/**//*clEnqueueWriteBuffer(*queue, mem_obj[0], CL_TRUE, 0,num_CC*sizeof(ComplexType), CC, 0, NULL, NULL);*/
	errNum = clEnqueueNDRangeKernel(*queue,*kernel,1,NULL,globalWorkSize,localWorkSize,0,NULL,NULL);
	checkErr(errNum,"ENQUEUE NDRange");

	/*gettimeofday(&t1, 0);*/
	/**//**//*//Read back data 150ms*/
	/*errNum = clEnqueueReadBuffer(*queue, mem_obj[0], CL_TRUE, 0, */
	/**//*num_CC*sizeof(ComplexType), CC, 0, NULL, NULL);*/
	/**//*checkErr(errNum,"READ BUFFER");*/
	/*clEnqueueMapBuffer(*queue,mem_obj[0],CL_TRUE,CL_MAP_WRITE,0,num_CC*sizeof(ComplexType),0,NULL,NULL,&errNum);*/
	clEnqueueMapBuffer(*queue,mem_obj[1],CL_TRUE,CL_MAP_WRITE,0,num_CC_out*sizeof(ComplexType),0,NULL,NULL,&errNum);
	checkErr(errNum,"MAP BUFFER");
	}
	}
	printf("%.20f\n",CCRes[0].re);

	gettimeofday(&t1, 0);
	/**//*test = clEnqueueMapBuffer(*queue,mem_obj[0],CL_TRUE,CL_MAP_WRITE,0,num_CC*sizeof(ComplexType),0,NULL,NULL,&errNum);*/
#endif
#ifndef USE_GPU

	runs = 300;
	int runs2 = 4000;
	int runs3 = 1024;

	double a = 1;
	int j,k;
	gettimeofday(&t0, 0);
	for(k=0;k<runs;k++){
		a = 1;
		for(i = 0; i< runs2; i++){
			for(j = 0; j< runs3; j++){
				/*a = a *b[(i*j)%(400)].re;*/
				a = a *creal(CC[(i*j)%(num_CC_in)]);
			}
		}
	}

	gettimeofday(&t1, 0);
	printf("%.20f\n",a);
#endif
	
	/**/
	long elapsed1 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	printf("%f\n",((double)elapsed1/ (double)runs));


}
