package c2_1_2.c2;

class Person
{
    String name;
    int age;

    public Person(String name)
    {
        this(name, 10);
    }

    public Person(String name, int age)
    {
        this.name = name;
        this.age = age;
    }

    void display()
    {
        System.out.println("姓名 : " + this.name + " , 年龄 : " + this.age);
    }
}
