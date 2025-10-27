package tema4;
import java.util.Scanner;
public class Animal {
private String nume;
private String specie;
private int varsta;
public Animal()
{
	nume="Necunoscut";
	specie="Necunoscuta";
	varsta=0;
}
public void afisareAnimal()
{
	System.out.println("Numele: "+nume);
	System.out.println("Specia: "+specie);
	System.out.println("Varsta: "+varsta);
}
public static void main(String args[]) 
{
	Animal animal1=new Animal();
	System.out.println("Detalii animal: ");
	animal1.afisareAnimal();
}
}
