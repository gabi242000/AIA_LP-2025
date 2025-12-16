package tema9;
import java.io.*;
import java.util.*;

public class Angajati {
    public static void main(String[] args) {
        String fisier = "angajati.txt";
        List<String[]> lista = new ArrayList<>(); 

        File f = new File(fisier);
        if (!f.exists()) {
            System.out.println("Fisierul nu exista.");
            return;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(f))) {
            String linie;
            while ((linie = br.readLine()) != null) {
                String[] parts = linie.split(" ");
                if (parts.length != 3) continue;
                lista.add(parts);
            }
        } catch (IOException e) {
            System.out.println("Eroare la citire.");
            return;
        }

        double suma = 0, maxSalariu = Double.MIN_VALUE;
        String angajatMax = "";

        for (String[] a : lista) {
            double s = Double.parseDouble(a[2]);
            suma += s;
            if (s > maxSalariu) {
                maxSalariu = s;
                angajatMax = a[0] + " " + a[1];
            }
        }

        double medie = suma / lista.size();

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("venit_peste_medie.txt"))) {
            for (String[] a : lista) {
                double s = Double.parseDouble(a[2]);
                if (s > medie) {
                    bw.write(a[0] + " " + a[1] + " " + s);
                    bw.newLine();
                }
            }
        } catch (IOException e) { System.out.println("Eroare la scrierea fisierului"); }

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("raport_angajati.txt"))) {
            bw.write("Numar angajati: " + lista.size());
            bw.newLine();
            bw.write("Salariu mediu: " + medie);
            bw.newLine();
            bw.write("Angajat cu salariu maxim: " + angajatMax + " " + maxSalariu);
        } catch (IOException e) { System.out.println("Eroare la scrierea raportului"); }
    }
}
