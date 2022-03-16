#include<cstdio>
#include<cstdlib>

#define MAXSIZE 5  //定义队列中元素的最大个数
typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];  //用静态数组存放队列元素 
	ElemType front,rear;  //对头指针和队列指针 
} SqQueue;


void menu(){
	printf("-------顺序队列的基本操作-------\n\n");
	printf("---------1.初始化队列-------\n\n");
	printf("---------2.判断队列空-------\n\n");
	printf("---------3.入队  操作-------\n\n");
	printf("---------4.出队  操作-------\n\n");
	printf("--------------------------\n\n");
	printf("请选择你的操作（1-4）："); 
} 


//初始化 
void Sq_InitQueue(SqQueue *Q){
	// 初始队空
	Q->rear = Q->front = 0;
}


//判断队列是否为空
bool Sq_QueueEmpty(SqQueue *Q){
	if(Q->rear == Q->front){
		return true;
	}
	else{
		return false;
	}
} 


//入队
bool Sq_InQueue(SqQueue *Q,int e){
	//这里会发生上溢 
	if(Q->rear >= MAXSIZE){
		return false;
	}
	//先放再移 
	Q->data[Q->rear] = e;
	printf("对尾指针等于：%d\n",Q->rear); 
	++Q->rear;
	return true;
} 


//出队
bool Sq_OutQueue(SqQueue *Q,int *e){
	if(Sq_QueueEmpty(Q)){
		return false; 
	}
	//先获取再移动 
	*e = Q->data[Q->front];
	printf("对头指针等于：%d\n",Q->front); 
	++Q->front;
	return true;
	
} 


int main(){
	SqQueue Q;
	int e;
	//初始化 
	Sq_InitQueue(&Q);
	//判断是否为空
	if(Sq_QueueEmpty(&Q)){
		printf("队列为空\n"); 
	}
	//入队 
	for(int i = 0; i < 5; i++){
		Sq_InQueue(&Q,i + 1);
	} 
	printf("\n");
	//出队
	for(int i = 0; i < 4; i++){
		Sq_OutQueue(&Q,&e);
		printf("出队元素是：%d\n\n", e);
	} 
	if(!Sq_InQueue(&Q,100)){
		printf("上溢\n"); 
	}
	//if(Sq_QueueEmpty(&Q)){
	//	printf("队列为空\n"); 
	//}
	printf("\n");
	system("pause");
	return 0;
}


