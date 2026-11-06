// 2026-10-27
package c2_3_1.c3;

interface AnimalBehavior
{
    void sound();
}

abstract class Animal implements AnimalBehavior
{
    abstract void eat();
}

class Dog extends Animal
{
    @Override
    public void sound()
    {
        System.out.println("Dog barks");
    }

    @Override
    void eat()
    {
        System.out.println("Dog eats");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Dog dog = new Dog();
        dog.sound();
        dog.eat();
    }
}
