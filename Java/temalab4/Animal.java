package temalab4;

public class Animal {
	private String nume;
	private String specie;
	private int varsta;
	
	//constructor fara parametri (cu valori implicite)
	public Animal() {
		nume= "Necunoscut";
		specie= "Necunoscuta";
		varsta= 0;
	}
	
	//met pt afisare
	public void afisareAnimal() {
		System.out.println("Nume: " + nume);
		System.out.println("specie: " + specie);
		System.out.println("Varsta: " + varsta + " ani");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Animal a1= new Animal();
		System.out.println("Detalii animal: ");
		a1.afisareAnimal();
		}

	}

