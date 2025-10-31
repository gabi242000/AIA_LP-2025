package javalab4;
import java.util.Scanner;
public class Masina {
	private String marca;
	private String model;
	private int an_fabricare;
	private String culoare;
	private int pret;
	
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
		Scanner in = new Scanner(System.in);
		System.out.println("Introdu marca: ");
		String marca = in.nextLine();
		System.out.println("Introdu modelul: ");
		String model = in.nextLine();
		System.out.println("Introdu anul de fabricare: ");
		int an_fabricare = in.nextInt();
		System.out.println("Introdu culoarea: ");
		String culoare = in.nextLine();
		System.out.println("Introdu pretul: ");
		int pret = in.nextInt();
	
		Masina m1 = new Masina(marca, model, an_fabricare, culoare, pret);
		m1.afisareMasina();
	}
}
