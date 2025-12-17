package lab_10_java;

import java.io.*;
import java.util.*;

class Angajat {
    String nume;
    String prenume;
    double salariu;

    public Angajat(String nume, String prenume, double salariu) {
        this.nume = nume;
        this.prenume = prenume;
        this.salariu = salariu;
    }

    public String toString() {
        return nume + " " + prenume + " " + salariu;
    }
}

public class tema_lab_9_ex1 {

    public static void main(String[] args) {
        File fisier = new File("angajati.txt");

        if (!fisier.exists()) {
            System.out.println("Fisierul angajati.txt nu exista!");
            return;
        }

        List<Angajat> angajati = new ArrayList<>();
        double sumaSalarii = 0;

        try (Scanner sc = new Scanner(fisier)) {
            while (sc.hasNext()) {
                String nume = sc.next();
                String prenume = sc.next();
                double salariu = sc.nextDouble();

                Angajat a = new Angajat(nume, prenume, salariu);
                angajati.add(a);
                sumaSalarii += salariu;
            }
        } catch (Exception e) {
            System.out.println("Eroare la citirea fisierului!");
            return;
        }

        int nrAngajati = angajati.size();
        double salariuMediu = sumaSalarii / nrAngajati;

        Angajat maxSalariu = angajati.get(0);
        for (Angajat a : angajati) {
            if (a.salariu > maxSalariu.salariu) {
                maxSalariu = a;
            }
        }

        try (PrintWriter pw = new PrintWriter("venit_peste_medie.txt")) {
            for (Angajat a : angajati) {
                if (a.salariu > salariuMediu) {
                    pw.println(a);
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului venit_peste_medie.txt");
        }

        try (PrintWriter pw = new PrintWriter("raport_angajati.txt")) {
            pw.println("Numar total angajati: " + nrAngajati);
            pw.println("Salariu mediu: " + salariuMediu);
            pw.println("Angajat cu salariul maxim: " + maxSalariu);
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului raport_angajati.txt");
        }

    }
}

