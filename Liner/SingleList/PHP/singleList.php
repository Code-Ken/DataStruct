<?php

/**
 * Class Node
 */
class Node
{
    /**
     * @var
     */
    protected $data;
    /**
     * @var null
     */
    protected $next;

    /**
     * Node constructor.
     * @param $value
     */
    public function __construct($value)
    {
        $this->data = $value;
        $this->next = null;
    }

    /**
     * 获取节点数值
     * @return mixed
     */
    public function getValue()
    {
        return $this->data;
    }

    /**
     * 获取下一个节点
     * @return null
     */
    public function getNext()
    {
        return $this->next;
    }

    /**
     * 设置节点数值
     * @param Node $node
     * @return int
     */
    public function setNext(Node $node)
    {
        $this->next = $node;
        return 0;
    }

}

/**
 * 线性表的链式存储结构
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class SingleList
{
    /**
     * 头指针
     * @var null
     */
    protected $head;
    /**
     * 尾指针
     * @var null
     */
    protected $tail;
    /**
     * 链表长度
     * @var int
     */
    protected $length;

    /**
     * SingleList constructor.
     */
    public function __construct()
    {
        $this->head = null;
        $this->tail = null;
        $this->length = 0;
    }

    /**
     * 初始化线性表
     * @param $arr
     * @return bool
     */
    public function InitList($arr)
    {
        if (empty($arr)) {
            return false;
        }
        $count = count($arr);
        for ($i = 0; $i < $count; $i++) {
            $node = new Node($arr[$i]);
            if (!$this->head) {
                $this->head = $node;
                $this->tail = $node;
            } else {
                $this->tail->setNext($node);
                $this->tail = $node;
            }
            $this->length++;
        }
    }

    /**
     * 判断线性表是否为空
     * @return bool
     */
    public function ListEmpty()
    {
        return $this->length === 0;
    }

    /**
     * 将线性表清空
     */
    public function ClearList()
    {
        $this->head = null;
        $this->tail = null;
        $this->length = 0;
    }

    /**
     * 获取线性表第i位的元素
     * @param $index
     * @return int
     */
    public function GetElem($index)
    {
        if ($index < 0 || $index > $this->length) return -1;
        $i = 0;
        $current = $this->head;
        while ($i < $index) {
            $current = $current->getNext();
            $i++;
        }
        return $current->getValue();
    }

    /**
     * 获取元素elem在线性表中的位置
     * @param $elem
     * @return int
     */
    public function LocateElem($elem)
    {
        $current = $this->head;
        $pos = 0;
        $length = $this->length;
        while ($length > 0) {
            if ($current->getValue() == $elem) {
                return $pos;
            }
            $current = $current->getNext();
            $pos++;
            $length--;
        }
        return -1;
    }

    /**
     * 向线性表中的第i位插入元素
     * @param $index
     * @param $elem
     * @return int
     */
    public function ListInsert($index, $elem)
    {
        if ($index < 0 || $index > $this->length) return -1;
        $pos = 0;
        $node = new Node($elem);
        $current = $this->head;
        while ($pos < $index - 1) {
            $current = $current->getNext();
            $pos++;
        }
        $node->setNext($current->getNext());
        $current->setNext($node);
        $this->length++;
        return 0;
    }

    /**
     * 向线性表中的第i位删除元素
     * @param $index
     * @return int
     */
    public function ListDelete($index)
    {
        if ($index < 0 || $index > $this->length) return -1;
        $pos = 0;
        $current = $this->head;
        while ($pos < $index - 1) {
            $current = $current->getNext();
            $pos++;
        }
        $next = $current->getNext()->getNext();
        $current->setNext($next);
        $this->length--;
        return 0;
    }

    /**
     * 获取线性表的长度
     * @return int
     */
    public function ListLength()
    {
        return $this->length;
    }

    /**
     * 反转
     * @return int
     */
    public function ReverseList()
    {
        $p = $this->head;
        $q = null;
        $length = $this->length;
        while ($length > 1) {
            $q = $p->getNext();
            $tmp = $q->getNext();
            if ($tmp) {
                $p->setNext($tmp);
            }
            $q->setNext($this->head);

            $this->head = $q;
            $length--;
        }
        return 0;
    }


    /**
     * 打印
     */
    public function ListPrint()
    {
        $arr = [];
        $current = $this->head;
        $length = $this->length;
        while ($length > 0) {
            $arr[] = $current->getValue();
            $current = $current->getNext();
            $length--;
        }
        print_r($arr);
    }
}

$list = new SingleList();
$list->InitList([1, 2, 3, 4, 5, 6]);
$list->ReverseList();
$list->ListPrint();
var_dump($list->GetElem(1));
var_dump($list->LocateElem(1));
$list->ListInsert(1, 222);
$list->ListPrint();
$list->ListDelete(2);
$list->ListPrint();


