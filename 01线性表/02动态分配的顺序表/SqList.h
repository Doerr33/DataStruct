//###############头文件#################### 
 
 #include<cstdio>
 #include<cstdlib>
 
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