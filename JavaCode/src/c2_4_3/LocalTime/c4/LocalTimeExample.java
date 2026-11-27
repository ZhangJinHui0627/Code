package c2_4_3.LocalTime.c4;

import java.time.LocalTime;

public class LocalTimeExample
{
    public static void main(String[] args)
    {
        // 当前时间
        LocalTime currentTime = LocalTime.now();
        System.out.println("Current Time: " + currentTime);

        // 设置秒数为 45
        LocalTime timeWithNewSecond = currentTime.withSecond(45);//LocalTime 内部保存的是纳秒精度
        System.out.println("Time with second set to 45: " + timeWithNewSecond);

        // 设置秒数为 0
        LocalTime timeWithZeroSecond = currentTime.withSecond(10).withNano(0);
        System.out.println("Time with second set to 0: " + timeWithZeroSecond);
    }
}
