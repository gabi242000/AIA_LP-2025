package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul5;

abstract class Produs {
    protected String denumire;
    protected double pret;
    public boolean aproapeExpirare;

    public Produs(String denumire, double pret) {
        this.denumire = denumire;
        this.pret = pret;
    }

    abstract void PretFinal();
}
