package crud.src.crud; // READ - SELECT
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

// za stavranje baze na student.veleri.hr:3306   CREATE_TABLE ooop_pangos( id_student INT PRIMARY KEY AUTO_INCREMENT NOT NULL, ime VARCHAR(30) NOT NULL, prezime VARCHAR(50) NOT NULL, godina INT NOT NULL ); DESCRIBE ooop_pangos;


public class Select {				// SELECT *(sve) FROM tablica / SELECT ime, prezime, .... FROM tablica

	public static void main(String[] args) {
		
		try {
		Class.forName("com.mysql.jdbc.Driver");					//rad sa serverom mora biti u try/catch bloku
		}
		catch (Exception e2){

		}


		try{
		Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/ipangos?serverTimezone=UTC","ipangos","11");			//Connection klasa  con Objekt spajanje na sql server - serverTimezone=UTC da bi vrijeme lokalno i na serveru bilo isto
		String upit="SELECT * FROM ooop_pangos";
		PreparedStatement ps=con.prepareStatement(upit);
		ResultSet rs=ps.executeQuery();
		
		if(!rs.next()){
			System.out.println("Nisu dohvaceni podatci");
		}
		else{
			while (rs.next()){ 
			System.out.println(rs.getInt(1));
			System.out.println(rs.getString(2));
			System.out.println(rs.getString(3));
			System.out.println(rs.getInt(4));
			}
		}
		
		}
		catch(Exception e1) {
			System.out.println("Doslo je do greske u try bloku");
		}

	}

}
