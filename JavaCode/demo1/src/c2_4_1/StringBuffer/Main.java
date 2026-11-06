package c2_4_1.StringBuffer;

public class Main
{
    public static void main(String[] args)
    {
        StringBuilder sb123 = new StringBuilder();
        System.out.println(sb123);
        sb123.append("Hello");
        sb123.append(" ");
        sb123.append("World");
        System.out.println(sb123.toString());

    //插入insert
        StringBuffer sb = new StringBuffer("Hello");
        sb.insert(5, " Java"); // 在索引 5 的位置插入 " Java"
        System.out.println(sb); // 输出: Hello Java

    //删除
        StringBuffer sb1 = new StringBuffer("Hello World");
        sb1.delete(7, 11); // 删除索引从 7 到 10 的字符
        System.out.println(sb1); // 输出: Hello W
        sb1.deleteCharAt(4); // 删除索引 4 的字符 (字符 "o")
        System.out.println(sb1); // 输出: Hell W

    //替换
        StringBuffer sb2 = new StringBuffer("Hello World! ");
        sb2.replace(6, 11, "Java"); // 将索引 6 到 10 的字符替换为 "Java"
        System.out.println(sb2); // 输出: Hello Java!

    //反转字符串
        StringBuffer sb6 = new StringBuffer("Hello");
        sb6.reverse();
        System.out.println(sb6); // 输出: olleH

    //获取指定位置字符
        StringBuffer sb7 = new StringBuffer("Hello");
        char ch = sb7.charAt(1); // 获取索引 1 位置的字符
        System.out.println(ch); // 输出: e

    //修改指定位置字符
        StringBuffer sb8 = new StringBuffer("Hello");
        sb8.setCharAt(1, 'a'); // 将索引 1 位置的字符改为 'a'
        System.out.println(sb8); // 输出: Hallo

    //获取当前StringBuffer的容量
        StringBuffer sb9 = new StringBuffer();
        System.out.println(sb9.capacity()); // 默认容量为 16
        sb9.append("Hello");
        System.out.println(sb9.capacity()); // 容量依然是 16, 因为未超出 16 个字符
        sb9.append(" World! This is a long string.");
        System.out.println(sb9.capacity()); // 由于超过 16 个字符, 容量会自动扩容

    // 获取字符数量
        StringBuffer sb10 = new StringBuffer("Hello");
        int len = sb10.length();
        System.out.println(len); // 输出: 5
    //*66-67简写输出:
        System.out.println(sb10.length());
    }
}
