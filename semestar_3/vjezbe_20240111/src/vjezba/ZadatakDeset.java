package vjezba;
import java.util.Scanner;

public class ZadatakDeset {

	public static void main(String[] args) {

		Scanner sc = new Scanner (System.in);
		
		int broj;
		
		System.out.println("Unesite broj: ");
		broj = sc.nextInt();
		
		while(broj != 0) {
			
			System.out.println(broj%10);
			broj=broj/10;
			
		}


	}

}
