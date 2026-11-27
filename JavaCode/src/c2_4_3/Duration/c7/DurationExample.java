package c2_4_3.Duration.c7;

import java.time.Duration;

public class DurationExample
{
    public static void main(String[] args)
    {
        // 创建一个持续时间为 1 小时的 Duration 对象
        Duration duration1 = Duration.ofHours(1);
        // 创建一个持续时间为 30 分钟的 Duration 对象
        Duration duration2 = Duration.ofMinutes(30);

        // 将 duration2 加到 duration1 上
        Duration combinedDuration = duration1.plus(duration2);
        System.out.println("Combined Duration (1 hour + 30 minutes): " +
                combinedDuration.toMinutes() + " Minutes");
    }
}
