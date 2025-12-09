package grafica;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtName;
	private JTextField txtAge;
    JLabel lblInfo;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainFrame frame = new MainFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});}

	/**
	 * Create the frame.
	 */
	public MainFrame() {
		setTitle("Demo");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Introdu numele");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblNewLabel.setBounds(25, 10, 84, 12);
		contentPane.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Introdu varsta");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblNewLabel_1.setBounds(25, 54, 84, 16);
		contentPane.add(lblNewLabel_1);
		
		txtName = new JTextField();
		txtName.setBounds(119, 8, 96, 18);
		contentPane.add(txtName);
		txtName.setColumns(10);
		txtAge = new JTextField();
		txtAge.setBounds(119, 52, 96, 18);
		contentPane.add(txtAge);
		txtAge.setColumns(10);
		
		JButton btnOk = new JButton("Ok");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String n=txtName.getText();
				txtAge.getText();
				int age=Integer.parseInt(txtAge.getText());
				if(age>=18)
					lblInfo.setText(n + " Esti eligil sa votezi!");
				else
					lblInfo.setText(n + " Nu esti eligil sa votezi!");
			}
		});
		btnOk.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnOk.setBounds(25, 93, 84, 20);
		contentPane.add(btnOk);
		
		JButton btnReset = new JButton("Reset");
		btnReset.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				txtName.setText("");
				txtAge.setText("");
				lblInfo.setText("");
			}
		});
		btnReset.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnReset.setBounds(198, 93, 84, 20);
		contentPane.add(btnReset);
		
		lblInfo = new JLabel("");
		lblInfo.setBounds(89, 185, 193, 12);
		contentPane.add(lblInfo);
	}}
