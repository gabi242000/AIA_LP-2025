package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul4;

import java.util.*;

public class TestUniversitate {
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){

        List<Persoana> persoane = new ArrayList<>();

        System.out.print("Introduceti numarul de persoane:");
        int n = scanner.nextInt();
        scanner.nextLine(); 

        for(int i=0;i<n;i++){
            System.out.println("Persoana numarul " + (i+1) + ":");
            System.out.print("Introduceti tipul persoanei (1-student/2-profesor): ");
            int tip = scanner.nextInt();
            scanner.nextLine();
            if(tip == 1){
                Persoana student = new Student(null, 0,0);
                System.out.println("Introduceti numele studentului:");
                String numeStudent = scanner.nextLine();
                student.nume = numeStudent;
                System.out.println("Introduceti CNP-ul studentului:");
                int cnpStudent = scanner.nextInt();
                student.cnp = cnpStudent;
                scanner.nextLine();
                System.out.println("Introduceti media studentului:");
                double medieStudent  = scanner.nextDouble();
                scanner.nextLine();
                ((Student) student).medie = medieStudent;

                persoane.add(student);
                System.out.println("Student adaugat cu succes!");
            }

            else if(tip == 2){
                Persoana profesor = new Profesor(null,0,null,0);
                System.out.println("Introduceti numele profesorului:");
                String numeProfesor = scanner.nextLine();
                profesor.nume = numeProfesor;
                System.out.println("Introduceti CNP-ul profesorului:");
                int cnpProfesor = scanner.nextInt();
                profesor.cnp = cnpProfesor;
                scanner.nextLine();
                System.out.println("Introduceti specializarea profesorului:");
                String specializareProfesor = scanner.nextLine();
                ((Profesor) profesor).specializare = specializareProfesor;
                System.out.println("Introduceti salariul profesorului:");
                int salariuProfesor = scanner.nextInt();
                scanner.nextLine();
                ((Profesor) profesor).salariu = salariuProfesor;

                persoane.add(profesor);
                System.out.println("Profesor adaugat cu succes!");
            }
        }



        System.out.println("\nAfisarea informatiilor despre persoane:");
        for(Persoana p : persoane){
            System.out.println("Persoana numarul: "+ persoane.indexOf(p));
            p.afiseazaInfo();
            System.out.println();
        }

    }



        }
}
