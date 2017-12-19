/**
 * 节点函数
 * @param {int} data
 */
function StackNode(data) {
    this.data = data;
    this.next = null;
}

/**
 * 栈
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class Stack {
    /**
     * 构造函数
     */
    constructor() {
        this.top = null;
        this.length = 0;
    }
    /**
     * 初始化栈
     * @param {object} arr
     */
    InitStack(arr) {
        for (let i = 0; i < arr.length; i++) {
            let sNode = new StackNode(arr[i]);
            if (this.top) {
                sNode.next = this.top;
            }
            this.top = sNode;
            this.length++;
        }
    }
    /**
     * 销毁栈
     */
    DestroyStack() {
        this.top = null;
        this.length = 0;
    }

    /**
     * 判断栈是否为空
     * @return {boolean}
     */
    StackEmpty() {
        return this.length === 0;
    }
    /**
     * 获取栈的长度
     * @return {int}
     */
    StackLength() {
        return this.length;
    }

    /**
     * 入栈
     * @param {int} x
     */
    Push(x) {
        let sNode = new StackNode(x);
        sNode.next = this.top;
        this.top = sNode;
        this.length++;
    }

    /**
     * 出栈
     * @return {int}
     */
    Pop() {
        if (this.length === 0) {
            return -1;
        }
        let p = this.top;
        let x = p.data;
        this.top = p.next;
        this.length--;
        return x;
    }

    /**
     * 获取栈顶元素
     * @return {int} -1时表示失败
     */
    GetTop() {
        if (this.length === 0) {
            return -1;
        }
        return this.top.data;
    }
    /**
     * 打印栈
     */
    PrintStack() {
        let string = '';
        let current = this.top;
        while (current) {
            string += `${current.data}-> `;
            current = current.next;
        }
        console.log(string.trim());
    }
}


let a = new Stack();
a.InitStack([1, 2, 3, 4, 5]);
a.Push(1111);
a.Push(2222);
a.PrintStack();
a.Push(3333);
a.PrintStack();
a.Pop();
a.PrintStack();
console.log(a.GetTop());
console.log(a.StackLength());
console.log(a.StackEmpty());
a.DestroyStack();
console.log(a.StackEmpty());
