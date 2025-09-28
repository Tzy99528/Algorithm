//
// Created by T2125 on 2025/9/16.
//
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

int menu_select();
void CreateList_L(LinkList *L, int n);
void PrintList_L(LinkList L);
Status GetElem_L(LinkList *L, int i, ElemType *e);
Status ListInsert_L(LinkList *L, int i, ElemType e);
Status ListDelete_L(LinkList *L, int i, ElemType *e);
int LocateElem_L(LinkList L, ElemType e);

int main()
{
    LinkList L;
    int n;
    int i;
    int e;
    while (1)
    {
        switch (menu_select())
        {
            case 1:
                printf("请输入元素个数 n：");
                scanf("%d", &n);
                CreateList_L(&L, n);
                printf("创建单链表成功！\n");
                break;
            case 2:
                PrintList_L(L);
                printf("输出单链表成功！\n");
                break;
            case 3:
                printf("请输入位序 i：");
                scanf("%d", &i);
                printf("线性表中第 i 个位序上的元素为%d\n", GetElem_L(&L, i, &e));
                printf("查找元素成功！\n");
                break;
            case 4:
                printf("请依次输入位序 i 和给定值 e：");
                scanf("%d%d", &i, &e);
                ListInsert_L(&L, i, e);
                printf("成功插入元素！\n");
                break;
            case 5:
                printf("请输入位序 i：");
                scanf("%d", &i);
                ListDelete_L(&L, i, &e);
                printf("成功删除元素%d！\n", e);
                break;
            case 6:
                printf("请输入给定值：");
                scanf("%d", &e);
                printf("等于给定值的第一个元素的位序为%d", LocateElem_L(L, e));
                break;
            case 0:
                printf("成功结束程序！\n");
                exit(OK);
        }
    }
    return 0;
}

int menu_select()
{
    int op;
    printf("1.输入n个元素，创建一个单链表\n");
    printf("2.输出单链表\n");
    printf("3.查找线性表第i个位序上的元素，并保存到e\n");
    printf("4.插入给定值e到指定位序i\n");
    printf("5.删除指定位序i的元素，并保存到e\n");
    printf("6.查找等于给定值的第一个元素的逻辑位序\n");
    printf("0.结束\n");
    printf("请输入您的选择（0~6）：");
    scanf("%d", &op);
    while (op < 0 || op > 6)
    {
        printf("输入有误，请重新输入0~6：");
        scanf("%d", &op);
    }
    return op;
}

void CreateList_L(LinkList *L, int n)
{
    LinkList p = L;
    for (int i = 0; i < n; i++)
    {
        LinkList node = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &node->data);
        node->next = NULL;
        p->next = node;
        p = p->next;
    }
}

void PrintList_L(LinkList L)
{
    LinkList p = L;
    while (p->next)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

Status GetElem_L(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p = L->next;
    for (j = 0; j < i && p != NULL; j++)
        p = p->next;
    if (j < i || p == NULL)
        return ERROR;
    e = p;
    return OK;
}

Status ListInsert_L(LinkList *L, int i, ElemType e)
{
    LinkList p = L;
    for (int j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    if (!q)
        return OVERFLOW;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status ListDelete_L(LinkList *L, int i, ElemType *e)
{
    LinkList p = L;
    for (int j = 0; j < i - 1; j++)
        p = p->next;
    LinkList q = p->next;
    *e = q->data;
    p->next = p->next->next;
    free(q);
    return OK;
}

int LocateElem_L(LinkList L, ElemType e)
{
    int i = 1;
    LinkList p = L->next;
    while (p != NULL)
    {
        if (p->data == e)
            return i;
        p = p->next;
        i++;
    }
    return ERROR;
}