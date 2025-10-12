import java.io.*;
public class ex2 {
    public static void main(String[] args) throws IOException{
        System.out.println("Va rog introduceti un numar: ");
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s = br.readLine();
        int n = Integer.parseInt(s);
        int maxim = -1;
        int minim = 11;
        while (n != 0){
            if (n % 10 > maxim)
                maxim = n % 10;
            if (n % 10 < minim)
                minim = n % 10;
            n = n / 10;
        }
        System.out.print("Cea mai mare cifra este " + maxim + " si cea mai mica este " + minim);
    }
}
