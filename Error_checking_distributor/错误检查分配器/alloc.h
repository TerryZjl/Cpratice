#ifndef _ALLOC_H_
#define _ALLOC_H_

#include<stdio.h>
#include<windows.h>

#define malloc "no malloc"
#define MALLOC(num, type) \
	(type *)alloc((num)*(sizeof(type)))

extern void *alloc(size_t size);

#endif 