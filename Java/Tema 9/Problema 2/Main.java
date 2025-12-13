import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        File f = new File("temperaturi.txt");

        if (!f.exists()) {
            System.out.println("Fisierul temperaturi.txt nu exista.");
            return;
        }

        double suma = 0;
        double min = 0;
        double max = 0;
        int count = 0;
        int subZero = 0;

        try (Scanner sc = new Scanner(f);
             BufferedWriter bwNeg = new BufferedWriter(new FileWriter("temp_sub_zero.txt", false))) {

            while (sc.hasNextLine()) {
                String linie = sc.nextLine().trim();
                if (linie.isEmpty()) continue;

                double t;
                try {
                    t = Double.parseDouble(linie);
                } catch (NumberFormatException e) {
                    continue;
                }

                if (count == 0) {
                    min = t;
                    max = t;
                } else {
                    if (t < min) min = t;
                    if (t > max) max = t;
                }

                suma += t;
                count++;

                if (t < 0) {
                    subZero++;
                    bwNeg.write(String.valueOf(t));
                    bwNeg.newLine();
                }
            }

        } catch (FileNotFoundException e) {
            System.out.println("Nu pot deschide temperaturi.txt.");
            return;
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului temp_sub_zero.txt.");
            return;
        }

        if (count == 0) {
            System.out.println("Fisierul temperaturi.txt nu contine valori valide.");
            try (BufferedWriter bwRaport = new BufferedWriter(new FileWriter("raport_temperaturi.txt", false))) {
                bwRaport.write("Nu exista temperaturi valide in fisier.");
                bwRaport.newLine();
            } catch (IOException e) {
                System.out.println("Eroare la scrierea raport_temperaturi.txt.");
            }
            return;
        }

        double medie = suma / count;

        try (BufferedWriter bwRaport = new BufferedWriter(new FileWriter("raport_temperaturi.txt", false))) {
            bwRaport.write("Numar valori citite: " + count);
            bwRaport.newLine();
            bwRaport.write("Temperatura medie: " + medie);
            bwRaport.newLine();
            bwRaport.write("Temperatura minima: " + min);
            bwRaport.newLine();
            bwRaport.write("Temperatura maxima: " + max);
            bwRaport.newLine();
            bwRaport.write("Numar valori sub 0°C: " + subZero);
            bwRaport.newLine();
        } catch (IOException e) {
            System.out.println("Eroare la scrierea fisierului raport_temperaturi.txt.");
            return;
        }

        System.out.println("Gata. Au fost generate: temp_sub_zero.txt si raport_temperaturi.txt");
    }
}
