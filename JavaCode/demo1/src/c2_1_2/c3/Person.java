package c2_1_2.c3;

class Person
{
    String name;

    public Person(String name)
    {
        this.name = name;
    }

    void greet(Person another)
    {
        System.out.println(this.name + " 问 " + another.name + " 打招呼!");
    }
}
