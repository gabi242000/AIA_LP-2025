import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ex2 {
    public static void main(String[] args) throws IOException{

        System.out.println("Introdu numarul");

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s= br.readLine();
        int n= Integer.parseInt(s);

        
        int min=9, max=1;
        
        while (n>0){
            int u=n%10;
            if(u<min){
                min=u;
            }
            if(u>max){
                max=u;
            }
            n/=10;
        }

        System.out.println("cifra minima este: " + min);
        System.out.println("cifra maxima este: " + max);
    }
    

}
