#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MaxSize 50
typedef struct{
	ElemType data[MaxSize];
	int top;//栈顶指针 
}SqStack;


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
	// 设置栈为空
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
	// 判断是否栈满
	if(S->top == MaxSize - 1){
		return false;
	} 
	// 进栈
	S->data[++S->top] = x;
	return true;
} 

//出栈
bool Pop(SqStack *S,ElemType x){
	// 判断栈是否空了
	if(S->top == -1){
		return false;
	}
	// 先出栈再移动
	x = S->data[S->top--];
	return true;
}

//读栈顶元素
bool GetTop(SqStack *S){
	// 没有元素
	if(S->top == -1){
		return false;
	}
	printf("栈顶元素是:%d\n",S->data[S->top]);
	return true;
} 


int main(){
	SqStack *S;
	menu(); 
	int Op = -1;
	scanf("%d",&Op);
	while(1){
		system("clear");
		menu();
		switch(Op){
			case 1:
				printf("\n");
				InitStack(S);
				break;
			case 2:
				printf("\n");
				StackEmpty(S);
				break;
			case 3:
				printf("\n");
				int PushNum;
				printf("\n");
				printf("Please input the Push number:");
				scanf("%d",&PushNum);
				Push(S,PushNum);
				break;
			case 4:
				printf("\n");
				int PopNum;
				printf("Please input the Pop number:");
				scanf("%d",&PopNum);
				Pop(S,PopNum);
				break;
			case 5:
				printf("\n");
				GetTop(S); 
				break;
			default:
				printf("\n");
				printf("ERROR\n");
		} 
		scanf("%d",&Op);	
	}
	return 0;
}