package tetris1;


import java.awt.EventQueue;
import javax.swing.JFrame;


public class EcranPrincipal extends JFrame {

	private static final long serialVersionUID = 1L;
	public static final int inaltime=500;
	public static final int latime=400;
	private Board board;
	
	public EcranPrincipal() {
		setTitle("Tetris");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(latime,inaltime);
		setLocationRelativeTo(null);
		setResizable(false);
		
		board=new Board();
		add(board);
		addKeyListener(board);
	}
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					EcranPrincipal frame = new EcranPrincipal();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}


}
