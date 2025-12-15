package tema9;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class tema92 {
    public static void main(String args[]) {

        File fisier = new File("temperaturi.txt");
        if (!fisier.exists()) {
            System.out.println("Fisierul temperaturi.txt nu exista.");
            return;
        }

        double sumaTemp = 0;
        int nrTemp = 0;
        double tempMin = 99;
        double tempMax = 0;
        int nrSubZero = 0;

        ArrayList<Double> temperaturi = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fisier))) {
            String linie;

            while ((linie = br.readLine()) != null) {
                double temp = Double.parseDouble(linie);
                temperaturi.add(temp);

                sumaTemp += temp;
                nrTemp++;

                if (temp < tempMin) {
                    tempMin = temp;
                }
                if (temp > tempMax) {
                    tempMax = temp;
                }
                if (temp < 0) {
                    nrSubZero++;
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la citirea fisierului.");
            return;
        }

        double tempMedie = sumaTemp / nrTemp;

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("temp_sub_zero.txt"))) {
            for (double t : temperaturi) {
                if (t < 0) {
                    bw.write(String.valueOf(t));
                    bw.newLine();
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului temp_sub_zero.txt.");
        }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("raport_temperaturi.txt"))) {
            bw.write("Temperatura medie: " + tempMedie);
            bw.newLine();
            bw.write("Temperatura minima: " + tempMin);
            bw.newLine();
            bw.write("Temperatura maxima: " + tempMax);
            bw.newLine();
            bw.write("Numar temperaturi sub 0: " + nrSubZero);
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului raport_temperaturi.txt.");
        }
    }
}
