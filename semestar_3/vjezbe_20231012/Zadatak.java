package vjezbe_20231012;
import java.util.Scanner;

public class Zadatak {          //Klase se zovu isitim imenom kao i file, obavezno velikim pocetnim slovom
    
    public static void main(String[] args){

        int broj1, broj2, rezultat;

        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("unesite prvi broj:");
            broj1 = sc.nextInt();                               //metoda koja povlaci unos sa stdin

            System.out.println("unesite drugi broj:");
            broj2= sc.nextInt();
        }
        rezultat=broj1+broj2;

        System.out.println("Rezultat je: " + rezultat);

    }
}
