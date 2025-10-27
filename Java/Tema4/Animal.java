package Tema4;

public class Animal {
   
    private String nume;
    private String specie;
    private int varsta;

    public Animal() {
        this.nume = "Necunoscut";
        this.specie = "Necunoscută";
        this.varsta = 0;
    }


    public void afisareAnimal() {
        System.out.println("Nume: " + nume);
        System.out.println("Specie: " + specie);
        System.out.println("Vârstă: " + varsta);
    }

    public static void main(String[] args) {
        Animal a = new Animal();
        a.afisareAnimal();
    }
}