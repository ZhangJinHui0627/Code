package c2_1_2.c1;

public class Main
{
    public static void main(String[] args)
    {
        Employee emp1 = new Employee();
        Employee emp2 = new Employee();

        emp1.name = "张三";
        emp1.age = 25;
        emp2.name = "李四";
        emp2.age = 30;

        Employee.company = "XYZ 科技";

        emp1.displayInfo();
        emp2.displayInfo();
    }
}
