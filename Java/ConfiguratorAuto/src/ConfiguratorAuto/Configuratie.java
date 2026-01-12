package ConfiguratorAuto;

public class Configuratie {
    
    // Constante de Preț (Păstrate)
    public static final double PRET_DE_BAZA = 15000.00;
    public static final double PRET_VOPSEA_METALIZATA = 500.00;
    public static final double PRET_JANTE_ALIAJ = 1200.00;
    public static final double PRET_TRAPA = 800.00;
    public static final double PRET_SCAUNE_INCALZITE = 300.00;
    public static final double PRET_NAVIGATIE = 200.00;
    
    // Cale de Bază pentru Imagini (Păstrată aici)
    public static final String CALE_BAZA_IMAGINI = "D:\\Code\\Java\\ConfiguratorAuto\\src\\ConfiguratorAuto\\"; 

    // Starea Curentă (Simplu)
    private String culoareSelectata = "Alb";
    private boolean areJanteAliaj = false;
    private boolean areTrapa = false;
    private boolean areScauneIncalzite = false;
    private boolean areNavigatie = false;

    // --- Getteri și Setteri (Aceștia rămân la fel) ---
    public String getCuloareSelectata() { return culoareSelectata; }
    public void setCuloareSelectata(String culoareSelectata) { this.culoareSelectata = culoareSelectata; }

    public boolean areJanteAliaj() { return areJanteAliaj; }
    public void setAreJanteAliaj(boolean areJanteAliaj) { this.areJanteAliaj = areJanteAliaj; }
    
    public boolean areTrapa() { return areTrapa; }
    public void setAreTrapa(boolean areTrapa) { this.areTrapa = areTrapa; }

    public boolean areScauneIncalzite() { return areScauneIncalzite; }
    public void setAreScauneIncalzite(boolean areScauneIncalzite) { this.areScauneIncalzite = areScauneIncalzite; }

    public boolean areNavigatie() { return areNavigatie; }
    public void setAreNavigatie(boolean areNavigatie) { this.areNavigatie = areNavigatie; }
    
    // --- Metoda Principală de Calcul (Rămâne la fel) ---
    public double calculeazaPretTotal() {
        double pret = PRET_DE_BAZA;
        if (!culoareSelectata.equals("Alb")) pret += PRET_VOPSEA_METALIZATA;
        if (areJanteAliaj) pret += PRET_JANTE_ALIAJ;
        if (areTrapa) pret += PRET_TRAPA;
        if (areScauneIncalzite) pret += PRET_SCAUNE_INCALZITE;
        if (areNavigatie) pret += PRET_NAVIGATIE;
        return pret;
    }
}