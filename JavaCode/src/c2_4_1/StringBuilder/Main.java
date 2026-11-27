package c2_4_1.StringBuilder;

public class Main
{
    public static void main(String[] args)
    {
        StringBuilder sb = new StringBuilder("Hello");
        sb.append(" World"); // 拼接 " World" 到 sb, 结果是 "Hello World"
        System.out.println(sb); // 输出: Hello World

        StringBuilder sb1 = new StringBuilder("Hello");
        sb1.insert(5, " Java"); // 在索引 5 的位置插入 " Java"
        System.out.println(sb1); // 输出: Hello Java

        StringBuilder sb2 = new StringBuilder("Hello World!");
        sb2.delete(5, 11); // 删除索引从 5 到 10 的字符
        System.out.println(sb2); // 输出: Hello!
        sb2.deleteCharAt(4); // 删除索引 4 的字符 (字符 "o")
        System.out.println(sb2); // 输出: Hell!

        StringBuilder sb3 = new StringBuilder("Hello World");
        sb3.replace(6, 11, "Java"); // 将索引 6 到 10 的字符替换为 "Java"
        System.out.println(sb3); // 输出: Hello Java

        StringBuilder sb4 = new StringBuilder("Hello");
        sb4.reverse(); // 反转字符串
        System.out.println(sb4); // 输出: olleH

        StringBuilder sb5 = new StringBuilder("Hello");
        char ch = sb5.charAt(1); // 获取索引 1 位置的字符
        System.out.println(ch); // 输出: e

        StringBuilder sb6 = new StringBuilder("Hello");
        sb6.setCharAt(1, 'a'); // 将索引 1 位置的字符改为 'a'
        System.out.println(sb6); // 输出: Hallo

        StringBuilder sb7 = new StringBuilder();
        System.out.println(sb7.capacity()); // 默认容量为 16
        sb7.append("Hello");
        System.out.println(sb7.capacity()); // 容量依然为 16, 因为未超出 16 个字符
        sb7.append(" World! This is a long string.");
        System.out.println(sb7.capacity()); // 由于超过 16 个字符, 容量会自动扩容

        StringBuilder sb8 = new StringBuilder("Hello");
        int len = sb8.length(); // 获取字符数量
        System.out.println(len); // 输出: 5
    }
}
