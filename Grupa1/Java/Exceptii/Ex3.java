package Grupa1.Java.Exceptii;

class InssuficientFundsException extends Exception {
    public InssuficientFundsException(String message) {
        super(message);
    }
}

class InvalidAmountException extends Exception{
    public InvalidAmountException(String message){
        super(message);
    }
}

class BankAccount {
    private double balanta;

    public BankAccount(double balanta) {
        this.balanta = balanta;
    }

    public void deposit(double suma) throws InvalidAmountException {
        if (suma <= 0) {
            throw new InvalidAmountException("Suma depusa trebuie sa fie pozitiva.");
        }
        balanta += suma;
    }

    public void withdraw(double suma) throws InssuficientFundsException,InvalidAmountException{
        if(suma<=0)
            throw new InvalidAmountException("Suma retrasa trebuie sa fie pozitiva.");
        if (suma > balanta){
            throw new InssuficientFundsException("Fonduri insuficiente pentru retragere.");
        }
        balanta -= suma;
    }
}

public class Ex3 {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(0);

        try {
            account.deposit(1000);
            account.withdraw(0);
            System.out.println("Tranzactii efectuate cu succes.");
        } catch (InvalidAmountException e) {
            System.out.println("Eroare la depunere/retragere: " + e.getMessage());
        } catch (InssuficientFundsException e) {
            System.out.println("Eroare la retragere: " + e.getMessage());
        }
    }
}
