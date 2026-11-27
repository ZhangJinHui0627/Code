// 2026-10-26
package c2_2_2.c3;

class Animal
{
    void sound()
    {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal
{
    @Override
    void sound()
    {
        System.out.println("Dog barks");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Animal animal = new Dog();
        animal.sound();

        if (animal instanceof Dog)
        {
            Dog dog1 = (Dog) animal;
            dog1.sound();
        }
    }
}
