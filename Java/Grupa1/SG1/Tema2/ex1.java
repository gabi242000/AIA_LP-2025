import java.io.*;


public class ex1 {
    public static void main(String[] args) throws IOException{
        System.out.println("Introduceti nr de elemente: ");
        int n =CitireNr();

        int vector[] = new int[n];

        for (int i=0; i<n; i++){
            System.out.print("elementul " + (i+1) + ": ");
            vector[i]=CitireNr();
        }

        System.out.println("");

        for (int i = 0; i < n; i++) {
            if(vector[i]%2==0)
            System.out.println("v[" +i+"] = " + vector[i]); 
        }

        System.out.println("");
        System.out.println("Suma tuturor numerelor pare este: " + SumaNrPare(vector));

    }

    public static int CitireNr() throws IOException{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s = br.readLine();
        return Integer.parseInt(s);
    }

    public static int SumaNrPare(int v[]) {
        int suma=0;
        for (int i = 0; i < v.length; i++) {
            if (v[i] % 2 == 0)
                suma+=v[i];
        }
        return suma;
    }


}
