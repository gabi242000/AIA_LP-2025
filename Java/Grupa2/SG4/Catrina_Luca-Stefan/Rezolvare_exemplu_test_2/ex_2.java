package exemplu_test_2;

import java.io.*;

class Vehicul {
	public int vitezaMaxima() {
		return 0;
	}
}

class Masina extends Vehicul {
	public int vitezaMaxima() {
		return 180;
	}
}
class TipVehiculInvalidException extends Exception {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public TipVehiculInvalidException(String msg) {
		super(msg);
	}
}

class VehiculThread extends Thread{
	private String fileName;
	public VehiculThread(String fileName) {
		this.fileName = fileName;
	}
	
	public void run() {
		try (BufferedReader br = new BufferedReader(new FileReader(fileName))){
			String tip = br.readLine();
			if("MASINA".equalsIgnoreCase(tip)) {
				Vehicul v = new Masina();
				System.out.println("Viteza maxima: " + v.vitezaMaxima());
			}else {
				throw new TipVehiculInvalidException("Tip invalid: " + tip);}
		}catch(IOException e) {
			System.out.println("Eroare la citire fisier.");
		}catch (TipVehiculInvalidException e) {
			System.out.println(e.getMessage());
		}
	}
}

public class ex_2 {

	public static void main(String[] args) {
		VehiculThread t = new VehiculThread("vehicul.txt");
		t.start();
	}
	
}
