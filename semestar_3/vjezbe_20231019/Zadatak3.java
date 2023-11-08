package vjezbe_20231019;

import java.util.Scanner;

public class Zadatak3 {
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            String zankovi;
            int brojac=0;

            System.out.print("Unesi recenicu: ");
            zankovi=sc.nextLine();  //sc.nextLine  za unos stringa

            // metoda 'contains' za utvrdjivanje postojanja znaga

            //charAt ide po indexu stringa

            for (int i=0;i<zankovi.length();i++){

                if (zankovi.charAt(i)=='a'){
                    brojac++;
                    }
            }
            System.out.println(brojac);
        }
    }
}
