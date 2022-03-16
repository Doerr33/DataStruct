//###############头文件#################### 
 
 //为什么直接传顺序表不可以，网上传的指针；
 //直接传L过去，那它就是直接拷贝，不会影响实参 
 
 //Status InitList_Sq(SqList L) 
 #include<cstdio>
 #include<cstdlib>
 //###############函数返回状态##############
 
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define OVERFLOW -2
 
 //##############定义数据类型#############
 
 typedef int ElemType; 
 
 //顺序表最大值  
 #define MAXSIZE 100
 //增量+最大值的 
 
 typedef struct{
 	//静态分配，数组大小和空间固定，空间占满会溢出，导致崩溃 
 	ElemType data[MAXSIZE];
 	ElemType length; //当前长度 
 }SqList; 