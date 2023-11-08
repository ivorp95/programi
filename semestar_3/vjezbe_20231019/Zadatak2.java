package vjezbe_20231019;

import java.util.Scanner;

public class Zadatak2 {
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            int polje[]=new int[10];
            int min=0;

            for (int i=0; i<10;i++){
                System.out.println("Unesite "+(i+1)+". broj: ");
                polje[i]=sc.nextInt();
            }

            min=polje[0];
            
            for(int i=0;i<10;i++){
                if(polje[i]<min){
                    min=polje[i];
                }
            }

            System.out.println("Minimalni broj je :"+min);
        }
    }
}
