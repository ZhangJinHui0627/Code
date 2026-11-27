package c2_4_3.Period;

import java.time.LocalDateTime;
import java.time.Period;
import java.time.Duration;

public class DurationPeriodExample
{
    public static void main(String[] args)
    {
        LocalDateTime startDateTime = LocalDateTime.of(2023, 1, 1, 10, 30, 45);
        LocalDateTime endDateTime = LocalDateTime.of(2024, 12, 17, 14, 45, 30);

        // 计算日期部分的差异
        Period period = Period.between(startDateTime.toLocalDate(), endDateTime.toLocalDate());
        System.out.println("Period: " + period);

        // 计算时间部分的差异
        Duration duration = Duration.between(startDateTime.toLocalTime(), endDateTime.toLocalTime());
        System.out.println("Duration: " + duration);

        // 输出日期和时间的差异
        System.out.println("Years: " + period.getYears());
        System.out.println("Months: " + period.getMonths());
        System.out.println("Days: " + period.getDays());
        System.out.println("Duration in hours: " + duration.toHours());
        System.out.println("Duration in minutes: " + duration.toMinutes());
    }
}
