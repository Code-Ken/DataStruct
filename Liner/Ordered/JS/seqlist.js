/**
 * 线性表的顺序存储结构
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class SeqList {
    /**
     * 构造函数
     */
    constructor() {
        this.seqArr = [];
        this.length = null;
    }

    /**
     * 初始化线性表
     * @param {object} arr
     */
    InitList(arr = []) {
        this.seqArr = arr;
        this.length = arr.length;
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
        this.seqArr = [];
        this.length = 0;
    }

    /**
     * 获取线性表第i位的元素
     * @param {int} index
     * @return {string|int}
     */
    GetElem(index) {
        if (index < 0 || index >= this.length) return -1;
        return this.seqArr[index];
    }

    /**
     * 获取元素elem在线性表中的位置
     * @param {int} elem
     * @return {int}
     */
    LocateElem(elem) {
        for (let i = 0; i < this.length; i++) {
            if (elem === this.seqArr[i]) {
                return i;
            }
        }
        return -1;
    }

    /**
     * 向线性表中的第i位插入元素
     * @param {int} index
     * @param {string} elem
     * @return {int}
     */
    ListInsert(index, elem) {
        if (index < 0 || index > this.length) return -1;
        if (index === this.length) {
            this.seqArr[index] = elem;
            this.length++;
            return 0;
        }
        for (let i = this.length - 1; i >= index; i--) {
            this.seqArr[i + 1] = this.seqArr[i];
        }
        this.seqArr[index] = elem;
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
        let elem = this.seqArr[index];
        for (let i = index; i < this.length; i++) {
            this.seqArr[i - 1] = this.seqArr[i];
        }
        this.seqArr.pop();
        return elem;
    }

    /**
     * 获取线性表的长度
     * @return int
     */
    ListLength() {
        return this.length;
    }

    /**
     * 打印
     * @return {Object}
     */
    ListPrint() {
        return this.seqArr;
    }
}

let arr = new SeqList();
arr.InitList();
for (let i = 0; i < 10; i++) {
    arr.ListInsert(i, i + 2);
}
console.log(arr.ListPrint());
arr.ListInsert(0, 33);
arr.ListInsert(3, 55);
console.log(arr.ListPrint());
console.log(`elem=3 location=${arr.LocateElem(3)}`);
console.log(`location=3 elem=${arr.GetElem(3)}`);
arr.ListDelete(2);
console.log(arr.ListPrint());
console.log(`length = ${arr.ListLength()}`);
console.log(arr.ListEmpty());
console.log(arr.ClearList());
console.log(arr.ListEmpty());





