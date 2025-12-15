package modeltest2ex1;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileWriter;

class Animal{
	public void sunet() {
		System.out.println("animalul face un sunet");
	}
}
class Caine extends Animal{
	public void sunet(){
	class Sunet extends Thread{
		public void run() {
			try (BufferedWriter bw = new BufferedWriter(new FileWriter("caine.txt"))){
				bw.write("ham");
			}catch (IOException e) {
				System.out.println("eroare la scriere");
			}
		
		}
	}
	Sunet s= new Sunet();
	s.start();
	System.out.println("Sunet adaugat in fisier");
}
}
public class Ex1 {

	public static void main(String[] args) {
		Animal caine = new Caine();
        caine.sunet();
        
	}

}
