package com.demo1.basic;

public class ClassDemo2
{
    public static void main(String[] args)
    {
        int a = 10, b = 5, c = 20;
        int result1 = a + b * c;
        System.out.println("result1=a+b*c=" + result1);
        int result2 = (a + b) * c;
        System.out.println("result2=(a+b)*c=" + result2);
        boolean result3 = a > b && c > a;
        System.out.println("result3=a>b&&c>a=" + result3);
        int result4 = a + (b * c) / (c - a);
        System.out.println("result4=a+b*c/(c-a)=" + result4);
        boolean result5 = a > b || c < a;
        System.out.println("result5=a>b||c<a=" + result5);
        int result6 = 5 + 3;
        result6 *= 2;
        System.out.println("result6 *= 2 = " + result6);
    }
}
