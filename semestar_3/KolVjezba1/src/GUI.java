
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class GUI {

	private JFrame frame;
	private JTextField recenica;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI window = new GUI();
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
	public GUI() {
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
		
		JLabel label = new JLabel("UNESI RECENICU");
		label.setBounds(166, 36, 158, 16);
		frame.getContentPane().add(label);
		
		recenica = new JTextField();
		recenica.setBounds(49, 87, 359, 26);
		frame.getContentPane().add(recenica);
		recenica.setColumns(10);
		
		JButton btnNewButton = new JButton("POSALJI");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				String recenicas=null;
				recenicas = recenica.getText();
				//JOptionPane.showMessageDialog(null, recenicas);
				
				int recenicasBezRazmaka = recenicas.replace(" ", "").length();
				String recenicasBezRazmakaS = recenicas.replace(" ", "");
				
					if (recenicasBezRazmaka%2!=0) {
						JOptionPane.showMessageDialog(null, "Recenica ima neparan broj slova");
						//System.out.println("Recenica ima neparan broj slova");
					}
					else {
						for(int i =0; i<=recenicasBezRazmaka;i++) {
							if (recenicasBezRazmakaS.charAt(i)=='a') {
								JOptionPane.showMessageDialog(null, "Upisati u bazu broj :"+(i+1));
								
							}
						}
						
						
						//System.out.println("Recenica ima neparan broj slova");
					}
				
				
				
				
			}
		});
		btnNewButton.setBounds(166, 163, 117, 29);
		frame.getContentPane().add(btnNewButton);
		
		
	}
		///////////////////////////////////////////////////////////////////////////////////////// kako bi mogli doci do metode showWindow iz drugih klasa
			public void showWindow(){
			frame.setVisible(true);
			}
}
