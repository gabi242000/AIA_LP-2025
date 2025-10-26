import java.util.Scanner;
public class FacturaServiciu {
    private String denumireServiciu;
    private double tarifOra;
    private double ore;
    private double valoareTotala;
    public FacturaServiciu(String denumireServiciu, double tarifOra, double ore) {
        this.denumireServiciu = denumireServiciu;
        this.tarifOra = tarifOra;
        this.ore = ore;
        calcul_valoareTotala();
    }
    public void calcul_valoareTotala(){
        this.valoareTotala = tarifOra * ore;
    }
    public void afisareFactura() {
        System.out.println("Denumire serviciu: " + denumireServiciu);
        System.out.println("Tarif pe ora serviciu: " + tarifOra);
        System.out.println("Ore serviciu: " + ore);
        System.out.println("Valorarea serviciu: " + valoareTotala);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduceti datele facturii: ");
        System.out.println("Denumire serviciu: ");
        String denumireServiciu = sc.nextLine();
        System.out.println("Introducti Tarif pe ora serviciu: ");
        double tarifOra = sc.nextDouble();
        sc.nextLine();
        System.out.println("Introducti Ore serviciu: ");
        double ore = sc.nextDouble();
        sc.nextLine();
        FacturaServiciu factura = new FacturaServiciu(denumireServiciu, tarifOra, ore);
        factura.afisareFactura();
    }
}
