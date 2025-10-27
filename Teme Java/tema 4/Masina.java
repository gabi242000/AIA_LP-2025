package tema4;

import java.util.Scanner;

public class Masina {
	private String marca;
	private String model;
	private int an_fabricatie;
	private String culoare;
	private double pret;

	public Masina(String marca, String model, String culoare, int an_fabricatie, double pret) {
		this.marca = marca;
		this.model = model;
		this.culoare = culoare;
		this.an_fabricatie = an_fabricatie;
		this.pret = pret;
	}

	public void afisareMasina() {
		System.out.println("Marca : " + marca);
		System.out.println("Model : " + model);
		System.out.println("An fabricatie : " + an_fabricatie);
		System.out.println("Culoare : " + culoare);
		System.out.println("Pret : " + pret);
	}

	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		System.out.print("Introduceti marca : ");
		String marca = sc.nextLine();
		System.out.print("Introduceti modelul : ");
		String model = sc.nextLine();

		System.out.print("Introduceti culoarea : ");
		String culoare = sc.nextLine();
		System.out.print("Introduceti anul fabricatiei : ");
		int an_fabricatie = sc.nextInt();
		System.out.print("Introduceti pretul : ");
		double pret = sc.nextDouble();
		Masina mm = new Masina(marca, model, culoare, an_fabricatie, pret);
		System.out.println("\nDetalii masina : ");
		mm.afisareMasina();
	}
}
