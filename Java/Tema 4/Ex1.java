package Tema4;
import java.io.*;
import java.util.*;

class Animal {
    private String nume;
    private String specie;
    private int varsta;

    // constructor fara parametri (valori implicite)
    public Animal() {
        nume = "Necunoscut";
        specie = "Necunoscută";
        varsta = 0;
    }

    public void afisareAnimal() {
        System.out.println("Nume: " + nume);
        System.out.println("Specie: " + specie);
        System.out.println("Vârsta: " + varsta);
    }
}

public class Ex1 {
    public static void main(String[] args) {
        Animal a = new Animal();
        a.afisareAnimal();
    }
}

