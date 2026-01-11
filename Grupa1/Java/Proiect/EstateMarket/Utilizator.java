public class Utilizator {
    private  String nume;
    private String prenume;
    private String numeutilizator;
    private String email;
    private String parola;
    private String tara;
    private String oras;
    private String telefon;
    private double balanta =0;
    private double profit_total=0;
    private double profit_vanzari=0;
    private double profit_chirii=0;
    
    

    public Utilizator(String nume, String prenume,String numeutilizator,String email,String parola,
    String tara,String oras,String telefon,double balanta){
            this.nume = nume;
            this.prenume = prenume;
            this.numeutilizator = numeutilizator;
            this.email = email;
            this.parola = parola;
            this.tara = tara;
            this.oras = oras;
            this.telefon = telefon;
            this.balanta = balanta;
    }

    public Utilizator(){

    }

    public void setNume(String nume){
        this.nume = nume;

    }

    public void setPrenume(String prenume){
        this.prenume = prenume;
    }

    public void setNumeUtilizator(String numeutilizator){
        this.numeutilizator = numeutilizator;
    }

    public void setEmail(String email){
        this.email = email;
    }

    public void setParola(String parola){
        this.parola = parola;
    }
    public void setTara(String tara){
        this.tara = tara;
    }

    public void setOras(String oras){
        this.oras = oras;
    }

    public void setTelefon(String telefon){
        this.telefon = telefon;
    }

    public void setBalanta(double balanta){
        this.balanta = balanta;
    }

    public void setProfitTotal(double profit_total){
        this.profit_total = profit_total;
    }
    public void setProfitVanzari(double profit_vanzari){
        this.profit_vanzari = profit_vanzari;
    }
    public void setProfitChirii(double profit_chirii){
        this.profit_chirii = profit_chirii;
    }

    

    public String getNume(){
        return nume;
    }

    public String getPrenume(){
        return prenume;
    }

    public String getNumeUtilizator(){
        return numeutilizator;
    }

    public String getEmail(){
        return email;

    }
    public String getParola(){
        return parola;
    }

    public String getTara(){
        return tara;
    }

    public String getOras(){
        return oras;
    }

    public String getTelefon(){
        return telefon;
    }

    public double getBalanta(){
        return balanta;
    }

    public double getProfitTotal(){
        return profit_total;
    }
    public double getProfitVanzari(){
        return profit_vanzari;
    }
    public double getProfitChirii(){
        return profit_chirii;
    }


    


}
