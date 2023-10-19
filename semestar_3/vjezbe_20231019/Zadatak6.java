package vjezbe_20231019;
import java.util.Scanner;
public class Zadatak6 {     //zadatak 28.
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        System.out.println("Unesite reenicu: ");
        String recenica=sc.nextLine();
        String nova;
       
               //umijesto razmaka ubaci \n
                nova=recenica.replaceAll( " ","\n");
        
        System.out.println(nova);
    }
}
