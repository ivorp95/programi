package vjezbe_20231012;

import java.util.Scanner;

public class Zadatak4 {
    public static void main(String[] args){

        Scanner sc=new Scanner(System.in);

        int broj;

        System.out.print("Unesimo bilo koji cijeli broj: ");
        broj=sc.nextInt();

        while(broj!=0){
            System.out.println(broj%10);        //modulo
            broj=broj/10;                       //djeljenje
        }

    }
}
