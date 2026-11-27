// 2026-10-28
package c2_3_2.c2;

interface Animal
{
    void sound();

    int AGE_ANIMAL = 5;
}

class Dog implements Animal
{
    @Override
    public void sound()
    {
        System.out.println("Dog barks");
    }
}

class Cat implements Animal
{
    @Override
    public void sound()
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
        System.out.println(Animal.AGE_ANIMAL);
    }
}
