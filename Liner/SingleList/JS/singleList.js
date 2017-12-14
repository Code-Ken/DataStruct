/**
 * 节点函数
 * @param {int} data
 */
function Node(data) {
    this.data = data;
    this.next = null;
}

/**
 * 线性表的链式存储结构
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class SingleList {
    /**
     * 构造函数
     */
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    /**
     * 初始化线性表
     * @param {object} arr
     */
    InitList(arr) {
        for (let i = 0; i < arr.length; i++) {
            let node = new Node(arr[i]);
            if (!this.head) {
                this.head = node;
                this.tail = node;
            } else {
                this.tail.next = node;
                this.tail = node;
            }
            this.length++;
        }
    }

    /**
     * 判断线性表是否为空
     * @return {boolean}
     */
    ListEmpty() {
        return this.length === 0;
    }

    /**
     * 将线性表清空
     */
    ClearList() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    /**
     * 获取线性表第i位的元素
     * @param {int} index
     * @return {string|int}
     */
    GetElem(index) {
        if (index < 0 || index >= this.length) return -1;
        let i = 0;
        let current = this.head;
        while (i < index) {
            current = current.next;
            i++;
        }
        return current.data;
    }

    /**
     * 获取元素elem在线性表中的位置
     * @param {int} elem
     * @return {int}
     */
    LocateElem(elem) {
        let current = this.head;
        let pos = 0;
        while (current.next) {
            if (current.data === elem) {
                return pos;
            }
            current = current.next;
            pos++;
        }
        return -1;
    }

    /**
     * 向线性表中的第i位插入元素
     * @param {int} index
     * @param {string|int} elem
     * @return {int}
     */
    ListInsert(index, elem) {
        if (index < 0 || index > this.length) return -1;
        let pos = 0;
        let node = new Node();
        let current = this.head;
        node.data = elem;
        while (pos < index) {
            current = current.next;
            pos++;
        }
        node.next = current.next;
        current.next = node;
        this.length++;
        return 0;
    }

    /**
     * 向线性表中的第i位删除元素
     * @param {int} index
     * @return {string|int}
     */
    ListDelete(index) {
        if (index < 0 || index >= this.length) return -1;
        let pos = 0;
        let current = this.head;
        if (index === 0) {
            this.head = current.next;
            this.length--;
            return 0;
        }
        while (pos < index - 1) {
            current = current.next;
            pos++;
        }
        current.next = current.next.next;
        this.length--;
        return 0;
    }

    /**
     * 获取线性表的长度
     * @return int
     */
    ListLength() {
        return this.length;
    }

    /**
     * 反转
     * @return 0
     */
    ReverseList() {
        let p = this.head;
        let q = this.head;
        while (p.next) {
            q = p.next;
            p.next = q.next;
            q.next = this.head;
            this.head = q;
        }
        return 0;
    }

    /**
     * 打印
     * @return {Object}
     */
    ListPrint() {
        let string = '';
        let current = this.head;
        while (current) {
            string += `${current.data}-> `;
            current = current.next;
        }
        console.log(string.trim());
    }

}


let a = new SingleList();
let arr = [1, 2, 3, 4, 5, 6];
a.InitList(arr);
a.ReverseList();
a.ListPrint();
a.ListInsert(1, 222);
a.ListPrint();
console.log(a.GetElem(2));
console.log(a.LocateElem(222));
a.ListDelete(0);
a.ListPrint();





