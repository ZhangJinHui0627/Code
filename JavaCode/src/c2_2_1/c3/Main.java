package c2_2_1.c3;

class Animal
{
    String name;

    public Animal() { System.out.println("Animal Constructor"); }

    public Animal(String name){this.name=name;}

    void eat() { System.out.println("Animal eats"); }
}

class Dog extends Animal
{
    public Dog()
    {
        super();
        System.out.println("Dog Constructor");
    }

    public Dog(String name)
    {
        super(name);
    }

    @Override
    void eat()
    {
        super.eat();
        System.out.println("Dog eats");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Dog dog = new Dog();
        dog.eat();
        Dog dog1=new Dog("小黄");
        System.out.println(dog1.name);
    }
}
