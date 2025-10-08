import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ex1 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Introduceți un șir de caractere: ");
        String input = reader.readLine();

        if (input.matches("[0-9]+")) {
          
            long nr = Long.parseLong(input);

            System.out.println("Numărul introdus este: " + nr);

            
            if (nr % 2 == 0) {
                System.out.println("Numărul este par.");
            } else {
                System.out.println("Numărul este impar.");
            }
        } else {
            System.out.println("Ai introdus o valoare invalida!");
        }
    }
}

