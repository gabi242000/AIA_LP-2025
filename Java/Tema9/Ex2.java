package Tema9;

import java.io.*;
import java.util.*;

public class Ex2 {
    public static void main(String[] args) {
        File f = new File("temperaturi.txt");
        if (!f.exists()) {
            System.out.println("Fisierul temperaturi.txt NU exista!");
            return;
        }

        ArrayList<Double> temp = new ArrayList<>();

        // 1) Citire temperaturi
        try (Scanner sc = new Scanner(f)) {
            while (sc.hasNextLine()) {
                String linie = sc.nextLine().trim();
                if (linie.isEmpty()) continue;

                try {
                    double t = Double.parseDouble(linie);
                    temp.add(t);
                } catch (NumberFormatException e) {
                    // ignoram liniile invalide
                }
            }
        } catch (Exception e) {
            System.out.println("Eroare la citire: " + e.getMessage());
            return;
        }

        if (temp.size() == 0) {
            System.out.println("Nu exista temperaturi valide in fisier.");
            return;
        }

        // 2) Calcule
        double suma = 0;
        double min = temp.get(0);
        double max = temp.get(0);
        int nrSubZero = 0;

        for (double t : temp) {
            suma += t;
            if (t < min) min = t;
            if (t > max) max = t;
            if (t < 0) nrSubZero++;
        }

        double medie = suma / temp.size();

        // 3) raport_temperaturi.txt
        try (PrintWriter out = new PrintWriter(new FileWriter("raport_temperaturi.txt"))) {
            out.println("Numar valori: " + temp.size());
            out.println("Temperatura medie: " + medie);
            out.println("Temperatura minima: " + min);
            out.println("Temperatura maxima: " + max);
            out.println("Numar valori sub 0°C: " + nrSubZero);
        } catch (IOException e) {
            System.out.println("Eroare la scriere raport_temperaturi.txt: " + e.getMessage());
        }

        // 4) temp_sub_zero.txt (doar temperaturi negative)
        try (PrintWriter out = new PrintWriter(new FileWriter("temp_sub_zero.txt"))) {
            for (double t : temp) {
                if (t < 0) out.println(t);
            }
        } catch (IOException e) {
            System.out.println("Eroare la scriere temp_sub_zero.txt: " + e.getMessage());
        }

        System.out.println("Gata! Am generat: raport_temperaturi.txt si temp_sub_zero.txt");
    }
}

