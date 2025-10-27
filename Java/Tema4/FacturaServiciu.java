package Tema4;
import java.util.Scanner;

public class FacturaServiciu {
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

  
    public double calculeazaValoareTotala() {
        return tarifOra * numarOre;
    }

    public void afisareFactura() {
        System.out.println("Denumire serviciu: " + denumireServiciu);
        System.out.println("Tarif/oră: " + tarifOra + " lei");
        System.out.println("Număr ore: " + numarOre);
        System.out.println("Valoare totală: " + valoareTotala + " lei");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introduceți denumirea serviciului: ");
        String denumire = sc.nextLine();

        System.out.print("Introduceți tariful pe oră (lei): ");
        double tarif = sc.nextDouble();

        System.out.println("Introduceți numărul de ore lucrate: ");
        int ore = sc.nextInt();

        FacturaServiciu factura = new FacturaServiciu(denumire, tarif, ore);

        factura.afisareFactura();
    }
}
