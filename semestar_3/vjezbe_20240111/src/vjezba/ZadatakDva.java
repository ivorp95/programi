package vjezbe_20240111.src.vjezba;
import java.util.Scanner;

public class ZadatakDva {

	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);
		
		double broj1, broj2, broj3, as;
		
		System.out.println("Unesite prvi broj: ");
		broj1 = sc.nextInt();
		System.out.println("Unesite drugi broj: ");
		broj2 = sc.nextInt();
		System.out.println("Unesite treci broj: ");
		broj3 = sc.nextInt();
		
		as = (broj1+broj2+broj3)/3;
		
		System.out.printf("Aritmeticka sredina: %.3f", as);
		
	}

}
