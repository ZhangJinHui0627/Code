// 2026-10-27
package c2_3_1.c1;

abstract class Animal
{
    String name;

    void eat()
    {
        System.out.println(name + " is eating.");
    }

    abstract void sound();
}

class Dog extends Animal
{
    Dog(String name)
    {
        this.name = name;
    }

    @Override
    void sound()
    {
        System.out.println(name + " barks.");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Dog dog = new Dog("Buddy");
        dog.eat();
        dog.sound();
    }
}
