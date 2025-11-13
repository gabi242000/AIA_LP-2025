package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul5;

public class Haine extends Produs {

    protected double reducere = 0.20;


    public Haine(String denumire, double pret){
        super(denumire, pret);
    }

    @Override
    public void PretFinal() {
        double pretFinal = pret - (pret * reducere);
        
    }
}