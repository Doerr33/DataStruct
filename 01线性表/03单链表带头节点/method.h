#include"LinkList.h"
//1.????? 
bool InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
} 
//2.?卸????????
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
//3.???? 
bool DestroyList(LinkList &L){
	LNode *p; //?????????LinkList p?????????????????????????
	while(L){
		p = L;
		L = L->next;
		free(p);//delete p??? 
	} 
	return true;
} 

//4.??? 
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
//5.????
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

//6.??位??
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
//7.???????
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
//8.???????????澹�????????????????i-1????? 
bool ListInsert(LinkList &L,int i,int e){
	if(i < 1){
		return false;
	}
	LNode *p;//????????璧�???? 
	int j = 0;//???p????????????? 
	p = L;//L??????????????0?????
	while(p != NULL && j < i - 1){
		p = p->next;
		j++;
	} 
	if(p == NULL){//i?????? 
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; 
	
} 
//9.??????
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
	printf("鎻掑叆鐨勫厓绱犳槸%d\n",e);
	p->next = q->next;
	free(q);
	return true; 
}
//10尾?宸�
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
 //11.??宸� 
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
 //13.???
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