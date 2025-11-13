package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul5;

public class Alimente extends Produs {

    protected boolean aproapeExpirare;
    protected double reducere = 0.30;
    public Alimente(String denumire, double pret,boolean aproapeExpirare){
        super(denumire,pret);
        this.aproapeExpirare = aproapeExpirare;
    }


    @Override
    public void PretFinal() {
        if(aproapeExpirare){
            double pretFinal = pret - (pret * reducere);
            
        } 
    }

    
    
}
