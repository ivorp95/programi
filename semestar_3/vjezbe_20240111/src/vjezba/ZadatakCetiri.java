package vjezbe_20240111.src.vjezba;
import java.util.Scanner;

public class ZadatakCetiri {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner (System.in);
		
		int broj;
		
		System.out.print("Unesite broj: ");
		broj = sc.nextInt();
		
		if(broj == 0) {
			System.out.println("Broj je nula.");
		}else if(broj % 2 == 0) {
			System.out.println("Broj je paran.");
		}else {
			System.out.println("Broj je neparan.");
		}
		
	}

}
