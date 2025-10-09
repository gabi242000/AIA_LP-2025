package Tema1;
import java.io.*;
public class Exercitiu1 {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Introduceți un numar natural: ");
        String input = br.readLine();

        try {
            int numar = Integer.parseInt(input);

            if (numar < 0) {
                System.out.println("Valoarea introdusa nu este un numar natural valid (este numar negativ)");
            } else {
                System.out.println("Numarul introdus este: " + numar);
                if (numar % 2 == 0)
                    System.out.println("Numarul este par.");
                else
                    System.out.println("Numarul este impar.");
            }

        } catch (NumberFormatException e) {
            System.out.println("Valoarea introdusa nu este un numar natural valid!");
        }
    }
}
