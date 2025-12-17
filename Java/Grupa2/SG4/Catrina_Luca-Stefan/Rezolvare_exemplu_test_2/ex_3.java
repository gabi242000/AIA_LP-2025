package exemplu_test_2;
import java.io.*;

class Produs {
	protected double pret;
	
	public Produs(double pret) {
		this.pret = pret;
	}
	
	public double pretFinal() {
		return pret;
	}
}

class ProdusAlimentar extends Produs {
	public ProdusAlimentar(double pret) {
		super(pret);
	}
	
	public double pretFinal() {
		return pret * 0.9;
	}
}

class PretInvalidException extends Exception {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public PretInvalidException(String msg) {
		super(msg);
	}
}

class ProdusThread extends Thread {
	private Produs produs;
	private String fileName;
	public ProdusThread(Produs produs, String fileName) {
		this.produs = produs;
		this.fileName = fileName;
	}
	
	public void run() {
		try {
			if (produs.pret < 0) {
				throw new PretInvalidException("Pret negativ!");
			}
			try (FileWriter fw = new FileWriter(fileName)){
				fw.write("Pret final: " + produs.pretFinal());
			}
		} catch (PretInvalidException e) {
			System.out.println(e.getMessage());
		}catch (IOException e) {
			System.out.println("Erosre la scriere din fisier.");
		}
	}
}

public class ex_3 {
	
	public static void main(String[] args) {
		Produs p = new ProdusAlimentar(100);
		ProdusThread t = new ProdusThread(p, "produs.txt");
		t.start();
	}

}
