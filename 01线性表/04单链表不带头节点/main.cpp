#include"Method.h"
int main(){
	LinkList L;
	int e;
	InitList(L);
	Empty(L); 
	List_TailInsert(L);
	PrintList(L);
	ClearList(L);
	Empty(L);
	List_HeadInsert(L);
	PrintList(L);
	ListInsert(L,3,999999);
	PrintList(L); 
	ListDelete(L,3,e);
	PrintList(L);
	return 0;
}