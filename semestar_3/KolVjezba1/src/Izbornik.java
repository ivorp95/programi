package KolVjezba1.src;


import java.util.Scanner;



public class Izbornik {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		String izbor=null;
		
		while(izbor !=  "c") {
		System.out.println("Izbornik: ");
		
		izbor = sc.next();
		
		
		switch (izbor) {
		case "a":
			System.out.println("case a: Zadatak 1");
			String IBAN = null;
			Scanner sc1 = new Scanner(System.in);
			
			
			do {
				System.out.println("UNESITE IBAN :");
				IBAN = sc1.next();
					if (IBAN.charAt(0)!='H' || IBAN.charAt(1)!='R' || IBAN.length()!=21) {
					System.out.println("Nije pravilan:");
					}
					else {
						System.out.println("IBAN je u redu");
					}
			}while(IBAN.charAt(0)!='H' || IBAN.charAt(1)!='R' || IBAN.length()!=21 );
			
			break;	
			
		case "b":
			System.out.println("case b: Zadatak 2");
			GUI novi = new GUI();
			novi.showWindow();
			
			break;
			
			
		case "c":
			//System.out.println("case c");
			izbor="c";
			break;
				
		default:
			System.out.println("krivi odabir, c za izlaz");
			break;
			}
		
		
		}
	}

}
