package crud.src.crud;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class Delete {

	public static void main(String[] args) {
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");					//rad sa serverom mora biti u try/catch bloku
			Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/isimac?serverTimezone=UTC","isimac","is123");	
			String upit="DELETE FROM ooop_simac WHERE id_student=5"; 
			PreparedStatement ps=con.prepareStatement(upit);
			
			int deleteRedaka=ps.executeUpdate();
			
			if (deleteRedaka==1) {
				System.out.println("Zapis je izbrisan u bazi");
			}
			else {
				System.out.println("Doslo je do greske u brisanju");
			}
			
		}
		catch(Exception e1) {
			System.out.println("Doslo je do greske u try bloku");
		}
	}

}
