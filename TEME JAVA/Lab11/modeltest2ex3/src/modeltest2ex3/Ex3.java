package modeltest2ex3;
import java.io.IOException;
import java.io.FileWriter;

class Produs{
	protected double pret;
	public Produs(double pret) {
		this.pret=pret;
	}
	public double pretFinal() {
		return pret;
	}
}
class PretInvalidException extends Exception{
	public PretInvalidException(String msg) {
		super(msg);
	}
}
class ProdusAlimentar extends Produs{
	public ProdusAlimentar(double pret) {
	super(pret);
	}
	public double pretFinal() {
		return pret *0.9;
	}
}
class ProdusThread extends Thread{
	private Produs produs;
	public ProdusThread (Produs produs) {
			this.produs=produs;
		}
	public void run() {
		try{
			if (produs.pret<0) {
				throw new PretInvalidException("pret negativ");
			}
		
		try (FileWriter fw = new FileWriter("produs.txt")){
			fw.write("Pret final: "+produs.pretFinal());
		}}catch(PretInvalidException e)	{
			System .out.println(e.getMessage());
		}catch(IOException e)	{
			System .out.println("eroare la scriere in fisier");
			}
	}
}

public class Ex3 {

	public static void main(String[] args) {
		Produs p1 =new ProdusAlimentar(100);
		ProdusThread t1 =new ProdusThread (p1);
		t1.start();	
		Produs p2 =new ProdusAlimentar(-50);
		ProdusThread t2 =new ProdusThread (p2);
		t2.start();	
	}
}

