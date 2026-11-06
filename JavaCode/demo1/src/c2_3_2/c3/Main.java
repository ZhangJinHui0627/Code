// 2026-10-28
package c2_3_2.c3;

interface Student
{
    default void aa()
    {
        System.out.println("接口中的普通方法!");
    }

    static void bb()
    {
        System.out.println("接口中的静态方法!");
    }

    void cc();
}

class Test implements Student
{
    @Override
    public void cc()
    {
        System.out.println("实现的接口中的抽象方法!");
    }

    @Override
    public void aa()
    {
        System.out.println("重写接口中的普通方法!");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Test t1 = new Test();
        t1.aa();
        t1.cc();
        Student.bb();
    }
}
