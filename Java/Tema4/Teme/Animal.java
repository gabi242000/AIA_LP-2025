package Teme;
import java.io.*;
public class Animal {
private String nume;
private String specie;
private int varsta;
public Animal() {
	this.nume = "Necunoscut";
	this.specie = "Necunoscuta";
	this.varsta = 0;
}
public void afisareAnimal() {
	System.out.println("Animalul " + nume + ", specia " + specie + " are varsta de " + varsta);
}
public static void main(String[] args) {
	Animal s1 = new Animal();
	s1.afisareAnimal();
}
}
