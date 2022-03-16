#include<cstdio>
#include<cstdlib>

#define MAXSIZE 5  //定义队列中元素的最大个数
typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];  //用静态数组存放队列元素 
	ElemType front,rear;  //对头指针和队列指针 
} SqQueue;
