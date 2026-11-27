package com.demo1.basic;

public class ArrayDemo
{
    public static void main(String[] args)
    {
        int[] scores = {77, 85, 90, 60, 95};

        System.out.println("--- 普通for循环遍历 ---");
        for (int i = 0; i < scores.length; i++)
        {
            System.out.println("scores[" + i + "] = " + scores[i]);
        }

        System.out.println("--- 增强for循环遍历 ---");
        for (int score : scores)
        {
            System.out.println(score);
        }

        int min = scores[0];
        for (int i = 1; i < scores.length; i++)
        {
            if (scores[i] < min)
            {
                min = scores[i];
            }
        }
        System.out.println("最小值是：" + min);
    }
}
