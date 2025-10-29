package lab4;
public class Animal {
		private String nume;
		private String specie;
		private int varsta;
		
		public void afisareAnimal() {
			System.out.println("nume: " + nume);
			System.out.println("specie: " + specie);
			System.out.println("varsta: "+ varsta);
		}
		
		public Animal(){
			this.nume="Necunoscut";
			this.specie="Necunoscuta";
			this.varsta=0;
		}
		
		public static void main(String[] args) {
			Animal animal=new Animal();
			System.out.println("detaii animal:");
			animal.afisareAnimal();
		}
}
