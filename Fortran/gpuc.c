#include<stdio.h>

#define test test_

void test(){
	printf("Hi\n");
}

typedef void (*subroutine)(int *);

void ex_ ( subroutine foo ,int *k) {
  	foo(k);
}
