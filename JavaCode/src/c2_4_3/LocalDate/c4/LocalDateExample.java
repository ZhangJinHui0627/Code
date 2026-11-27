package c2_4_3.LocalDate.c4;

import java.time.LocalDate;

public class LocalDateExample
{
    public static void main(String[] args)
    {
        // 当前日期
        LocalDate today = LocalDate.now();
        System.out.println(today);

        // 另一个日期
        LocalDate futureDate = LocalDate.of(2026, 12, 1);

        // 判断今天是否在另一个日期之前
        boolean isBefore = today.isBefore(futureDate);
        System.out.println("Is today's date before the future date? " + isBefore);

        // 判断今天是否在另一个日期之前
        boolean isBeforePast = today.isBefore(LocalDate.of(2024, 12, 1));
        System.out.println("Is today's date before 2024-12-01? " + isBeforePast);
    }
}
