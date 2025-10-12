import java.io.*;
public class ex1  {
    public static int citire() throws  IOException{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s = br.readLine();
        return  Integer.parseInt(s);
    }
    public static int[] citirevector() throws  IOException{
        int n =  citire();
        int[] v= new int[n];
        System.out.println("Va rog introduceti sirul de numere");
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String linie = br.readLine();
        String[] p = linie.split(" ");
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(p[i]);
        }
        return v;
    }
    public static int suma(int[] v) throws  IOException{
        int s = 0;
        System.out.println("Elementele pare sunt: ");
        for (int i: v){
            if (i % 2 == 0){
                System.out.print(i + " ");
                s += i;
            }
        }
        System.out.println();
        return s;
    }
    public static void main(String[] args) throws IOException {
        System.out.println("Va rog introduceti marimea sirului: ");
        System.out.print("Suma elementelor pare este: " + suma (citirevector()));
    }

}
