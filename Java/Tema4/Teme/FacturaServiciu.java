package Teme;

import java.util.*;

public class FacturaServiciu {
private String denumireServiciu;
private double tarifOra;
private int numarOre;
private double valoareTotala;
public FacturaServiciu(String denumireServiciu, double tarifOra, int numarOre) {
	this.denumireServiciu = denumireServiciu;
	this.tarifOra = tarifOra;
	this.numarOre = numarOre;
}
public void valoareTotala(){
	this.valoareTotala = tarifOra * numarOre;
}
public void afisareFactura() {
	System.out.println("Serviciul " + denumireServiciu + ": ");
	System.out.println("Tarif pe ora: " + tarifOra + ";");
	System.out.println("Numar de ore: " + numarOre + ";");
	System.out.println("In total: " + valoareTotala + ";");
}
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("Introdu serviciul prestat: ");
	String a = sc.nextLine();
	System.out.println("Introdu tariful pe ora: ");
	double b = sc.nextDouble();
	System.out.println("Introdu numarul de ore: ");
	int c = sc.nextInt();
	FacturaServiciu s1 = new FacturaServiciu(a,b,c);
	s1.valoareTotala();
	s1.afisareFactura();
}
}
