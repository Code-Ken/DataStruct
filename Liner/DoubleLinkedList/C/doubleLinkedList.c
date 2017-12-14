/**
 * Copyright:   MIT
 * File name:   doubleLinkedList.c
 * Author:      Ken(gaosong0301@foxmail.com)
 * Description: 双链表
 * Others:      C语言版本
 * Function List:
 *      InitList        初始化操作,建立一个链表
 *      ListEmpty       判断列表是否为空
 *      ClearList       将链表清空
 *      GetElem         获取链表中的元素
 *      LocateElem      查找链表中的元素
 *      ListInsert      向链表中插入元素
 *      ListDelete      删除链表元素
 *      ListLength      返回链表d元素个数
 *      PrintList       打印链表
 *      ReverseList     反转链表
 */
#include <stdio.h>
#include <stdlib.h>

//元素的类型别名  以int类型做举例
typedef int ElemType;

//链表结构体
typedef struct Node {
    ElemType data;
    struct Node *prior;
    struct Node *next;
} DuLNode, *DuLinkList;

/**
 * Function Name: InitList
 * Purpose: 初始化单链表
 * Params:
 *      @LinkList    L     链表实例
 * Return:  int     是否初始化成功
 * Limitation: 返回-1则代表失败
 */
int InitList(DuLinkList dL) {
    int n;
    DuLinkList p, q;
    p = dL;
    printf("请输入n和n个元素:\n");
    scanf("%d", &n);
    while (n--) {
        q = (DuLinkList) malloc(sizeof(DuLNode));
        scanf("%d", &q->data);
        p->next = q;
        q->prior = p;
        q->next = NULL;
        p = p->next;
    }
    return 0;
}

/**
 * Function Name: ListEmpty
 * Purpose: 判断链表是否为空
 * Params:
 *      @LinkList    L     链表实例
 * Return:  int     是否为空
 * Limitation: 返回1则代表不为空
 */
int ListEmpty(DuLinkList dL) {
    if (dL->next) {
        return 1;
    }
    return 0;
}

/**
 * Function Name: ClearList
 * Purpose: 将链表清空
 * Params:
 *      @LinkList    L     链表实例
 * Return:  int     是否初成功
 * Limitation: 返回-1则代表失败
 */
int ClearList(DuLinkList dL) {
    DuLinkList p;
    p = dL->next;
    dL->next = NULL;
    free(p);
    return 0;
}

/**
 * Function Name: GetElem
 * Purpose: 获取链表第i位的元素,并将它赋值给e
 * Params:
 *      @LinkList   L     链表实例
 *      @int        i     元素位数
 *      @ELemType  *e    元素地址
 * Return:  int     是否初成功
 * Limitation: 返回-1则代表失败
 */
int GetElem(DuLinkList dL, int i, ElemType *e) {
    int pos = 0;
    DuLinkList p;
    p = dL;
    while (p->next) {
        if (pos == i) {
            *e = p->data;
            return 0;
        }
        pos++;
        p = p->next;
    }
    return -1;
}

/**
 * Function Name: LocateElem
 * Purpose: 获取元素x在链表中的位置
 * Params:
 *      @LinkList   L     链表实例
 *      @ELemType   *e    元素地址
 * Return:  int     元素x的位置
 * Limitation: 返回-1则代表元素x不存在
 */
int LocateElem(DuLinkList dL, ElemType e) {
    int pos = 0;
    DuLinkList p;
    p = dL;
    while (p->next) {
        if (e == p->data) {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;
}

/**
 * Function Name: ListInsert
 * Purpose: 向链表中的第i位插入元素
 * Params:
 *      @LinkList   L     链表实例
 *      @int        i     插入位置
 *      @ELemType   e     插入元素
 * Return:  int     是否成功
 * Limitation: 返回-1则代表插入失败
 */
int ListInsert(DuLinkList dL, int i, ElemType e) {
    int pos = 1;
    DuLinkList p, q;
    q = (DuLinkList) malloc(sizeof(DuLNode));
    p = dL;
    while (p->next && pos < i) {
        p = p->next;
        pos++;
    }
    if (pos < i) {
        return -1;
    }
    q->data = e;
    p->next->prior = q;
    q->next = p->next;
    p->next = q;
    q->prior = p;
    return 0;
}

/**
 * Function Name: ListDelete
 * Purpose: 向链表中的第i位删除元素
 * Params:
 *      @LinkList   L     链表实例
 *      @int        i     删除位置
 *      @ELemType   *e    删除元素
 * Return:  int     是否成功
 * Limitation: 返回-1则代表删除失败
 */
int ListDelete(DuLinkList dL, int i, ElemType *e) {
    int pos = 1;
    DuLinkList p, q;
    p = dL;
    while (p->next && pos < i) {
        p = p->next;
        pos++;
    }
    if (pos < i) {
        return -1;
    }

    *e = p->next->data;
    q = p->next->next;
    q->prior = p;
    p->next = q;
    return 0;

}

/**
 * Function Name: ListLength
 * Purpose: 获取链表的长度
 * Params:
 *      @LinkList   L     链表实例
 * Return:  int     返回链表长度
 */
int ListLength(DuLinkList dL) {
    int num = 0;
    DuLinkList p;
    p = dL->next;
    while (p) {
        num++;
        p = p->next;
    }
    return num;
}

/**
 * Function Name: PrintList
 * Purpose: 打印链表
 * Params:
 *      @LinkList   L     链表实例
 */
void PrintList(DuLinkList dL) {
    int num = 0;
    DuLinkList p;
    p = dL->next;
    while (p) {
        num++;
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n长度为%d\n", num);
}

/**
 * Function Name: PrintList
 * Purpose: 打印链表
 * Params:
 *      @LinkList   L     链表实例
 */
int ReverseList(DuLinkList dL) {
    DuLinkList p, temp;
    p = dL->next;
    while (p) {
        temp = p->prior;
        p->prior = p->next;
        p->next = temp;
        if (p->prior == NULL) break;
        else p = p->prior;
    }
    dL->next->next = NULL;
    dL->next = p;
    return 0;
}

int main() {
    ElemType b;
    DuLinkList L;
    ElemType a;
    L = (DuLinkList) malloc(sizeof(DuLNode));
    L->next = NULL;
    L->data = -1;
    InitList(L);
    PrintList(L);
    ListDelete(L, 3, &b);
    ReverseList(L);
    PrintList(L);
}

