#include"method.h"
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