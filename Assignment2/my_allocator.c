/* 
    File: my_allocator.c

    Author: <your name>
            Department of Computer Science
            Texas A&M University
    Date  : <date>

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include<stdlib.h>
#include "my_allocator.h"

Header** list_ptr;
Addr def_adr;
unsigned int base;
uintptr_t sys_begin;
unsigned int iListSize;
typedef struct Header Header;

struct Header {
	int size;
	bool is_free;
	Header* next;
};

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE MY_ALLOCATOR */
/*--------------------------------------------------------------------------*/

/* Don't forget to implement "init_allocator" and "release_allocator"! */
unsigned int init_allocator(unsigned int _basic_block_size, unsigned int _length) {	
	Header* int_header;
	unsigned int remain = _length%_basic_block_size;
	if (remain) {
		printf("It's not evenly divided\n");
		return 0;
	}
	double dlist_size = ceil(log2(_length/_basic_block_size));
	iListSize = (int) dlist_size;
	Header** free_list = (Header**)malloc(2*list_size*sizeof(Header*));
	free_list[0]=(Header*)malloc(_length);
	sys_begin = (uintptr_t)free_list[0];
	Header* myInitHeader = free_list[0];
	myInitHeader->is_free = true;
	myInitHeader->next = NULL;
	Header* curHeader = myInitHeader;
	int currentSize = pow(2,list_size-1);
	unsigned int total = _length;
	for (int i = 0; i < list_size*2; i+=1) {
		_basic_block_size*power(2,(list_size-(i+1)));
		if (total>=(_basic_block_size*power(2,(list_size-((i+1)))))) {
			free_list[i] = free_list[i-1]->next;
			free_list[i] -> is_free = true;
			free_list[i] -> size = currentSize;
			currentSize /= 2;
		}
			
			
	/*
	int cnt = 1;
	while(currentSize > 0){
		//1. find the maximum size in power of 2
		int maxSize = currentSize / 2;
		//2. initial the block of memory with header is_free, next and size
	}
	
	*/
			
	
	}
	list_ptr = free_list;
	
	return 1;
}

extern Addr my_malloc(unsigned int _length) {
  /* This preliminary implementation simply hands the call over the 
     the C standard library! 
     Of course this needs to be replaced by your implementation.
  */
  
  // return malloc((size_t)_length);
}

extern int my_free(Addr _a) {
  /* Same here! */
  Header* my_addr = (Header*)_a;
  
  // free(_a);
  return 0;
}

extern int release_allocator() {
	free((void*)list_ptr);
	free((void*)def_adr);
	printf("The allocator fails!\n");
	return 0;
}