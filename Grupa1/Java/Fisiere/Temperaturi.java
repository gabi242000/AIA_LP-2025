package Grupa1.Java.Fisiere;

import java.io.*;

public class Temperaturi {
    public static void main(String[] args) {
        
        File file  = new File("Grupa1/Java/Fisiere/temperaturi.txt");

        if(!file.exists()){
            System.out.println("Fisierul nu exista.");
            return;
        }

        double temp_medie=0;
        double temp_max = 0.0;
        double temp_min = 999.9;
        int nr_temp_sub_0=0;

        try(BufferedReader br = new BufferedReader(new FileReader(file));
            BufferedWriter bw = new BufferedWriter(new FileWriter("Grupa1/Java/Fisiere/temp_sub_zero.txt"))){

                String linie;

                double suma_temperaturi = 0.0;
                int nr_temperaturi=0;

                while((linie= br.readLine())!= null){
                    double temperatura = Double.parseDouble(linie);

                    nr_temperaturi++;

                    if(temperatura < 0){
                        bw.write(linie);
                        bw.newLine();
                        nr_temp_sub_0++;
                    }

                    if(temperatura > temp_max)
                        temp_max = temperatura;
                    

                    if(temperatura < temp_min)
                        temp_min = temperatura;

                    suma_temperaturi += temperatura;
                    
                    

                }

                temp_medie = suma_temperaturi / nr_temperaturi;

        }catch (IOException e){
            System.out.println("Eroare la citirea fisierului: " + e.getMessage());
        }



        try(BufferedWriter bw = new BufferedWriter(new FileWriter("Grupa1/Java/Fisiere/raport_temperaturi.txt"))){


            bw.write("Temperatura medie : "+ temp_medie);
            bw.newLine();
            bw.write("Temperatura maxima: "+ temp_max);
            bw.newLine();
            bw.write("Temperatura minima: "+temp_min);
            bw.newLine();
            bw.write("Numarul temperaturilor negative: "+ nr_temp_sub_0);
        }catch (IOException e){
            System.out.println("Eroare la scrierea raportului: " + e.getMessage());
        }


    }

}
