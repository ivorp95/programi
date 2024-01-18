import java.util.Scanner;
import java.sql.*;

public class Zadatak2 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Unesite recenicu:");
		
		String recenica = sc.nextLine();
		int indexZadnji=0;
		
		for (int i=0; i<=recenica.length()-1;i++) {
			
			if(recenica.charAt(i)=='a') {
				indexZadnji = i+1;
			}

		}
		System.out.println(indexZadnji);
		
		
		
		
	}
}
