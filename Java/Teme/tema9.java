import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class tema9 {
    public static void ex1(){
        try {
            File file = new File("angajati.txt");
            Scanner scanner = new Scanner(file);
            String[][] parts = new String[100][3]; // presupunem ca nu sunt mai mult de 100 de angajati
            int index = 0;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                parts[index] = line.split(" ");
                index++;
            }
            int salar_mediu = 0;
            for (int i = 0; i < index; i++) {
                salar_mediu += Integer.parseInt(parts[i][2]);
            }
            salar_mediu /= index;

            File outputFile = new File("venit_peste_medie.txt");

            java.io.PrintWriter writer = new java.io.PrintWriter(outputFile);
            for (int i = 0; i < index; i++) {
                int salariu = Integer.parseInt(parts[i][2]);
                if (salariu > salar_mediu) {
                    writer.println(parts[i][0] + " " + parts[i][1] + " " + salariu);
                }
            }

            File outputFile2 = new File("raport_angajati.txt");
            java.io.PrintWriter writer2 = new java.io.PrintWriter(outputFile2);
            writer2.println("Numar total de angajati: " + index);
            writer2.println("Salariul mediu este: " + salar_mediu);
            writer2.print("Angajatul cu salariul cel mai mare:");
            int max_salariu = Integer.parseInt(parts[0][2]);
            String nume_max = parts[0][0];
            String prenume_max = parts[0][1];
            for (int i = 1; i < index; i++) {
                int salariu = Integer.parseInt(parts[i][2]);
                if (salariu > max_salariu) {
                    max_salariu = salariu;
                    nume_max = parts[i][0];
                    prenume_max = parts[i][1];
                }
            }
            writer2.println(nume_max + " " + prenume_max + " " + max_salariu);
            writer2.close();
            writer.close();
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Fisierul nu exista.");
            e.printStackTrace();
        }
    }

    public static void ex2(){
        try {
            File file = new File("temperaturi.txt");
            Scanner scanner = new Scanner(file);
            int temp_under_0 = 0 , avg_temp = 0 , count = 0 , min_temp = Integer.MAX_VALUE , max_temp = Integer.MIN_VALUE;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                for (String part : parts) {
                    avg_temp += Integer.parseInt(part);
                    count++;
                    int temp = Integer.parseInt(part);
                    if (temp < min_temp) {
                        min_temp = temp;
                    }
                    if (temp > max_temp) {
                        max_temp = temp;
                    }
                    if (temp < 0) {
                        temp_under_0++;
                    }
                }
                File outPutFile = new File("raport_temperaturi.txt");
                java.io.PrintWriter writer = new java.io.PrintWriter(outPutFile);
                writer.println("Temperatura minima este: " + min_temp);
                writer.println("Temperatura maxima este: " + max_temp);
                writer.println("Temperatura medie este: " + (avg_temp / count));
                writer.println("Numarul de zile cu temperatura sub 0 grade este: " + temp_under_0);
                writer.close();

                File outputFile2 = new File("temperaturi_sub_0.txt");
                java.io.PrintWriter writer2 = new java.io.PrintWriter(outputFile2);
                //salvam temperaturile sub 0 grade
                writer2.println("Temperaturi sub 0 grade:");
                scanner = new Scanner(file);
                while (scanner.hasNextLine()) {
                    String line2 = scanner.nextLine();
                    String[] parts2 = line2.split(" ");
                    for (String part2 : parts2) {
                        int temp = Integer.parseInt(part2);
                        if (temp < 0) {
                            writer2.println(temp);
                        }
                    }
                }
                writer2.close();
                scanner.close();
            }

            avg_temp /= count;
        } catch (Exception FileNotFoundException) {
            System.out.println("Fisierul nu a putut fi gasit.");
            FileNotFoundException.printStackTrace();}
    }
    public static void main(String[] args) {
        ex1();
        ex2();
    }
}
