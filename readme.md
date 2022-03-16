# 第八章:引用

## 8.2 引用变量

### 8.2.1 创建引用变量

![image-20210817170827288](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210817170827288.png)

![image-20210817171802405](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210817171802405.png)

> 指针和引用的区别

![image-20210817172111178](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210817172111178.png)



![image-20210817172154800](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210817172154800.png)

![image-20210817172300285](C:\Users\朱领\AppData\Roaming\Typora\typora-user-images\image-20210817172300285.png)

### 8.2.2 作为函数参数

![image-20210817172502560](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210817172502560.png)

![image-20210817172548875](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210817172548875.png)





# 1.顺序表

## 1.静态分配

![image-20210817190929700](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210817190929700.png)

### 1.SqList.h

```
//SqList.h
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
```

### 2.初始化InitSqList

```
//1.顺序表初始化 
 int InitSqList(SqList& L){	
 
 	for(int i = 0; i < MAXSIZE; i++){
	 	L.data[i] = 0;
	 	//printf("%d ",L.data[i]);
 	} 
	
 	L.length= 0;
 	return OK;
 }
 
```

### 3.DestroySqList

```
 //2.销毁顺序表 
 void DestroySqList(SqList& L){
 	
 	//静态顺序表中，只要将长度设置为0即可，操作系统会回收空间 
 	L.length = 0;
 	
 } 
```

### 4.ClearSqList

```
//3.清空顺序表 
 void ClearSqList(SqList& L){
 	
 	L.length = 0; 
 	printf("Clear顺序表已清空现在长度为：%d\n",L.length);
 	
 } 
```

### 5.GetSqListLength

```
//4.获取顺序表长度
 int GetSqListLength(SqList& L){
 	printf("顺序表的长度为：%d\n",L.length);
 	return L.length;
 } 
```

### 6.SqListIsEmpty

```
//5.判断顺序表是否空
 void SqListIsEmpty(SqList& L){
 	if(L.length == 0)printf("空\n");
 	else{
	 	printf("非空\n");
 	}
 } 
```

### 7.SqListGetElem按位

```
//6.按位查找（时间复杂度O（1）随机存取，每一条只运行一次） 
 int SqListGetElem(SqList& L,int i,int& e){
 	//1-length范围 
 	if(i < 1 || i > L.length)return ERROR;
 	e = L.data[i - 1];
 	printf("第%d位置的元素是：%d\n",i,e);
 	return OK;
 } 
 
```

### 8.SqListLocateElem按值

```
//7.按值查找，顺序查找
 int SqListLocateElem(SqList& L,int& e){
 	for(int i = 0; i < L.length; i++){
	 	if(L.data[i] == e)return i + 1;
 	}
 	return 0;
 } 
```

### 9.SqListInsert

```
//8.插入
 int SqListInsert(SqList& L,int i,int& e){
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
```

### 10.SqListDelete

```
//9.删除
 int SqListDelete(SqList &L,int &i){
 	if((i < 1)||(i > L.length))return ERROR;
 	//从i-最后一个均往前移动 
 	for(int j = i; j <= L.length - 1; j++){
		L.data[j - 1] = L.data[j];
 	}
 	//长度减1 
 	L->length --;
 	return OK;
 } 
```

### 11.SqListprintf

```
//10.打印
 void SqListprintf(SqList &L){
 	if(L.length == 0){
	 	printf("顺序表长度为0\n");
	 	return;
	 }
 	for(int i = 0; i < L.length; i++){
		printf("%5d ",L.data[i]); 	
 	}
 	printf("\n");
 } 
```

## 2.动态分配

### 1.SqList.h

```
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
```

### 2.初始化InitSqList

```
//1.顺序表初始化 
 int InitSqList(SqList& L){
 	//申请初始空间 
 	L.elem = (int*)malloc(sizeof(int)*InitSize); 
 	if(!L.elem)exit(OVERFLOW);
 	//清除脏数据 
 	for(int i = 0; i < 10; i++){
		L.elem[i] = 0; 	
 	}
 	//初始化成员 
 	L.length = 0;
 	L.MaxSize = InitSize;
 	return OK;
 }
```

### 3.DestroySqList

```
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
```

### 4.ClearSqList

```
//3.清空顺序表 
 void ClearSqList(SqList& L){
 	L.length = 0;
	L.MaxSize = InitSize; 
 	printf("Clear顺序表已清空现在长度为：%d\n",L.length);
 } 
```

### 5.GetSqListLength

```
//4.获取顺序表长度
 int GetSqListLength(SqList& L){
 	printf("顺序表的长度为：%d\n",L.length);
 	return OK;
 } 
```

### 6.SqListIsEmpty

```
//5.判断顺序表是否空
 void SqListIsEmpty(SqList& L){
 	if(L.length == 0)printf("空\n");
 	else{
	 	printf("非空\n");
 	}
 } 
```

### 7.SqListGetElem按位

```
 //6.获取顺序表中位置i的元素的内容（时间复杂度O（1）随机存取，每一条只运行一次） 
 int SqListGetElem(SqList& L,int i,int &e){
 	//1-length范围 
 	if(i < 1 || i > L.length)return ERROR;
 	e = L.elem[i - 1];
 	printf("第%d位置的元素是：%d\n",i,e);
 	return OK;
 } 
 
```

### 8.SqListLocateElem按值

```
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
```

### 9.SqListInsert

```
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
```

### 10.SqListDelete

```
//9.删除
 int SqListDelete(SqList& L,int i){
 	if((i < 1)||(i > L.length))return ERROR;
 	for(int j = i; j <= L.length - 1; j++){
		L.elem[j - 1] = L.elem[j];
			
 	}
 	L.length --; 
 	return OK;
 } 
```

### 11.SqListprintf

```
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
 
```

# 2.单链表

## 1.带头节点

### 1.初始化：InitList

![image-20210822221334624](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822221334624.png)

```
//1.初始化：申请头节点，设置next为空
bool InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
} 
```

### 2.求表长：Length

![image-20210822221500596](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822221500596.png)

```
//5.求表长：从L->next遍历累加
int Length(LinkList L){
	LNode* p;
	p = L->next;
	int i = 0;
	while(p){
		i++;
		p = p->next;
	}
	return i;
} 
```

### 3.按值查找：LocateElem

> 从L->next遍历，计数从1开始记录当前节点，并查找

![image-20210822221925677](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822221925677.png)

![image-20210822222024265](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822222024265.png)

```
//7.按值查找
 int LocateELem(LinkList L,int e){
 	LNode *p;
 	p = L->next;
 	int j = 1;
 	while(p && p->data != e){
	 	p = p->next;
	 	j++;
	 }
	 if(p){
 		return j;
 	}
	 else {
 		return 0;
 	}
 	
 } 
```

### 4.按位查找：GetElem

> 遍历记位置：j > i,即i不合法

![image-20210822222713211](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822222713211.png)

![image-20210822222801208](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822222801208.png)

```
//6.按位取值
int GetElem(LinkList L,int i){
	LNode *p;
	p = L->next;
	int j = 1;
	while(p && j < i){
		p = p->next; 
		j ++; 
	}
	if(!p || j > i){
		return 0;
	}
	return p->data;
	
} 
```

### 5.插入ListInsert

> 1.判断合法：1 —— length+1
>
> 2.循环找到i - 1
>
> 3.判断是否找到
>
> 4.申请空间插入节点

![image-20210822223128098](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822223128098.png)

```
//思考：当i = 10，是，仍然满足条件，下一次，p变成了最后一个元素的后面为空；
//8.插入节点：前插和后插，前插可以转换为后插找到i-1个节点 
bool ListInsert(LinkList &L,int i,int e){
	if(i < 1){
		return false;
	}
	LNode *p;//当前指针扫描到的节点 
	int j = 0;//当前p指向的是第几个节点 
	p = L;//L指向头节点，头节点是第0个节点
	while(p != NULL && j < i - 1){
		p = p->next;
		j++;
	} 
	if(p == NULL){//i值不合法 
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; 
	
} 
```

### 6.删除ListDelete

> 1.判断位置是否合法：1-length
>
> 2.找到i-1个位置
>
> 3.判断链表中是否找到
>
> 4.判断是否为最后一个节点，如果是那么，他后面没有节点，自然也没有next，需特殊
>
> 5.p指向i-1，q指向i，跳过q释放q即可

![image-20210822225055980](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822225055980.png)

```
//9.删除节点
bool ListDelete(LinkList &L,int i,int &e){
	if(i < 1){
		return false;
	} 
	LNode *p;
	int j = 0;
	p = L;
	while(p != NULL && j < i - 1){
		p = p->next;
		j++;
	}
	if(p == NULL){//超过了最后一个节点
		return false;
	}
	if(p->next == NULL){//到最后一个节点，我们找的是i - 1，说明没有i
		return false;
	}
	LNode *q = p->next;
	e = q->data;
	printf("被删除的节点是：%d\n",e);
	p->next = q->next;
	free(q);
	return true; 
}
```

### 7.输出操作：PrintList

> 遍历输出

![image-20210822225326369](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822225326369.png)

```
 //13.打印
void PrintList(LinkList L)
{
	L = L->next;
    printf("表中的数据为：");
    //不为空打印
    if (L != NULL)
    {
        printf("%d ", L->data);
        while (L->next != NULL)
        {
            L = L->next;
            printf("%d ", L->data);
        }
    }
    printf("\n");
} 
```

### 8.判空：Empty

> L->next == null

![image-20210822225432787](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822225432787.png)

```
//2.判断表是否为空
bool Empty(LinkList L){
	if(L->next){
		return true;
	}
	else{
		return false;
	}
} 
```

### 9.销毁：DestoryList

> 1.用p记录L
>
> 2.L后移
>
> 3.释放p

![image-20210822225758372](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822225758372.png)

```
//3.销毁 
bool DestroyList(LinkList &L){
	LNode *p; //指向一个节点LinkList p也可以，不过为了便于理解用前一个
	while(L){
		p = L;
		L = L->next;
		free(p);//delete p也行 
	} 
	return true;
} 
```

### 10.清空：ClearList

> 1.p = L->next开始
>
> 2.q = p->next
>
> 3.释放p，将q赋值给p
>
> 4.最后L- >next设置为NULL

![image-20210822225920978](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822225920978.png)

```
//4.清空 
bool ClearList(LinkList &L){
	LNode *p,*q;
	p = L->next;
	while(p){
		q = p->next;
		free(p);//delete p;
		p = q;
	}
	L->next = NULL;
	return true;
} 
```

### 11.头插法：ListHeaderInsert

>1.申请头节点L，L->next == NULL
>
>2.申请节点S，s->next = L->next
>
>3.L->next = s



![image-20210822230440290](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822230440290.png)

```
//11.头插法 
 LinkList List_HeadeInsert(LinkList &L){
 	LNode *s;
 	int x;
 	L = (LinkList)malloc(sizeof(LNode));
 	L->next = NULL;
 	scanf("%d",&x);
 	while(x != 9999){
	 	s = (LNode *)malloc(sizeof(LNode));
	 	s->data = x;
	 	s->next = L->next;
	 	L->next = s;
	 	scanf("%d",&x);
	 }
	 return L;
 }
```

### 12.尾插法：ListTailInsert

> 1.申请头节点L,R尾指针同时指向头节点
>
> 2.申请节点S
>
> 3.R->next = s
>
> 4.移动R到S：r = s
>
> 5.设置r->next == NULL

![image-20210822230724960](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210822230724960.png)

```
//10尾插法
 LinkList List_TailInsert(LinkList &L){
 	int x;
 	L = (LinkList)malloc(sizeof(LNode));
 	LNode *s,*r = L;
	scanf("%d",&x);
	while(x != 9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x); 
	} 
	r->next = NULL;
	return L;
 } 
```

## 2.不带头节点
### 1.初始化：InitList

> 指针设置为空即可

![image-20210825211503503](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825211503503.png)

```
void InitList(LinkList &L)
{
    L = NULL;
}
```

### 2.求表长：Length

> 1.判断是否为空，如果为空直接返回，否则length = 1；
>
> 2.遍历剩下的length - 1个，累加

![image-20210825211715081](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825211715081.png)

```
//2.获取单链表长度 
int Length(LinkList L)
{
    int length = 0;
    if (L == NULL) //首先判断第一个结点是否为空
        return length;
    else
        length++;
    while (L->next != NULL)
    {
        length++;
        L = L->next;
    }
    return length;
}
```

### 3.按值查找：LocateElem

> 1.判断第一个是不是要查找的元素，如果是直接返回，不是则下一个
>
> 2.循环找到e
>
> 3.返回的j+1是不是有什么问题，最后一个的这个是否判断条件需要加上p ！= NULL；

![image-20210825211810420](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825211810420.png)



```
//在表中查找第一个与查找元素相同的结点的位置
int LocatedElem(LinkList L, ElemType e)
{
    int j = 1;
    LNode *p = L;
    if (p->data == e)
        return j;
    else
        p = p->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (j == Length(L)) //到最后一位依然没找到
    {
        return 0;
    }
    return j + 1;
}
```

### 4.按位查找：GetElem

> 1.判断位置是否合法
>
> 2.循环找到i位置
>
> 3.返回i位置的元素

![image-20210825213013077](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825213013077.png)



```
//获得某一位置元素的值
int GetElem(LinkList L, int i)
{
    LNode *p = L;
    if (i < 0 || i > Length(L))
        return 0;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    return p->data;
}
```

### 5.插入ListInsert

> 1.判断位置是否合法
>
> 2.申请节点放入数据
>
> 3.特殊处理第一位置：S->next = L;    L = S;
>
> 4.其他所有节点处理方式一致：找到 i - 1节点； s->next = p - > next; p->next = s;

![image-20210825213251828](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825213251828.png)

```
//向表中插入数据
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1 || i > Length(L) + 1)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    if (i == 1)
    {
        s->next = L;
        L = s;
        return true;
    }
    LNode *p = GetElem_LNode(L, i - 1);
    s->next = p->next;
    p->next = s;
    return true;
}

```

### 6.删除ListDelete

> 1.判断位置是否合法
>
> 2.判断表是否为空
>
> 3.p和q
>
> 4.特殊处理第一个节点：p指向L，q指向L->next；释放p，将q赋值给L
>
> 5.其他节点统一：找到i - 1节点；，q 为 节点，跳过节点

![image-20210825213643551](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825213643551.png)

```
//删除表中某位置的数据
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1 || i > Length(L)) //位置不在表中则返回false
        return false;
    if (L == NULL) //表为空则返回false
        return false;
    LNode *p;
    LNode *q;
    if (i == 1) //删除第一个结点的情况
    {
        p = L;
        e = p->data;
        q = L->next;
        free(p); //释放p结点
        L = q;
        return true;
    }
    p = GetElem_LNode(L, i - 1);
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
```

### 7.输出操作：PrintList

> 1.先判断L是否为空，不为空打印再循环输出其他

![image-20210825214109827](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825214109827.png)

```
 //打印单链表的所有数据
void PrintList(LinkList L)
{
    printf("表中的数据为：");
    if (L != NULL)
    {
        printf("%d ", L->data);
        while (L->next != NULL)
        {
            L = L->next;
            printf("%d ", L->data);
        }
    }
    printf("\n");
}
```

### 8.判空：Empty

> 1.L == NULL

![image-20210825214152173](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825214152173.png)

```
//3.判断的单链表是否为空表
bool Empty(LinkList L)
{
    if (L == NULL)
        return true;
    else
        return false;
}

```

### 9.销毁：DestoryList

> 1.p记录L，从L开始

![image-20210825214258990](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825214258990.png)

```
//3.销毁 
bool DestroyList(LinkList &L){
	LNode *p; //指向一个节点LinkList p也可以，不过为了便于理解用前一个
	while(L){
		p = L;
		L = L->next;
		free(p);//delete p也行 
	} 
	return true;
} 
```

### 10.清空：ClearList

> 1.判断是否为空表
>
> 2.删除除第一个外的节点：判断L->next是否为空，p=L->next； L->next移动到下一个，删除p
>
> 3.删除第一个节点

![image-20210825214430541](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825214430541.png)

![image-20210825214754304](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825214754304.png)

```
//清空表的数据
bool ClearList(LinkList &L)
{
    if (L == NULL) //表空则返回false
        return false;
    LNode *p;
    while (L->next != NULL) //删除第一个结点之后的所有结点
    {
        p = L->next;
        L->next = p->next;
        free(p);
    }
    L = NULL; //删除第一个结点
    return true;
}
```

### 11.头插法：ListHeaderInsert

>1.申请节点L，并赋值
>
>2.循环插入节点和带头节点的一样

![image-20210825215807669](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825215807669.png)

![image-20210825215249508](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825215249508.png)

```
//4.头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    InitList(L); //初始化 
    LNode *s;
    ElemType e;
    printf("输入数据9999停止：\n");
    scanf("%d", &e);
    if (e != 9999) // 首先对第一个结点赋值
    {
        L = (LinkList)malloc(sizeof(LNode));
        L->next = NULL;
        L->data = e;
        scanf("%d", &e);
        while (e != 9999)
        {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = e;
            s->next = L->next;
            L->next = s;
            scanf("%d", &e);
        }
    }
    return L;
}
```

### 12.尾插法：ListTailInsert

> 1.给第一个节点赋值，其他统一视为带头节点的一样

![image-20210825215858280](https://raw.githubusercontent.com/Doerr33/images/master/img3/image-20210825215858280.png)

```
//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    InitList(L); //初始化 
    LNode *s, *r;
    ElemType e;
    printf("输入数据9999停止：\n");
    scanf("%d", &e);
    if (e != 9999) //首先对第一个结点赋值
    {
        L = (LinkList)malloc(sizeof(LNode));
        L->data = e;
        r = L;
        scanf("%d", &e);
        while (e != 9999)
        {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = e;
            r->next = s;
            r = s;
            scanf("%d", &e);
        }
    }
    r->next = NULL;
    return L;
}
```

# 3.静态链表

![image-20210920202725700](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920202725700.png)

## 1.节点

![image-20210920202827914](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920202827914.png)

```
typedef struct
{
  int data; //静态链表节点中的数据
  int cur;   //静态链表节点中的游标
}component;
```

![image-20210920202903930](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920202903930.png)

![image-20210920202944144](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920202944144.png)



## 2.备用链表

![image-20210920203359456](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920203359456.png)

## 3.静态链表的实现

![image-20210920203443368](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920203443368.png)

```
1.在数据链表未初始化之前，数组中所有位置都处于空闲状态，所以都链接在备用链表上。(图1)

2.向静态链表中添加数据时，需提前从备用链表中摘除结点，让新数据使用。

3.备用链表摘除节点最简单的方法是摘除a[0]的直接后继节点(即摘除a[1]的游标2):获取a[0]指向的空闲的第一个节点

  同样，向备用链表中添加空闲节点也是添加作为a[0]新的直接后继节点(
  
  图2中a[1]为a[0]新的直接后继结点(游标为2)、
  图3中a[2]为a[0]新的直接后继结点(游标为3)、
  图4中a[3]为a[0]新的直接后继结点(游标为4))。
  因为 a[0] 是备用链表的第一个节点，我们知道它的位置，操作它的直接后继节点相对容易，无需遍历备用链表，耗费的时间复杂度为为O(1)。
```



```
/*************************************************************************
创建备用链表
*****************************************************************************/
void reserveArr(component *array) {
    int i = 0;
    for (i = 0; i < maxSize; i++) {
        array[i].cur = i + 1;//将每个数组分量链接到一起
        array[i].data = 0;
    }
    array[maxSize - 1].cur = 0;//链表最后一个结点的游标值为0
}//做的事如图
```

![image-20210920214559808](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920214559808.png)



```
/********************************************************
提取分配空间
若备用链表为非空，则返回分配的节点下标，否则返回0(当分配最后一个节点时，该节点的游标值为0)
********************************************************/
int mallocArr(component * array) {
    //若备用链表非空，则返回分配的结点下标，否则返回 0（当分配最后一个结点时，该结点的游标值为 0）
    int i = array[0].cur;//a[0]指向第一个空闲的空间
    //更新a[0]指向下一个空闲的空间
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }
    return i;
}//通过a[0]找到第一个空闲的空间，cur为0时为最后一个元素
```

![image-20210920214717499](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920214717499.png)

```
/***************************************************************************
初始化静态链表
****************************************************************************/
int initArr(component *array) {
    // 尾指针
    int tail = 0;
    // 头指针
    int head = 0;

    int i = 0;
    // 初始化备用链表
    reserveArr(array);
    // 提取分配空间
    head = mallocArr(array);//第一次时body=1，a【0】.cur = 1;

    //建立首元结点
    array[head].data = 1;
    array[head].cur = 0;//只有一个元素时设置a【1】为最后一个节点

    //声明一个变量，把它当指针使，指向链表的最后的一个结点，当前和首元结点重合
    tail = head;//第一遍时设置尾指针指向a[1]

    // 分配2-5的空间
    for (i = 2; i < 6; i++) {
        // a【0】.cur即指向空闲的第一个空间
        int j = mallocArr(array); //从备用链表中拿出空闲的分量

        printf("获取的备用链表空间j是%d\n\n",j);
        array[j].data = i;      //初始化新得到的空间结点

        printf("存入j空间的元素是%d\n\n",i);
        printf("tail的位置是是%d\n\n",tail);
        array[tail].cur = j; //将新得到的结点链接到数据链表的尾部

        tail = j;             //将指向链表最后一个结点的指针后移
    }
    array[tail].cur = 0;//新的链表最后一个结点的指针设置为0
    return head;//第一个元素所在的位置
}
```

![image-20210921152622781](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921152622781.png)

```
//输出静态链表，通过游标遍历，直到游标等于0停止
void displayArr(component * array, int head) {
    int index = head;//index准备做遍历使用,从a【1】开始
    while (array[index].cur) {
        printf("%d,%d\n", array[index].data, array[index].cur);
        index = array[index].cur;
    }
    //输出最后等于0的时候的数组元素
    printf("%d,%d\n", array[index].data, array[index].cur);
}
```

![image-20210920215609261](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210920215609261.png)

## 4.添加元素

![image-20210921153707356](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921153707356.png)

![image-20210921153550403](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921153550403.png)

![image-20210921134750859](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921134750859.png)

```
//向链表中插入数据，body表示链表的头结点在数组中的位置，add表示插入元素的位置，num表示要插入的数据
void insertArr(component * array, int body, int add, int num) {
    int tempBody = body;//tempBody做遍历结构体数组使用
    int i = 0, insert = 0;
    //找到要插入位置的上一个结点在数组中的位置:找到前驱的位置
    for (i = 1; i < add - 1; i++) {
        tempBody = array[tempBody].cur;
    }
    insert = mallocArr(array);//申请空间，准备插入
    array[insert].data = num;

    array[insert].cur = array[tempBody].cur;//新插入结点的游标等于其直接前驱结点的游标

    array[tempBody].cur = insert;//直接前驱结点的游标等于新插入结点所在数组中的下标
}
```



## 5.删除元素

![image-20210921135521077](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921135521077.png)

![image-20210921141244441](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921141244441.png)

```
//删除结点函数，num表示被删除结点中数据域存放的数据
int deletArr(component * array, int body, int num) {
    // 用于遍历
    int tempBody = body;
    // 标记删除节点位置
    int del = 0;
    // 用于无头结点的，删除第一个节点
    int newbody = 0;

    //找到被删除结点的位置
    while (array[tempBody].data != num) {
        tempBody = array[tempBody].cur;
        //当tempBody为0时，表示链表遍历结束，说明链表中没有存储该数据的结点
        if (tempBody == 0) {
            printf("链表中没有此数据");
            return body;
        }
    }

    //运行到此，证明有该结点
    del = tempBody;
    tempBody = body;

    //删除首元结点，需要特殊考虑
    if (del == body) {
        newbody = array[del].cur;
        freeArr(array, del);
        return newbody;
    }

    else
    {
        //找到该结点的上一个结点，做删除操作
        while (array[tempBody].cur != del) {
            tempBody = array[tempBody].cur;
        }
        //将被删除结点的游标直接给被删除结点的上一个结点
        array[tempBody].cur = array[del].cur;
        //回收被摘除节点的空间
        freeArr(array, del);
        return body;
    }  
}
```

```
//备用链表回收空间的函数，其中array为存储数据的数组，k表示未使用节点所在数组的下标
void freeArr(component * array, int k) {
    array[k].cur = array[0].cur;//第一个空闲的空间和被删除的节点链接起来
    array[0].cur = k;//将a[0]和被删除节点的空间链接起来
}
```



## 6.查找元素

![image-20210921144119191](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921144119191.png)

```
//在以body作为头结点的链表中查找数据域为elem的结点在数组中的位置
int selectNum(component * array, int body, int num) {
    //当游标值为0时，表示链表结束
    while (array[body].cur != 0) {
        if (array[body].data == num) {
            return body;
        }
        body = array[body].cur;
    }
    //判断最后一个结点是否符合要求
    if (array[body].data == num) {
        return body;
    }
    return -1;//返回-1，表示在链表中没有找到该元素
}
```

## 7.修改元素

![image-20210921144315094](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921144315094.png)

```
//在以body作为头结点的链表中将数据域为oldElem的结点，数据域改为newElem
void amendElem(component * array, int body, int oldElem, int newElem) {
    int add = selectNum(array, body, oldElem);
    if (add == -1) {
        printf("无更改元素");
        return;
    }
    array[add].data = newElem;
}
```

## 8.完整代码

```
#include <stdio.h>
#define maxSize 7
typedef struct {
    int data;
    int cur;
}component;

//将结构体数组中所有分量链接到备用链表中
void reserveArr(component *array);

//初始化静态链表
int initArr(component *array);

//向链表中插入数据，body表示链表的头结点在数组中的位置，add表示插入元素的位置，num表示要插入的数据
void insertArr(component * array, int body, int add, int num);

//删除链表中存有num的结点,返回新数据链表中第一个节点所在的位置
int deletArr(component * array, int body, int num);

//查找存储有num的结点在数组的位置
int selectNum(component * array, int body, int num);

//将链表中的字符oldElem改为newElem
void amendElem(component * array, int body, int oldElem, int newElem);

//输出函数
void displayArr(component * array, int body);

//从备用链表中摘除空闲节点的实现函数
int mallocArr(component * array);

//将摘除下来的节点链接到备用链表上
void freeArr(component * array, int k);


int main() {
    component array[maxSize];
    int body = initArr(array);
    int selectAdd;
    printf("静态链表为：\n");
    displayArr(array, body);

    printf("在第3的位置上插入元素4:\n");
    insertArr(array, body, 3, 4);
    displayArr(array, body);

    printf("删除数据域为1的结点:\n");
    body = deletArr(array, body, 1);
    displayArr(array, body);

    printf("查找数据域为4的结点的位置:\n");
    selectAdd = selectNum(array, body, 4);
    printf("%d\n", selectAdd);
    printf("将结点数据域为4改为5:\n");
    amendElem(array, body, 4, 5);
    displayArr(array, body);
    return 0;
}
//创建备用链表
void reserveArr(component *array) {
    int i = 0;
    for (i = 0; i < maxSize; i++) {
        array[i].cur = i + 1;//将每个数组分量链接到一起
    }
    array[maxSize - 1].cur = 0;//链表最后一个结点的游标值为0
}

//初始化静态链表
int initArr(component *array) {
    int tempBody = 0, body = 0;
    int i = 0;
    reserveArr(array);
    body = mallocArr(array);
    //建立首元结点
    array[body].data = 1;
    array[body].cur = 0;
    //声明一个变量，把它当指针使，指向链表的最后的一个结点，当前和首元结点重合
    tempBody = body;
    for (i = 2; i < 4; i++) {
        int j = mallocArr(array); //从备用链表中拿出空闲的分量
        array[j].data = i;      //初始化新得到的空间结点
        array[tempBody].cur = j; //将新得到的结点链接到数据链表的尾部
        tempBody = j;             //将指向链表最后一个结点的指针后移
    }
    array[tempBody].cur = 0;//新的链表最后一个结点的指针设置为0
    return body;
}

//向链表中插入数据，body表示链表的头结点在数组中的位置，add表示插入元素的位置，num表示要插入的数据
void insertArr(component * array, int body, int add, int num) {
    int tempBody = body;//tempBody做遍历结构体数组使用
    int i = 0, insert = 0;
    //找到要插入位置的上一个结点在数组中的位置
    for (i = 1; i < add; i++) {
        tempBody = array[tempBody].cur;
    }
    insert = mallocArr(array);//申请空间，准备插入
    array[insert].data = num;

    array[insert].cur = array[tempBody].cur;//新插入结点的游标等于其直接前驱结点的游标
    array[tempBody].cur = insert;//直接前驱结点的游标等于新插入结点所在数组中的下标
}

//删除结点函数，num表示被删除结点中数据域存放的数据
int deletArr(component * array, int body, int num) {
    int tempBody = body;
    int del = 0;
    int newbody = 0;

    //找到被删除结点的位置
    while (array[tempBody].data != num) {
        tempBody = array[tempBody].cur;
        //当tempBody为0时，表示链表遍历结束，说明链表中没有存储该数据的结点
        if (tempBody == 0) {
            printf("链表中没有此数据");
            return body;
        }
    }

    //运行到此，证明有该结点
    del = tempBody;
    tempBody = body;

    //删除首元结点，需要特殊考虑
    if (del == body) {
        newbody = array[del].cur;
        freeArr(array, del);
        return newbody;
    }
    
    else
    {
        //找到该结点的上一个结点，做删除操作
        while (array[tempBody].cur != del) {
            tempBody = array[tempBody].cur;
        }
        //将被删除结点的游标直接给被删除结点的上一个结点
        array[tempBody].cur = array[del].cur;
        //回收被摘除节点的空间
        freeArr(array, del);
        return body;
    }  
}

//在以body作为头结点的链表中查找数据域为elem的结点在数组中的位置
int selectNum(component * array, int body, int num) {
    //当游标值为0时，表示链表结束
    while (array[body].cur != 0) {
        if (array[body].data == num) {
            return body;
        }
        body = array[body].cur;
    }
    //判断最后一个结点是否符合要求
    if (array[body].data == num) {
        return body;
    }
    return -1;//返回-1，表示在链表中没有找到该元素
}

//在以body作为头结点的链表中将数据域为oldElem的结点，数据域改为newElem
void amendElem(component * array, int body, int oldElem, int newElem) {
    int add = selectNum(array, body, oldElem);
    if (add == -1) {
        printf("无更改元素");
        return;
    }
    array[add].data = newElem;
}

void displayArr(component * array, int body) {
    int tempBody = body;//tempBody准备做遍历使用
    while (array[tempBody].cur) {
        printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);

}

//提取分配空间
int mallocArr(component * array) {
    //若备用链表非空，则返回分配的结点下标，否则返回0（当分配最后一个结点时，该结点的游标值为0）
    int i = array[0].cur;
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }
    return i;
}

//备用链表回收空间的函数，其中array为存储数据的数组，k表示未使用节点所在数组的下标
void freeArr(component * array, int k) {
    array[k].cur = array[0].cur;
    array[0].cur = k;
}
```



# 4.双向链表

## 1.不带头结点

![image-20210921155523764](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921155523764.png)

### 1.节点

![image-20210921160106705](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921160106705.png)

```
typedef struct line{
    struct line * prior; //指向直接前趋
    int data;
    struct line * next; //指向直接后继
}line;
```

### 2.尾插法创建

![image-20210921160202648](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921160202648.png)

![image-20210921160909807](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921160909807.png)

```
line* initLine(line * head) {
    int i = 0;
    line * list = NULL;
    //创建一个首元节点，链表的头指针为head
    head = (line*)malloc(sizeof(line));
    //对节点进行初始化
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    //声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
    list = head;
    
    for (i = 2; i <= 5; i++) {
        //创建新的节点并初始化
        line * body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;
        //新节点与链表最后一个节点建立关系
        list->next = body;
        body->prior = list;
        //list永远指向链表中最后一个节点
        list = list->next;
    }
    
    //返回新创建的链表
    return head;
}
```

![image-20210921161028027](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921161028027.png)

### 3.添加

#### 1.表头添加

![image-20210921161258203](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921161258203.png)



#### 2.添加到表中间位置

![image-20210921161352449](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921161352449.png)

#### 3.表尾添加

![image-20210921161438717](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921161438717.png)

```
//data 为要添加的新数据，add 为添加到链表中的位置
line * insertLine(line * head, int data, int add) {

    //新建数据域为data的结点
    line * temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    
    //插入到链表头，要特殊考虑
    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    }
    else {
        int i = 0;//用于遍历
        line * body = head;
        //找到要插入位置的前一个结点
        
        
        for (i = 1; i < add - 1; i++) {
            body = body->next;
            if (body == NULL) {
            	//只要不是表头就肯定有前驱，否则位置出错
                printf("插入位置有误\n");
                break;
            }
        }
        
        if (body) {
            //判断条件为真，说明插入位置为链表尾
            if (body->next == NULL) {
                body->next = temp;
                temp->prior = body;
            }
            else {
                body->next->prior = temp;
                temp->next = body->next;
                body->next = temp;
                temp->prior = body;
            }
        }
    }
    return head;
}
```

#### 4.删除节点

![image-20210921162826406](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921162826406.png)



```
//删除结点的函数，data为要删除结点的数据域的值
line * delLine(line * head, int data) {
    line * temp = head;
    //遍历链表
    while (temp) {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (temp->data == data) {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中无该数据元素\n");
    return head;
}
```

### 4.按值查找

![image-20210921163010964](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921163010964.png)

```
//head为原双链表，elem表示被查找元素
int selectElem(line * head, int elem) {
    //新建一个指针t，初始化为头指针 head
    line * t = head;
    int i = 1;
    while (t) {
        if (t->data == elem) {
            return i;
        }
        i++;//记录节点
        t = t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}
```

### 5.修改

![image-20210921163217965](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921163217965.png)

```
//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
line *amendElem(line * p, int add, int newElem) {
    int i = 0;
    line * temp = p;
    //遍历到被删除结点,位置最多到最后一个节点
    for (i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("更改位置有误！\n");
            break;
        }
    }
    if (temp) {
        temp->data = newElem;
    }
    return p;
}
```

```
//完整代码
#include <stdio.h>
#include <stdlib.h>
typedef struct line {
    struct line * prior;
    int data;
    struct line * next;
}line;

//双链表的创建
line* initLine(line * head);

//双链表插入元素，add表示插入位置
line * insertLine(line * head, int data, int add);

//双链表删除指定元素
line * delLine(line * head, int data);

//双链表中查找指定元素
int selectElem(line * head, int elem);

//双链表中更改指定位置节点中存储的数据，add表示更改位置
line *amendElem(line * p, int add, int newElem);

//输出双链表的实现函数
void display(line * head);

int main() {
    line * head = NULL;
    //创建双链表
    printf("初始链表为：\n");
    head = initLine(head);
    display(head);
    //在表中第 3 的位置插入元素 7
    printf("在表中第 3 的位置插入新元素 7：\n");
    head = insertLine(head, 7, 3);
    display(head);
    //表中删除元素 2
    printf("删除元素 2：\n");
    head = delLine(head, 2);
    display(head);

    printf("元素 3 的位置是：%d\n", selectElem(head, 3));
    //表中第 3 个节点中的数据改为存储 6
    printf("将第 3 个节点存储的数据改为 6：\n");
    head = amendElem(head, 3, 6);
    display(head);
    return 0;
}

line* initLine(line * head) {
    int i = 0;
    line * list = NULL;
    head = (line*)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    list = head;
    for (i = 2; i <= 3; i++) {
        line * body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        body->prior = list;
        list = list->next;
    }
    return head;
}


line * insertLine(line * head, int data, int add) {
    //新建数据域为data的结点
    line * temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;
    //插入到链表头，要特殊考虑
    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    }
    else {
        int i = 0;
        line * body = head;
        //找到要插入位置的前一个结点
        for (i = 1; i < add - 1; i++) {
            body = body->next;
            if (body == NULL) {
                printf("插入位置有误\n");
                break;
            }
        }
        if (body) {
            //判断条件为真，说明插入位置为链表尾
            if (body->next == NULL) {
                body->next = temp;
                temp->prior = body;
            }
            else {
                body->next->prior = temp;
                temp->next = body->next;
                body->next = temp;
                temp->prior = body;
            }
        }
    }
    return head;
}


line * delLine(line * head, int data) {
    line * temp = head;
    //遍历链表
    while (temp) {
        //判断当前结点中数据域和data是否相等，若相等，摘除该结点
        if (temp->data == data) {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中无该数据元素\n");
    return head;
}


//head为原双链表，elem表示被查找元素
int selectElem(line * head, int elem) {
    //新建一个指针t，初始化为头指针 head
    line * t = head;
    int i = 1;
    while (t) {
        if (t->data == elem) {
            return i;
        }
        i++;
        t = t->next;
    }
    //程序执行至此处，表示查找失败
    return -1;
}


//更新函数，其中，add 表示更改结点在双链表中的位置，newElem 为新数据的值
line *amendElem(line * p, int add, int newElem) {
    int i = 0;
    line * temp = p;
    //遍历到被删除结点
    for (i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("更改位置有误！\n");
            break;
        }
    }
    if (temp) {
        temp->data = newElem;
    }
    return p;
}


//输出链表的功能函数
void display(line * head) {
    line * temp = head;
    while (temp) {
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        }
        else {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }
}
```

## 2.带头结点

# 5.循环链表

## 1.双循环链表

## 2.循环链表









































# 6.栈

![image-20210921171051593](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921171051593.png)

![image-20210921171202988](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921171202988.png)

![image-20210921183526450](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921183526450.png)

![image-20210921171236661](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921171236661.png)

![image-20210921171320044](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921171320044.png)

![image-20210921171501316](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921171501316.png)



## 1.顺序栈

![image-20210921183726083](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921183726083.png)



![image-20210921183838996](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921183838996.png)

![image-20210921183920736](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921183920736.png)

![image-20210921183948261](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921183948261.png)

![image-20210921211834555](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921211834555.png)

![image-20210921211854805](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921211854805.png)

![image-20210921211912034](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921211912034.png)

![image-20210921211939283](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921211939283.png)

![image-20210921211957256](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921211957256.png)

![image-20210921212016875](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921212016875.png)

![image-20210921212037475](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921212037475.png)

```
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

typedef struct{
    int *base;//栈底指针
    int *top;//栈顶指针
    int stacksize;//可用最大容量
}SqStack;


void menu(){
	printf("-------栈的基本操作-------\n\n");
	printf("---------1.初始化栈-------\n\n");
	printf("---------2.判断栈空-------\n\n");
	printf("---------3.进栈操作-------\n\n");
	printf("---------4.出栈操作-------\n\n");
	printf("---------5.清空栈-------\n\n");
	printf("--------------------------\n\n");
	printf("请选择你的操作（1-5）："); 
} 


// 初始化
Status InitStack(SqStack &s){
    s.base = (int *)malloc(MAXSIZE*sizeof(int));
    if(!s.base)exit(OVERFLOW);
    s.top = s.base;//设置为空
    s.stacksize = MAXSIZE;
    printf("初始化成功\n");
    return OK;
}


Status StackEmpty(SqStack s){
    if(s.top == s.base){
        printf("NULL\n");
        return TRUE;
    }
    else{
        printf("Not NULL\n");
        return FALSE;
    }
}


int StackLength(SqStack s){
    printf("长度为:%d\n",s.top - s.base);
    return s.top - s.base;
}


Status ClearStack(SqStack s){
    if(s.base){
        s.top = s.base;
        printf("清空成功\n");
    }
    return OK;
}


Status DestroyStack(SqStack &s){
    if(s.base){
        // s.base 存在则销毁
        delete s.base;
        s.stacksize = 0;
        s.base = s.top = NULL;
        printf("销毁成功\n");
    }
    return OK;
}


Status Push(SqStack &s,int e){
    if(s.top - s.base == s.stacksize){//栈满
        printf("栈满\n");
        return ERROR;
    }
    *s.top = e;
    s.top++;
    return OK;
}


Status Pop(SqStack &s,int &e){
    if(s.top == s.base){
        printf("栈空\n");
        return ERROR;
    }
    --s.top;
    e = *s.top;
    printf("出栈元素是%d\n",e);
    return OK;
}


int main(){
	SqStack S;
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
				ClearStack(S); 
				break;
			default:
				printf("\n");
				printf("ERROR\n");
		} 
		scanf("%d",&Op);	
	}
	return 0;
}
```



## 2.链栈

![image-20210921173215725](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921173215725.png)

![image-20210921173236638](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921173236638.png)



![image-20210921173346601](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921173346601.png)





![image-20210921212629334](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921212629334.png)

![image-20210921212659552](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921212659552.png)

![image-20210921212731000](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921212731000.png)

![image-20210921213245744](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921213245744.png)

![image-20210921213746982](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921213746982.png)

![image-20210921214148951](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921214148951.png)

**完整代码**

```
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

```

# 7.队列

![image-20210921215616196](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921215616196.png)

![image-20210921215736240](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921215736240.png)

![image-20210921215754765](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921215754765.png)



## 1.顺序队列

![image-20210921221033642](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921221033642.png)

![image-20210921221642616](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921221642616.png)

![image-20210921222347423](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921222347423.png)

![image-20210921222705042](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921222705042.png)

![image-20210921222952609](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921222952609.png)

![image-20210921223106860](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921223106860.png)

![image-20210921223158251](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921223158251.png)

![image-20210921223308135](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921223308135.png)

![image-20210921223617804](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921223617804.png)

![image-20210921223955110](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210921223955110.png)

![image-20210922104122006](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922104122006.png)

![image-20210922104412691](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922104412691.png)

![image-20210922104437928](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922104437928.png)

![image-20210922104914973](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922104914973.png)

![image-20210922105125451](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922105125451.png)

![image-20210922105606580](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922105606580.png)

![image-20210922113521562](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922113521562.png)

![image-20210922113538866](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922113538866.png)

```
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


```



## 2.链队

![image-20210922114341944](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922114341944.png)

![image-20210922114556323](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922114556323.png)

![image-20210922115027156](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922115027156.png)

![image-20210922115244759](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922115244759.png)

![image-20210922115648852](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922115648852.png)

![image-20210922120436644](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922120436644.png)

![image-20210922120849404](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922120849404.png)

![image-20210922121041773](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922121041773.png)

![image-20210922121633209](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922121633209.png)

# 8.模式匹配算法

## 1.BF算法

![image-20210922143631534](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922143631534.png)

![image-20210922143658934](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922143658934.png)

![image-20210922143719926](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922143719926.png)

![image-20210922145349742](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922145349742.png)

![image-20210922150521643](https://gitee.com/Doerr33/images/raw/master/imagesU1/image-20210922150521643.png)

```
#include <stdio.h>
#include <string.h>
#include"./SString.h"
int BF(SqString s,SqString t){
    int i = 1,j = 1;//我这里字符从1开始存储
    while(i <= s.length && j <= t.length){//不超过两个字符串的长度
        if(s.data[i] == t.data[j]){//相同则往下
            ++i;
            ++j;
        }
        else{//不相同则回溯
            i = i - j + 2;//从1移动到j个位置，移动了j - 1
            //个单位，要回到原始位置的下一个则是i - (j - 1) + 1
            j = 1;
        }
    }
    if(j > t.length){//返回匹配的第一个字符的下标,匹配完成时j>=子串的长度
        printf("匹配到的子串第一个字母的下标是：%d\n",i - t.length);
        return i - t.length;
    }
    else{
        printf("没有与之相匹配的子串\n");
        return 0;
    }
}
int main(){
    SqString s1;
    SqString s2;
    // 初始化字符串
    char a[100] = "heAAAAlloworld";
    char b[100] = "AAAA";
    StrAssign(s1,a);
    StrAssign(s2,b);
    printf("s1：\n");
    DispStr(s1);
    printf("s2：\n");
    DispStr(s2);
    // 调用BF算法
    BF(s1,s2);
    return 0;
}
```

![image-20211001123840304](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211001123840304.png)

## 2.*KMP算法

### 0.完整演示过程

![image-00000000kmp](/home/jack/%E8%A7%86%E9%A2%91/4.gif)

### 1.现象

> 仅仅后移模式串，比较指针不回溯

+ 第一个现象：某个位置发生不匹配时比较指针左边是匹配的

![image-20210916120943182](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916120943182.png)

+ 第二个现象：模式串前缀后缀相匹配，最长公共前后缀AB和AB

![image-20210916121117315](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916121117315.png)

### 2.核心步骤

> 移动模式串的前缀到模式串的后缀位置，这样就能保证左边的串和主串匹配

![核心步骤](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/Peek 2021-10-01 13-08.gif)

![image-20210916121240118](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916121240118.png)

![image-20210916121342497](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916121342497.png)

+ 中间并没有匹配的模式串

![](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/2.gif)

![image-20210916121915602](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916121915602.png)

+ 一般模式：可以不用看主串，衍生到串对于所有位置都有可能不匹配的现象

![](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/3.gif)

![image-20210916122056885](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122056885.png)

![1321321321](/home/jack/%E8%A7%86%E9%A2%91/4.gif)

> 模式串超出主串的位置，判断结束不匹配

![image-20210916122222548](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122222548.png)

+ 不匹配找最长公共前后缀

![image-20210916122246444](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122246444.png)

+ 长度不能等于子串长度，无意义

![image-20210916122318395](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122318395.png)

![image-20210916122422199](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122422199.png)

### 3.去掉主串

![image-20210916122541357](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122541357.png)

+ 存入数组，从1开始存

![image-20210916122600937](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122600937.png)

+ 第一个位置不匹配

![image-20210916122721569](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122721569.png)

![image-20210916123223389](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123223389.png)

让模式串中一号位置的字符和主串的下一位比较

![image-20210916122947719](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916122947719.png)

+ 二号位不匹配

![image-20210916123036067](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123036067.png)

> 不匹配的位置前后缀的长度为1，但是公共前后缀的长度<不匹配位置前的串长度，所以最长公共前后缀为0，所以前移一位
>
> 模式串的1号位和主串的当前位置比较

![image-20210916123145589](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123145589.png)

![image-20211001133730381](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211001133730381.png)

+ 3号位不匹配

![image-20210916123409419](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123409419.png)

![image-20211001133958893](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211001133958893.png)

![image-20210916123510342](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123510342.png)

+ 4号位不匹配，最长公共前后缀为1

![image-20210916123533366](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123533366.png)

![image-20210916123542598](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123542598.png)

![image-20210916123608574](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123608574.png)

+ 5号位不匹配

![image-20211001134334707](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211001134334707.png)

![image-20210916123627532](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123627532.png)

+ 6号位不匹配的情况

![image-20211001134454413](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211001134454413.png)

![image-20210916123643075](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123643075.png)

规律出来了

![image-20210916123712095](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123712095.png)

+ 7号位不匹配

![image-20210916123724471](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123724471.png)

![image-20210916123750329](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123750329.png)

+ 8号位不匹配

![image-20210916123801208](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123801208.png)

![image-20211001134744541](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211001134744541.png)

### 4.总结

![image-20211001140356186](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211001140356186.png)

> 算法的关键是求next【j】，除了下标1位置之外，其他位置描述都是一样的，都是最长公共前后缀+1

![image-20210916123838170](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123838170.png)

+ 将第一句话标记位0，看到0按照第一句话的方式处理

![image-20210916123854018](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123854018.png)

+ 将每句话的数字抽取出来作为代号放入数组中

![image-20210916123915176](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123915176.png)

![image-20210916123950502](https://gitee.com/Doerr33/images/raw/master/imagesU/image-20210916123950502.png)

### 5.next数组代码说明

![image-20211002084828577](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002084828577.png)

+ 有7时

![image-20211002085954467](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002085954467.png)

![image-20211002090222931](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002090222931.png)

![image-20211002092505970](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002092505970.png)

+ 假设k+1等于17

![image-20211002092623850](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002092623850.png)

+ 假设next16 = 8

![image-20211002092814108](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002092814108.png)

![image-20211002093014702](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002093014702.png)

![image-20211002093637142](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002093637142.png)

![image-20211002093752994](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002093752994.png)

![image-20211002093823518](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002093823518.png)

![image-20211002093843403](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002093843403.png)

![image-20211002093931254](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002093931254.png)

![image-20211002094004902](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002094004902.png)

![image-20211002095037151](https://cdn.jsdelivr.net/gh/Doerr33/images//imagesubuntu/image-20211002095037151.png)

# 9.树的递归算法



# 10.树的非递归

## 1.先序

![image-20211009182948925](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009182948925.png)

![image-20211009183226040](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009183226040.png)



+ 过程演示

![image-20211009183333270](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009183333270.png)

![image-20211009183400665](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009183400665.png)

![image-20211009183427258](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009183427258.png)

![image-20211009183444103](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009183444103.png)

> D的左子树为空，则栈顶POP，指针P的回到D位置，然后遍历右子树

![image-20211009183520947](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009183520947.png)

![image-20211009183739994](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009183739994.png)

> G的左节点为空，则栈顶的G出栈；P指针指向回到G节点，然后遍历右节点；又因为右节点为空，则栈顶元素B出栈；P指针指向B节点

![image-20211009184046862](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184046862.png)

![image-20211009184120140](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184120140.png)

> 对于B元素来说,右子树为空,又要出栈;则A出栈,P指针回退到A节点

![image-20211009184247000](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184247000.png)

+ 其他步骤

![image-20211009184327387](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184327387.png)



![image-20211009184339822](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184339822.png)

![image-20211009184359491](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184359491.png)

![image-20211009184434026](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184434026.png)

> 当访问到F的右节点时,栈中的元素也为空,此时循环终止

![image-20211009184601946](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009184601946.png)

```
//非递归先序遍历
void PreOrder1(Tree t)
{
    Tree p = t;
    Sqstack s;
    InitStack(s);

    while (p || !StackEmpty(s))
    {
        // 不为空遍历左子树
        if (p)
        {
            printf("%c", p->data);//输出根节点 
            Push(s, p);//根节点进栈,方便左子树没有时返回
            p = p->lchild;//遍历左子树
        }
        // 为空遍历右子树
        else
        {
            Pop(s, p);//回退
            p = p->rchild;
        }
    }
}
```





## 2.中序

![image-20211009185422241](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009185422241.png)

![image-20211009185536528](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009185536528.png)

+ 过程演示

> 1.根节点进栈但是不访问,遍历左子树

![image-20211009185649412](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009185649412.png)

> 2.B节点入栈,但是不访问,遍历左子树

![image-20211009185831258](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009185831258.png)

> 3.D节点进栈，访问左子树为空

![image-20211009185948987](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009185948987.png)

> 4.D出栈，输出D节点；P指针指向D节点，开始访问右子树

![image-20211009190101305](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009190101305.png)

> 5.G节点入栈，访问左子树，为空，则G节点出栈，P回退到G，访问右节点

![image-20211009190221945](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009190221945.png)

![image-20211009190448371](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009190448371.png)

> 6.右子树为空，栈顶元素出栈，P回退到B节点，输出B节点

![image-20211009190723422](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009190723422.png)

> 7.访问右子树，也为空，则A出栈，P指针指向A，输出A节点

![image-20211009190908430](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009190908430.png)

+ 其他步骤

![image-20211009191039516](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009191039516.png)

![image-20211009191049134](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009191049134.png)

![image-20211009191103039](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009191103039.png)

![image-20211009191126431](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009191126431.png)

![image-20211009191142170](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009191142170.png)

![image-20211009191202450](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009191202450.png)

> 访问到F的右子树时，此时栈为空，并且P为空，循环停止，遍历结束

![image-20211009191318156](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211009191318156.png)

```
//非递归中序遍历
void InOrder1(Tree t)
{
    Tree p = t;
    Sqstack s;
    InitStack(s);

    while (p || !StackEmpty(s))
    {
        if (p)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            Pop(s, p);
            printf("%c", p->data);//和先序的区别
            p = p->rchild;
        }
    }
}
```

## 3.后序

```
后序遍历首先访问左子树，然后退栈，访问右子树，进栈，退栈,用Debug走一遍
```

![image-20211011095511302](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211011095511302.png)

# 11.二叉树层序遍历算法

![image-20211016092804172](https://cdn.jsdelivr.net/gh/Doerr33/images1//imagesubuntu1/image-20211016092804172.png)

