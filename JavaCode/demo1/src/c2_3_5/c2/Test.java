package c2_3_5.c2;
// 匿名类的语法：匿名类继承类
// 使用匿名类继承 Animal 类并重写 sound 方法
class Animal
{
    public void sound()
    {
        System.out.println("Animal makes sound");
    }
}

public class Test
{
    public static void main(String[] args)
    {
        Animal animal = new Animal()
        { //定义了一个匿名内部类并继承了Animal，重写/覆盖了其方法
            @Override
            public void sound()
            {
                System.out.println("Dog barks");
            }
        };
        animal.sound();
    }
}
