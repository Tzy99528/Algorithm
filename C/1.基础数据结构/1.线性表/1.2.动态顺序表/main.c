//
// Created by T2125 on 2025/9/10.
//
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LISI_INIT_SIZE 10
#define LIST_INCREMENT 2

typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listSize;
} SqList;

void Menu();
Status InitListSq(SqList *L);
Status CreateListSq(SqList *L, int n);
void PrintListSq(SqList L);
Status ListInsertSq(SqList *L, int i, ElemType e);
Status ListDeleteSq(SqList *L, int i, ElemType *e);
int LocateElemSq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
Status equal(ElemType x, ElemType y);
Status greater(ElemType x, ElemType y);
Status less(ElemType x, ElemType y);

int main()
{
    SqList L;
    int op;
    while (1)
    {
        int n;
        int i;
        int e;
        int index;
        Menu();
        scanf("%d", &op);
        while (op < 0 || op > 8)
        {
            printf("输入有误，请重新输入0~8：");
            scanf("%d", &op);
        }
        switch (op)
        {
            case 1:
                InitListSq(&L);
                printf("成功初始化顺序表！\n");
                break;
            case 2:
                printf("请输入元素个数n：");
                scanf("%d", &n);
                if (CreateListSq(&L, n))
                    printf("创建顺序表成功！\n");
                else
                    printf("创建顺序表失败！\n");
                break;
            case 3:
                PrintListSq(L);
                printf("输出顺序表成功！\n");
                break;
            case 4:
                printf("请依次输入位序i和给定值e：");
                scanf("%d%d", &i, &e);
                if (ListInsertSq(&L, i, e))
                    printf("插入成功！\n");
                else
                    printf("插入失败！\n");
                break;
            case 5:
                printf("请输入位序i：");
                scanf("%d", &i);
                if (ListDeleteSq(&L, i, &e))
                    printf("删除元素%d成功！\n", e);
                else
                    printf("删除失败！\n");
                break;
            case 6:
                printf("请输入比较值e：");
                scanf("%d", &e);
                index = LocateElemSq(L, e, equal);
                if (index)
                    printf("第一个等于比较值%d的元素的位序是%d\n", e, index);
                else
                    printf("查找失败！\n");
                break;
            case 7:
                printf("请输入比较值e：");
                scanf("%d", &e);
                index = LocateElemSq(L, e, greater);
                if (index)
                    printf("第一个大于比较值%d的元素的位序是%d\n", e, index);
                else
                    printf("查找失败！\n");
                break;
            case 8:
                printf("请输入比较值e：");
                scanf("%d", &e);
                index = LocateElemSq(L, e, less);
                if (index)
                    printf("第一个小于比较值%d的元素的位序是%d\n", e, index);
                else
                    printf("查找失败！\n");
                break;
            case 0:
                printf("程序运行结束！\n");
                exit(ERROR);
        }
    }
    return 0;
}

void Menu()
{
    printf("=====菜单=====\n");
    printf("1.初始化一个动态顺序表\n");
    printf("2.输入n个元素\n");
    printf("3.输出顺序表\n");
    printf("4.插入给定值e到位序i\n");
    printf("5.删除指定位序i的元素\n");
    printf("6.查找等于给定值e的第一个元素的位序\n");
    printf("7.查找大于给定值e的第一个元素的位序\n");
    printf("8.查找小于给定值e的第一个元素的位序\n");
    printf("0.结束\n");
    printf("请输入你的选择：");
}

Status InitListSq(SqList *L)
{
    L->elem = NULL;
    L->length = 0;
    L->listSize = 0;
    return OK;
}

Status CreateListSq(SqList *L, int n)
{
    L->elem = (ElemType*)malloc(sizeof(ElemType) * n);
    if (L->elem == NULL) return ERROR;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", L->elem + i);
    }
    L->length = n;
    L->listSize = n * sizeof(ElemType);
    return OK;
}

void PrintListSq(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

Status ListInsertSq(SqList *L, int i, ElemType e)
{
    if (i < 1 || i > L->length + 1)
        return ERROR;
    for (int j = L->length - 1; j >= i - 1; j--)
    {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i - 1] = e;
    L->length++;
    L->listSize += sizeof(ElemType);
    return OK;
}

Status ListDeleteSq(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
        return ERROR;
    *e = L->elem[i - 1];
    for (int j = i - 1; j < L->length - 1; j++)
        L->elem[j] = L->elem[j+1];
    L->length--;
    L->listSize -= sizeof(ElemType);
    return OK;
}

int LocateElemSq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    for (int i = 0; i < L.length; i++)
    {
        if (compare(L.elem[i], e))
            return i + 1;
    }
    return ERROR;
}

Status equal(ElemType x, ElemType y)
{
    if (x == y)
        return OK;
    else
        return ERROR;
}

Status greater(ElemType x, ElemType y)
{
    if (x > y)
        return OK;
    else
        return ERROR;
}

Status less(ElemType x, ElemType y)
{
    if (x < y)
        return OK;
    else
        return ERROR;
}