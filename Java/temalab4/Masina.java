package temalab4;
import java.util.Scanner;

public class Masina {
	private String marca;
	private String model;
	private int anFabricare;
	private String culoare;
	private double pret;
	
	//constructor parametrizat
	public Masina(String marca, String model, int anFabricare, String culoare, double pret) {
		this.marca= marca;
		this.model= model;
		this.anFabricare= anFabricare;
		this.culoare= culoare;
		this.pret= pret;
	}
	
	//afisare
	public void afisareMasina() {
		System.out.println("Marca: " + marca);
		System.out.println("Model: " + model);
		System.out.println("An fabricatie: " + anFabricare);
		System.out.println("Culoare: " + culoare);
		System.out.println("Pret: " + pret + "lei");
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		
		System.out.print("Introduceți marca mașinii: ");
	    String marca = sc.nextLine();
	    System.out.print("Introduceți modelul: ");
	    String model = sc.nextLine();
	    System.out.print("Introduceți anul fabricației: ");
	    int anFabricare = sc.nextInt();
	    sc.nextLine(); // curățare buffer
	    System.out.print("Introduceți culoarea: ");
	    String culoare = sc.nextLine();
	    System.out.print("Introduceți prețul: ");
	    double pret = sc.nextDouble();

	    Masina m = new Masina(marca, model, anFabricare, culoare, pret);

	    System.out.println("\nDetaliile mașinii:");
	    m.afisareMasina();

	}

}
