package vjezbe_20231012;
import java.util.Scanner;

public class Zadatak6 {
    public static void main(String[] args){

        Scanner sc=new Scanner(System.in);
        int broj=0, i=0;


        do{
            System.out.println("Unesite broj");
            broj=sc.nextInt();
            i++;

        }while(broj%2==0);                  //radi dok je broj paran -> broj%2==0

        System.out.println("Uneseno je parnih brojeva :"+(i-1));

    }
}
