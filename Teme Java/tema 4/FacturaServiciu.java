package tema4;

import java.util.Scanner;

public class FacturaServiciu {
	private String denumireServiciu;
	private int tarifOra;
	private static int numarOre;
	private static double valoareTotala;

	public FacturaServiciu(String denumireServiciu, int tarifOra, int numarOre) {
		this.denumireServiciu = denumireServiciu;
		this.tarifOra = tarifOra;
		this.numarOre = numarOre;


	}

	public double valoareTotala() {
		return tarifOra * numarOre;
	}

	public void afisareFactura() {
		System.out.println("Serviciul oferit : " + denumireServiciu);
		System.out.println("Tarif : " + tarifOra);
		System.out.println("Numar ore : " + numarOre);
		System.out.println("Valoare totala:  : " + valoareTotala() + "lei");

	}

	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		System.out.print("Introduceti serviciul : ");
		String denumireServiciu = sc.nextLine();
		System.out.print("Introduceti tarif : ");
		int tarifOra = sc.nextInt();
		System.out.print("Introduceti numarul de ore : ");
		int numarOre = sc.nextInt();
		FacturaServiciu fs = new FacturaServiciu(denumireServiciu, tarifOra, numarOre);
		System.out.println("\nDetalii factura : ");
		fs.afisareFactura();
	}
}
