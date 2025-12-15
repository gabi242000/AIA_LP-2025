package tema9;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class tema91 {
    public static void main(String args[]) {

        File fisier = new File("angajati.txt");
        if (!fisier.exists()) {
            System.out.println("Fisierul angajati.txt nu exista.");
            return;
        }

        double sumaSal = 0;
        int nrAngajati = 0;
        double salMax = 0;

        String numeSalMax = "";
        String prenumeSalMax = "";

        ArrayList<String[]> angajati = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fisier))) {
            String linie;

            while ((linie = br.readLine()) != null) {
                String[] parti = linie.split(" ");
                angajati.add(parti);

                double salariu = Double.parseDouble(parti[2]);
                sumaSal += salariu;
                nrAngajati++;

                if (salariu > salMax) {
                    salMax = salariu;
                    numeSalMax = parti[0];
                    prenumeSalMax = parti[1];
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la citirea fisierului.");
            return;
        }

        double mediaSal = sumaSal / nrAngajati;

        ArrayList<String> angajatiPesteMedie = new ArrayList<>();

        for (String[] angajat : angajati) {
            double salariu = Double.parseDouble(angajat[2]);
            if (salariu >= mediaSal) {
                angajatiPesteMedie.add(angajat[0] + " " + angajat[1]);
            }
        }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("venit_peste_medie.txt"))) {
            for (String a : angajatiPesteMedie) {
                bw.write(a);
                bw.newLine();
            }
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului venit_peste_medie.txt.");
        }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("raport_angajati.txt"))) {
            bw.write("Numar angajati: " + nrAngajati);
            bw.newLine();
            bw.write("Salariu mediu: " + mediaSal);
            bw.newLine();
            bw.write("Angajatul cu salariu maxim: " 
                     + numeSalMax + " " + prenumeSalMax 
                     + " (" + salMax + ")");
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului raport_angajati.txt.");
        }
    }
}
