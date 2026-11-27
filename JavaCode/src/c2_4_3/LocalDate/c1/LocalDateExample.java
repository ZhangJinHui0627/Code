package c2_4_3.LocalDate.c1;

import java.time.LocalDate;

public class LocalDateExample
{
    public static void main(String[] args)
    {
        // 获取当前日期
        LocalDate currentDate = LocalDate.now();
        System.out.println("Current Date: " + currentDate);

        // 创建指定日期
        LocalDate specificDate = LocalDate.of(2024, 12, 17);
        System.out.println("Specific Date: " + specificDate);

        // 从字符串解析日期
        LocalDate parsedDate = LocalDate.parse("2024-12-18");
        System.out.println("Parsed Date: " + parsedDate);

        // 获取年份、月份和日期
        int year = currentDate.getYear();
        int month = currentDate.getMonthValue();
        int dayOfMonth = currentDate.getDayOfMonth();
        System.out.println("Year: " + year + ", Month: " + month + ", Day: " + dayOfMonth);

        // 判断是否是闰年
        boolean isLeapYear = specificDate.isLeapYear();
        System.out.println("Is Leap Year: " + isLeapYear);
    }
}
