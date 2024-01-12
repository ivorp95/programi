package vjezbe_20240111.src.vjezba;
import java.util.Scanner;

public class ZadatakSesnaest {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int broj, brojac=0;
		
		do {
			
			System.out.println("Unesite broj: ");
			broj = sc.nextInt();
			
			brojac++;
			
		}while(broj % 2 == 0);
		
		System.out.println(brojac-1);

	}

}
