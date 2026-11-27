// 2026-10-28
package c2_3_4.c3;

class OuterClass
{
    int a1 = 0;

    void test1()
    {
        System.out.println("外部类成员方法!");
    }

    public void createInnerClass()
    {
        final String localVarible = "Local variable";

        class LocalInnerClass
        {
            int a2 = 1;

            public void display()
            {
                System.out.println(localVarible);
                System.out.println(a1);
                test1();
            }
        }

        LocalInnerClass inner = new LocalInnerClass();
        inner.display();
        System.out.println(inner.a2);
    }
}

public class Test
{
    public static void main(String[] args)
    {
        OuterClass outer = new OuterClass();
        outer.createInnerClass();
    }
}
