package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul4;

public class Profesor extends Persoana {
    protected String specializare;
    protected int salariu;

    public Profesor(String nume,int cnp, String specializare, int salariu){
        super(nume,cnp);
        this.specializare = specializare;
        this.salariu = salariu;
    }

    @Override
    public void afiseazaInfo(){
        System.out.println("Detaliile profesorului");
        System.out.println("Nume: " + nume);
        System.out.println("CNP: " + cnp);
        System.out.println("Specializarea: " + specializare);
        System.out.println("Salariu: " + salariu);
    }

    
}
