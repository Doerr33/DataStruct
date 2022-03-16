//###############头文件#################### 
 
 #include<stdio.h>
 #include<stdlib.h>
 
 //###############函数返回状态##############
 
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define OVERFLOW -2
 #define InitSize 10
 //##############Status函数类型#############
 
 typedef int ElemType;  
 //顺序表最大值  
 
 //增量+最大值的 
 
 typedef struct{
 	//顺序表元素类型 float.char
 	int *elem;
 	int length; //当前长度 
 	int MaxSize;//当前最大值 
 }SqList; 

//################静态初始化顺序表的基本操作#########################
void menu(){
	printf("---------静态顺序表操作--------\n\n");
	printf("---------1. 初始化顺序表-------\n\n");
	printf("---------2. 判断是否空---------\n\n");
	printf("---------3. 销毁顺序表---------\n\n");
	printf("---------4. 清空顺序表---------\n\n");
	printf("---------5. 获取表长度---------\n\n");
	printf("---------6. 按位获取元素-------\n\n");
	printf("---------7. 按值获取元素-------\n\n");
	printf("---------8. 插入元素-----------\n\n");
	printf("---------9. 删除元素-----------\n\n");
    printf("---------10.打     印----------\n\n");
	
	printf("--------------------------\n\n");
	printf("请选择你的操作（1-10）："); 
} 

 //1.顺序表初始化 
 int InitSqList(SqList& L){
 	//申请初始空间 
 	L.elem = (int*)malloc(sizeof(int)*InitSize); 
 	if(!L.elem)exit(OVERFLOW);
 	//清除脏数据 
 	for(int i = 0; i < 10; i++){
		int a = rand() % 10;    //产生0~9的随机数，注意10会被整除
		L.elem[i] = a; 	
 	}
 	//初始化成员 
 	L.length = 10;
 	L.MaxSize = InitSize;
	printf("初始化成功\n");
 	return OK;
 }
 
 
 //2.销毁顺序表 
 void DestroySqList(SqList& L){
 	printf("顺序表已经销毁\n");
 	L.length = 0;
 	L.MaxSize = 0;
 	//释放指针 
 	if(L.elem != NULL){
		free(L.elem);
		L.elem = NULL; 	
 	}
 } 
 
 //3.清空顺序表 
 void ClearSqList(SqList& L){
 	L.length = 0;
	L.MaxSize = InitSize; 
 	printf("Clear顺序表已清空现在长度为：%d\n",L.length);
 } 
 
 //4.获取顺序表长度
 int GetSqListLength(SqList& L){
 	printf("顺序表的长度为：%d\n",L.length);
 	return OK;
 } 
 
 //5.判断顺序表是否空
 void SqListIsEmpty(SqList& L){
 	if(L.length == 0)printf("空\n");
 	else{
	 	printf("非空\n");
 	}
 } 
 
 //6.获取顺序表中位置i的元素的内容（时间复杂度O（1）随机存取，每一条只运行一次） 
 int SqListGetElem(SqList& L,int i,int &e){
 	//1-length范围 
 	if(i < 1 || i > L.length)return ERROR;
 	e = L.elem[i - 1];
 	printf("第%d位置的元素是：%d\n",i,e);
 	return OK;
 } 
 
 //7.按值查找，顺序查找
 int SqListLocateElem(SqList& L,int e){
 	int flag = - 1; 
 	for(int i = 0; i < L.length; i++){
	 	if(L.elem[i] == e){
	 		flag = i + 1;
	 		printf("元素%d在顺序表中的位置是%d\n",e,flag);
	 		return OK;
	 	}
 	}
 	if(flag == -1){
	 	printf("顺序表中没有元素%d\n",e);
	 }
 	return 0;
 } 
 //8.插入
 int SqListInsert(SqList& L,int i,int e){
 	if(i < 1 || i > L.length + 1)return ERROR;
 	//空间满，增加空间 
 	if(L.length >= L.MaxSize){
	 	L.MaxSize = L.MaxSize + InitSize;
	 }
 	for(int j = L.length - 1;j >= i-1; j--){
	 	L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length ++;
    return OK;
 } 
 
 //9.删除
 int SqListDelete(SqList& L,int i){
 	if((i < 1)||(i > L.length))return ERROR;
 	for(int j = i; j <= L.length - 1; j++){
		L.elem[j - 1] = L.elem[j];
			
 	}
 	L.length --; 
 	return OK;
 } 
 //10.打印
 void SqListPrintf(SqList& L){
 	if(L.length == 0){
	 	printf("顺序表长度为0\n");
	 	return;
	 }
 	for(int i = 0; i < L.length; i++){
		printf("%5d ",L.elem[i]); 	
 	}
 	printf("\n");
 } 

 
int main(){
  	menu();
    int optional;
    SqList L;
    int e;
    scanf("%d",&optional);
    while(1){
    	system("clear"); 
    	menu();
    	switch(optional){
	    	case 1:
	    		InitSqList(L);
	    		break;
    		case 2:
	    		SqListIsEmpty(L);
	    		break;
    		case 3:
	    		DestroySqList(L);
	    		break;
    		case 4:
	    		ClearSqList(L);
	    		break;
    		case 5:
	    		GetSqListLength(L);
	    		break;
    		case 6:
  				//按位查找 
	    		SqListGetElem(L,4,e);
	    		break;
    		case 7:
    			//按值查找 
	    		SqListLocateElem(L,e);
	    		break;
   			case 8:
	    		// for(int i = 1; i <= 10; i++){
	    		// 	printf("插入之前\n");
	    		// 	SqListPrintf(L);
		    	// 	SqListInsert(L,i,i);
		    	// }
				SqListInsert(L,5,99999);
		    	break;
    		case 9:
	    		SqListDelete(L,4);
	    		break;
    		case 10:
	    		SqListPrintf(L);
	    		break;
    		default:
    			SqListInsert(L,4,99999);
   				
	    }
	    scanf("%d",&optional);
    }
	return 0; 
}
 
 