package vjezbe_20231012;
import java.util.Scanner;

public class Zadatak2 {
    public static void main(String[] args){

        Scanner sc=new Scanner(System.in);

        double broj1, broj2, broj3, as;

        System.out.println("Unseite prvi broj:");
        broj1=sc.nextInt();

        System.out.println("Unseite drugi broj:");
        broj2=sc.nextInt();

        System.out.println("Unseite treci broj:");
        broj3=sc.nextInt();

        as = ( broj1 + broj2 + broj3)/3;


        System.out.printf("Aritmeticka sredina: %.4f\n", as);         // System.out.printf -- print formated ("%.xf",varijabla)  kao u C



    }
}
