#include"SqStack.h"
void menu(){
	printf("-------栈的基本操作-------\n\n");
	printf("---------1.初始化栈-------\n\n");
	printf("---------2.判断栈空-------\n\n");
	printf("---------3.进栈操作-------\n\n");
	printf("---------4.出栈操作-------\n\n");
	printf("---------5.读栈顶数-------\n\n");
	printf("--------------------------\n\n");
	printf("请选择你的操作（1-5）："); 
} 
//初始化
void InitStack(SqStack *S){
	S->top = -1;
} 
//判断栈是否为空
bool StackEmpty(SqStack *S){
	if(S->top == -1){
		printf("SqStack is NULL\n");
		return true;
	}
	else{
		printf("SqStack is not NULL\n"); 
		return false;
	}
} 
//进栈
bool Push(SqStack *S,ElemType x){
	if(S->top == MaxSize - 1){
		return false;
	} 
	S->data[++S->top] = x;
	return true;
} 
//出栈
bool Pop(SqStack *S,ElemType x){
	if(S->top == -1){
		return false;
	}
	x = S->data[S->top--];
	return true;
}
//读栈顶元素
bool GetTop(SqStack *S){
	if(S->top == -1){
		return false;
	}
	printf("栈顶元素是:%d\n",S->data[S->top]);
	return true;
} 
