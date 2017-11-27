<?php

/**
 * 线性表的顺序存储结构
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class SeqList
{
    /**
     * 数组
     */
    private $_seq_arr;
    /**
     * 数组长度
     */
    private $_length;

    /**
     * constructor.
     * @param array $arr
     */
    public function __construct($arr = array())
    {
        $this->_seq_arr = $arr;
        $this->_length = count($arr);
    }

    /**
     * 初始化线性表
     */
    public function InitList()
    {
        $this->_seq_arr = array();
        $this->_length = 0;
    }

    /**
     * 判断线性表是否为空
     * @return bool
     */
    public function ListEmpty()
    {
        return $this->_length === 0;
    }

    /**
     * 将线性表清空
     */
    public function ClearList()
    {
        $this->_seq_arr = array();
        $this->_length = 0;
    }

    /**
     * 获取线性表第i位的元素
     * @param $index
     * @return mixed|string
     */
    public function GetElem($index)
    {
        if ($index < 0 || $index >= $this->_length) return "err";
        return $this->_seq_arr[$index];
    }

    /**
     * 获取元素elem在线性表中的位置
     * @param $elem
     * @return int
     */
    public function LocateElem($elem)
    {
        for ($i = 0; $i < $this->_length; $i++) {
            if ($elem == $this->_seq_arr[$i]) {
                return $i;
            }
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
        if ($index < 0 || $index > $this->_length) return -1;
        if ($index == $this->_length) {
            $this->_seq_arr[$index] = $elem;
            $this->_length++;
            return 0;
        }
        for ($i = $this->_length - 1; $i >= $index; $i--) {
            $this->_seq_arr[$i + 1] = $this->_seq_arr[$i];
        }
        $this->_seq_arr[$index] = $elem;
        $this->_length++;
        return 0;
    }

    /**
     * 向线性表中的第i位删除元素
     * @param $index
     * @return mixed|string
     */
    public function ListDelete($index)
    {
        if ($index < 1 || $this->_length == 0 || !is_int($index) || $index > $this->_length) return "err";
        $elem = $this->_seq_arr[$index - 1];
        for ($i = $index; $i < $this->_length; $i++) {
            $this->_seq_arr[$i - 1] = $this->_seq_arr[$i];
        }
        unset($this->_seq_arr[$this->_length - 1]);
        $this->_length--;
        return $elem;
    }

    /**
     * 获取线性表的长度
     * @return int
     */
    public function ListLength()
    {
        return $this->_length;
    }

    /**
     * 打印
     * @return array
     */
    public function ListPrint()
    {
        return $this->_seq_arr;
    }
}

$l = new SeqList();
$l->InitList();
for ($i = 0; $i < 10; $i++) {
    $l->ListInsert($i, $i + 2);
}
var_dump($l->ListPrint());
$l->ListInsert(0, 33);
$l->ListInsert(3, 55);
var_dump($l->ListPrint());
var_dump("elem=3 location=" . $l->LocateElem(3));
var_dump("location=3 elem=" . $l->GetElem(3));
var_dump("length = " . $l->ListLength());
$l->ListDelete(2);
var_dump($l->ListPrint());
echo "length = " . $l->ListLength() . "\n";
var_dump($l->ListEmpty());
$l->ClearList();
var_dump($l->ListEmpty());
