package registracija.src.registracija;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class RegObrazac {

	private JFrame frame;
	private JTextField JIme;
	private JTextField JPrezime;
	private JTextField Jemail;
	private JTextField Jjmbag;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					RegObrazac window = new RegObrazac();
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
	public RegObrazac() {
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
		
		JIme = new JTextField();
		JIme.setBounds(200, 26, 130, 26);
		frame.getContentPane().add(JIme);
		JIme.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("Unesite Ime");
		lblNewLabel.setBounds(25, 31, 97, 16);
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Unesite Prezime");
		lblNewLabel_1.setBounds(25, 77, 120, 16);
		frame.getContentPane().add(lblNewLabel_1);
		
		JPrezime = new JTextField();
		JPrezime.setBounds(200, 72, 130, 26);
		frame.getContentPane().add(JPrezime);
		JPrezime.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("Unesite e-mail");
		lblNewLabel_2.setBounds(25, 125, 112, 16);
		frame.getContentPane().add(lblNewLabel_2);
		
		Jemail = new JTextField();
		Jemail.setBounds(200, 120, 130, 26);
		frame.getContentPane().add(Jemail);
		Jemail.setColumns(10);
		
		JLabel lblNewLabel_3 = new JLabel("Unesite JMBAG");
		lblNewLabel_3.setBounds(25, 178, 112, 16);
		frame.getContentPane().add(lblNewLabel_3);
		
		Jjmbag = new JTextField();
		Jjmbag.setBounds(200, 173, 130, 26);
		frame.getContentPane().add(Jjmbag);
		Jjmbag.setColumns(10);
		
		JButton btnRegistriraj = new JButton("Registriraj");
		btnRegistriraj.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			
			String imeS=null, prezimeS=null, emailS=null;
			long jmbagS=0;
			
			try {
				imeS=String.valueOf(JIme.getText());
				prezimeS=String.valueOf(JPrezime.getText());
			}
			catch(Exception e2){
				JOptionPane.showMessageDialog(null, "Ime, Prezime - morate unjeti string znakova");
			}

			try {
				emailS=String.valueOf(Jemail.getText());
			} catch (Exception e3) {
				
			}
			
			try {
				jmbagS=Long.parseLong(Jjmbag.getText());

				System.out.println(imeS);
				System.out.println(prezimeS);
				System.out.println(emailS);
				System.out.println(jmbagS);

				JOptionPane.showMessageDialog(null, "Uspijesno ste se registrirali");
			}
			catch(Exception e4) {
				JOptionPane.showMessageDialog(null, "JMBAG - morate unjeti brojeve");
				e4.printStackTrace();
			}
			


			}
		});
		btnRegistriraj.setBounds(200, 226, 117, 29);
		frame.getContentPane().add(btnRegistriraj);
		
	
	}
}
