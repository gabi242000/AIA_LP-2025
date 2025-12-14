package temafisiere;

import java.io.*;

public class ex1 {
    public static void main(String[] args) {
        File fisier = new File("angajati.txt");

        if (!fisier.exists()) {
            System.out.println("Fisierul angajati.txt nu exista!");
            return;
        }

        int nrAngajati = 0;
        double suma = 0.0;

        double salariuMax = 0;
        String angajatMax = ""; 


        try (BufferedReader br = new BufferedReader(new FileReader(fisier))) {
            String linie;

            while ((linie = br.readLine()) != null) {
                linie = linie.trim();
                if (linie.isEmpty()) continue;

                String[] parti = linie.split("\\s+"); 
                if (parti.length < 3) continue;       

                String nume = parti[0];
                String prenume = parti[1];
                double salariu = Double.parseDouble(parti[2]);

                nrAngajati++;
                suma += salariu;

                if (salariu > salariuMax) {
                    salariuMax = salariu;
                    angajatMax = nume + " " + prenume;
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la citirea fisierului.");
            return;
        } catch (NumberFormatException e) {
            System.out.println("Eroare: exista un salariu care nu e numar.");
            return;
        }

        if (nrAngajati == 0) {
            System.out.println("Fisierul nu contine angajati validi.");
            return;
        }

        double salariuMediu = suma / nrAngajati;


        try (
            BufferedReader br = new BufferedReader(new FileReader(fisier));
            BufferedWriter bw = new BufferedWriter(new FileWriter("venit_peste_medie.txt"))) {
            String linie;

            while ((linie = br.readLine()) != null) {
                linie = linie.trim();
                if (linie.isEmpty()) continue;

                String[] parti = linie.split("\\s+");
                if (parti.length < 3) continue;

                double salariu = Double.parseDouble(parti[2]);

                if (salariu > salariuMediu) {
                    bw.write(linie);
                    bw.newLine();
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la scrierea venit_peste_medie.txt.");
            return;
        } catch (NumberFormatException e) {
            System.out.println("Eroare: exista un salariu care nu e numar (la a doua citire).");
            return;
        }


        try (BufferedWriter raport = new BufferedWriter(new FileWriter("raport_angajati.txt"))) {
            raport.write("Numar total angajati: " + nrAngajati);
            raport.newLine();
            raport.write("Salariu mediu: " + salariuMediu);
            raport.newLine();
            raport.write("Angajat cu salariu maxim: " + angajatMax);
            raport.newLine();
            raport.write("Salariu maxim: " + salariuMax);
        } catch (IOException e) {
            System.out.println("Eroare la scrierea raport_angajati.txt.");
            return;
        }

        System.out.println("Gata! Am generat venit_peste_medie.txt si raport_angajati.txt");
    }
}
