package game;

import java.util.Random;
import java.util.Scanner;

public class Game {

    private Scanner scanner = new Scanner(System.in);
	private Random rand = new Random();
    private Menu menu = new Menu();
    private HintSystem hintSystem = new HintSystem();

    private int secretNumber;
    private int maxTries;
    private int range;
    private int guessH;
    private int score = 100;

    public void start() {
        boolean running = true;

        while (running) {
            int option = menu.showMainMenu();

            switch (option) {
                case 1 -> play();
                case 2 -> showRules();
                case 3 -> {
                    System.out.println("La revedere!");
                    running = false;
                }
                default -> System.out.println("Optiune invalida.\n");
            }
        }
    }

    private void showRules() {
        System.out.println("\n===== REGULI =====");
        System.out.println("Alege o dificultate.");
        System.out.println("Calculatorul genereaza un numar secret.");
        System.out.println("Tu trebuie sa il ghicesti in numarul de incercari.");
        System.out.println("Vei primi indicii: mai mare/mai mic, distanta, paritate.\n");
    }

    private void play() {
        setDifficulty();

        boolean guessed = false;
        int tries = 0;

        System.out.println("\nAm ales un numar intre 1 si " + range + ".");
        System.out.println("Ai " + maxTries + " incercari. Succes!\n");

        while (tries < maxTries && !guessed) {
            System.out.println("Introdu numarul tau: ");
            int guess = scanner.nextInt();
            tries++;
            
            guessH = guess;

            if (guess == secretNumber) {
                guessed = true;
                break;
            }

            System.out.println("Mai ai " + (maxTries - tries) + " incercari.\n");
            System.out.println("Scor: " + (score - tries));
            askHint();
        }

        if (guessed) {
            System.out.println("Felicitari! Ai ghicit numarul " + secretNumber + " in " + tries + " incercari!");
            System.out.println("Scor final: " + (score - tries + 1));
        } else {
            System.out.println("Ai pierdut! Numarul era: " + secretNumber);
        }

        askReplay();
    }

    private void setDifficulty() {
    	hintSystem.resetHints();
        int diff = menu.chooseDifficulty();

        switch (diff) {
            case 1 -> { range = 100; maxTries = 12; }
            case 2 -> { range = 500; maxTries = 10; }
            case 3 -> { range = 1000; maxTries = 8; }
            default -> {
                System.out.println("Optiune invalida, setez Medium.");
                range = 500; maxTries = 10;
            }
        }

        secretNumber = rand.nextInt(range) + 1;
    }

    private void askReplay() {
        System.out.print("\nVrei sa joci din nou? (da/nu): ");
        String answer = scanner.next();

        if (answer.equalsIgnoreCase("da")) {
            play();
        } else {
            System.out.println("Te am intors in meniul principal.\n");
        }
    }
    
    private void askHint() {
        System.out.print("\nVrei un indiciu? (da/nu): ");
        System.out.println("Ai -1 punct pentru fiecare indiciu");
        String hint = scanner.next();

        if (hint.equalsIgnoreCase("da")) {
        	hintSystem.hint(secretNumber, guessH);
        	score--;
        }
    }
    
}
