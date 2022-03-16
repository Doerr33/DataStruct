#include"method.h"
int main(){
	SqStack *S;
	menu(); 
	int Op = -1;
	scanf("%d",&Op);
	while(1){
		system("cls");
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