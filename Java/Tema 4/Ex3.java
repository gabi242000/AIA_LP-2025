package Tema4;

import java.util.*;

class FacturaServiciu {
    private String denumireServiciu;
    private double tarifOra;
    private int numarOre;
    private double valoareTotala;

    public FacturaServiciu(String denumireServiciu, double tarifOra, int numarOre) {
        this.denumireServiciu = denumireServiciu;
        this.tarifOra = tarifOra;
        this.numarOre = numarOre;
        this.valoareTotala = calculeazaValoareTotala();
    }

    // metoda de calcul
    private double calculeazaValoareTotala() {
        return tarifOra * numarOre;
    }

    public void afisareFactura() {
        System.out.println("Serviciu: " + denumireServiciu);
        System.out.println("Tarif/oră: " + tarifOra);
        System.out.println("Număr ore: " + numarOre);
        System.out.println("Valoare totală: " + valoareTotala);
    }
}

public class Ex3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Denumire serviciu: ");
        String den = sc.nextLine();

        System.out.print("Tarif/oră: ");
        double tarif = sc.nextDouble();

        System.out.print("Număr ore: ");
        int ore = sc.nextInt();

        FacturaServiciu f = new FacturaServiciu(den, tarif, ore);

        System.out.println("\n=== Factură ===");
        f.afisareFactura();

        sc.close();
    }
}
