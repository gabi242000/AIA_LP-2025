package grafica;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.BorderLayout;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;

public class calculator {

	private JFrame CALCULATOR;
	private JTextField textField;
	double first;
	double second;
	double result;
	String operation;
	String answer;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					calculator window = new calculator();
					window.CALCULATOR.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public calculator() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		CALCULATOR = new JFrame();
		CALCULATOR.setTitle("Calculator");
		CALCULATOR.setBounds(100, 100, 384, 484);
		CALCULATOR.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		CALCULATOR.getContentPane().setLayout(null);
		
		textField = new JTextField();
		textField.setFont(new Font("Tahoma", Font.BOLD, 12));
		textField.setBounds(10, 22, 350, 83);
		CALCULATOR.getContentPane().add(textField);
		textField.setColumns(10);
		
		JButton btnPercent = new JButton("%");
		btnPercent.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnPercent.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(textField.getText());
				textField.setText("");
				operation="%";;
			}
		});
		btnPercent.setBounds(275, 383, 85, 54);
		CALCULATOR.getContentPane().add(btnPercent);
		
		JButton btn7 = new JButton("7");
		btn7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn7.getText();
				textField.setText(number);
			}
		});
		btn7.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn7.setBounds(10, 198, 85, 54);
		CALCULATOR.getContentPane().add(btn7);
		
		JButton btn4 = new JButton("4");
		btn4.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn4.getText();
				textField.setText(number);
			}
		});
		btn4.setBounds(10, 257, 85, 54);
		CALCULATOR.getContentPane().add(btn4);
		
		JButton btn1 = new JButton("1");
		btn1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn1.getText();
				textField.setText(number);
			}
		});
		btn1.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn1.setBounds(10, 321, 85, 54);
		CALCULATOR.getContentPane().add(btn1);
		
		JButton btn0 = new JButton("0");
		btn0.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn0.getText();
				textField.setText(number);
			}
		});
		btn0.setBounds(10, 383, 85, 54);
		CALCULATOR.getContentPane().add(btn0);
		
		JButton btnBack = new JButton("\uF0E7");
		btnBack.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String backSpace=null;
				if(textField.getText().length()>0);
				{
					StringBuilder str=new StringBuilder(textField.getText());
					str.deleteCharAt(textField.getText().length()-1);
					backSpace=str.toString();
					textField.setText(backSpace);
				}
				
			}
		});
		btnBack.setFont(new Font("Windings", Font.BOLD, 12));
		btnBack.setBounds(10, 134, 85, 54);
		CALCULATOR.getContentPane().add(btnBack);
		
		JButton btn8 = new JButton("8");
		btn8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn8.getText();
				textField.setText(number);
			}
		});
		btn8.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn8.setBounds(97, 198, 85, 54);
		CALCULATOR.getContentPane().add(btn8);
		
		JButton btn5 = new JButton("5");
		btn5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn5.getText();
				textField.setText(number);
			}
		});
		btn5.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn5.setBounds(97, 257, 85, 54);
		CALCULATOR.getContentPane().add(btn5);
		
		JButton btn2 = new JButton("2");
		btn2.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn2.getText();
				textField.setText(number);
			}
		});
		btn2.setBounds(97, 321, 85, 54);
		CALCULATOR.getContentPane().add(btn2);
		
		JButton btn00 = new JButton("00");
		btn00.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn00.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn00.getText();
				textField.setText(number);
			}
		});
		btn00.setBounds(188, 134, 85, 54);
		CALCULATOR.getContentPane().add(btn00);
		
		JButton btnClear = new JButton("C");
		btnClear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(null);
			}
		});
		btnClear.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnClear.setBounds(97, 134, 85, 54);
		CALCULATOR.getContentPane().add(btnClear);
		
		JButton btn9 = new JButton("9");
		btn9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn9.getText();
				textField.setText(number);
			}
		});
		btn9.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn9.setBounds(188, 198, 85, 54);
		CALCULATOR.getContentPane().add(btn9);
		
		JButton btn6 = new JButton("6");
		btn6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn6.getText();
				textField.setText(number);
			}
		});
		btn6.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn6.setBounds(188, 257, 85, 54);
		CALCULATOR.getContentPane().add(btn6);
		
		JButton btn3 = new JButton("3");
		btn3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btn3.getText();
				textField.setText(number);
			}
		});
		btn3.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn3.setBounds(188, 321, 85, 54);
		CALCULATOR.getContentPane().add(btn3);
		JButton btnDot = new JButton(".");
		btnDot.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String number=textField.getText()+btnDot.getText();
				textField.setText(number);
			}
		});
		btnDot.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnDot.setBounds(97, 383, 85, 54);
		CALCULATOR.getContentPane().add(btnDot);
		
		JButton btnPlus = new JButton("+");
		btnPlus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(textField.getText());
				textField.setText("");
				operation="+";
			}
		});
		btnPlus.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnPlus.setBounds(275, 134, 85, 54);
		CALCULATOR.getContentPane().add(btnPlus);
		
		JButton btnMinus = new JButton("-");
		btnMinus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(textField.getText());
				textField.setText("");
				operation="-";
			}
		});
		btnMinus.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnMinus.setBounds(275, 198, 85, 54);
		CALCULATOR.getContentPane().add(btnMinus);
		
		JButton btnMul = new JButton("*");
		btnMul.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(textField.getText());
				textField.setText("");
				operation="*";
			}
		});
		btnMul.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnMul.setBounds(275, 257, 85, 54);
		CALCULATOR.getContentPane().add(btnMul);
		
		JButton btnDiv = new JButton("/");
		btnDiv.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(textField.getText());
				textField.setText("");
				operation="/";
			}
		});
		btnDiv.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnDiv.setBounds(275, 321, 85, 54);
		CALCULATOR.getContentPane().add(btnDiv);
		
		JButton btnEgal = new JButton("=");
		btnEgal.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String answer;
				second=Double.parseDouble(textField.getText());
				if (operation=="+")
				{
					result=first+second;
					answer=String.format("%.2f", result);
					textField.setText(answer);
					
				}
				else if (operation=="-")
				{
					result=first-second;
					answer=String.format("%.2f", result);
					textField.setText(answer);
					
				}
				else if (operation=="*")
				{
					result=first*second;
					answer=String.format("%.2f", result);
					textField.setText(answer);
					
				}
		
				else if (operation=="/")
				{
					result=first/second;
					answer=String.format("%.2f", result);
					textField.setText(answer);
					
				}
			}
			
		});
		btnEgal.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnEgal.setBounds(188, 383, 85, 54);
		CALCULATOR.getContentPane().add(btnEgal);
	}

}
