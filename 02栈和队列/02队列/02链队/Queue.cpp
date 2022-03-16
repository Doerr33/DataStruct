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

typedef struct Qnode{
    int data;
    struct Qnode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


// 初始化
Status InitQueue(LinkQueue &q){
    q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!q.front)exit(OVERFLOW);
    q.front->next = NULL;
    printf("初始化成功\n");
    return OK;
}


// 销毁
Status DestoryQueue(LinkQueue &q){
    QNode *p;
    while(q.front){
        p = q.front->next;
        free(q.front);
        q.front = p;
    }
    //q.rear = q.front->next; free(q.front);q.front = q.rear;也行

    printf("销毁成功\n");
    return OK;
}

// 入队
Status EnQueue(LinkQueue &q,int e){
    QNode *p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
    printf("入队元素是%d\n",p->data);
    return OK;

}

// 出队，删除的是最后一个节点，那么特殊考虑
Status DeQueue(LinkQueue &q){
    QNode *p;
    if(q.front == q.rear){
        printf("栈空，下溢\n");
        return ERROR;
    }
    p = q.front->next;
    printf("删除的元素是%d\n",p->data);

    q.front->next = p->next;
    // 如果里面只有一个元素，即删除的是最后一个元素
    if(q.rear == p){
        q.rear = q.front;
    }

    free(p);
    return OK;
}


// 获取队头元素
Status GetHead(LinkQueue q){
    if(q.front == q.rear)return ERROR;
    printf("队头元素是%d\n",q.front->next->data);
    return OK;
}



//判断队列是否为空
bool Sq_QueueEmpty(LinkQueue Q){
	if(Q.rear == Q.front){
		return true;
	}
	else{
        printf("队列不为空\n");
		return false;
	}
} 

int main(){
	LinkQueue Q;
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
	for(int i = 0; i < 9; i++){
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
