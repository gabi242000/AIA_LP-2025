package javalab4;
import java.util.Scanner;
public class FacturaServiciu {
	private String denumireServiciu;
	private int tarifOra;
	private int numarOre;
	private int valoareTotala;
	
	public FacturaServiciu(String denumireServiciu, int tarifOra, int numarOre, int valoareTotala) {
		this.denumireServiciu = denumireServiciu;
		this.tarifOra = tarifOra;
		this.numarOre = numarOre;
		this.valoareTotala = tarifOra * numarOre;
		
	}
	public  int valoareTotala() {
		return tarifOra * numarOre;
	}
	
	public void afisareFactura() {
		System.out.println("Job: " + denumireServiciu);
		System.out.println("Tarif ora: " + tarifOra);
		System.out.println("Numar ore: " + numarOre);
		System.out.println("Valoarea totala: " + valoareTotala());
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Introdu numele job-ului: ");
		String denumireServiciu = sc.nextLine();
		System.out.println("Introdu tariful pe ora: ");
		int tarifOra = sc.nextInt();
		System.out.println("introdu numarul de ore: ");
		int numarOre = sc.nextInt();
		
		FacturaServiciu s1 = new FacturaServiciu(denumireServiciu, tarifOra, numarOre, 0);
		s1.afisareFactura();
		
		
		
	}
}
