package tema4;

public class animal {
	private String nume;
	private String specie;
	private int varsta;
	public animal()
	{
		nume="Necunoscut";
		specie="Necunoscuta";
		varsta=0;
	}
	public void afisareAnimal()
	{
		System.out.println("Nume: "+nume);
		System.out.println("Specie: "+specie);
		System.out.println("Varsta: "+varsta);
	}
	public static void main(String[] args)
	{
		animal a1=new animal();
		System.out.println("Date animal:");
		a1.afisareAnimal();
	}
}
