package lab4;
//import java.util.*;

public class Animal {

	private String nume;
	private int varsta;
	private String specie;
	
	Animal()
	{
		nume = "Necunoscut";
		varsta = 0;
		specie = "Necunoscut";
	}
	
	public void afisareAnimal()
	{
		System.out.println("nume: " + nume);
		System.out.println("varsta: " + varsta);
		System.out.println("specie: " + specie);
	}
	
	public static void main(String[] args)
	{
		Animal a1 = new Animal();
		System.out.println("Detalii animal: ");
		a1.afisareAnimal();
	}
}

