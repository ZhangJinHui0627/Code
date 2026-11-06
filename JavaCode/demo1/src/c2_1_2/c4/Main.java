// 2026-10-14
package c2_1_2.c4;

class MathUtils
{
    public int square(int number)
    {
        return number * number;
    }

    public static int add(int a, int b)
    {
        return a + b;
    }
}

public class Main
{
    public static void main(String[] args)
    {
        MathUtils math = new MathUtils();
        System.out.println(math.square(5));
        System.out.println(MathUtils.add(3, 4));
    }
}
