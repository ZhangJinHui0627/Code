package c2_1_2.c5;

class Person
{
    private String name;
    private int age;

    public Person setName(String name)
    {
        this.name = name;
        return this;
    }

    public Person setAge(int age)
    {
        this.age = age;
        return this;
    }

    public void display()
    {
        System.out.println("姓名 : " + this.name + " , 年龄 : " + this.age);
    }
}
