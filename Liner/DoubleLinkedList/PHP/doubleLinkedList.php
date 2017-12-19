<?php

/**
 * Class Node
 */
class DuLNode
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
     * @var null
     */
    protected $prior;

    /**
     * Node constructor.
     * @param $value
     */
    public function __construct($value)
    {
        $this->data = $value;
        $this->prior = null;
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
     * @param DuLNode $node
     * @return int
     */
    public function setNext(DuLNode $node)
    {
        $this->next = $node;
        return 0;
    }


    /**
     * 获取上一个节点
     * @return null
     */
    public function getPrior()
    {
        return $this->prior;
    }

    /**
     * 设置节点数值
     * @param DuLNode $node
     * @return int
     */
    public function setPrior(DuLNode $node)
    {
        $this->prior = $node;
        return 0;
    }
}

/**
 * 双链表存储结构
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class DoubleLinkedList
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
     * 初始化双链表
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
            $node = new DuLNode($arr[$i]);
            if (!$this->head) {
                $this->head = $node;
                $this->tail = $node;
            } else {
                $node->setPrior($this->tail);
                $this->tail->setNext($node);
                $this->tail = $node;
            }
            $this->length++;
        }
    }

    /**
     * 判断双链表是否为空
     * @return bool
     */
    public function ListEmpty()
    {
        return $this->length === 0;
    }

    /**
     * 将双链表清空
     */
    public function ClearList()
    {
        $this->head = null;
        $this->tail = null;
        $this->length = 0;
    }

    /**
     * 获取双链表第i位的元素
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
     * 获取元素elem在双链表中的位置
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
     * 向双链表中的第i位插入元素
     * @param $index
     * @param $elem
     * @return int
     */
    public function ListInsert($index, $elem)
    {
        if ($index < 0 || $index > $this->length) return -1;
        $pos = 0;
        $node = new DuLNode($elem);
        $current = $this->head;
        while ($pos < $index - 1) {
            $current = $current->getNext();
            $pos++;
        }
        $node->setNext($current->getNext());
        $node->setPrior($current);
        $current->getNext()->setPrior($node);
        $current->setNext($node);
        $this->length++;
        return 0;
    }

    /**
     * 向双链表中的第i位删除元素
     * @param $index
     * @return int
     */
    public function ListDelete($index)
    {
        if ($index < 0 || $index > $this->length) return -1;
        $pos = 0;
        $current = $this->head;
        while ($pos < $index) {
            $current = $current->getNext();
            $pos++;
        }
        $current->getNext()->getNext()->setPrior($current->getNext());
        $current->setNext($current->getNext()->getNext());
        $this->length--;
        return 0;
    }

    /**
     * 获取双链表的长度
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
        $temp = $this->head;
        while ($p) {
            $temp = $p->getPrior();
            $p->setPrior($p->getNext());
            $p->setNext($temp);
            if($p->getPrior() == null) break;
            else $p = $p->getPrior();
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


$a = new DoubleLinkedList();
$a->InitList([1, 2, 3, 4, 5]);
$a->ListInsert(2,33333);
$a->ListPrint();
//$a->ListDelete(1);
//$a->ListPrint();
$a->ReverseList();
$a->ListPrint();


