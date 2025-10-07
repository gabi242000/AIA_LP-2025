package tema1;
import java.io.*;
public class ex1 {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Introduceti un numar natural: ");
        String s = br.readLine();
        int ok = 1;
        int i = 0;
        while(i<s.length()){char c=s.charAt(i);
                                if(c<'0' || c>'9'){ok = 0;
                                                          break;}
                            i++;}

        if(ok==0){System.out.println("Valoarea introdusă nu este un număr natural valid!");}
        else{int x=Integer.parseInt(s);
            System.out.println("Numarul introdus este: " + x);
            if (x % 2 == 0){System.out.println("Numarul este par.");} 
            else {System.out.println("Numarul este impar.");}
            System.out.println("Numarul de caractere din sir este: " + s.length());
        }
    }
}
