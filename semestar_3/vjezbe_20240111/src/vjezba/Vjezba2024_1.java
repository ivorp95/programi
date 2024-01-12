package vjezba;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.Scanner;

import javax.swing.JOptionPane;

// zadatak 2 drugi rok

public class Vjezba2024_1 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Unesite ime i prezime");
		
		String imePrezime = sc.nextLine();
		
		char inicijalIme=imePrezime.charAt(0);
		char inicijalPrezime = ' ';
		
		
		
		for (int i=0;i<imePrezime.length()-1;i++) {
			if((imePrezime.charAt(i)==' ') && (imePrezime.charAt(i+1) !=' ')) {
				inicijalPrezime=imePrezime.charAt(i+1);
			}
		}
		
		String inicijali = inicijalIme+""+inicijalPrezime;     /// dva char za spojiti u string moramo operator konkatenacije + spojiti sa praznim stringom ""
		
		//System.out.println(inicijalIme);
		System.out.println(inicijali);
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/ipangos?serverTimezone=UTC","ipangos","11");
			String insert="INSERT INTO kolokvijOOOP (imePrezime, inicijali) VALUES (?,?)"; 
			PreparedStatement ps=con.prepareStatement(insert);
			ps.setString(1, imePrezime);
			ps.setString(2,inicijali);
			
			ps.executeUpdate();
			JOptionPane.showMessageDialog(null, "Uspjesan unos");
		}
			
		catch (Exception e1) {
			JOptionPane.showMessageDialog(null, e1);
			e1.printStackTrace();

		}
		
		
	}
	}


// metoda split po rezmaku za pokupiti inicijale
/*

create table kolokvijOOOP (
id int auto_increment primary key not null,
imePrezime varchar(100) not null,
inicijali varchar(50) not null
);


u eclipse kliknuti dont create module kod novog java projecta
*/