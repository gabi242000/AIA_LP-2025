public class Animal{
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
        System.out.println("Numele animalului este: "+nume);
        System.out.println("Specia animalului este: "+specie);
        System.out.println("Varsta animalului este: "+varsta);
    }
    
    public static void main(String []args)
    {
        Animal a=new Animal();
        System.out.println("Informatii cu privire la animal: ");
        a.afisareAnimal();
    }
}