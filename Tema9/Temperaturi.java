package tema9;
import java.io.*;
import java.util.*;
public class Temperaturi{
    public static void main(String[] args) {
        String fisier = "temperaturi.txt";
        List<Double> valori = new ArrayList<>();

        File f = new File(fisier);
        if (!f.exists()) {
            System.out.println("Fisierul nu exista.");
            return;
        }

  
        try (BufferedReader br = new BufferedReader(new FileReader(f))) {
            String linie;
            while ((linie = br.readLine()) != null) {
                try { valori.add(Double.parseDouble(linie)); }
                catch (NumberFormatException e) { }
            }
        } catch (IOException e) { System.out.println("Eroare la citire"); return; }

        if (valori.isEmpty()) { System.out.println("Nu exista valori valide"); return; }

        double suma = 0, min = Double.MAX_VALUE, max = Double.MIN_VALUE;
        int subZero = 0;

        for (double t : valori) {
            suma += t;
            if (t < min) min = t;
            if (t > max) max = t;
            if (t < 0) subZero++;
        }

        double medie = suma / valori.size();

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("raport_temperaturi.txt"))) {
            bw.write("Temperatura medie: " + medie);
            bw.newLine();
            bw.write("Temperatura minima: " + min);
            bw.newLine();
            bw.write("Temperatura maxima: " + max);
            bw.newLine();
            bw.write("Numar valori sub 0: " + subZero);
        } catch (IOException e) { System.out.println("Eroare la scrierea raportului"); }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("temp_sub_zero.txt"))) {
            for (double t : valori) {
                if (t < 0) { bw.write(String.valueOf(t)); bw.newLine(); }
            }
        } catch (IOException e) { System.out.println("Eroare la scriere"); }
    }
}
