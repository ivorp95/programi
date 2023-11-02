package crud.src.crud;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;


public class Insert {
	public static void main(String[] args) {
		
		try {
		Class.forName("com.mysql.cj.jdbc.Driver");					//rad sa serverom mora biti u try/catch bloku
		Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/isimac?serverTimezone=UTC","isimac","is123");			//Connection klasa  con Objekt spajanje na sql server - serverTimezone=UTC da bi vrijeme lokalno i na serveru bilo isto
		String upit="INSERT INTO ooop_simac(ime,prezime,godina) VALUES (?,?,?)"; 			//upitnici odgovarnju broju u ps.set
		PreparedStatement ps=con.prepareStatement(upit);
		
		ps.setString(1, "Ivor"); //prvi upitnik
		ps.setString(2, "Pangos");		//drugi upitnik
		ps.setInt(3, 2);		//treci upitnik
		
		int ubacenoRedaka=ps.executeUpdate();
		if (ubacenoRedaka==1) {
			System.out.println("Zapis je ubacen u bazu");
		}
		else {
			System.out.println("Doslo je do greske u upisivanju");
		}
		}
		catch(Exception e1) {
			System.out.println("Doslo je do greske u try bloku");
		}
	}
}
