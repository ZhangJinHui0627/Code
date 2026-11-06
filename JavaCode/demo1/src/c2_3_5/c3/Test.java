package c2_3_5.c3;

interface Greeting
{ //接口只有一个抽象方法, 叫它【函数式接口】, 此时匿名内部类可以简化成Lambda表达式形式
    void greet();
}

public class Test
{
    public static void main(String[] args)
    {
        // 使用 Lambda 表达式实现接口
        Greeting greeting = () -> {
            System.out.println("Hello from Lambda!");
            System.out.println("写一句话的时候才可以省略花括号");
        };
        // 连方法名、@Override、参数类型都省了, 因为编译器知道接口里只有一个抽象方法, 直接把这段代码赋给那个抽象方法
//      Greeting greeting1=new Greeting() {
//          @Override
//          public void greet() {
//              System.out.println("Hello from Lambda!");
//          }
//      };
        greeting.greet();
    }
}
