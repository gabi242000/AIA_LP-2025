package tema4;

import java.util.Scanner;

public class Masina {
private String marca;
private String model;
private int an_fabricare;
private String culoare;
private double pret; 
public Masina (String marca, String model, int an_fabricare, String culoare, double pret) {
	this.marca=marca;
	this.model=model;
	this.an_fabricare=an_fabricare;
	this.culoare=culoare;
	this.pret=pret;
}
public void afisareMasina () {
	System.out.println("Marca: " +marca);
	System.out.println("Model: " +model);
	System.out.println("An fabricare: " +an_fabricare);
	System.out.println("Culoare: " +culoare);
	System.out.println("Pret: " +pret + " lei");
}
public static void main (String []args) {
	Scanner br=new Scanner(System.in);
	System.out.println("Introduceti marca masinii: ");
	String marca=br.nextLine();
	System.out.println("Introduceti modelul masinii: ");
	String model=br.nextLine();
	System.out.println("Introduceti anul de fabricare: ");
	int an_fabricare=br.nextInt();
	br.nextLine();
	System.out.println("Introduceti culoarea: ");
	String culoare=br.nextLine();
	System.out.println("Introduceti pretul: ");
	double pret=br.nextDouble();
	
	Masina s=new Masina(marca, model, an_fabricare, culoare, pret);
	System.out.println("\nInformatiile masinii:");
	s.afisareMasina();
}
}
