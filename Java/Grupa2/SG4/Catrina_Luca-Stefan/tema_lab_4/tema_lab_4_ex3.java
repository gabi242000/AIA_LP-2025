package lab_4_java;

import java.util.Scanner;

public class tema_lab_4_ex3 {
    
    private String denumireServiciu;
    private double tarifOra;
    private int numarOre;
    private double valoareTotala;

    public tema_lab_4_ex3(String denumireServiciu, double tarifOra, int numarOre) {
        this.denumireServiciu = denumireServiciu;
        this.tarifOra = tarifOra;
        this.numarOre = numarOre;
        this.valoareTotala = calculeazaValoareTotala();
    }

    public double calculeazaValoareTotala() {
        return tarifOra * numarOre;
    }

    public void afisareFactura() {
        System.out.println("----- FACTURA SERVICIU -----");
        System.out.println("Serviciu: " + denumireServiciu);
        System.out.println("Tarif pe ora: " + tarifOra + " RON");
        System.out.println("Numar ore: " + numarOre);
        System.out.println("Valoare totala: " + valoareTotala + " RON");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introduceti denumirea serviciului: ");
        String serviciu = sc.nextLine();
        System.out.print("Introduceti tariful pe ora: ");
        double tarif = sc.nextDouble();
        System.out.print("Introduceti numarul de ore: ");
        int ore = sc.nextInt();

        tema_lab_4_ex3 factura = new tema_lab_4_ex3(serviciu, tarif, ore);
        System.out.println();
        factura.afisareFactura();

        sc.close();
    }
}

