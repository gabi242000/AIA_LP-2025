package exemplu_test_2;
import java.io.*;

class Animal {
	public String sunet() {
		return "sunet";
	}
}

class Caine extends Animal{
	public String sunet() {
		return "Ham, ham";
	}
}

class FileWriteException extends Exception {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public FileWriteException (String msg) {
		super(msg);
	}
}
class AnimalThread extends Thread{
	private Animal animal;
	private String fileName;
	
	public AnimalThread(Animal animal, String fileName) {
		this.animal = animal;
		this.fileName = fileName;
	}
	
	public void run() {
		try (FileWriter fw = new FileWriter(fileName)){
			fw.write("Sunet: " + animal.sunet());
		} catch (IOException e) {
			try {
				throw new FileWriteException("Nu pot scrie in fisier.");
			} catch (FileWriteException ex) {
				System.out.println(ex.getMessage());
			}
		}
	}
}

public class ex_1 {
	public static void main(String[] args) {
		Animal a = new Caine();
		AnimalThread t = new AnimalThread(a, "animal.txt");
		t.start();
	}
}
