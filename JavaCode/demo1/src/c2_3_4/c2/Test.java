// 2026-10-28
package c2_3_4.c2;

class OuterClass
{
    private static String outerStaticField = "Outer static field";

    static class StaticInnerClass
    {
        public void display()
        {
            System.out.println("Accessing from Static Inner Class: " + outerStaticField);
            OuterClass.h1();
        }
    }

    public static void outerTest()
    {
        StaticInnerClass innerClass = new StaticInnerClass();
        innerClass.display();
    }

    public static void h1()
    {
        System.out.println("hello");
    }
}

public class Test
{
    public static void main(String[] args)
    {
        OuterClass.outerTest();
        OuterClass.StaticInnerClass inner = new OuterClass.StaticInnerClass();
        inner.display();
    }
}
