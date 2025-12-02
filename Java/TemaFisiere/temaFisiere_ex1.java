import java.io.*;
import java.util.*;

public class AngajatiProcessor {
    public static void main(String[] args) {

        File input = new File("angajati.txt");
        File pesteMedie = new File("venit_peste_medie.txt");
        File raport = new File("raport_angajati.txt");

        if (!input.exists()) {
            System.err.println("Fișierul angajati.txt nu există!");
            return;
        }

        List<String> linii = new ArrayList<>();
        double suma = 0;
        int nr = 0;

        String maxNume = "";
        String maxPrenume = "";
        double maxSalariu = -1;

        try (BufferedReader br = new BufferedReader(new FileReader(input))) {
            String linie;

            while ((linie = br.readLine()) != null) {
                linie = linie.trim();
                if (linie.isEmpty()) continue;

                String[] t = linie.split("\\s+");
                if (t.length < 3) continue;

                double salariu;
                try {
                    salariu = Double.parseDouble(t[t.length - 1]);
                } catch (Exception e) {
                    continue;
                }

                // reconstruieste numele + prenumele
                String numeComplet = "";
                for (int i = 0; i < t.length - 1; i++) {
                    numeComplet += t[i] + " ";
                }
                numeComplet = numeComplet.trim();

                linii.add(numeComplet + " " + salariu);

                suma += salariu;
                nr++;

                // salariu maxim
                if (salariu > maxSalariu) {
                    maxSalariu = salariu;
                    maxNume = t[0];
                    maxPrenume = t[1];
                }
            }
        } catch (IOException e) {
            System.err.println("Eroare la citire!");
            return;
        }

        if (nr == 0) {
            System.out.println("Nu exista date valide.");
            return;
        }

        double medie = suma / nr;

        
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(pesteMedie))) {
            for (String linie : linii) {
                String[] t = linie.split("\\s+");
                double salariu = Double.parseDouble(t[t.length - 1]);
                if (salariu > medie) {
                    bw.write(linie);
                    bw.newLine();
                }
            }
        } catch (IOException e) {
            System.err.println("Eroare la scriere peste medie!");
        }

        
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(raport))) {
            bw.write("Numar total angajati: " + nr); bw.newLine();
            bw.write("Salariu mediu: " + String.format("%.2f", medie)); bw.newLine();
            bw.write("Angajat cu salariul maxim: " + maxNume + " " + maxPrenume +
                     " (" + String.format("%.2f", maxSalariu) + ")"); bw.newLine();
        } catch (IOException e) {
            System.err.println("Eroare la scriere raport!");
        }

        System.out.println("Gata! Fișiere generate.");
    }
}
