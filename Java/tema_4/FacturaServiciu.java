package tema_4;
import java.util.*;

public class FacturaServiciu {

	private String denumireServiciu;
	private double tarifOra;
	int numarOre;
	
	public FacturaServiciu(String denumireServiciu, double tarifOra, int numarOre) {
		this.denumireServiciu = denumireServiciu;
		this.tarifOra = tarifOra;
		this.numarOre = numarOre;
	}
	
	public double valoareTotala() {
		return tarifOra * numarOre;
	}
	
	public void afisareFactura() {
		System.out.println("Denumire: " + denumireServiciu);
		System.out.println("Tarif/ora: " + tarifOra + " lei" + "/60 min");
		System.out.println("Numarul de ore: " + numarOre);
		System.out.println("Valoarea totala: " + valoareTotala() + " lei");
	}
	
	public static void main(String[] args) { 
		Scanner sc = new Scanner(System.in);
		System.out.print("Introduceti denumirea serviciului: ");
		String denumireSer = sc.nextLine();
		System.out.print("Introduceti tariful pe ora: ");
		double tarifOra = sc.nextDouble();
		System.out.print("Introduceti numarul de ore: ");
		int numarOre = sc.nextInt();
		
		System.out.println("\nFactura: ");
		FacturaServiciu fs = new FacturaServiciu(denumireSer, tarifOra, numarOre);
		fs.afisareFactura();
	}

}
