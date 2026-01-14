import java.io.*;
import java.util.*;

class SignUpUser{
    Scanner sc;
    String numeutil;
    String parola;
    final String Delimiter = " , ";
    final String numeFis = "User.txt";

    public SignUpUser(Scanner sc){
        this.sc = sc;
    }

    public void insertData(){
        System.out.println("--- INREGISTRARE ---");
        System.out.println("Introduceti un nume de utilizator: ");
        numeutil = sc.nextLine().trim();

        if(userExists(numeutil)){
            System.out.println("Utilizatorul cu numele " + numeutil + " exista deja!");
            return;
        }

        System.out.println("Introduceti un parola: ");
        parola = sc.nextLine().trim();


        if(numeutil.isEmpty() || parola.isEmpty()){
            System.out.println("Eroare: Numele de utilizator sau parola nu pot fi goale!");
            return;
        }
        SaveToTextFIle();
    }

    private boolean userExists(String userCheck){
        File f = new File(numeFis);
        if (!f.exists()){
            return false;
        }

        try(Scanner fileScanner = new Scanner(f)){
            while(fileScanner.hasNextLine()){
                String linie = fileScanner.nextLine();
                String[] date= linie.split(Delimiter);
                if(date.length >=1){
                    String userDinFisier = date[0];
                    if(userDinFisier.equals(userCheck)){
                        return true;
                    }
                }
            }
        }catch(FileNotFoundException e){

        }
        return false;
    }


    private void SaveToTextFIle(){
        try{
            FileWriter fw = new FileWriter(numeFis,  true);
            fw.write(numeutil + Delimiter + parola + "\n");
            fw.close();
            System.out.println("Utilizatorul a fost salvat cu succes!");
        }catch(IOException e){
            System.out.println("Eroare la scrierea in fisier: " + e.getMessage());
        }
    }

    public Boolean verificareUser(){
        System.out.println("--- Autentificare ---");
        System.out.println("Numele de utilizator: " );
        String inputUser = sc.nextLine();
        System.out.println("Parola: " );
        String inputParola = sc.nextLine();

        boolean gasit = false;

        try{
            File f = new File(numeFis);
            if(!f.exists()){
                System.out.println("Nu exista utilizatori inregistrati inca. ");
                return false;
            }
            Scanner fileScanner = new Scanner(f);

            while(fileScanner.hasNextLine()){
                String linie = fileScanner.nextLine();
                String[] date = linie.split(Delimiter);

                if(date.length >=2){
                    String userDinFisier = date[0];
                    String parolaDinFisier = date[1];

                    if(userDinFisier.equals(inputUser) && parolaDinFisier.equals(inputParola)){
                        numeutil = userDinFisier;
                        gasit = true;
                        break;
                    }
                }
            }
            fileScanner.close();
            if(gasit){
                System.out.println("Autentificarea a fost reusita! Bine ai venit ");
            }else{System.out.println("Numele de utilizator sau parola sunt gresite. ");
            }
        }catch (FileNotFoundException e){
            System.out.println("Fisierul nu a fost gasit");
        }
        return gasit;
    }
}
class Fisaevenimente {
    Scanner sc, filescanner;
    String numeutil;
    String nume, numarultelefon, emailpersonal, dataeveniment, numarpersoane, pacheteveniment, tipeveniment, culoareeveniment, florieveniment, bauturieveniment;

    private boolean esteDataOcupata(String dataDeVerificat) {
        File folder = new File(".");
        File[] listaFisiere = folder.listFiles((dir, name) -> name.endsWith(".txt") && !name.equals("User.txt"));

        if (listaFisiere != null) {
            for (File fisier : listaFisiere) {
                try (Scanner cititor = new Scanner(fisier)) {
                    int contorLinii = 0;
                    while (cititor.hasNextLine()) {
                        String linie = cititor.nextLine();
                        contorLinii++;
                        // In structura ta, data este scrisa pe a 4-a linie a fisierului
                        if (contorLinii == 4 && linie.trim().equals(dataDeVerificat.trim())) {
                            return true;
                        }
                    }
                } catch (FileNotFoundException e) {
                }
            }
        }
        return false;
    }


    public Fisaevenimente(Scanner sc, String numeutil){
        this.numeutil = numeutil;
        File f = new File(numeutil+".txt" );
        try {
            FileWriter fw = new FileWriter(f.getName(), true );

            System.out.println("Introduceți numele și prenumele: ");
            this.nume = sc.nextLine();
            fw.write(this.nume + "\n");

            boolean telefonValid = false;
            while (!telefonValid) {
                try {
                    System.out.println("Introduceți numărul de telefon (doar cifre): ");
                    String input = sc.nextLine();
                    Long.parseLong(input);
                    this.numarultelefon = input;
                    fw.write(this.numarultelefon + "\n");

                    telefonValid = true;

                } catch (NumberFormatException e) {
                    System.out.println("Eroare: Vă rugăm introduceți un număr valid (doar cifre, fără litere sau spații).");
                }
            }

            System.out.println("Introduceți emailul personal: ");
            this.emailpersonal = sc.nextLine();
            fw.write(this.emailpersonal + "\n");

            boolean dataLibera = false;
            while (!dataLibera) {
            System.out.println("Introdu data evenimentului(DD.MM.YYYY): ");
            this.dataeveniment = sc.nextLine();
            fw.write(this.dataeveniment + "\n");

            this.tipeveniment = sc.nextLine();

                if (esteDataOcupata(this.dataeveniment)) {
                    System.out.println("Atentie! Data de " + this.dataeveniment + " este deja rezervata. Te rugam alege alta data.");
                } else {
                    dataLibera = true;
                    fw.write(this.tipeveniment+ "\n");
                }
            }

            System.out.println("Introdu tipul evenimentului: ");
            this.tipeveniment = sc.nextLine();
            fw.write(this.tipeveniment + "\n");


            int x = 0;
            boolean inputValid = false;

            while (!inputValid) {
                System.out.println("Introduceti numarul aproximativ de persoane (capacitate maxim 250 de persoane): ");
                String input = sc.nextLine();

                try {
                    x = Integer.parseInt(input);

                    if (x > 250) {
                        System.out.println("Capacitatea salonului este de 250 de persoane. Va rog introduceti alt numar.");
                    } else if (x <= 0) {
                        System.out.println("Va rugam introduceti un numar pozitiv.");
                    } else {
                        this.numarpersoane = input;
                        fw.write(this.numarpersoane + "\n");
                        inputValid = true;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Eroare: Va rugam introduceti un numar valid (cifre).");
                }
            }

                boolean inputValid2 = false;
                while (!inputValid2) {
                    System.out.println("Alege uun pachet(1, 2 sau 3):\n" +
                            "1 Bronz----Culoare tematică, Open Bar pană la ora 1 cu băutură presatbilită, Meniu standard----65€/persoană\n" +
                            " " +
                            "2 Argint----Culoare tematică, Ornamente florale la alegere, Open Bar pană la ora 3 cu băutură presatbilită,\n " +
                            "Meniu standard cu degustare înainte, DJ din patea restaurantului----95€/persoană\n" +
                            " " +
                            "3 Aur----Culoare tematică, Ornamente florale la alegere, Open Bar pană la ora 6 cu băutură aleasă,\n Meniu standard cu degustare înainte,Tort personalizat cu degustare înainte, DJ din partea restaurantului,\n Fotograf din partea restauranului----150€/persoană\n");

                    this.pacheteveniment = sc.nextLine();
                    switch (this.pacheteveniment) {
                        case "1":
                            System.out.println("Pachet Bronz selectat.");

                            System.out.println("Culoarea tematica a evenimentului");
                            this.culoareeveniment = sc.nextLine();
                            fw.write("Pachet: Bronz | Open Bar: ora 1 | Meniu: Standard | Tematica:" + this.culoareeveniment + "\n");
                            inputValid2 =true;
                            break;

                        case "2":
                            System.out.println("Pachet Argint selectat.");

                            System.out.println("Culoarea tematica a evenimentului");
                            this.culoareeveniment = sc.nextLine();

                            System.out.println("Tipuri de flori dorite(maxim 3 tipuri)");
                            this.florieveniment = sc.nextLine();

                            fw.write("Pachet: Argint | Open Bar: ora 3 | DJ inclus | Degustare meniu | Tematică: " + this.culoareeveniment + " | Flori alese: " + this.florieveniment + "\n");
                            inputValid2 =true;
                            break;

                        case "3":
                            System.out.println("Pachet Aur selectat.");

                            System.out.println("Culoarea tematica a evenimentului");
                            this.culoareeveniment = sc.nextLine();

                            System.out.println("Tipuri de flori dorite(maxim 3 tipuri)");
                            this.florieveniment = sc.nextLine();

                            System.out.println("Tipul de bauturi alcoolice preferate: (tip și brand)");
                            this.bauturieveniment = sc.nextLine();

                            fw.write("Pachet: Aur | Open Bar: ora 6 | DJ + Foto | Tort inclus | Tematică: " + this.culoareeveniment + " | Flori alese: " + this.florieveniment + " | Băuturi alcoolice alese" + this.bauturieveniment + "\n");
                            inputValid2 =true;
                            break;

                        default:
                            System.out.println("Pachet invalid. Vă rugăm selectați Bronz(1), Argint(2) sau Aur(3).");
                            break;
                    }
                }
                System.out.println("Pentru a remedia orice greșeală din formular vă rog să sunați la numarul 07xx-xxx-xxx. Pentru mai multe detalii sunați la numarul 07yy-yyy-yyy.");
            fw.close();
        }catch(Exception e){
            System.out.println(e);
        }
    }

}
public class Main{
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        SignUpUser userManager = new SignUpUser(sc);

        boolean meniuInitial = true;

        while(meniuInitial){
            System.out.println("\n --- Meniu ---");
            System.out.println("1. Inregistrare");
            System.out.println("2. Autentificare");
            System.out.println("3. Iesire");
            System.out.println("Alege: ");

            String optiune = sc.nextLine();

            switch(optiune){
                            case "1":
                                userManager.insertData();
                                    break;
                            case "2":
                                boolean IsValid = userManager.verificareUser();

                                if(IsValid) {
                                    Fisaevenimente fisa = new Fisaevenimente(sc, userManager.numeutil);
                                    meniuInitial = false;
                                    }else{
                                System.out.println("Eroare");
                                }
                                      break;
                             case "3":
                                 meniuInitial = false;
                                    break;
                            default:
                                System.out.println("Optiune gresita");
            }

        }
    }
}
