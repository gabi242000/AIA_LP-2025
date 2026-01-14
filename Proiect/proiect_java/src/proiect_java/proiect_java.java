package proiect_java;
import java.util.Scanner;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.IOException;

public class proiect_java {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Alege criptare/decriptare :");
        System.out.println("1. Criptare");
        System.out.println("2. Decriptare");

        int operation = scanner.nextInt();
        scanner.nextLine(); 
        
        System.out.println("\nText scris/fisier:");
        System.out.println("1. Scris");
        System.out.println("2. Fisier");
        
        int inputChoice = scanner.nextInt();
        scanner.nextLine(); 
        
        String text = "";
        
        if (inputChoice == 1) {
            System.out.print("\nTextul: ");
            text = scanner.nextLine();
        } else if (inputChoice == 2) {
            System.out.print("\nNumele fisierului: ");
            String inputPath = scanner.nextLine();
            try {
                BufferedReader reader = new BufferedReader(new FileReader(inputPath));
                StringBuilder fileContent = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    fileContent.append(line).append("\n");
                }
                reader.close();
                text = fileContent.toString();
                System.out.println("Fisier gasit!");
            } catch (IOException e) {
                System.out.println("Problema fisier: " + e.getMessage());
                scanner.close();
                return;
            }
        } else {
            System.out.println("Alegere invalida!");
            scanner.close();
            return;
        }
        
        System.out.println("\nAlege algoritmul:");
        System.out.println("1. Caesar Cipher");
        System.out.println("2. XOR Cipher");
        System.out.println("3. Atbash Cipher");

        int algorithm = scanner.nextInt();
        scanner.nextLine(); 
        
        String result = "";
        
        switch (algorithm) {
            case 1: 
                System.out.print("Alege un numar (1-94): ");
                int shift = scanner.nextInt();
                scanner.nextLine();
                if (operation == 1) {
                    result = caesarEncrypt(text, shift);
                } else {
                    result = caesarDecrypt(text, shift);
                }
                break;
                
            case 2: 
                System.out.print("Scrie cheia : ");
                char key = scanner.next().charAt(0);
                scanner.nextLine();
                result = xorCipher(text, key);
                break;
                
            case 3: 
                result = atbashCipher(text);
                break;
                
            default:
                System.out.println("Alegere invalida!");
                scanner.close();
                return;
        }
        
        System.out.println("\n--- Rezultat ---");
        System.out.println(result);
        
        System.out.print("\nScrie fisierul output: ");
        String outputPath = scanner.nextLine();
        
        try {
            FileWriter writer = new FileWriter(outputPath);
            writer.write(result);
            writer.close();
            System.out.println("Rezultat salvat in: " + outputPath);
        } catch (IOException e) {
            System.out.println("Eroare scriere: " + e.getMessage());
        }
        
        scanner.close();
    }
    
    public static String caesarEncrypt(String text, int shift) {
        StringBuilder result = new StringBuilder();
        int range = 95; 
        shift = shift % range; 
        
        for (char c : text.toCharArray()) {
            if (c >= 32 && c <= 126) { 
                int shifted = ((c - 32 + shift) % range) + 32;
                result.append((char) shifted);
            } else {
                result.append(c); 
            }
        }
        return result.toString();
    }
    
    public static String caesarDecrypt(String text, int shift) {
        int range = 95;
        return caesarEncrypt(text, range - (shift % range));
    }
    
    public static String xorCipher(String text, char key) {
        StringBuilder result = new StringBuilder();
        
        for (char c : text.toCharArray()) {
            result.append((char) (c ^ key));
        }
        return result.toString();
    }
    
    public static String atbashCipher(String text) {
        StringBuilder result = new StringBuilder();
        
        for (char c : text.toCharArray()) {
            if (Character.isUpperCase(c)) {
                char reversed = (char) ('Z' - (c - 'A'));
                result.append(reversed);
            } else if (Character.isLowerCase(c)) {
                char reversed = (char) ('z' - (c - 'a'));
                result.append(reversed);
            } else {
                result.append(c); 
            }
        }
        return result.toString();
    }
}