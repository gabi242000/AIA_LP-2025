import java.io.*;
public class ex1 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        System.out.println("Va rog introduceti un numar: ");
        String s = br.readLine();
        int ok = 0;
        for (int i=0; i<s.length(); i++) {
            if (Character.isLetter(s.charAt(i))) {
                ok = 1;
                break;
            }
        }
        if (ok == 1) {
            System.out.print("Valoarea introdusa nu este numar natural valid");
        }else {
            int numar = Integer.parseInt(s);
            if(numar % 2 == 0)
                System.out.print("Valoarea este un numar par");
            else
                System.out.print("Valoarea este un numar impar");
        }
    }
}
