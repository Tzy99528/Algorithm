//
// Created by T2125 on 2025/9/20.
//
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;