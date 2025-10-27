package tema4;
import java.util.Scanner;
public class FacturaServiciu {
private String denumireServiciu;
private float tarifOra;
private float numarOre;
private float valoareTotala;
	public FacturaServiciu(String denumireServiciu, float tarifOra, float numarOre)
	{
		this.denumireServiciu=denumireServiciu;
		this.tarifOra=tarifOra;
		this.numarOre=numarOre;
	}
public void afisareFactura()
{
	System.out.println("Denumire serviciu: "+denumireServiciu);
	System.out.println("Tariful/ora: "+tarifOra);
	System.out.println("Numarul de ore: "+numarOre);
}
public void afisareValTot(float tarifOra, float numarOre)
{
	valoareTotala=tarifOra*numarOre;
	System.out.println(valoareTotala);
}
public static void main(String args[])
{
	Scanner scanner = new Scanner(System.in);
	
	System.out.println("Introduceti denumirea serviciului: ");
	String denumireServiciu=scanner.nextLine();
	
	System.out.println("Introduceti tariful pe ora: ");
	float tarifOra=scanner.nextFloat();
	
	System.out.println("Introduceti numarul de ore: ");
	float numarOre=scanner.nextFloat();
	
	FacturaServiciu fs=new FacturaServiciu(denumireServiciu, tarifOra,numarOre);
	fs.afisareFactura();
	fs.afisareValTot(tarifOra, numarOre);
	
}
}
