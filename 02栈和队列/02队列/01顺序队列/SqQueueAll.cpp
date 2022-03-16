#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 7

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
 

typedef int Status;

typedef struct{
    int *base;//栈底指针
    int front;//头指针
    int rear;//尾指针
}SqQueue;


void menu(){
	printf("-------顺序队列的基本操作-------\n\n");
	printf("---------1.初始化队列-------\n\n");
	printf("---------2.判断队列空-------\n\n");
	printf("---------3.入队  操作-------\n\n");
	printf("---------4.出队  操作-------\n\n");
	printf("--------------------------\n\n");
	printf("请选择你的操作（1-4）："); 
} 

// 初始化
Status InitQueue(SqQueue &q){
    // 首元素的地址就是一个指针
    q.base = (int *)malloc(MAXSIZE*sizeof(int));
    if(!q.base)exit(OVERFLOW);
    q.front = q.rear = 0;//头尾指针设置为0，队列空
    printf("初始化成功\n");
    return OK;
}


// 求长度
int QueueLength(SqQueue q){
    printf("线性表的长度尾%d\n",(q.rear - q.front + MAXSIZE)%MAXSIZE);
    return((q.rear - q.front + MAXSIZE) % MAXSIZE);
}


//判断队列是否为空
bool Sq_QueueEmpty(SqQueue Q){
	if(Q.rear == Q.front){
		return true;
	}
	else{
        printf("队列不为空\n");
		return false;
	}
} 


// 入队
Status EnQueue(SqQueue &q,int e){
    // 少用一个元素形成的解决方法
    if((q.rear + 1) % MAXSIZE == q.front){
        printf("栈满、上溢\n");
        return ERROR;
    }
    q.base[q.rear] = e;//新元素插入到队尾
    printf("入队元素是%d\n\n",q.base[q.rear]);
    q.rear = (q.rear + 1)%MAXSIZE;//队尾指针加1
    return OK;
}

// 出队
Status DeQueue(SqQueue &q){
    if(q.front == q.rear){
        printf("队空、下溢\n");
        return ERROR;
    }
    printf("出队元素是：%d\n\n", q.base[q.front]);
    q.front = (q.front + 1) % MAXSIZE;//队头+1
    return OK;
}


Status GetHead(SqQueue q){
    if(q.front != q.rear){//队列不为空
        printf("队头元素是：%d\n",q.base[q.front]);
        return q.base[q.front];
    }
    return OK;
}

int main(){
	SqQueue Q;
	int e = 0;
	//初始化 
	InitQueue(Q);
	//判断是否为空
	if(Sq_QueueEmpty(Q)){
		printf("队列为空\n"); 
	}
	//入队 
	for(int i = 0; i < 8; i++){
		EnQueue(Q,i + 1);
	} 
	printf("\n");
	//出队
	for(int i = 0; i < 8; i++){
		DeQueue(Q);
		//printf("出队元素是：%d\n\n", e);
	} 
	if(!EnQueue(Q,100)){
		printf("上溢\n"); 
	}
    GetHead(Q);
	//if(Sq_QueueEmpty(&Q)){
	//	printf("队列为空\n"); 
	//}
	printf("\n");
	system("pause");
	return 0;
}

