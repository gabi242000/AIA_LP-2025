package Grupa1.Java.Tema1;
import java.io.*;
public class Ex1 {
    public static void main(String[] args) throws IOException{
        InputStreamReader isr = new InputStreamReader(System.in);

        BufferedReader br = new BufferedReader(isr);

        int n=0;

        String s = br.readLine();

        try {
            n = Integer.parseInt(s);
            System.out.println("Numarul este: " + n);
        } catch (NumberFormatException e) {
            System.out.println("Nu ati introdus un numar valid.");
        }

        if(n%2==0){
            System.out.println("Numarul este par.");
        } else {
            System.out.println("Numarul este impar.");
        }


    }

       
}