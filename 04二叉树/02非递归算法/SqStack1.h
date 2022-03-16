#include <stdio.h>
#include <stdlib.h>

#define STACKINITSIZE 100 //栈初始化大小
#define STACKINCREASESIZE 20 //栈满增加空间

typedef char ElemType;
//树结构
typedef struct tree
{
    ElemType data;
    struct tree *lchild;
    struct tree *rchild;
    unsigned int isOut = 0; //专为后序遍历设置的，0为不需要被输出，1为需要被输出
} TreeNode, *Tree;

//栈结构
typedef struct stack
{
    // // 用于后序
    // TreeNode *pr;
    // int flag; //1表示第1次出栈，2表示第2次出栈


    Tree *base;
    Tree *top;
    int stacksize;
} Sqstack;

/*****************栈的操作声明********************/

//初始化栈
void InitStack(Sqstack &s);
//元素入栈
void Push(Sqstack &s, Tree e);
//获得栈顶元素
void GetTop(Sqstack s, Tree &e);
//弹出栈顶元素
void Pop(Sqstack &s, Tree &e);
//判断栈是否为空，为空返回1，否则返回0
int StackEmpty(Sqstack s);

/*****************栈的操作声明********************/

/*****************树的操作声明********************/
//创建树,以先序序列建立树
void CreateTree(Tree &t);
//递归先序遍历
void PreOrder(Tree t);
//非递归先序遍历
void PreOrder1(Tree t);
//递归中序遍历
void InOrder(Tree t);
//非递归中序遍历
void InOrder1(Tree t);
//递归后序遍历
void PostOrder(Tree t);
//非递归后序遍历
void PostOrder1(Tree t);
/*****************树的操作声明********************/