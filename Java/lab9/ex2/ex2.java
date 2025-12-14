package temafisiere;
import java.io.*;

public class ex2 {
    public static void main(String[] args) {

        File fisier = new File("temperaturi.txt");

        if (!fisier.exists()) {
            System.out.println("Fisierul temperaturi.txt nu exista");
            return;
        }

        int nrValori = 0;
        int nrSubZero = 0;

        double suma = 0.0;
        double min = Double.POSITIVE_INFINITY;
        double max = Double.NEGATIVE_INFINITY;

        try (
            BufferedReader br = new BufferedReader(new FileReader(fisier));
            BufferedWriter bwSubZero = new BufferedWriter(new FileWriter("temp_sub_zero.txt"))
        ) {
            String linie;

            while ((linie = br.readLine()) != null) {
                linie = linie.trim();
                if (linie.isEmpty()) continue;

                double temp = Double.parseDouble(linie);

                nrValori++;
                suma += temp;

                if (temp < min) min = temp;
                if (temp > max) max = temp;

                if (temp < 0) {
                    nrSubZero++;
                    bwSubZero.write(String.valueOf(temp));
                    bwSubZero.newLine();
                }
            }

        } catch (IOException e) {
            System.out.println("Eroare la citirea/scrierea fisierelor.");
            return;
        } catch (NumberFormatException e) {
            System.out.println("Eroare: o valoare nu este numar.");
            return;
        }

        if (nrValori == 0) {
            System.out.println("Fisierul nu contine temperaturi valide.");
            return;
        }

        double medie = suma / nrValori;

        try (BufferedWriter raport = new BufferedWriter(new FileWriter("raport_temperaturi.txt"))) {
            raport.write("Temperatura medie: " + medie);
            raport.newLine();
            raport.write("Temperatura minima: " + min);
            raport.newLine();
            raport.write("Temperatura maxima: " + max);
            raport.newLine();
            raport.write("Numar valori sub 0°C: " + nrSubZero);
        } catch (IOException e) {
            System.out.println("Eroare la scrierea raportului.");
            return;
        }

        System.out.println("Raportul a fost generat.");
    }
}
