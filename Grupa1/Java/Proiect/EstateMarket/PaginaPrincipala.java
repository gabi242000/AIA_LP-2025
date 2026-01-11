
import java.util.Scanner;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;


public  class PaginaPrincipala {


    public static void main(String[] args){


        ServiciuAuth serviciuAuth = new ServiciuAuth();
        Scanner scanner = new Scanner(System.in);
        
        while(true){
        System.out.println("===================EstateMarket===================");

        System.out.println("1. Autentificare");
        System.out.println("2. Inregistrare");
        System.out.println("3.Iesire");
        System.out.print("Selecteaza o optiune: ");
        int optiune = scanner.nextInt();

        switch(optiune){
            case 1 -> serviciuAuth.Autentificare();
            case 2 -> serviciuAuth.Inregistrare();
            case 3 -> System.out.println("La revedere!");
            default -> System.out.println("Optiune invalida. Te rog incearca din nou.");
        }


        ConfigDB.activeazaWAL();
        ProprietateDAO dao = new ProprietateDAO();
        UtilizatorDAO udao = new UtilizatorDAO();
        TranzactiiDAO tdao = new TranzactiiDAO();

        ServiciuChirii ServiciuChirii = new ServiciuChirii(udao, tdao, dao);
        ScheduledExecutorService scheduler =  Executors.newScheduledThreadPool(10);

        scheduler.scheduleWithFixedDelay(()->{

            ServiciuChirii.proceseazaChirii();

        }, 0, 30, TimeUnit.SECONDS);
        
        


        
    }

    

    }
    
}
