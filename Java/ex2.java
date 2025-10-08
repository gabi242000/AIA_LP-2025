import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ex2 {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            System.out.print("Introdu primul număr: ");
            int a = Integer.parseInt(br.readLine());

            System.out.print("Introdu al doilea număr: ");
            int b = Integer.parseInt(br.readLine());

            System.out.print("Introdu al treilea număr: ");
            int c = Integer.parseInt(br.readLine());

            int s = a + b + c;
            double ma = s / 3.0;

            
            int maxim = Math.max(a, Math.max(b, c));
            int minim = Math.min(a, Math.min(b, c));

          
            System.out.println("Suma celor trei numere este: " + s);
            System.out.println("Media aritmetică este: " + ma);
            System.out.println("Cel mai mare număr este: " + maxim);
            System.out.println("Cel mai mic număr este: " + minim);

        } catch (IOException e) {
            System.out.println("Eroare! " + e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("Trebuie sa introduci doar numere întregi!");
        }
    }
}

