import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;


class tema1 {
    public static InputStreamReader isr = new InputStreamReader(System.in);
    public static BufferedReader bfr = new BufferedReader(isr);
    
    public static void ex1() throws IOException {
        String line = bfr.readLine();
        try {
            int n = Integer.parseInt(line);
            if (n % 2 == 0) {
                System.out.println("Even");
            }
            else {
                System.out.println("Odd");
            }
        } catch (NumberFormatException e) {
            System.out.println("Input invalid.");
            return;
        }        
    }

    public static void ex2() throws IOException {
        System.out.println("Introdu 3 numere:");
        String line = bfr.readLine();
        String[] parts = line.split(" ");
        int suma , num1, num2, num3 , max , m_arit , min;
        if (parts.length != 3) {
            System.out.println("Trebuie introduse exact 3 numere.(separate prin spatiu pe o singura linie)");
            return;
        }
        try {
            num1 = Integer.parseInt(parts[0]);
            num2 = Integer.parseInt(parts[1]);
            num3 = Integer.parseInt(parts[2]);
            System.out.println("Suma: " + (num1 + num2 + num3));
        } catch (NumberFormatException e) {
            System.out.println("Toate intrările trebuie să fie numere întregi.");
            return;
        }

        suma = num1 + num2 + num3;
        m_arit = suma / 3;
        max = Math.max(num1, Math.max(num2, num3));
        min = Math.min(num1, Math.min(num2, num3));
        System.out.println("Media aritmetica: " + m_arit);
        System.out.println("Maximul: " + max);
        System.out.println("Minimul: " + min);
    }

    public static void main(String[] args) throws IOException {
        while(true)
        {
            System.out.println("Alege exercitiul (1 sau 2 , 0 pentru iesire): ");
            String line = bfr.readLine();
            int x = Integer.parseInt(line);

            switch (x) {
                case 1:
                    ex1();
                    break;
                case 2:
                    ex2();
                    break;
                case 0:
                    System.out.println("Iesire...");
                    return;
                default:
                    System.out.println("Optiune invalida. Te rog alege 1 sau 2.");
                    continue;
            }
        }

        //bfr.close();
        //isr.close();
    }
    
}