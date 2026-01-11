public class Tranzactii {

    private String vanzator;
    private String cumparator;
    private String titlu_proprietate;
    private double pret;
    private String tip_achizitie;

    public Tranzactii(){

    }

    public void setVanzator(String vanzator){
        this.vanzator = vanzator;
    }

    public void setCumparator(String cumparator){
        this.cumparator = cumparator;
    }

    public void setTitluProprietate(String titlu_proprietate){
            this.titlu_proprietate = titlu_proprietate;
    }

    public void setPret(double pret){
            this.pret = pret;
    }

    public void setTipAchizitie(String tip_achizitie){
            this.tip_achizitie = tip_achizitie;
    }

    public String getTitluProprietate(){
        return titlu_proprietate;
    }

    public double getPret(){
        return pret;
    }

    public String getTipAchizitie(){
        return tip_achizitie;
    }

    public String getVanzator(){
        return vanzator;
    }
    
    public String getCumparator(){
        return cumparator;
    }

    
}

    