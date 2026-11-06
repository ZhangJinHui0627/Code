// 2026-10-26
package c2_2_2.c4;

class Animal
{
    String name = "动物";

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

    void eat()
    {
        System.out.println("Dog eat!");
    }

    String color = "red";
}

public class Main
{
    public static void main(String[] args)
    {
        Animal animal1 = new Dog();
        animal1.sound();
        System.out.println(animal1.name);

        if (animal1 instanceof Dog)
        {
            Dog dog1 = (Dog) animal1;
            dog1.eat();
            System.out.println(dog1.color);
            dog1.sound();
        }
    }
}
