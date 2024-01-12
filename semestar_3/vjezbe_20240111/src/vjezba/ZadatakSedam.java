package vjezba;
import java.util.Scanner;

public class ZadatakSedam {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		double broj, suma=0;
		int brojac=0;
		
		
		
		System.out.println("Unesite broj (0 za prekid): ");
		broj=sc.nextInt();
		
		while(broj != 0) {
			
			suma += broj;
			brojac++;
			
			System.out.println("Unesite broj (0 za prekid): ");
			broj=sc.nextInt();
			
		}
		
		System.out.printf("Aritmeticka sredina je: "+(suma/brojac));
	}

}
