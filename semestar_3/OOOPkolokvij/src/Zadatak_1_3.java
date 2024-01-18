import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.awt.event.ActionEvent;

public class Zadatak_1_3 {

	private JFrame frame;
	private JTextField ime;
	private JTextField prezime;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Zadatak_1_3 window = new Zadatak_1_3();
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
	public Zadatak_1_3() {
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
		
		JLabel lblNewLabel = new JLabel("ime");
		lblNewLabel.setBounds(30, 31, 61, 16);
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("prezime");
		lblNewLabel_1.setBounds(30, 92, 61, 16);
		frame.getContentPane().add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("grad");
		lblNewLabel_2.setBounds(30, 148, 61, 16);
		frame.getContentPane().add(lblNewLabel_2);
		
		ime = new JTextField();
		ime.setBounds(194, 26, 130, 26);
		frame.getContentPane().add(ime);
		ime.setColumns(10);
		
		prezime = new JTextField();
		prezime.setBounds(194, 87, 130, 26);
		frame.getContentPane().add(prezime);
		prezime.setColumns(10);
		

		String grad1="RIjeka";
		String grad2="Zagreb";
		String grad3="Split";
		String grad4="Osjijek";
		
		JComboBox comboGrad = new JComboBox();
		comboGrad.setBounds(194, 144, 130, 27);
		frame.getContentPane().add(comboGrad);
		
		comboGrad.addItem(grad1);
		comboGrad.addItem(grad2);
		comboGrad.addItem(grad3);
		comboGrad.addItem(grad4);
		
		JButton btnNewButton = new JButton("posalji");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				try {
				String imeS, prezimeS;

				
				imeS=ime.getText();
				prezimeS=prezime.getText();
				String gradS=(String)comboGrad.getSelectedItem();
				char ZslovoIme=' ';
				char ZslovoPrezime=' ';
				
				for (int i=0;i<imeS.length()-1;i++) {
						ZslovoIme=imeS.charAt(i+1);
					}
				for (int i=0;i<prezimeS.length()-1;i++) {
					ZslovoPrezime=prezimeS.charAt(i+1);
				}
				
				String ZadnjaSlova = ZslovoIme +" "+ZslovoPrezime;
				System.out.println(ZadnjaSlova);
				
				
				Class.forName("com.mysql.cj.jdbc.Driver");
				Connection con=DriverManager.getConnection("jdbc:mysql://student.veleri.hr/ipangos?serverTimezone=UTC","ipangos","11");
				String insert="INSERT INTO registracijaKolokvij (ime, prezime, grad, Zslova) VALUES (?, ?,?,?)"; 
				PreparedStatement psInsert=con.prepareStatement(insert);
				psInsert.setString(1, imeS);
				psInsert.setString(2, prezimeS);
				psInsert.setString(3, gradS);
				psInsert.setString(4, ZadnjaSlova);
				
			/*
			 * create table registracijaKolokvij(
					id int(5) auto_increment primary key not null,
					ime varchar(50) not null,
					prezime varchar(100) not null,
					grad varchar(50) not null,
					Zslova varchar(10) not null
					);
			 * 
			 */
				
				
				int ubacenoRedaka=psInsert.executeUpdate();
				if(ubacenoRedaka==1) {
					JOptionPane.showMessageDialog(null, "Registracija uspjesna");
				}
				else {
					JOptionPane.showMessageDialog(null, "Registracija neuspjesna");
				}
				
				
				}
				catch (Exception e1) {
					JOptionPane.showMessageDialog(null, "Doslo je do greske u povezivanju sa bazom u try bloku");
					e1.printStackTrace();
				}
				

				
			}
		});
		btnNewButton.setBounds(194, 217, 117, 29);
		frame.getContentPane().add(btnNewButton);
	}
}
