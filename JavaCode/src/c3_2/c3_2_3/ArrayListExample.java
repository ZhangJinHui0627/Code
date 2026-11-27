package c3_2.c3_2_3;

import java.util.ArrayList;

public class ArrayListExample
{
    public static void main(String[] args)
    {
        ArrayList list = new ArrayList(); // 创建ArrayList集合
        list.add("apple");
        //list.add("cherry");
        list.add("banana");
        list.add("cherry");
        System.out.println(list); // 输出: [apple, banana, cherry]
        System.out.println(list.get(1)); // 输出: banana
        System.out.println(list.size());
    }
}

/*练习:
编写程序创建ArrayList集合，向集合中添加5个元素。
添加顺序不可变依次分别是你的: 姓名、年龄、性别、专业、班级
打印出该集合的长度
打印出你的性别
*/
