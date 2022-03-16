#include"NoHeaderLinkList.h"
//1.不带头节点的初始化 
void InitList(LinkList &L)
{
    L = NULL;
}

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

//3.判断的单链表是否为空表
bool Empty(LinkList L)
{
    if (L == NULL){
    	printf("NULL\n");
    	return true;
    }
        
    else
    {
    	printf("Not NULL\n");
		return false; 
    }
}

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

//在表中查找第一个与查找元素相同位置的:结点
LNode *LocateElem_LNode(LinkList L, ElemType e)
{
    int j = 1;
    LNode *p = L;
    if (p->data == e) //首先查看第一个结点
        return p;
    else
        p = p->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (j == Length(L))
    {
        return NULL;
    }
    return p;
}
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

//得到表中某一位置的结点
LNode *GetElem_LNode(LinkList L, int i)
{
    LNode *p = L;
    if (i < 0 || i > Length(L))
        return NULL;
    for (int j = 1; j < i; j++)
    {
        p = p->next;
    }
    return p;
}
//获得某一位置元素的值
ElemType GetElem(LinkList L, int i)
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
    printf("del num is %d\n",e); 
    p->next = q->next;
    free(q);
    return true;
}

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
//销毁 
bool DestroyList(LinkList &L){
	LNode *p; //指向一个节点LinkList p也可以，不过为了便于理解用前一个
	while(L){
		p = L;
		L = L->next;
		free(p);//delete p也行 
	} 
	return true;
} 

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
