package vjezbe_20231012;

import java.util.Scanner;

public class Zadatak7 {
        public static void main(String[] args){

        Scanner sc=new Scanner(System.in);

        double broj,suma=0;
        int brojac=0;

        System.out.println("Unesite broj, nula prekida unos");
        broj=sc.nextInt();

        while(broj!=0){
            suma+=broj;
            brojac++;
            System.out.println("Unesite broj, nula prekida unos");
            broj=sc.nextInt();
        }

        System.out.println("Aritmeticka sredina je :" +(suma/brojac));
    }
}
