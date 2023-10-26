package vjezbe_20231026;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Kalk {

	private JFrame frame;
	private JTextField broj1;
	private JTextField broj2;
	private JTextField rezultat;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Kalk window = new Kalk();
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
	public Kalk() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 445, 428);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("unesite broj");
		lblNewLabel.setBounds(59, 65, 86, 14);
		frame.getContentPane().add(lblNewLabel);
		
		broj1 = new JTextField();
		broj1.setBounds(208, 62, 86, 20);
		frame.getContentPane().add(broj1);
		broj1.setColumns(10);
		
		JComboBox combo = new JComboBox();
		combo.setModel(new DefaultComboBoxModel(new String[] {"+", "-", "*", "/"}));
		combo.setBounds(208, 104, 86, 22);
		frame.getContentPane().add(combo);
		
		JLabel lblNewLabel_1 = new JLabel("unesite drugi broj");
		lblNewLabel_1.setBounds(59, 146, 108, 14);
		frame.getContentPane().add(lblNewLabel_1);
		
		broj2 = new JTextField();
		broj2.setBounds(208, 143, 86, 20);
		frame.getContentPane().add(broj2);
		broj2.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("rezultat");
		lblNewLabel_2.setBounds(59, 234, 46, 14);
		frame.getContentPane().add(lblNewLabel_2);
		
		rezultat = new JTextField();
		rezultat.setBounds(208, 231, 86, 20);
		frame.getContentPane().add(rezultat);
		rezultat.setColumns(10);
		
		JButton btnNewButton = new JButton("izracunaj");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				float broj1S=0,broj2S=0,rezultatS;
				String comboS;
				
				try {
					broj1S=Integer.parseInt(broj1.getText());
					broj2S=Integer.parseInt(broj2.getText());
				}
				catch (Exception e2){
					//System.out.println(e2);
					JOptionPane.showMessageDialog(null, "morate unjeti broj");
				}
				
				
				comboS=(String) combo.getSelectedItem();
				
				switch(comboS) {
					case "+":
						rezultatS=broj1S+broj2S;
						rezultat.setText(String.valueOf(rezultatS));
						break;
					case "-":
						rezultatS=broj1S-broj2S;
						rezultat.setText(String.valueOf(rezultatS));
						break;
					case "*":
						rezultatS=broj1S*broj2S;
						rezultat.setText(String.valueOf(rezultatS));
						break;
					case "/":
						try {							//try catch blok 
							rezultatS=broj1S/broj2S;
							rezultat.setText(String.valueOf(rezultatS));
							break;
						}
						catch(Exception e1){		//klasa Exception objekt e1  ispisuje sistemsku gresku
							//System.out.println(e1);
							JOptionPane.showMessageDialog(null, "djeljenje nulom nije moguce");
						}
						
				
					
				}
			}
		});
		btnNewButton.setBounds(208, 185, 89, 23);
		frame.getContentPane().add(btnNewButton);
	}
}
