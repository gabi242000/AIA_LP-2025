package modeltest2ex2;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileReader;

class Vehicul{
	public int vitezaMaxima() {
		return 0;
	}
}
class Masina extends Vehicul{
	public int vitezaMaxima() {
		return 250;
	}
}
class TipVehiculInvalidException extends Exception{
	public TipVehiculInvalidException(String msg) {
		super(msg);
	}
}
class ThreadVehicul extends Thread{
	public void run() {
	try (BufferedReader br = new BufferedReader(new FileReader("masina.txt"))){
		String cuvant = br.readLine();
		if(!cuvant.equals("MASINA")) {
			throw new TipVehiculInvalidException("Cuvant invalid "+ cuvant);
	}
		Vehicul v = new Masina();
		System.out.println("Viteza maxima= "+v.vitezaMaxima());
		
	} catch (IOException e) {
		System.out.println("Eroare la cititre");
	}catch(TipVehiculInvalidException e) {
		System.out.println(e.getMessage());
	}
}
}
public class Ex2 {

	public static void main(String[] args) {
		ThreadVehicul vehicul = new ThreadVehicul();
		vehicul.start();
	}

}
