package c2_4_3.LocalDate.c5;

import java.time.LocalDate;

public class LocalDateExample
{
    public static void main(String[] args)
    {
        // 当前日期
        LocalDate today = LocalDate.now();

        // 另一个日期
        LocalDate pastDate = LocalDate.of(2024, 12, 1);

        // 判断今天是否在另一个日期之后
        boolean isAfter = today.isAfter(pastDate);
        System.out.println("Is today's date after 2024-12-01? " + isAfter);

        // 判断今天是否在另一个日期之后
        boolean isAfterFuture = today.isAfter(LocalDate.of(2026, 12, 1));
        System.out.println("Is today's date after the future date? " + isAfterFuture);
    }
}
