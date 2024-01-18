package vjezba;

import java.awt.EventQueue;
import java.sql.*;


import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.awt.event.ActionEvent;
import javax.swing.JPasswordField;

public class GUI_vjezbaKol {

	private JFrame frame;
	private JTextField korisnikIme;
	private JTextField email;
	private JPasswordField lozinka;
	private JPasswordField lozinkaPonovo;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI_vjezbaKol window = new GUI_vjezbaKol();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public GUI_vjezbaKol() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("username");
		lblNewLabel.setBounds(33, 40, 61, 16);
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("e-mail");
		lblNewLabel_1.setBounds(33, 91, 61, 16);
		frame.getContentPane().add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("password");
		lblNewLabel_2.setBounds(33, 147, 61, 16);
		frame.getContentPane().add(lblNewLabel_2);
		
		JLabel lblNewLabel_3 = new JLabel("repeatPassw");
		lblNewLabel_3.setBounds(33, 201, 88, 16);
		frame.getContentPane().add(lblNewLabel_3);
		
		korisnikIme = new JTextField();
		korisnikIme.setBounds(151, 35, 130, 26);
		frame.getContentPane().add(korisnikIme);
		korisnikIme.setColumns(10);
		
		email = new JTextField();
		email.setBounds(151, 91, 130, 26);
		frame.getContentPane().add(email);
		email.setColumns(10);
		
		lozinka = new JPasswordField();
		lozinka.setBounds(151, 142, 130, 26);
		frame.getContentPane().add(lozinka);
		
		lozinkaPonovo = new JPasswordField();
		lozinkaPonovo.setBounds(151, 196, 130, 26);
		frame.getContentPane().add(lozinkaPonovo);
		
		JButton btnNewButton = new JButton("registriraj");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				String korisnikImeS, emailS, lozinkaS, lozinkaPonovoS;
				
				korisnikImeS = korisnikIme.getText();
				emailS=email.getText();
				
				lozinkaS=new String (lozinka.getPassword());
				lozinkaPonovoS=new String (lozinkaPonovo.getPassword());
				
				if(lozinkaS.equals(lozinkaPonovoS)) {
					
				
					try {
						
						/*
						 * create table registracijaVjezba(	
								id int(5) auto_increment primary key not null,
								korisnikIme varchar(50) not null unique,
								email varchar(100) not null unique,
								lozinka varchar(50) not null
								);

							select * from registracijaVjezba;
						 * 
						 */
						Class.forName("com.mysql.cj.jdbc.Driver");
						Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/ipangos?serverTimezone=UTC","ipangos","11");
						String upit="SELECT * FROM registracijaVjezba WHERE korisnikIme=? OR email=?";
						PreparedStatement ps=con.prepareStatement(upit);
						ps.setString(1, korisnikImeS);	//provjera ako u bazi ima vec 
						ps.setString(2, emailS);	
						ResultSet rs=ps.executeQuery();
						
						if(rs.next()) {
							JOptionPane.showMessageDialog(null, "Registracija nije moguca, korisnik sa tim imenom ili email-om vec postoji");
						}
						
						else {
						String insert="INSERT INTO registracijaVjezba (korisnikIme,email,lozinka) VALUES (?,?,?)"; 
						PreparedStatement psInsert=con.prepareStatement(insert);
						psInsert.setString(1, korisnikImeS);
						psInsert.setString(2, emailS);
						psInsert.setString(3, lozinkaS);
						
						
						int ubacenoRedaka=psInsert.executeUpdate();
							if(ubacenoRedaka==1) {
								JOptionPane.showMessageDialog(null, "Registracija uspjesna");
							}
							else {
								JOptionPane.showMessageDialog(null, "Registracija neuspjesna");
							}
						}
						
						
						
					}
					catch(Exception e1) {
						JOptionPane.showMessageDialog(null, "Doslo je do greske u povezivanju sa bazom bloku");
						e1.printStackTrace();
					}
					
					
					
				}
				else {
					JOptionPane.showMessageDialog(null, "Lozinke nisu jednake");
				}
				
		}
		});
		btnNewButton.setBounds(314, 104, 117, 29);
		frame.getContentPane().add(btnNewButton);
		

	}
}
