#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
 

typedef int Status;

typedef struct{
    int *base;//栈底指针
    int *top;//栈顶指针
    int stacksize;//可用最大容量
}SqStack;


void menu(){
	printf("-------栈的基本操作-------\n\n");
	printf("---------1.初始化栈-------\n\n");
	printf("---------2.判断栈空-------\n\n");
	printf("---------3.进栈操作-------\n\n");
	printf("---------4.出栈操作-------\n\n");
	printf("---------5.清空栈-------\n\n");
	printf("--------------------------\n\n");
	printf("请选择你的操作（1-5）："); 
} 


// 初始化
Status InitStack(SqStack &s){
    s.base = (int *)malloc(MAXSIZE*sizeof(int));
    if(!s.base)exit(OVERFLOW);
    s.top = s.base;//设置为空
    s.stacksize = MAXSIZE;
    printf("初始化成功\n");
    return OK;
}


Status StackEmpty(SqStack s){
    if(s.top == s.base){
        printf("NULL\n");
        return TRUE;
    }
    else{
        printf("Not NULL\n");
        return FALSE;
    }
}


int StackLength(SqStack s){
    printf("长度为:%d\n",s.top - s.base);
    return s.top - s.base;
}


Status ClearStack(SqStack s){
    if(s.base){
        s.top = s.base;
        printf("清空成功\n");
    }
    return OK;
}


Status DestroyStack(SqStack &s){
    if(s.base){
        // s.base 存在则销毁
        delete s.base;
        s.stacksize = 0;
        s.base = s.top = NULL;
        printf("销毁成功\n");
    }
    return OK;
}


Status Push(SqStack &s,int e){
    if(s.top - s.base == s.stacksize){//栈满
        printf("栈满\n");
        return ERROR;
    }
    *s.top = e;
    s.top++;
    return OK;
}


Status Pop(SqStack &s,int &e){
    if(s.top == s.base){
        printf("栈空\n");
        return ERROR;
    }
    --s.top;
    e = *s.top;
    printf("出栈元素是%d\n",e);
    return OK;
}


int main(){
	SqStack S;
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
				// printf("Please input the Pop number:");
				// scanf("%d",&PopNum);
				Pop(S,PopNum);
				break;
			case 5:
				printf("\n");
				ClearStack(S); 
				break;
			default:
				printf("\n");
				printf("ERROR\n");
		} 
		scanf("%d",&Op);	
	}
	return 0;
}