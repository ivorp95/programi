package vjezbe_20231019;

import java.util.Scanner;

public class Zadatak1 {
    
    public static void main(String[] args){

        int[] polje = new int[5];          //deklaracija polja - new int[11] - nova instanca objekta polje
        int suma=0, umnozak=1;

        Scanner sc=new Scanner(System.in);

        for (int i=0; i<5; i++){
            System.out.print(" Unesite " +(i+1)+". broj: ");
            polje[i]=sc.nextInt();
        }
        
        for (int i=0;i<5;i++){
            suma+=polje[i];
            umnozak=umnozak*polje[i];
        }
        System.out.println("Suma je: " +suma);
        System.out.println("Umnozak je: "+umnozak);
    }
        
}
