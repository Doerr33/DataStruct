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
typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode,*LinkStack;

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


int InitStack(LinkStack &s){
    s = NULL;
    printf("初始化成功\n");
    return OK;
}

Status StackEmpty(LinkStack s){
    if(s == NULL){
        printf("栈空\n");
        return true;
    }
    else{
        printf("非空");
        return false;
    }
}

Status Push(LinkStack &s,int e){
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s;
    // 头插
    s = p;
    printf("插入成功\n");
    return OK;
}

Status Pop(LinkStack &s,int &e){
    StackNode *p;
    if(s == NULL){
        printf("栈空\n");
        return ERROR;
    }
    e = s->data;
    p = s;//保存s
    printf("出栈元素是%d",e);
    s = s->next;
    delete p;
    return OK;
}

int GetTop(LinkStack s){
    if(s != NULL){
        printf("栈顶元素是%d\n",s->data);
        return s->data;
    }
}


int main(){
	StackNode *S;
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

