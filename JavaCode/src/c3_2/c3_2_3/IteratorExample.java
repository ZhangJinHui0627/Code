package c3_2.c3_2_3;

import java.util.*;

public class IteratorExample
{
    public static void main(String[] args)
    {
        ArrayList list = new ArrayList(); // 创建ArrayList集合
        list.add("张三");                   // 向该集合中添加字符串
        list.add("李四");
        list.add("王五");
        list.add("赵六");
        Iterator it = list.iterator(); // 1. 获取Iterator对象
        while (it.hasNext())           // 2. 判断ArrayList集合中是否存在下一个元素
        {
            System.out.println(it.next()); //3.next() 获取当前元素，并将迭代器指针移到下一位置
        }
    }
}
