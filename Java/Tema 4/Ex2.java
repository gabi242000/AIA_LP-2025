package Tema4;

import java.util.*;

class Masina {
    private String marca;
    private String model;
    private int anFabricare;
    private String culoare;
    private double pret;

    // constructor parametrizat
    public Masina(String marca, String model, int anFabricare, String culoare, double pret) {
        this.marca = marca;
        this.model = model;
        this.anFabricare = anFabricare;
        this.culoare = culoare;
        this.pret = pret;
    }

    public void afisareMasina() {
        System.out.println("Marca: " + marca);
        System.out.println("Model: " + model);
        System.out.println("An fabricație: " + anFabricare);
        System.out.println("Culoare: " + culoare);
        System.out.println("Preț: " + pret);
    }
}

public class Ex2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Marca: ");
        String marca = sc.nextLine();

        System.out.print("Model: ");
        String model = sc.nextLine();

        System.out.print("An fabricație: ");
        int an = sc.nextInt();
        sc.nextLine(); // consuma Enter

        System.out.print("Culoare: ");
        String culoare = sc.nextLine();

        System.out.print("Preț: ");
        double pret = sc.nextDouble();

        Masina m = new Masina(marca, model, an, culoare, pret);

        System.out.println("\n=== Date mașină ===");
        m.afisareMasina();

        sc.close();
    }
}
