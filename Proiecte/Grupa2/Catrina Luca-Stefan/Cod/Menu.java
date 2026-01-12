package game;

import java.util.Scanner;

public class Menu {

    private Scanner scanner = new Scanner(System.in);

    public int showMainMenu() {
        System.out.println("===== MENIU PRINCIPAL =====");
        System.out.println("1. Joaca");
        System.out.println("2. Reguli");
        System.out.println("3. Iesire");
        System.out.print("Alege o optiune: ");
        return scanner.nextInt();
    }

    public int chooseDifficulty() {
        System.out.println("\n--- Alege dificultatea ---");
        System.out.println("1. Easy (1–100, 12 incercari)");
        System.out.println("2. Medium (1–500, 10 incercari)");
        System.out.println("3. Hard (1–1000, 8 incercari)");
        System.out.print("Optiune: ");
        return scanner.nextInt();
    }
}
