/**
 * Copyright:   MIT
 * File name:   seqlist.c
 * Author:      Ken(gaosong0301@foxmail.com)
 * Description: 线性表的顺序存储结构
 * Others:      C语言版本
 * Function List:
 *      InitList        初始化操作,建立一个空的线性表
 *      ListEmpty       判断列表是否为空
 *      ClearList       将线性表清空
 *      GetElem         获取线性表中的元素
 *      LocateElem      查找线性表中的元素
 *      ListInsert      向线性表中插入元素
 *      ListDelete      删除线性表元素
 *      ListLength      返回线性表元素个数
 */

#include <stdio.h>
#include <stdlib.h>

//初始化表元素的大小
#define LIST_INIT_SIZE 100
//每次增长的大小
#define LIST_INCR 10

// 元素的类型别名  以int类型做举例
typedef int ElemType;
//线性表结构体
typedef struct {
    ElemType *elem;  //元素数组指针
    int length;   //元素长度
    int list_size;  //表长度
} SeqList;


/**
 * Function Name: InitList
 * Purpose: 初始化线性表
 * Params:
 *      @SeqList    *L     线性表实例
 * Return:  int     是否初始化成功
 * Limitation: 返回-1则代表失败
 */
int InitList(SeqList *L) {
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem) {
        return -1;
    }

    L->length = 0;
    L->list_size = LIST_INIT_SIZE;
    return 0;
}

/**
 * Function Name: ListEmpty
 * Purpose: 判断线性表是否为空
 * Params:
 *      @SeqList    L     线性表实例
 * Return:  int     是否初始化成功
 * Limitation: 返回-1则代表不为空
 */
int ListEmpty(SeqList L) {
    if (L.length == 0) {
        return 0;
    }
    return -1;
}

/**
 * Function Name: ClearList
 * Purpose: 将线性表清空
 * Params:
 *      @SeqList    *L     线性表实例
 * Return:  int     是否初成功
 * Limitation: 返回-1则代表失败
 */
int ClearList(SeqList *L) {
    if (L->elem) {
        free(L->elem);
    }
    L->length = 0;
    L->list_size = 0;
    return 0;
}


/**
 * Function Name: GetElem
 * Purpose: 获取线性表第i位的元素,并将它赋值给e
 * Params:
 *      @SeqList    L     线性表实例
 *      @int        i     元素位数
 *      @ELemType  *e    元素地址
 * Return:  int     是否初成功
 * Limitation: 返回-1则代表失败
 */
int GetElem(SeqList L, int i, ElemType *e) {
    if (i < 0 || i >= L.length) return -1;
    *e = L.elem[i];
    return 0;
}

/**
 * Function Name: LocateElem
 * Purpose: 获取元素x在线性表中的位置
 * Params:
 *      @SeqList    L     线性表实例
 *      @ELemType   *e    元素地址
 * Return:  int     元素x的位置
 * Limitation: 返回-1则代表元素x不存在
 */
int LocateElem(SeqList L, ElemType x) {
    int pos = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == x) {
            pos = i;
        }
    }
    return pos;
}

/**
 * Function Name: ListInsert
 * Purpose: 向线性表中的第i位插入元素
 * Params:
 *      @SeqList    L     线性表实例
 *      @int        i     插入位置
 *      @ELemType   e     插入元素
 * Return:  int     是否成功
 * Limitation: 返回-1则代表插入失败
 */
int ListInsert(SeqList *L, int i, ElemType e) {
    if (i < 0 || i > L->length) return -1;

    if (L->length >= L->list_size) {
        ElemType *newBase = (ElemType *) realloc(L->elem, (L->list_size + LIST_INCR) * sizeof(ElemType));
        if (!newBase) return -1;
        L->elem = newBase;
        L->list_size += LIST_INCR;
    }
    ElemType *q, *p;
    q = &(L->elem[i]);
    for (p = &(L->elem[L->length - 1]); p >= q; p--) {
        *(p + 1) = *p;
    }
    *q = e;
    ++L->length;
    return 0;
}

/**
 * Function Name: ListDelete
 * Purpose: 向线性表中的第i位删除元素
 * Params:
 *      @SeqList    L     线性表实例
 *      @int        i     删除位置
 *      @ELemType   *e    删除元素
 * Return:  int     是否成功
 * Limitation: 返回-1则代表删除失败
 */
int ListDelete(SeqList *L, int i, ElemType *e) {
    if (i < 0 || i > L->length) return -1;
    ElemType *q, *p;
    *e = L->elem[i];
    q = &(L->elem[i]);
    for (p = q; p < &(L->elem[L->length - 1]); p++) {
        *p = *(p + 1);
    }
    L->length--;
    return 0;
}

/**
 * Function Name: ListLength
 * Purpose: 获取线性表的长度
 * Params:
 *      @SeqList    L     线性表实例
 * Return:  int     返回线性表长度
 */
int ListLength(SeqList L) {
    return L.length;
}

int main() {
    SeqList L;
    InitList(&L);
    printf("List is Empty? %d\n", ListEmpty(L));
    for (int i = 0; i < 10; i++) {
        ListInsert(&L, i, i);
    }

    for (int j = 0; j < 12; j++) {
        printf("elem[%d] = %d \n", j, L.elem[j]);
    }
    printf("Length:%d\n", ListLength(L));
    ElemType a;
    ListDelete(&L, 1, &a);
    for (int j = 0; j < 12; j++) {
        printf("elem[%d] = %d %p\n", j, L.elem[j], &L.elem[j]);
    }
    printf("Length:%d\n", ListLength(L));
    printf("Delete e: %d\n", a);
    ElemType b;
    GetElem(L, 0, &b);
    printf("get Elem: %d\n", b);
    printf("Location Elem %d\n", LocateElem(L, 2));
    printf("List is Empty? %d\n", ListEmpty(L));
    printf("Addr: %p\n",&L.elem);
    printf("ClearList: %d\n",ClearList(&L));
    printf("Addr: %p\n",*(&L.elem));
    printf("elem[0] = %d %p\n", L.elem[0], &L.elem[0]);
    printf("elem[1] = %d %p\n", L.elem[1], &L.elem[1]);
    printf("elem[2] = %d %p\n", L.elem[2], &L.elem[2]);
    return 0;
}




















