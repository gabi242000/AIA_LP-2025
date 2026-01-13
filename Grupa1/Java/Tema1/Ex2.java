package Grupa1.Java.Tema1;
import java.io.*;

public class Ex2 {
    public static void main(String[] args) throws IOException{
        InputStreamReader isr = new InputStreamReader(System.in);

        BufferedReader br = new BufferedReader(isr);

        int i=1,suma=0,nr=0,min=9999,max=-9999;

        while(i<=3){
            String s = br.readLine();

            try {
                int a = Integer.parseInt(s);
                suma+=a;
                nr++;
                if(a<min) min=a;
                if(a>max) max=a;
                i++;

            }catch (NumberFormatException e) {
                System.out.println("Nu ati introdus un numar valid.");
                continue;

            
        }
    }

        System.out.println("Suma numerelor este: " + suma);
        System.out.println("Media numerelor este: " + (suma/nr));
        System.out.println("Numarul minim este: " + min);
        System.out.println("Numarul maxim este: " + max);
        


        }



        
    }

