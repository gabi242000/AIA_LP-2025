public class ChirieInfo {
    private String titlu;
    private String vanzator;
    private String chirias;
    private double pret;
    private String tip_proprietate;
    private double profit;
    private int ID;
    
    


    public ChirieInfo(String titlu, String vanzator, String chirias,double pret,String tip_proprietate,int ID,double profit){
        this.titlu = titlu;
        this.chirias =chirias;
        this.vanzator = vanzator;
        this.pret =pret;
        this.tip_proprietate= tip_proprietate;
        this.ID = ID;
        this.profit = profit;
        
    }

    public void setProfit(double profit){
        this.profit = this.profit + profit;
    }


    public String getTitlu(){
        return titlu;
    }
    
    public String getVanzator(){
        return vanzator;
    }

    public String getChirias(){
        return chirias;
    }

    public double getPret(){
        return pret;
    }

    public String getTipProprietate(){
        return tip_proprietate;
    }

    public double getProfit(){
        return profit;
    }

    public int getID(){
        return ID;
    }

    



    

}
