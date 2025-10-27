package tema4;

import java.util.Scanner;

public class FacturaServiciu {
private String denumireServiciu;
private double tarifOra;
private double numarOre;
public FacturaServiciu (String denumireServiciu, double tarifOra, double numarOre ) {
	this.denumireServiciu=denumireServiciu;
	this.tarifOra=tarifOra;
	this.numarOre=numarOre;
}
public double valoareTotala() {
	return tarifOra*numarOre;
	
}

public void afisareFactura() {
	System.out.println("Denumire: " +denumireServiciu);
	System.out.println("Tarif/h " +tarifOra);
	System.out.println("Nr ore: " +numarOre);
	System.out.println("Valoare totala: " +valoareTotala() + "lei");
	
}
public static void main (String []args){
	Scanner br=new Scanner(System.in);
	System.out.println("Introduceti denumirea serviciului: ");
	String denumireServiciu=br.nextLine();
	System.out.println("Introduceti tariful pe ora: ");
	double tarifOra=br.nextDouble();
	System.out.println("Introduceti numarul de ore: ");
	double numarOre=br.nextDouble();
	FacturaServiciu f=new FacturaServiciu(denumireServiciu, tarifOra, numarOre);
	System.out.println("\nInformatii serviciu: ");
	f.afisareFactura();
}
}
