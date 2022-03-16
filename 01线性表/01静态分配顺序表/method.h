  #include"SqList.h" 
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
 
 	for(int i = 0; i < MAXSIZE; i++){
	 	L.data[i] = 0;
	 	//printf("%d ",L.data[i]);
 	} 
	
 	L.length= 0;
 	printf("初始化成功\n");
 	return OK;
 }
 
 
 //2.销毁顺序表 
 void DestroySqList(SqList& L){
 	
 	//静态顺序表中，只要将长度设置为0即可，操作系统会回收空间 
 	L.length = 0;
 	
 } 
 
 
 //3.清空顺序表 
 void ClearSqList(SqList& L){
 	
 	L.length = 0; 
 	printf("Clear顺序表已清空现在长度为：%d\n",L.length);
 	
 } 
 
 
 //4.获取顺序表长度
 void GetLength(SqList& L){
 	printf("顺序表的长度为：%d\n",L.length);
 } 
 
 
 //5.判断顺序表是否空
 void SqListIsEmpty(SqList& L){
 	if(L.length == 0)printf("空\n");
 	else{
	 	printf("非空\n");
 	}
 } 
 
 
 //6.按位查找（时间复杂度O（1）随机存取，每一条只运行一次） 
 int SqListGetElem(SqList& L,int i,int& e){
 	//1-length范围 
 	if(i < 1 || i > L.length)return ERROR;
 	e = L.data[i - 1];
 	printf("第%d位置的元素是：%d\n",i,e);
 	return OK;
 } 
 
 
 //7.按值查找，顺序查找
 int SqListLocateElem(SqList& L,int e){
 	int flag = -1; 
 	for(int i = 0; i < L.length; i++){
	 	if(L.data[i] == e){
	 		flag = i + 1;
	 		printf("元素%d的位置是：%d\n",e,i + 1);
	 		return OK;
	 	}
	 	
 	}
 	if(flag == -1){
		printf("元素%d不在顺序表中",e);
	 }
 	
 	return 0;
 } 
 
 
 //8.插入
 int SqListInsert(SqList& L,int i,int e){
 	//1 - length+1
 	if(i < 1 || i > L.length + 1)return ERROR;
 	
 	if(L.length == MAXSIZE)return ERROR;
 	//最后一个开始往前移动一个位置
    //i-到最后一个 ==（i-1 —— length - 1） 
 	for(int j = L.length - 1;j >= i-1; j--){
	 	L.data[j + 1] = L.data[j];
    }
    //插入元素 
    L.data[i - 1] = e;
    //长度加1 
    L.length ++;
    return OK;
 } 
 
 
 //9.删除
 int SqListDelete(SqList &L,int i){
 	if((i < 1)||(i > L.length))return ERROR;
 	//从i+1 - 最后一个均往前移动 
 	for(int j = i; j <= L.length - 1; j++){
		L.data[j - 1] = L.data[j];
 	}
 	//长度减1 
 	L.length --;
 	return OK;
 } 
 
 
 //10.打印
 void SqListPrintf(SqList &L){
 	if(L.length == 0){
	 	printf("顺序表长度为0\n");
	 	return;
	 }
 	for(int i = 0; i < L.length; i++){
		printf("%5d ",L.data[i]); 	
 	}
 	printf("\n");
 } 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 