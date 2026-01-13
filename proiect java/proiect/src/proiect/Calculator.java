package proiect;

import java.awt.EventQueue;
import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;
import java.lang.Math;

public class Calculator {

	private JFrame CALCULATOR;
	private JTextField opField;
	private JTextField rezField;
	double first;
	double second;
	double result;
	String operation;
	String answer;

	public void divideZero(double second) throws ArithmeticException{
		if (second == 0) {
			throw new ArithmeticException("Nu se poate imparti la zero");
		}
	}
 /**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Calculator window = new Calculator();
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
	public Calculator() {
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
		
		opField = new JTextField();
		opField.setFont(new Font("Tahoma", Font.BOLD, 12));
		opField.setBounds(10, 22, 350, 50);
		CALCULATOR.getContentPane().add(opField);
		opField.setColumns(10);
		opField.setEditable(false);
		opField.setBackground( Color.LIGHT_GRAY );
		
		rezField = new JTextField();
		rezField.setFont(new Font("Tahoma", Font.BOLD, 12));
		rezField.setBounds(10, 70, 350, 50);
		CALCULATOR.getContentPane().add(rezField);
		rezField.setEditable(false);
		rezField.setColumns(10);
		
		JButton btn1 = new JButton("1");
		btn1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn1.getText());
			}
		});
		btn1.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn1.setBounds(10, 321, 85, 54);
		btn1.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn1);
		
		JButton btn2 = new JButton("2");
		btn2.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn2.getText());
			}
		});
		btn2.setBounds(97, 321, 85, 54);
		btn2.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn2);
		
		JButton btn3 = new JButton("3");
		btn3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn3.getText());
			}
		});
		btn3.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn3.setBounds(188, 321, 85, 54);
		btn3.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn3);
		
		JButton btn4 = new JButton("4");
		btn4.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn4.getText());
			}
		});
		btn4.setBounds(10, 257, 85, 54);
		btn4.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn4);
		
		JButton btn5 = new JButton("5");
		btn5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn5.getText());
			}
		});
		btn5.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn5.setBounds(97, 257, 85, 54);
		btn5.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn5);
		
		JButton btn6 = new JButton("6");
		btn6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn6.getText());
			}
		});
		btn6.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn6.setBounds(188, 257, 85, 54);
		btn6.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn6);
		
		JButton btn7 = new JButton("7");
		btn7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn7.getText());
			}
		});
		btn7.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn7.setBounds(10, 198, 85, 54);
		btn7.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn7);
		
		JButton btn8 = new JButton("8");
		btn8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn8.getText());
			}
		});
		btn8.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn8.setBounds(97, 198, 85, 54);
		btn8.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn8);
		
		JButton btn9 = new JButton("9");
		btn9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn9.getText());
			}
		});
		btn9.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn9.setBounds(188, 198, 85, 54);
		btn9.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn9);
		
		JButton btn0 = new JButton("0");
		btn0.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn0.getText());
			}
		});
		btn0.setBounds(10, 383, 85, 54);
		btn0.setBackground( Color.PINK );
		CALCULATOR.getContentPane().add(btn0);
		
		JButton btn00 = new JButton("00");
		btn00.setFont(new Font("Tahoma", Font.BOLD, 12));
		btn00.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btn00.getText());
			}
		});
		btn00.setBounds(97, 134, 85, 54);
		btn00.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btn00);
		
		JButton btnClear = new JButton("C");
		btnClear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				opField.setText(null);
				rezField.setText(null);
			}
		});
		btnClear.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnClear.setBounds(10, 134, 85, 54);
		btnClear.setBackground( Color.ORANGE ); 
		CALCULATOR.getContentPane().add(btnClear);
		
		JButton btnPow = new JButton("x\u02B8");
		btnPow.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(rezField.getText());
				opField.setText(first + " ^ ");
				rezField.setText("");
				operation="x\u02B8";
			}
		});
		btnPow.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnPow.setBounds(188, 134, 85, 54);
		btnPow.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btnPow);
		
		JButton btnDot = new JButton(".");
		btnDot.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				rezField.setText(rezField.getText() + btnDot.getText());
			}
		});
		btnDot.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnDot.setBounds(97, 383, 85, 54);
		btnDot.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btnDot);
		
		JButton btnPlus = new JButton("+");
		btnPlus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(rezField.getText());
				opField.setText(first + " + ");
				rezField.setText("");
				operation="+";
			}
		});
		btnPlus.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnPlus.setBounds(275, 134, 85, 54);
		btnPlus.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btnPlus);
		
		JButton btnMinus = new JButton("-");
		btnMinus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(rezField.getText());
				opField.setText(first+ " - ");
				rezField.setText("");
				operation="-";
			}
		});
		btnMinus.setFont(new Font("Tahoma", Font.BOLD, 15));
		btnMinus.setBounds(275, 198, 85, 54);
		btnMinus.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btnMinus);
		
		JButton btnMul = new JButton("*");
		btnMul.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(rezField.getText());
				opField.setText(first+ " * ");
				rezField.setText("");
				operation="*";
			}
		});
		btnMul.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnMul.setBounds(275, 257, 85, 54);
		btnMul.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btnMul);
		
		JButton btnDiv = new JButton("/");
		btnDiv.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(rezField.getText());
				opField.setText(first + " / ");
				rezField.setText("");
				operation="/";
			}
		});
		btnDiv.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnDiv.setBounds(275, 321, 85, 54);
		btnDiv.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btnDiv);
		
		JButton btnSqrt = new JButton("\u221A");
		btnSqrt.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnSqrt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				first=Double.parseDouble(rezField.getText());
				opField.setText("\u221A "+ first);
				rezField.setText("");
				operation="\u221A";
			}
		});
		btnSqrt.setBounds(275, 383, 85, 54);
		btnSqrt.setBackground( Color.YELLOW );
		CALCULATOR.getContentPane().add(btnSqrt);
		
		JButton btnEgal = new JButton("=");
		btnEgal.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String answer;
				if(!operation.equals("\u221A")) {
					second=Double.parseDouble(rezField.getText());
					opField.setText(opField.getText() + rezField.getText());
				}
				switch(operation) {
				case "+":
					result=first+second;
					answer=String.format("%.2f", result);
					rezField.setText(answer);
					break;
				case "-":
					result=first-second;
					answer=String.format("%.2f", result);
					rezField.setText(answer);
					break;
				case "*":
					result=first*second;
					answer=String.format("%.2f", result);
					rezField.setText(answer);
					break;
				case "/":
					try {
					divideZero(second);
					result=first/second;
					answer=String.format("%.2f", result);
					rezField.setText(answer);
					
					} catch (ArithmeticException ex) {
						rezField.setText(ex.getMessage());
					}
					break;
				case "\u221A":
					result=Math.sqrt(first);
					answer=String.format("%.2f", result);
					rezField.setText(answer);
					break;
				case "x\u02B8":
					result=Math.pow(first, second);
					answer=String.format("%.2f", result);
					rezField.setText(answer);
				}
			}
		});
		btnEgal.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnEgal.setBounds(188, 383, 85, 54);
		btnEgal.setBackground( new Color(173, 216, 230) );
		CALCULATOR.getContentPane().add(btnEgal);
	}
}