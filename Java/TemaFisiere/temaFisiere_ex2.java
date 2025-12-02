import java.io.*;
import java.util.*;

public class TemperaturiProcessor {
    public static void main(String[] args) {

        File input = new File("temperaturi.txt");
        File raport = new File("raport_temperaturi.txt");
        File subZero = new File("temp_sub_zero.txt");

        if (!input.exists()) {
            System.err.println("Fișierul temperaturi.txt nu există!");
            return;
        }

        List<Double> valori = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(input))) {
            String linie;

            while ((linie = br.readLine()) != null) {
                linie = linie.trim();
                if (linie.isEmpty()) continue;

                try {
                    valori.add(Double.parseDouble(linie));
                } catch (Exception e) {
                    System.err.println("Valoare invalidă: " + linie);
                }
            }
        } catch (IOException e) {
            System.err.println("Eroare la citire!");
            return;
        }

        if (valori.isEmpty()) {
            System.out.println("Nu există valori valide.");
            return;
        }

        double suma = 0;
        double min = Double.POSITIVE_INFINITY;
        double max = Double.NEGATIVE_INFINITY;
        int subZeroCount = 0;

        for (double t : valori) {
            suma += t;
            if (t < min) min = t;
            if (t > max) max = t;
            if (t < 0) subZeroCount++;
        }

        double medie = suma / valori.size();

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(raport))) {
            bw.write("Numar valori: " + valori.size()); bw.newLine();
            bw.write("Temperatura medie: " + String.format("%.2f", medie)); bw.newLine();
            bw.write("Temperatura minima: " + String.format("%.2f", min)); bw.newLine();
            bw.write("Temperatura maxima: " + String.format("%.2f", max)); bw.newLine();
            bw.write("Valori sub zero: " + subZeroCount); bw.newLine();
        } catch (IOException e) {
            System.err.println("Eroare scriere raport!");
        }

        
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(subZero))) {
            for (double t : valori) {
                if (t < 0) {
                    bw.write(String.valueOf(t));
                    bw.newLine();
                }
            }
        } catch (IOException e) {
            System.err.println("Eroare scriere fișier sub zero!");
        }

        System.out.println("Gata! Fișiere generate.");
    }
}
