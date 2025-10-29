package lab4;
import java.util.Scanner;
public class Masina {
		private String marca;
		private String model;
		private int an_fabricare;
		private String culoare;
		private double pret;
		
		public Masina( String Marca, String Model, int An_fabricare, String Culoare, double Pret) {
			this.marca=Marca;
			this.model=Model;
			this.an_fabricare=An_fabricare;
			this.culoare=Culoare;
			this.pret=Pret;
		}
		
		public void afisareMasina() {
			System.out.println("marca: " + marca);
			System.out.println("model: " + model);
			System.out.println("an fabricatie: " + an_fabricare);
			System.out.println("culoare: " + culoare);
			System.out.println("pret: "+ pret);
		}
		
		public static void main (String[] args) {
			Scanner sc = new Scanner(System.in);
			System.out.println("introdu marca: ");
			String marca=sc.nextLine();
			System.out.println("introdu modelul: ");
			String model=sc.nextLine();
			System.out.println("introdu culoarea: ");
			String culoare=sc.nextLine();
			System.out.println("introdu anul fabricatiei: ");
			int an_fabricatie=sc.nextInt();
			System.out.println("introdu pretul: ");
			double pret=sc.nextDouble();
			Masina masina = new Masina(marca,model,an_fabricatie,culoare,pret);
			masina.afisareMasina();
		}
}
