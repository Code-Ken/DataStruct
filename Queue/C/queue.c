/**
 * Copyright:   MIT
 * File name:   queue.c
 * Author:      Ken(gaosong0301@foxmail.com)
 * Description: 队列
 * Others:      C语言版本
 * Function List:
 *      InitQueue       初始化操作,建立一个空的队列
 *      QueueEmpty      判断队列是否为空
 *      EnQueue         入队
 *      DeQueue         出队
 *      QueueFront      获取队首元素
 *      QueueLength     获取队列长度
 *      DestroyQueue    销毁队列
 *      PrintQueue      打印队列
 */

#include <stdio.h>
#include <stdlib.h>

//元素的类型别名  以int类型做举例
typedef int ElemType;

//元素结构体
typedef struct queueNode {
    ElemType data;
    struct queueNode *next;
} QueueNode, *QNode;

//队列结构体
typedef struct {
    int length;
    QNode front;
    QNode rear;
} LinkQueue, *LQueue;

/**
 * Function Name: InitQueue
 * Purpose: 初始化操作,建立一个队列
 * Params:
 *      @LQueue    Q     队列
 * Return:  void
 */
void InitQueue(LQueue Q) {
    Q->length = 0;
    Q->front = NULL;
    Q->rear = NULL;
}

/**
 * Function Name: QueueEmpty
 * Purpose: 判断队列是否为空
 * Params:
 *      @LQueue    Q     队列
 * Return:  int
 * Limitation: 返回1则代表是
 */
int QueueEmpty(LQueue Q) {
    return Q->length == 0;
}

/**
 * Function Name: EnQueue
 * Purpose: 入队
 * Params:
 *      @LQueue    Q     队列
 *      @ElemType  x     入队元素
 * Return:  void
 */
void EnQueue(LQueue Q, ElemType x) {
    QNode node = (QNode) malloc(sizeof(QueueNode));
    node->data = x;
    node->next = NULL;
    if (Q->length == 0) {
        Q->front = node;
        Q->rear = node;
    } else {
        Q->rear->next = node;
        Q->rear = node;
    }
    Q->length++;
}

/**
 * Function Name: DeQueue
 * Purpose: 入队
 * Params:
 *      @LQueue    Q     队列
 * Return:  ElemType|int
 * Limitation: 返回-1则代表失败
 */
ElemType DeQueue(LQueue Q) {
    ElemType x;
    QNode p;
    if (Q->length == 0) {
        return -1;
    }
    p = Q->front;
    x = p->data;
    Q->front = p->next;
    if (Q->length == 1) {
        Q->rear = NULL;
    }
    free(p);
    Q->length--;
    return x;
}

/**
 * Function Name: QueueFront
 * Purpose: 获取队首元素
 * Params:
 *      @LQueue    Q     队列
 * Return:  ElemType
 */
ElemType QueueFront(LQueue Q) {
    if (Q->length == 0) {
        return -1;
    }
    return Q->front->data;
}

/**
 * Function Name: QueueLength
 * Purpose: 获取队列长度
 * Params:
 *      @LQueue    Q     队列
 * Return:  int
 */
int QueueLength(LQueue Q) {
    return Q->length;
}

/**
 * Function Name: DestroyQueue
 * Purpose: 销毁队列
 * Params:
 *      @LQueue    Q     队列
 * Return:  void
 */
void DestroyQueue(LQueue Q) {
    Q->length = 0;
    free(Q->front);
    free(Q->rear);
}

/**
 * Function Name: PrintQueue
 * Purpose: 打印队列
 * Params:
 *      @LQueue    Q     队列
 * Return:  void
 */
void PrintQueue(LQueue Q) {
    QNode node = Q->front;
    while (node){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LQueue Q = (LQueue) malloc(sizeof(LinkQueue));
    InitQueue(Q);
    EnQueue(Q, 1111);
    EnQueue(Q, 2222);
    EnQueue(Q, 3333);
    EnQueue(Q, 4444);
    EnQueue(Q, 5555);
    PrintQueue(Q);
    DeQueue(Q);
    PrintQueue(Q);
    printf("%d\n",QueueLength(Q));
    printf("%d\n",QueueFront(Q));
    printf("%d\n",QueueEmpty(Q));
    DestroyQueue(Q);
    printf("%d\n",QueueEmpty(Q));
}



