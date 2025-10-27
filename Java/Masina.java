package lab4;
import java.util.*;

public class Masina {

	String marca, model, culoare;
	int an_fabricatie, pret;
	
	Masina(int a, int p, String m, String mod, String c)
	{
		an_fabricatie = a;
		pret = p;
		marca = m;
		model = mod;
		culoare = c;
	}
	
	public void afisareMasina()
	{
		System.out.println("An de fabricatie: " + an_fabricatie);
		System.out.println("pret: " + pret);
		System.out.println("marca: " + marca);
		System.out.println("model: " + model);
		System.out.println("culoare: " + culoare);
	}
	
	public static void main(String[] args)
	{
		Scanner ceva = new Scanner(System.in);
		
		System.out.println("introduceti anul ");
		int an = ceva.nextInt();
		ceva.nextLine();
		
		System.out.println("introduceti marca");
		String marca = ceva.nextLine();
		
		System.out.println("introduceti modelul");
		String model = ceva.nextLine();
		
		System.out.println("introduceti pretul");
		int pret = ceva.nextInt();
		ceva.nextLine();
		
		System.out.println("introduceti culoarea");
		String color = ceva.nextLine();
		
		

		Masina m1 = new Masina(an, pret, marca, model, color);
		m1.afisareMasina();
		
		ceva.close();
	}
	
}
