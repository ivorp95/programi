package crud.src.crud;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class Update {

	public static void main(String[] args) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");					//rad sa serverom mora biti u try/catch bloku
			Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/isimac?serverTimezone=UTC","isimac","is123");	
			String upit="UPDATE ooop_simac SET godina=? WHERE id_student=4"; 
			PreparedStatement ps=con.prepareStatement(upit);
			
			ps.setInt(1, 5);
			int updateRedaka=ps.executeUpdate();
			
			if (updateRedaka==1) {
				System.out.println("Zapis je izmjenjen u bazi");
			}
			else {
				System.out.println("Doslo je do greske u izmjeni");
			}
			
		}
		catch(Exception e1) {
			System.out.println("Doslo je do greske u try bloku");
		}
	}

}
