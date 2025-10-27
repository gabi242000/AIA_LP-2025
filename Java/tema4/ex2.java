package tema4;

import java.util.Scanner;

public class masina {
	private String marca;
	private String model;
	private int an_fabricatie;
	private String culoare;
	private int pret;
	public masina(String marca, String model, int an_fabricatie, String culoare, int pret)
	{
		this.marca=marca;
		this.model=model;
		this.an_fabricatie=an_fabricatie;
		this.culoare=culoare;
		this.pret=pret;
	}
	public void afisareMasina()
	{
		System.out.println("Marca: "+marca);
		System.out.println("Model: "+model);
		System.out.println("An fabricatie: "+an_fabricatie);
		System.out.println("Culoare: "+culoare);
		System.out.println("Pret: "+pret);
	}
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Introduceti marca:");
		String marca=s.nextLine();
		System.out.println("Introduceti modelul: ");
		String model=s.nextLine();
		System.out.println("Introduceti culoare: ");
		String culoare=s.nextLine();
		System.out.println("Introduceti an fabricatie: ");
		int an_fabricatie=s.nextInt();
		System.out.println("Introduceti pret: ");
		int pret=s.nextInt();
		masina m1=new masina(marca, model, an_fabricatie, culoare, pret);
		System.out.println("Detaliile masinii: ");
		m1.afisareMasina();
	}
}
