package c2_4_1.String;

import java.nio.charset.StandardCharsets;

public class Main
{
    public static void main(String[] args)
    {
        String str111 = "Java";
        String str222 = "Java"; // 由于字符串常量池, str1 和 str2 指向同一个内存地址
        String str333=new String("Java"); // 每次 new 都会创建新对象

    // 获取字符串长度
        String str = "Hello";
        int length = str.length(); // 返回字符串的长度5
        System.out.println(length);

        // 使用 "+" 操作符拼接
        String str1 = "Hello";
        String str2 = "World";
        String result = str1 + " " + str2;
        System.out.println(result);

    //equals()比较内容是否相同; equalsIgnoreCase()忽略大小写比较
        String str3 = "Hello";
        String str4 = "hello";
        boolean isEqual = str3.equals(str4); // false
        boolean isEqualIgnoreCase = str3.equalsIgnoreCase(str4); // true
        System.out.println(isEqual);
        System.out.println(isEqualIgnoreCase);

    //返回一个新字符串, 它是从指定beginIndex开始, 到endIndex结束的子字符串
        String str5 = "Hello World";
        String subStr1 = str5.substring(6); // 从索引 6 开始截取到末尾, 结果是 "World"
        String subStr2 = str5.substring(0, 5); // 从索引 0 到 5 (不包含索引 5), 结果是 "Hello"
        System.out.println(subStr1);
        System.out.println(subStr2);

    // 返回索引位置
        String str6 = "Hello World";
        int index = str6.indexOf("World"); // 返回子字符串首次出现的索引位置, 结果是 6
        int lastIndex = str6.lastIndexOf('o'); // 从后往前查找第一个 'o', 结果是 7
        System.out.println(index);
        System.out.println(lastIndex);

    //replace 替换
        String str7 = "Hello World";
        String newStr = str7.replace("World", "Java"); // 转换 "World" 为 "Java"
        System.out.println(newStr);

    //大小写转换
        String str8 = "Hello";
        String upperStr = str8.toUpperCase(); // 转换为大写, 结果是 "HELLO"
        String lowerStr = str8.toLowerCase(); // 转换为小写, 结果是 "hello"
        System.out.println(upperStr);
        System.out.println(lowerStr);

    //去除首尾空格
        String str9 = " Hello World ";
        String trimmedStr = str9.trim(); // 去掉前后空格, 结果是 "Hello World"
        System.out.println(str9);
        System.out.println(trimmedStr);

    //判断字符串长度是否为空
        String str10 = ""; // 或空格 " "
        String str11 = "h i";
        boolean isEmpty = str10.isEmpty(); // true, 判断字符串是否为空
        boolean isBlank = str10.isBlank(); // true, 判断字符串是否为空或只包含空白字符
        boolean isBlank1 = str11.isBlank();//false
        System.out.println(isEmpty);
        System.out.println(isBlank);
        System.out.println(isBlank1);

    // 编码: 字符串 -> UTF-8 字节数组
        String str12 = "Hello";
        byte[] bytes = str12.getBytes(StandardCharsets.UTF_8); // 将字符串转换为字节数组, 指定使用 UTF-8
        for (byte b : bytes)
        {
            System.out.print(b + " ");
        }
    // 解码: UTF-8 字节数组 -> 字符串:new String(bytes, ...) 构造法, 用指定的字符集把字节数组还原成字符串
        String decodedStr = new String(bytes, StandardCharsets.UTF_8);
        System.out.println("\n" + decodedStr);

    // 字符串转换为字符数组
        String str13 = "abcd";
        char[] charArray = str13.toCharArray();
        for (int i = 0; i < charArray.length; i++)
        {
            System.out.print(charArray[i] + " ");
        }

    // 数字 -> 字符串
        int num = 100;
        String str14 = String.valueOf(num);
        System.out.println("\n数字转字符串: " + str14); // 输出: 数字转字符串: 100
        if (str14 instanceof String)
            System.out.println("100是字符串");
        else
            System.out.println("100不是字符串");
    }
}
