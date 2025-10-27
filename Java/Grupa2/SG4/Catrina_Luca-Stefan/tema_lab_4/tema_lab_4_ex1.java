package lab_4_java;

public class tema_lab_4_ex1 { //Animal
    
    private String nume;
    private String specie;
    private int varsta;

    public tema_lab_4_ex1() { //Animal
        nume = "Necunoscut";
        specie = "Necunoscuta";
        varsta = 0;
    }

    public void afisareAnimal() {
        System.out.println("Nume: " + nume);
        System.out.println("Specie: " + specie);
        System.out.println("Varsta: " + varsta + " ani");
    }

    public static void main(String[] args) {
        tema_lab_4_ex1 A = new tema_lab_4_ex1();
        A.afisareAnimal();
    }
}

