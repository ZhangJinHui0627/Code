package c2_4_3.LocalTime.c1;

import java.time.LocalTime;

public class LocalTimeExample
{
    public static void main(String[] args)
    {
        // 获取当前时间
        LocalTime currentTime = LocalTime.now();
        System.out.println("Current Time: " + currentTime);

        // 创建指定时间
        LocalTime specificTime = LocalTime.of(14, 30, 10); // 14:30:10
        System.out.println("Specific Time: " + specificTime);

        // 从字符串解析时间
        LocalTime parsedTime = LocalTime.parse("14:30:10");
        System.out.println("Parsed Time: " + parsedTime);

        // 获取小时、分钟和秒
        int hour = currentTime.getHour();
        int minute = currentTime.getMinute();
        int second = currentTime.getSecond();
        System.out.println("Hour: " + hour + ", Minute: " + minute + ", Second: " + second);

        // 判断时间是否在另一个时间之前或之后
        boolean isBefore = currentTime.isBefore(specificTime);
        boolean isAfter = currentTime.isAfter(specificTime);
        System.out.println("Is current time before specific time? " + isBefore);
        System.out.println("Is current time after specific time? " + isAfter);
    }
}
