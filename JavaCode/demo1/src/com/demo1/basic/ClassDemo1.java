package com.demo1.basic;

public class ClassDemo1
{
    private int instanceVar = 5;

    public void method1()
    {
        System.out.println("Inside method1,instanceVar:" + instanceVar);
    }

    public void method2()
    {
        System.out.println("Inside method2,instanceVar:" + instanceVar);
    }

    public static void main(String[] args)
    {
        ClassDemo1 example1 = new ClassDemo1();
        example1.method1();

        example1.method2();
    }
}
