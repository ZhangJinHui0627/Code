package c3_1;

//throw 主动抛异常
public class ThrowExample
{
    public static void checkNumber(int number)
    {
        if (number < 0)
        {
            throw new IllegalArgumentException("数字不能为负数！"); //手动抛出异常，调用checkNumber方法进行try catch捕获异常
        }
    }

    public static void main(String[] args)
    {
        try
        {
            checkNumber(5);
            System.out.println("无异常的之后才会成功输出！");
        }
        catch (IllegalArgumentException e)
        {
            System.out.println("捕获到异常：" + e.getMessage());
        }
    }
}
