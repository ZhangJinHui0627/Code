package c2_3_4.c4;
//匿名内部类实现接口
interface Greeting
{
    void greet();
}

public class Test
{
    public static void main(String[] args)
    {
        //new Greeting() { ... } 并不是在“创建接口对象”,而是编译器先偷偷生成一个类;再 new 这个实现类的对象,并立刻向上转型为 Greeting 类型.
        Greeting greeting = new Greeting()
        { //接口不能 new, new 的是“匿名实现类”
            @Override
            public void greet()
            {
                System.out.println("Hello from Anonymous Inner Class!");
            }
        };

        greeting.greet();
    }
}
