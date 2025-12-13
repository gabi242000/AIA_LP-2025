import java.io.*;
import java.util.Scanner;

class Angajat {
    String nume;
    String prenume;
    double salariu;

    Angajat(String nume, String prenume, double salariu) {
        this.nume = nume;
        this.prenume = prenume;
        this.salariu = salariu;
    }
}

public class Main {

    public static double calculSalariuMediu(int n, Angajat[] angajat) {
        if (n == 0) return 0;
        double suma = 0;
        for (int i = 0; i < n; i++) {
            suma += angajat[i].salariu;
        }
        return suma / n;
    }

    public static String salariulMaxim(int n, Angajat[] angajat) {
        if (n == 0) return "";
        double max = angajat[0].salariu;
        String numeAngajatSalariuMaxim = angajat[0].nume + " " + angajat[0].prenume;

        for (int i = 1; i < n; i++) {
            if (angajat[i].salariu > max) {
                max = angajat[i].salariu;
                numeAngajatSalariuMaxim = angajat[i].nume + " " + angajat[i].prenume;
            }
        }
        return numeAngajatSalariuMaxim;
    }

    public static void main(String[] args) {
        File f = new File("angajati.txt");
        if (!f.exists()) {
            System.out.println("Fisierul angajati.txt nu exista.");
            return;
        }

        int n = 0;
        try (Scanner scCount = new Scanner(f)) {
            while (scCount.hasNextLine()) {
                String linie = scCount.nextLine().trim();
                if (!linie.isEmpty()) n++;
            }
        } catch (FileNotFoundException e) {
            System.out.println("Nu pot deschide angajati.txt.");
            return;
        }

        if (n == 0) {
            System.out.println("Fisierul angajati.txt este gol.");
            return;
        }

        Angajat[] angajat = new Angajat[n];
        int i = 0;

        try (Scanner sc = new Scanner(f)) {
            while (sc.hasNextLine() && i < n) {
                String linie = sc.nextLine().trim();
                if (linie.isEmpty()) continue;

                String[] cuvinte = linie.split("\\s+");
                if (cuvinte.length < 3) continue;

                String nume = cuvinte[0];
                String prenume = cuvinte[1];
                double salariu = Double.parseDouble(cuvinte[2]);

                angajat[i] = new Angajat(nume, prenume, salariu);
                i++;
            }
        } catch (FileNotFoundException e) {
            System.out.println("Nu pot deschide angajati.txt.");
            return;
        } catch (NumberFormatException e) {
            System.out.println("Eroare: salariu invalid pe una dintre linii.");
            return;
        }

        int nrAngajati = i;

        double salariuMediu = calculSalariuMediu(nrAngajati, angajat);

        try (BufferedWriter bw1 = new BufferedWriter(new FileWriter("venit_peste_medie.txt", false))) {
            for (int j = 0; j < nrAngajati; j++) {
                if (angajat[j].salariu > salariuMediu) {
                    bw1.write(angajat[j].nume + " " + angajat[j].prenume + " " + angajat[j].salariu);
                    bw1.newLine();
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la scrierea venit_peste_medie.txt.");
            return;
        }

        String angajatSalariuMaxim = salariulMaxim(nrAngajati, angajat);

        try (BufferedWriter bw2 = new BufferedWriter(new FileWriter("raport_angajati.txt", false))) {
            bw2.write("Numarul total de angajati este: " + nrAngajati);
            bw2.newLine();
            bw2.write("Salariul mediu este: " + salariuMediu);
            bw2.newLine();
            bw2.write("Angajatul cu salariul maxim este: " + angajatSalariuMaxim);
            bw2.newLine();
        } catch (IOException e) {
            System.out.println("Eroare la scrierea raport_angajati.txt.");
        }
    }
}
