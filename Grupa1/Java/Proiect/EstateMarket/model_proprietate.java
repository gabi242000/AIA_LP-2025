
public class model_proprietate {
    private int ID;
    private String titlu;
    private String descriere;
    private String locatie;
    private double pret;
    private String tipProprietate;
    private double suprafata;
    private  String numeUtilizator;
    private boolean deInchiriat;
    private boolean inchiriat= false;
    private boolean deVanzare=false;
    private String status;
    private double profit;

    public model_proprietate(){
        
    }

    public void setID(int ID){
        this.ID = ID;
    }

    public void setStatus(String status){
        this.status = status;
    }

    public void setDeInchiriat(boolean optiune){
        this.deInchiriat = optiune;
    }
    public void setInchiriat(boolean optiune){
        this.inchiriat = optiune;
    }

    public void setDeVanzare(boolean optiune){
        this.deVanzare = optiune;
    }

    public void setTitlu(String titlu){
        this.titlu = titlu;
    }

    public void setDescriere(String descriere){
        this.descriere = descriere;
    }  

    public void setLocatie(String locatie){
        this.locatie = locatie;
    }

    public void setPret(double pret){
        this.pret = pret;
    }

    public void setTipProprietate(String tipProprietate){
        this.tipProprietate = tipProprietate;
    }
    public void setSuprafata(double suprafata){
        this.suprafata = suprafata;
    }

    public void setNumeUtilizator(String numeutilizator){
        this.numeUtilizator = numeutilizator;
    }

    public void setProfit(double profit){
        this.profit =this.profit+ profit;
    }

    public int getID(){
        return ID;
    }

    public String getStatus(){
        return status;
    }

    public String getTitlu(){
        return titlu;
    }

    public String getDescriere(){
        return descriere;
    }
    public String getLocatie(){
        return locatie;
    }
    public double getPret(){
        return pret;
    }

    public String getTipProprietate(){
        return tipProprietate;
    }

    public double getSuprafata(){
        return suprafata;
    }
    public String getNumeUtilizator(){
        return numeUtilizator;
    }

    public boolean getInchiriat(){
        return inchiriat;
    }

    public boolean getDeInchiriat(){
        return deInchiriat;
    }

    public boolean getDeVanzare(){
        return deVanzare;
    }

    public double getProfit(){
        return profit;
    }




}
