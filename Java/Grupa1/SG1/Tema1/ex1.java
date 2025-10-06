

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ex1 {
    public static void main(String[] args) {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader bfr = new BufferedReader(isr);

        System.out.print("numar natural: ");
        try {
            String input = bfr.readLine();
            int n = Integer.parseInt(input);

            if (n < 0) {
                System.out.println("nr invalid");
            } else {
                if (n % 2 == 0) {
                    System.out.println(n +" este nr par.");
                } else {
                    System.out.println(n + " este nr impar.");
                }
            }
        } catch (NumberFormatException e) {
            System.out.println("nr invalid");
        } catch (IOException e) {
            System.out.println("eroare");
        }
    }
}
