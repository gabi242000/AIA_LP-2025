package temalab4;
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
        this.valoareTotala = valoareTotala();
    }
    
    public double valoareTotala() {
        return tarifOra * numarOre;
    }

    public void afisareFactura() {
        System.out.println("Denumire serviciu: " + denumireServiciu);
        System.out.println("Tarif pe oră: " + tarifOra + " lei");
        System.out.println("Număr ore: " + numarOre);
        System.out.println("Valoare totală: " + valoareTotala + " lei");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introduceți denumirea serviciului: ");
        String denumire = sc.nextLine();
        System.out.print("Introduceți tariful pe oră (lei): ");
        double tarif = sc.nextDouble();
        System.out.print("Introduceți numărul de ore: ");
        int ore = sc.nextInt();

        FacturaServiciu f = new FacturaServiciu(denumire, tarif, ore);

        System.out.println("\nFactura generată:");
        f.afisareFactura();
    }
}
