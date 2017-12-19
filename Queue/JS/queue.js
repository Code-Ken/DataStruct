/**
 * 节点函数
 * @param {int} data
 */
function QNode(data) {
    this.data = data;
    this.next = null;
}

/**
 * 队列
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class Queue {
    /**
     * 构造函数
     */
    constructor() {
        this.length = 0;
        this.front = null;
        this.rear = null;
    }

    /**
     * 初始化队列
     * @param {object} arr
     */
    InitQueue(arr) {
        for (let i = 0; i < arr.length; i++) {
            let qNode = new QNode(arr[i]);
            if (this.length === 0) {
                this.front = qNode;
                this.rear = qNode;
            } else {
                this.rear.next = qNode;
                this.rear = qNode;
            }
            this.length++;
        }
    }

    /**
     * 判断队列是否为空
     * @return {boolean}
     */
    QueueEmpty() {
        return this.length === 0;
    }

    /**
     * 入队
     * @param {int} x
     */
    EnQueue(x) {
        let qNode = new QNode(x);
        if (this.length === 0) {
            this.front = qNode;
            this.rear = qNode;
        } else {
            this.rear.next = qNode;
            this.rear = qNode;
        }
        this.length++;
    }

    /**
     * 出队
     * @return {int}
     */
    DeQueue() {
        if (this.length === 0) {
            return -1;
        }

        let p = this.front;
        let data = p.data;
        this.front = p.next;
        if (this.length === 1) {
            this.rear = null;
        }
        this.length--;
        return data;
    }

    /**
     * 获取队首元素
     * @return {int}
     */
    QueueFront() {
        return this.front.data;
    }

    /**
     * 获取队首长度
     * @return {int}
     */
    QueueLength() {
        return this.length;
    }

    /**
     * 销毁队列
     */
    DestroyQueue() {
        this.length = 0;
        this.front = null;
        this.rear = null;
    }


    /**
     * 打印队列
     */
    PrintQueue() {
        let string = '';
        let current = this.front;
        while (current) {
            string += `${current.data}-> `;
            current = current.next;
        }
        console.log(string.trim());
    }
}

let a = new Queue();
a.InitQueue([1, 2, 3, 4, 5, 6]);
a.PrintQueue();
a.EnQueue(7);
a.PrintQueue();
console.log(a.DeQueue());
console.log(a.QueueFront());
a.PrintQueue();
console.log(a.QueueLength());
console.log(a.QueueEmpty());
a.DestroyQueue();
console.log(a.QueueEmpty());





