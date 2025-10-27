package tema4;

import java.util.Scanner;

public class facturaServiciu {
	private String denumireServiciu;
	private double tarifOra;
	private double numarOre;
	private double valoareTotala;
	public double valoareTotala(double tarifOra, double numarOre)
	{
		valoareTotala=tarifOra*numarOre;
		return valoareTotala;
	}
	public facturaServiciu(String denumireServiciu, double tarifOra, double numarOre, double valoareTotala)
	{
		this.denumireServiciu=denumireServiciu;
		this.tarifOra=tarifOra;
		this.numarOre=numarOre;
		this.valoareTotala=valoareTotala(tarifOra, numarOre);
	}
	public void afisareFactura()
	{
		System.out.println("Denumire serviciu: "+denumireServiciu);
		System.out.println("Tarif orar: "+tarifOra);
		System.out.println("Numar ore: "+numarOre);
		System.out.println("Valoare Totala: "+valoareTotala);
	}
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Introduceti denumirea serviciului: ");
		String denumireServiciu=s.nextLine();
		System.out.println("Introduceti tariful: ");
		double tarifOra=s.nextDouble();
		System.out.println("Introduceti numar ore: ");
		double numarOre=s.nextDouble();
		double valoareTotala=0;
		facturaServiciu f1=new facturaServiciu(denumireServiciu, tarifOra, numarOre, valoareTotala);
		f1.afisareFactura();
	}
}
