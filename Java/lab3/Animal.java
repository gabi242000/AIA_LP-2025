package javalab4;
public class Animal {
	
		private String nume;
		private String specie;
		private int varsta;
		
		public Animal() {
			nume = "necunoscut";
			specie = "necunoscuta";
			varsta = 0;
		}
	
	public void afisareAnimal() {
		System.out.println("nume: " + nume);
		System.out.println("specie: " + specie);
		System.out.println("varsta: " + varsta);
		
		}
	
	
	
	
	
	
	public static void main(String[] args) {
		Animal an = new Animal();
		an.afisareAnimal();
	}
}
