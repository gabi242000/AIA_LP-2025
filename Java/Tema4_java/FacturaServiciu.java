import java.util.Scanner;

public class FacturaServiciu{
    
    private String denumireServiciu;
    private double tarifOra;
    private int numarOre;
    private double valoareTotala;
    
    public FacturaServiciu(String denumireServiciu, double tarifOra, int numarOre)
    {
        this.denumireServiciu=denumireServiciu;
        this.tarifOra=tarifOra;
        this.numarOre=numarOre;
        this.valoareTotala=valoareTotala();
    }
    
    public double valoareTotala()
    {
        return tarifOra*numarOre;
    }
    
    public void afisareFactura()
    {
        System.out.println("Denumire serviciu: "+denumireServiciu);
        System.out.println("Tarif/ora: "+tarifOra);
        System.out.println("Numar ore: "+numarOre);
        System.out.println("Valoarea totala: "+valoareTotala);
    }
    
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Introduceti denumirea serviciului: ");
        String denumireServiciu=sc.nextLine();
        
        System.out.println("Introduceti tariful pe ora: ");
        Double tarifOra=sc.nextDouble();
        
        System.out.println("Introduceti numarul de ore: ");
        int numarOre=sc.nextInt();
        
        FacturaServiciu f=new FacturaServiciu(denumireServiciu,tarifOra,numarOre);
        
        System.out.println("Factura generata: ");
        f.afisareFactura();
    }
}