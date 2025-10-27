package lab_4_java;

import java.util.Scanner;

public class tema_lab_4_ex2 {
    
    private String marca;
    private String model;
    private int an_fabricare;
    private String culoare;
    private double pret;

    public tema_lab_4_ex2(String marca, String model, int an_fabricare, String culoare, double pret) {
        this.marca = marca;
        this.model = model;
        this.an_fabricare = an_fabricare;
        this.culoare = culoare;
        this.pret = pret;
    }

    public void afisareMasina() {
        System.out.println("Marca: " + marca);
        System.out.println("Model: " + model);
        System.out.println("An fabricatie: " + an_fabricare);
        System.out.println("Culoare: " + culoare);
        System.out.println("Pret: " + pret + " RON");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introduceti marca: ");
        String marca = sc.nextLine();
        System.out.print("Introduceti modelul: ");
        String model = sc.nextLine();
        System.out.print("Introduceti anul fabricatiei: ");
        int an = sc.nextInt();
        sc.nextLine();
        System.out.print("Introduceti culoarea: ");
        String culoare = sc.nextLine();
        System.out.print("Introduceti pretul: ");
        double pret = sc.nextDouble();

        tema_lab_4_ex2 M = new tema_lab_4_ex2(marca, model, an, culoare, pret);
        System.out.println("\nInformatiile despre masina:");
        M.afisareMasina();

        sc.close();
    }
}
