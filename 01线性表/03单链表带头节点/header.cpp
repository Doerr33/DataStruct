#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; //1.定义ElemType为整形 

typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

//1.初始化头结点
bool InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
} 
//2.判断是否为空
bool Empty(LinkList L){
	if(L->next == NULL){
		printf("NULL\n");
		return true;
	}
	else{
		printf("Not NULL\n");
		return false;
	}
} 
//3.销毁线性表
bool DestroyList(LinkList &L){
	LNode *p; //定义一个节点指针，从L->next开始遍历释放
	while(L){
		p = L;
		L = L->next;
		free(p);//delete p也行
	} 
	return true;
} 

//4.清空线性表：从L-next开始遍历释放
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

//5.获取长度，遍历增加
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

//6.按位获取值
int GetElem(LinkList L,int i){
	LNode *p;
	p = L->next;
	int j = 1;
	while(p && j < i){
		p = p->next; 
		j ++; 
	}
	// 未找到
	if(!p || j > i){
		return 0;
	}
	return p->data;
	
} 
//7.按值获取
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
//8.插入
bool ListInsert(LinkList &L,int i,int e){
	if(i < 1){
		return false;
	}
	LNode *p;
	int j = 0;//用来找位置
	p = L;
	// 找到i - 1位置
	while(p != NULL && j < i - 1){
		p = p->next;
		j++;
	} 
	if(p == NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; 
	
} 
//9.删除
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
	if(p == NULL){
		return false;
	}
	if(p->next == NULL){
		return false;
	}
	LNode *q = p->next;
	e = q->data;
	printf("删除的数据是：%d\n",e);
	p->next = q->next;
	free(q);
	return true; 
}
//10.尾插法建立链表
 LinkList List_TailInsert(LinkList &L){
 	int x;
 	L = (LinkList)malloc(sizeof(LNode));
 	LNode *s,*r = L;
	printf("输入数据创建链表以9999为结束:");
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
 //11.头插法
 LinkList List_HeadeInsert(LinkList &L){
 	LNode *s;
 	int x;
 	L = (LinkList)malloc(sizeof(LNode));
 	L->next = NULL;
	printf("输入数据创建链表以9999为结束:");
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
 //13.打印
void PrintList(LinkList L)
{
	L = L->next;
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


int main(){
	LinkList L;
	int e;
	// 初始化
	InitList(L);
	Empty(L);
	// 尾插法建立链表
	List_TailInsert(L);
	PrintList(L);
	// 清空链表
	ClearList(L);
	Empty(L); 
	// 头插法建立链表
	List_HeadeInsert(L);
	PrintList(L);
	// 插入数据876
	ListInsert(L,3,876);
	PrintList(L);
	// 删除第3个位置上的数据
	ListDelete(L,3,e);
	PrintList(L);
	return 0;
}