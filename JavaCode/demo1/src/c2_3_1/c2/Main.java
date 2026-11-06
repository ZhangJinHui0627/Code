// 2026-10-27
package c2_3_1.c2;

abstract class Animal
{
    abstract void sound();
}

class Dog extends Animal
{
    void sound()
    {
        System.out.println("Dog barks");
    }

    void eat()
    {
        System.out.println("Dog eat beaf");
    }
}

class Cat extends Animal
{
    void sound()
    {
        System.out.println("Cat meows");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Animal animal1 = new Dog();
        Animal animal2 = new Cat();
        animal1.sound();
        animal2.sound();
    }
}
