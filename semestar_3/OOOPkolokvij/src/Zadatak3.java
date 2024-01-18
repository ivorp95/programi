import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.swing.JOptionPane;

public class Zadatak3 {

	public static void main(String[] args) {
		int i=0;
		

		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/ipangos?serverTimezone=UTC","ipangos","11");
			String upit="SELECT * FROM registracijaKolokvij ORDER BY id DESC LIMIT 1";
			Statement stmt=con.createStatement();
			ResultSet rs=stmt.executeQuery(upit);
			
			while (rs.next()){
				i++;
				int id = rs.getInt(1);
				String ime=rs.getString(2);
				String prezime=rs.getString(3);
				String grad=rs.getString(4);
				String ZadnjaSlova=rs.getString(5);
				
				System.out.println("ime:  "+ime+"               prezime:  "+prezime+ "                 Grad:   "+grad+"                  Zadnja slova:  "+ZadnjaSlova);
				}


			
		}
		catch (Exception e2) {
			JOptionPane.showMessageDialog(null, "Doslo je do greske u ispisu iz baze");
			e2.printStackTrace();
		}
		

	}

}
