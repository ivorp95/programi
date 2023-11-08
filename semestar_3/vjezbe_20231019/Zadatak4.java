package vjezbe_20231019;

//zadatak 24.   pojavljuje li se veliko ili malo slovo 'a/A'


import java.util.Scanner;
public class Zadatak4 {
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            String rijec;
            int flag=0;

            
            System.out.println("Unesite rijec: ");
            rijec=sc.nextLine();

            for(int i=0;i<rijec.length();i++){
                if (rijec.charAt(i)=='a' || rijec.charAt(i)=='A'){
                System.out.println("Rijec sadrzi veliko ili malo slovo 'a/A'");
                flag=1;
                }
            }
            if (flag==0){
                System.out.println("Rijec ne sadrzi malo ili veliko slovo 'a/A'");
            }
        }


    }
}
