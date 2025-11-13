package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul4;

abstract class Persoana {
    protected String nume;
    protected int cnp;

    public Persoana(String nume, int cnp){
        this.nume = nume;
        this.cnp = cnp;
    }


    public abstract void afiseazaInfo();
       
}
