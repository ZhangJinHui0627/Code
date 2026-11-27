package c2_1_2.c1;

class Employee
{
    String name;
    int age;

    static String company = "ABC 科技";

    void displayInfo()
    {
        System.out.println("员工姓名 :" + name + " , 年龄 : " + age + " , 公司 : " + company);
    }
}
