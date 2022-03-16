#include <cstdio>
#include <cstdlib>

typedef int ElemType; //1.定义ElemType为整形 

typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;