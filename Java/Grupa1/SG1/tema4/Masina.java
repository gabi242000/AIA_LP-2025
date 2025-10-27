package tema4;
import java.util.Scanner;
public class Masina {
private String marca;
private String model;
private int an_fabricare;
private String culoare;
private float pret;
public Masina(String marca, String model, int an_fabricare, String culoare, float pret)
{
	this.marca=marca;
	this.model=model;
	this.an_fabricare=an_fabricare;
	this.culoare=culoare;
	this.pret=pret;
}
public void afisareMasina()
{
	System.out.println("Marca: "+marca);
	System.out.println("Model: "+model);
	System.out.println("Anul fabricarii: "+an_fabricare);
	System.out.println("Culoarea: "+culoare);
	System.out.println("Pretul: "+pret);
}
public static void main(String args[]) 
{
	Scanner scanner = new Scanner(System.in);
	
	System.out.println("Introduceti marca masinii: ");
	String marca=scanner.nextLine();
	
	System.out.println("Introduceti modelul masinii: ");
	String model=scanner.nextLine();
	
	System.out.println("Introduceti anul fabricarii masinii: ");
	int an_fabricare=scanner.nextInt();
	scanner.nextLine();
	
	System.out.println("Introduceti culoarea masinii: ");
	String culoare=scanner.nextLine();
	
	System.out.println("Introduceti pretul masinii: ");
	float pret=scanner.nextFloat();
	
	Masina masina=new Masina(marca,model,an_fabricare,culoare,pret);
	System.out.println("Datele studentului sunt: ");
	masina.afisareMasina();
}
}
