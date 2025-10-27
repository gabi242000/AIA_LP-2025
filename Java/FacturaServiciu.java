package lab4;
import java.util.*;

public class FacturaServiciu {

	String denumireServiciu;
	int tarifOra, numarOre, valoareTotala;
	
	FacturaServiciu(String Serviciu, int Ora, int nrOre) 
	{
		denumireServiciu = Serviciu;
		tarifOra = Ora;
		numarOre = nrOre;
	}
	
	public int valoareTotala()
	{
		return tarifOra * numarOre;
	}
	
	public void afisareFactura()
	{
		System.out.println("Serviciu: " + denumireServiciu);
		System.out.println("Tariful pe ora: " + tarifOra);
		System.out.println("Numarul de ore: " + numarOre);
		System.out.println("Valoarea totala " + valoareTotala());
	}
	
	public static void main(String[] args)
	{
		Scanner ceva = new Scanner(System.in);
		
		System.out.println("loc de munca: ");
		String serviciu = ceva.nextLine();
		
		System.out.println("tarif: ");
		int tarif = ceva.nextInt();
		
		System.out.println("ore: ");
		int hrs = ceva.nextInt();
		
		FacturaServiciu fs1 = new FacturaServiciu(serviciu, tarif, hrs);
		fs1.afisareFactura();
		
		ceva.close();
		
	}
}
