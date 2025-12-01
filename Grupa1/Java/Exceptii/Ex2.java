package Grupa1.Java.Exceptii;
import java.util.*;
class Calculator{
    public double divide(int a, int b) throws ArithmeticException{
        if(b == 0){
            throw new ArithmeticException("Impartirea la zero nu este permisa");
        }
        return (double)a / b;
    }
}

public class Ex2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Calculator calc = new Calculator();
        try {
            System.out.println("Introduceti primul numar:");
            int num1 = scanner.nextInt();
            scanner.nextLine();
            System.out.println("Introduceti al doilea numar:");
            int num2 = scanner.nextInt();
            scanner.nextLine();
            double result = calc.divide(num1, num2);
            System.out.println("Rezultatul impartirii este: " + result);
            
        } catch (InputMismatchException e) {
            System.out.println("Eroare: Trebuie sa introduceti un numar valid.");
        } catch (ArithmeticException e) {
            System.out.println("Eroare: " + e.getMessage());
        }
    }
}