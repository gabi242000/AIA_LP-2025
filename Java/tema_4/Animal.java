package tema_4;
import java.util.*;

public class Animal {

	private String nume;
	private String specie;
	private int varsta;
	
	public Animal() {
		nume = "Necunoscut";
		specie = "Necunoscuta";
		varsta = 0;
	}
	
	public void afisareAnimal() {
		System.out.println("Nume: " + nume);
		System.out.println("Specie: " + specie);
		System.out.println("Varsta: " + varsta);
	}
	
	public static void main(String[] args) {
		Animal a = new Animal();
		System.out.println("  Detalii animal");
		a.afisareAnimal(); 

	}

}
