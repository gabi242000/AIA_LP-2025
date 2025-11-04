package Teme;
import java.io.*;
import java.util.*;
public class Masina {
private String marca;
private String model;
private String culoare;
private int an_fabricare;
private double pret;
public Masina(String marca, String model, String culoare, int an_fabricare, double pret) {
	this.marca = marca;
	this.model = model;
	this.culoare = culoare;
	this.an_fabricare = an_fabricare;
	this.pret = pret;
}
public void afisareMasina() {
	System.out.println("Masina: ");
	System.out.println("Marca " + marca + ", modelul " + model + ", culoarea " + culoare + ", fabricata in anul " + an_fabricare + ", se gaseste la pretul de: " + pret);
}
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("Introdu marca masinii: ");
	String a = sc.nextLine();
	System.out.println("Introdu modelul masinii: ");
	String b = sc.nextLine();
	System.out.println("Introdu culoarea masinii: ");
	String c = sc.nextLine();
	System.out.println("Introdu anul de fabricatie al masinii: ");
	int d = sc.nextInt();
	System.out.println("Introdu pretul masinii: ");
	double e = sc.nextDouble();
	Masina s1 = new Masina(a,b,c,d,e);
	s1.afisareMasina();
}
}