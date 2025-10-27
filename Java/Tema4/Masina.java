package Tema4;

import java.util.Scanner;

public class Masina {
 
    private String marca;
    private String model;
    private int an_fabricare;
    private String culoare;
    private double pret;

    public Masina(String marca, String model, int an_fabricare, String culoare, double pret) {
        this.marca = marca;
        this.model = model;
        this.an_fabricare = an_fabricare;
        this.culoare = culoare;
        this.pret = pret;
    }

    public void afisareMasina() {
        System.out.println("Marca: " + marca);
        System.out.println("Model: " + model);
        System.out.println("An fabricare: " + an_fabricare);
        System.out.println("Culoare: " + culoare);
        System.out.println("Preț: " + pret + " euro");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introduceți marca mașinii: ");
        String marca = sc.nextLine();

        System.out.print("Introduceți modelul mașinii: ");
        String model = sc.nextLine();

        System.out.print("Introduceți culoarea: ");
        String culoare = sc.nextLine();

        System.out.print("Introduceți prețul: ");
        double pret = sc.nextDouble();
        
        System.out.print("Introduceți anul de fabricare: ");
        int an_fabricare = sc.nextInt();

        Masina m = new Masina(marca, model, an_fabricare, culoare, pret);
        m.afisareMasina();
    }
}
