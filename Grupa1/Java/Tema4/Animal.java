package Grupa1.Java.Tema4;
public class Animal {
    public String nume;
    public String specie;
    public int varsta;

    public Animal(){
        nume = "Necunoscut";
        specie = "Necunoscuta";
        varsta = 0;
    }

    public  void afisareAnimal(){
        System.out.println("Nume animal:" + nume);
        System.out.println("Specie animal:" + specie);
        System.out.println("Varsta animal:" + varsta);

    }

    public static void main(String[] args){
        Animal animal = new Animal();
        animal.afisareAnimal();
    }
}
