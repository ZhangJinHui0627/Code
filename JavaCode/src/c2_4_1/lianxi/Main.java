package c2_4_1.lianxi;

public class Main
{
    public static void main(String[] args)
    {
        StringBuilder sb = new StringBuilder("ZhangJinHui");
        System.out.println(sb);

        sb.insert(5, "20070627");
        System.out.println(sb);

        sb.insert(9, "-");
        System.out.println(sb);

        sb.delete(5, 14);
        System.out.println(sb);
    }
}
