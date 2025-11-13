package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul4;

public class Student extends Persoana{
    
    protected double medie;

    public Student(String nume, int cnp,double medie){
        super(nume, cnp);
        this.medie = medie;
    }

    @Override
    public void afiseazaInfo(){
        System.out.println("Detaliile studentului");
        System.out.println("Nume: " + nume);
        System.out.println("CNP: " + cnp);
        System.out.println("Media: " + medie);
    }

    
}
