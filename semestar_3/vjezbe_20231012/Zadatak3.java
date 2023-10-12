package vjezbe_20231012;
import java.util.Scanner;

//za unesini broj ispisati je li paran ili neparan

public class Zadatak3 {
    public static void main(String[] args){
    
    Scanner sc=new Scanner(System.in);
    System.out.print("Uneismo broj: ");
    int broj;
    broj=sc.nextInt();
    
    if(broj==0){
        System.out.print("Broj je nula\n");
    }
    else if (broj%2==0){
        System.out.print("Broj je paran\n");
    }
    else{
        System.out.print("Broj je naparan\n");
    }
    
    }
}
