package Tema9;

import java.io.*;
import java.util.*;

public class Ex1 {
    static class Angajat {
        String nume, prenume;
        double salariu;

        Angajat(String nume, String prenume, double salariu) {
            this.nume = nume;
            this.prenume = prenume;
            this.salariu = salariu;
        }

        @Override
        public String toString() {
            return nume + " " + prenume + " " + salariu;
        }
    }

    public static void main(String[] args) {
        File f = new File("angajati.txt");
        if (!f.exists()) {
            System.out.println("Fisierul angajati.txt NU exista!");
            return;
        }

        ArrayList<Angajat> lista = new ArrayList<>();
        double suma = 0;
        Angajat maxAng = null;

        // 1) Citire
        try (Scanner sc = new Scanner(f)) {
            while (sc.hasNextLine()) {
                String linie = sc.nextLine().trim();
                if (linie.isEmpty()) continue;

                // Spargem linia pe spatii
                String[] p = linie.split("\\s+");
                if (p.length < 3) continue; // linie invalida

                String nume = p[0];
                String prenume = p[1];

                double salariu;
                try {
                    salariu = Double.parseDouble(p[2]);
                } catch (NumberFormatException e) {
                    continue; // salariu invalid
                }

                Angajat a = new Angajat(nume, prenume, salariu);
                lista.add(a);

                suma += salariu;

                if (maxAng == null || salariu > maxAng.salariu)
                    maxAng = a;
            }
        } catch (Exception e) {
            System.out.println("Eroare la citire: " + e.getMessage());
            return;
        }

        if (lista.size() == 0) {
            System.out.println("Nu exista angajati validi in fisier.");
            return;
        }

        // 2) Calcule
        double medie = suma / lista.size();

        // 3) Scriere venit_peste_medie.txt (doar salariu > medie)
        try (PrintWriter out = new PrintWriter(new FileWriter("venit_peste_medie.txt"))) {
            for (Angajat a : lista) {
                if (a.salariu > medie) {
                    out.println(a.nume + " " + a.prenume + " " + a.salariu);
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la scriere venit_peste_medie.txt: " + e.getMessage());
        }

        // 4) Scriere raport_angajati.txt
        try (PrintWriter out = new PrintWriter(new FileWriter("raport_angajati.txt"))) {
            out.println("Numar total angajati: " + lista.size());
            out.println("Salariu mediu: " + medie);
            out.println("Angajat cu salariu maxim: " + maxAng.nume + " " + maxAng.prenume + " (" + maxAng.salariu + ")");
        } catch (IOException e) {
            System.out.println("Eroare la scriere raport_angajati.txt: " + e.getMessage());
        }

        System.out.println("Gata! Am generat: venit_peste_medie.txt si raport_angajati.txt");
    }
}
