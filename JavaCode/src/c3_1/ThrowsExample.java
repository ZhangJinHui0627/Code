package c3_1;

//throws 声明受检异常
import java.io.*;

public class ThrowsExample
{
    public static void readFile(String fileName) throws IOException
    {
        FileReader reader = new FileReader(fileName); //FileReader读取文本文件的类
        System.out.println("文件打开成功");
        reader.close();
        System.out.println("文件已经关闭");
    }

    public static void main(String[] args)
    {
        try
        {
            readFile("no.txt"); //传入一个没有的文件名
            //readFile("data.txt");
        }
        catch (IOException e)
        {
            System.out.println("捕获到异常: " + e.getMessage());
        }
    }
}
