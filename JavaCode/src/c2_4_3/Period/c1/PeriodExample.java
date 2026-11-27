package c2_4_3.Period.c1;

import java.time.LocalDate;
import java.time.Period;

public class PeriodExample
{
    public static void main(String[] args)
    {
        // 获取两个日期之间的时间间隔
        LocalDate startDate = LocalDate.of(2023, 1, 1);
        LocalDate endDate = LocalDate.of(2024, 12, 17);
        Period period = Period.between(startDate, endDate); // 计算日期间隔
        System.out.println("Period: " + period); // 输出时间间隔

        // 获取年、月、日的各个部分
        int years = period.getYears();
        int months = period.getMonths();
        int days = period.getDays();
        System.out.println("Years: " + years);
        System.out.println("Months: " + months);
        System.out.println("Days: " + days);

        // 增加或减少时间
        Period addedPeriod = period.plusMonths(2); // 增加 2 个月
        System.out.println("Added Period: " + addedPeriod);
    }
}
