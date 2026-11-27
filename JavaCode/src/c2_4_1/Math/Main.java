package c2_4_1.Math;

public class Main
{
    public static void main(String[] args)
    {
        int absVal = Math.abs(-5); // absVal = 5
        double absVal2 = Math.abs(-3.14); // absVal2 = 3.14
        System.out.println(absVal);
        System.out.println(absVal2);

        int maxVal = Math.max(3, 7); // maxVal = 7
        int minVal = Math.min(3, 7); // minVal = 3
        System.out.println("max="+maxVal);
        System.out.println("min="+minVal);

        double sqrtVal = Math.sqrt(16); // sqrtVal = 4.0
        System.out.println(sqrtVal);

        double powerVal = Math.pow(2, 3); // powerVal = 8.0 (2^3)
        System.out.println(powerVal);

        double randVal = Math.random(); // 例如: 0.264559385294896
        System.out.println(randVal);

        double ceilVal = Math.ceil(3.14); // ceilVal = 4.0
        System.out.println(ceilVal);

        double floorVal = Math.floor(3.84); // floorVal = 3.0
        System.out.println(floorVal);

        long roundVal = Math.round(3.6); // roundVal = 4
        System.out.println(roundVal);

        double piVal = Math.PI; // piVal = 3.141592653589793
        System.out.println(piVal);

        double eVal = Math.E; // eVal = 2.718281828459045
        System.out.println(eVal);
    }
}
