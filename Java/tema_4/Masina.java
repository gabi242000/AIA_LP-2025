package tema_4;
import java.util.*;

public class Masina {

	public String marca, model, culoare;
	public int an_fabricare, pret;
	
	public Masina(String marca, String model, int an_fabricare, String culoare, int pret) {
		this.marca = marca;
		this.model = model;
		this.an_fabricare = an_fabricare;
		this.culoare = culoare;
		this.pret = pret;
	}
	
	public void afisareMasina() {
		System.out.println("Marca: " + marca);
		System.out.println("Model: " + model);
		System.out.println("An fabricare: " + an_fabricare);
		System.out.println("Culoare: " + culoare);
		System.out.println("Pret: " + pret);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Introduceti marca masinii: ");
		String marca = sc.nextLine();
		System.out.print("Introduceti modelul: ");
		String model = sc.nextLine();
		System.out.print("Introduceti anul de fabricare: ");
		int an_fabricare = sc.nextInt();
		sc.nextLine();
		System.out.print("Introduceti culoarea: ");
		String culoare = sc.nextLine();
		System.out.print("Introduceti pretul: ");
		int pret = sc.nextInt();
		
		Masina m1 = new Masina(marca, model, an_fabricare, culoare, pret);
		System.out.println("\nDetalii masina: ");
		m1.afisareMasina();
	}

}
