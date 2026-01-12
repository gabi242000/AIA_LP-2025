package Grupa1.Java.Tema4;

public class FacturaServiciu {
    public String denumireServiciu;
    public double tarifOra;
    public double numarOre;
    public double valoareTotala;
    public String dataScadenta;

    public FacturaServiciu(String denumireServiciu,double tarifOra, double numarOre,String dataScadenta){
        this.denumireServiciu = denumireServiciu;
        this.tarifOra = tarifOra;
        this.numarOre = numarOre;
        this.dataScadenta = dataScadenta;
        
    }

    public double valoareTotala(){
            return tarifOra * numarOre;
    }

    public void afisareFactura(){
        System.out.println("Aveti de platit factura la InternetDigi:");
        System.out.println("Denumire serviciu: "+ denumireServiciu);
        System.out.println("TarifOra: "+ tarifOra);
        System.out.println("numarOre: "+ numarOre);
        System.out.println("Valoare totala: "+ valoareTotala());
        System.out.println("Data scadenta: "+ dataScadenta);



        
    }

    public static void main(String[] args){
        FacturaServiciu facturaDigi = new FacturaServiciu("InternetDigi", 12, 25.7,"24.11.2025");
        facturaDigi.afisareFactura();
    }
}
