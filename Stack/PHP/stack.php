<?php

/**
 * Class sNode
 */
class sNode
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
     * @param mixed $node
     * @return int
     */
    public function setNext($node)
    {
        $this->next = $node;
        return 0;
    }
}

/**
 * 栈
 * @copyright   MIT.
 * @author      Ken(gaosong0301@foxmail.com)
 */
class Stack
{
    /**
     * 栈顶属性
     * @var null
     */
    protected $top;
    /**
     * 栈长度
     * @var int
     */
    protected $length = 0;

    /**
     * Stack constructor.
     */
    public function __construct()
    {
        $this->top = null;
        $this->length = 0;
    }

    /**
     * 初始化栈
     * @param $arr
     */
    public function InitStack($arr)
    {
        $count = count($arr);
        for ($i = 0; $i < $count; $i++) {
            $temp_node = new sNode($arr[$i]);
            if ($this->top) {
                $temp_node->setNext($this->top);
            }
            $this->top = $temp_node;
            $this->length++;
        }
    }

    /**
     * 销毁栈
     */
    public function DestroyStack()
    {
        $this->top = null;
        $this->length = 0;
    }

    /**
     * 判断栈是否是空
     * @return bool
     */
    public function StackEmpty()
    {
        return $this->length === 0;
    }

    /**
     * 获取栈的长度
     * @return int
     */
    public function StackLength()
    {
        return $this->length;
    }

    /**
     * 如栈
     * @param $x
     */
    public function Push($x)
    {
        $node = new sNode($x);
        $node->setNext($this->top);
        $this->top = $node;
        $this->length++;
    }

    /**
     * 出栈
     * @return int
     */
    public function Pop()
    {
        if ($this->length === 0) {
            return -1;
        }
        $p = $this->top;
        $data = $p->getValue();
        $this->top = $p->getNext();
        $this->length--;
        return $data;
    }

    /**
     * 获取栈顶元素
     * @return int
     */
    public function GetTop()
    {
        if ($this->length === 0) {
            return -1;
        }
        return $this->top->getValue();
    }

    /**
     * 打印栈
     */
    public function PrintStack()
    {
        $p = $this->top;
        $stack = "";
        while ($p) {
            $stack .= $p->getValue() . " ";
            $p = $p->getNext();
        }
        print_r($stack . PHP_EOL);
    }
}

$a = new Stack();
$a->InitStack([1, 2, 3, 4, 5]);
$a->PrintStack();
$a->Push(222);
$a->Push(444);
$a->Push(666);
$a->PrintStack();
echo $a->Pop() . PHP_EOL;
$a->PrintStack();
echo $a->GetTop() . PHP_EOL;
$a->PrintStack();



