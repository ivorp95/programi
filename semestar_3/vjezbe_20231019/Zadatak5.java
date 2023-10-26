package vjezbe_20231019;
import java.util.Scanner;
public class Zadatak5 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Unesite recenicu: ");
        String recenica=sc.nextLine();
        char zadnjeSlovo=recenica.charAt(recenica.length()-1);

        System.out.println("Zadnje slovo je: "+zadnjeSlovo);
    }
}
