package c2_2_1.c2;

class Animal
{
    int age=2;
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

class Cat extends Animal
{
    @Override
    void sound()
    {
        System.out.println("Cat barks");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Animal animal = new Animal();
        animal.sound();

        Dog dog = new Dog();
        dog.sound();
        System.out.println(dog.age);

        Cat cat=new Cat();
        cat.sound();
    }
}
