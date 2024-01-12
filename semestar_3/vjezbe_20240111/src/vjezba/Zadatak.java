package vjezba;
import java.util.Scanner;

public class Zadatak {

	public static void main(String[] args) {
		
		Scanner sc  = new Scanner(System.in);
		
		int prviBroj, drugiBroj, rezultat;
		
		System.out.println("Unesite prvi broj: ");
		prviBroj = sc.nextInt();
		System.out.println("Unesite drugi broj: ");
		drugiBroj =sc.nextInt();
		
		rezultat = prviBroj + drugiBroj;
		
		System.out.println("Rezultat je: "+ rezultat);
		
	}

}
