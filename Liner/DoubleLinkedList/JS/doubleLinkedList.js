/**
 * 节点函数
 * @param {int} data
 */
function DuLNode(data) {
    this.data = data;
    this.prior = null;
    this.next = null;
}

/**
 * 双链表
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class DoubleLinkedList {
    /**
     * 构造函数
     */
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    /**
     * 初始化双链表
     * @param {object} arr
     */
    InitList(arr) {
        for (let i = 0; i < arr.length; i++) {
            let node = new DuLNode(arr[i]);
            if (!this.head) {
                this.head = node;
                this.tail = node;
            } else {
                node.prior = this.tail;
                this.tail.next = node;
                this.tail = node;
            }
            this.length++;
        }
    }

    /**
     * 判断双链表是否为空
     * @return {boolean}
     */
    ListEmpty() {
        return this.length === 0;
    }

    /**
     * 将双链表清空
     */
    ClearList() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    /**
     * 获取双链表第i位的元素
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
     * 获取元素elem在双链表中的位置
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
     * 向双链表中的第i位插入元素
     * @param {int} index
     * @param {string|int} elem
     * @return {int}
     */
    ListInsert(index, elem) {
        if (index < 0 || index > this.length) return -1;
        let pos = 0;
        let node = new DuLNode(elem);
        let current = this.head;
        while (pos < index) {
            current = current.next;
            pos++;
        }
        node.next = current.next;
        node.prior = current;
        current.next.prior = node;
        current.next = node;
        this.length++;
        return 0;
    }

    /**
     * 向双链表中的第i位删除元素
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
        current.next.next.prior = current.next;
        current.next = current.next.next;
        this.length--;
        return 0;
    }

    /**
     * 获取双链表的长度
     * @return int
     */
    ListLength() {
        return this.length;
    }

    /**
     * 反转
     * @return int
     */
    ReverseList() {
        let p = this.head;
        let temp = this.head;
        while (p) {
            temp = p.prior;
            p.prior = p.next;
            p.next = temp;
            if (p.prior === null) break;
            else p = p.prior;
        }
        this.head.next = null;
        this.head = p;
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
            string += `${current.data}<->`;
            current = current.next;
        }
        console.log(string.trim());
    }
}

let a = new DoubleLinkedList();
let arr = [1, 2, 3, 4, 5, 6];
a.InitList(arr);
a.ListPrint();
//a.ListDelete(1);
a.ReverseList();
a.ListPrint();
