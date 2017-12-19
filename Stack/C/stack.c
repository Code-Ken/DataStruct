/**
 * Copyright:   MIT
 * File name:   stack.c
 * Author:      Ken(gaosong0301@foxmail.com)
 * Description: 栈
 * Others:      C语言版本
 * Function List:
 *      InitStack        初始化操作,建立一个栈
 *      DestroyStack     销毁栈
 *      StackEmpty       判断栈是否为空栈
 *      StackLength      获取栈的长度
 *      Push             插入栈顶元素
 *      Pop              删除栈顶元素
 *      GetTop           获取栈顶元素
 *      PrintStack       打印栈
 */
#include <stdio.h>
#include <stdlib.h>

//元素的类型别名  以int类型做举例
typedef int ElemType;

//元素结构体
typedef struct stackNode {
    ElemType data;
    struct stackNode *next;
} StackNode, *PSNode;

//栈结构体
typedef struct {
    StackNode *top;
    int length;
} LinkStack, *LStack;

/**
 * Function Name: InitStack
 * Purpose: 初始化操作,建立一个栈
 * Params:
 *      @LStack    S     栈
 * Return:  void
 */
void InitStack(LStack S) {
    S->top = NULL;
    S->length = 0;
}

/**
 * Function Name: DestroyStack
 * Purpose: 销毁栈
 * Params:
 *      @LStack    S     栈
 * Return:  void
 */
void DestroyStack(LStack S) {
    S->length = 0;
    free(S->top);
}

/**
 * Function Name: StackEmpty
 * Purpose: 判断是否为空栈
 * Params:
 *      @LStack    S     栈
 * Return:  int
 * Limitation: 返回1则代表是
 */
int StackEmpty(LStack S) {
    return S->length == 0;
}

/**
 * Function Name: StackLength
 * Purpose: 获取栈的长度
 * Params:
 *      @LStack    S     栈
 * Return:  int
 */
int StackLength(LStack S) {
    return S->length;
}

/**
 * Function Name: Push
 * Purpose: 插入栈顶元素
 * Params:
 *      @LStack    S     栈
 *      @ElemType  x     插入元素
 * Return:  void
 */
void Push(LStack S, ElemType x) {
    PSNode node = (PSNode) malloc(sizeof(StackNode));
    node->data = x;
    node->next = S->top;
    S->top = node;
    S->length++;
}

/**
 * Function Name: Pop
 * Purpose: 删除栈顶元素
 * Params:
 *      @LStack    S     栈
 * Return:  ElemType  原栈顶元素
 */
ElemType Pop(LStack S) {
    ElemType x;
    PSNode p = S->top;
    if (StackEmpty(S))
        return -1;
    x = p->data;
    S->top = p->next;
    free(p);
    S->length--;
    return x;
}

/**
 * Function Name: GetPop
 * Purpose: 获取栈顶元素
 * Params:
 *      @LStack    S     栈
 * Return:  ElemType  栈顶元素
 */
ElemType GetTop(LStack S) {
    if (StackEmpty(S))
        return -1;
    return S->top->data;
}

/**
 * Function Name: PrintStack
 * Purpose: 打印栈
 * Params:
 *      @LStack    S     栈
 * Return:  void
 */
void PrintStack(LStack S) {
    PSNode node = S->top;
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LStack S = (LStack) malloc(sizeof(LinkStack));
    InitStack(S);
    Push(S, 111);
    Push(S, 222);
    Push(S, 333);
    Push(S, 444);
    Push(S, 555);
    PrintStack(S);
    Pop(S);
    Pop(S);
    PrintStack(S);
    printf("%d\n", GetTop(S));
    printf("%d\n", StackEmpty(S));
    printf("%d\n", StackLength(S));
    DestroyStack(S);
    printf("%d\n", StackEmpty(S));
}

