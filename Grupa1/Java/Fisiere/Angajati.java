package Grupa1.Java.Fisiere;

import java.io.*;

public class Angajati {
    public static void main(String[] args) {
        
        File file = new File("Grupa1/Java/Fisiere/angajati.txt");

        if(!file.exists()){
            System.out.println("Fisierul nu exista.");
            return;
        }

        int nr_angajati=0;
        double salariu_mediu=0.0;
        String angajat_salariu_maxim="";
        double salariu_maxim = 0;

        try(BufferedReader br = new BufferedReader(new FileReader(file))) {
            String linie;

            while((linie=br.readLine())!=null){
                String[] date = linie.split(" ");
                String nume = date[0];
                String prenume = date[1];
                double salariu = Double.parseDouble(date[2]);

                salariu_mediu += salariu;
                nr_angajati++;
                if(salariu > salariu_maxim){
                    salariu_maxim = salariu;
                    angajat_salariu_maxim = nume + " " + prenume;
                }

            }
            salariu_mediu /= nr_angajati;

        



        }catch (IOException e){
            System.out.println("Eroare la citirea fisierului: " + e.getMessage());
        }


        try(BufferedReader br = new BufferedReader(new FileReader(file));
        BufferedWriter bw2 = new BufferedWriter(new FileWriter("Grupa1/Java/Fisiere/venit_peste_medie.txt"))){
            String linie;

            while((linie = br.readLine()) !=null){
                String[] date = linie.split(" ");
                String nume = date[0];
                String prenume = date[1];
                double salariu = Double.parseDouble(date[2]);

                if(salariu > salariu_mediu){
                    bw2.write(nume + " " + prenume + " " + salariu);
                    bw2.newLine();
                }

            }


        } catch (IOException e){
            System.out.println("Eroare la procesarea fisierului: " + e.getMessage());
        }

        

        try(BufferedWriter bw = new BufferedWriter(new FileWriter("Grupa1/Java/Fisiere/raport_angajati.txt"))){

            bw.write("Numar total angajati: " + nr_angajati);
            bw.newLine();
            bw.write("Salariu mediu: " + String.format("%.2f", salariu_mediu));
            bw.newLine();
            bw.write("Angajat cu salariu maxim: " + angajat_salariu_maxim );
            bw.newLine();
            

            }catch (IOException e){
            System.out.println("Eroare la scrierea in fisier: " + e.getMessage());
        }


    


    }
}
