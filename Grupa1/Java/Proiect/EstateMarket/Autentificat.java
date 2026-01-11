import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



    public class Autentificat {

        String[] args={};

        

        Scanner scanner = new Scanner(System.in);
        private final Utilizator utilizator;


        public Autentificat(Utilizator utilizator){
                this.utilizator = utilizator;
        }


        TranzactiiDAO tdao = new TranzactiiDAO();

        


        public void afisareAnunt(model_proprietate prop_selectata, int numar_proprietate){
            System.out.println();
                                                System.out.println();
                                                System.out.println("Ai ales proprietatea numarul:" + numar_proprietate);
                                                System.out.println("Detalii proprietate:");
                                                System.out.println("Titlu: " + prop_selectata.getTitlu());
                                                System.out.println("Descriere: " + prop_selectata.getDescriere());
                                                System.out.println("Locatie: " + prop_selectata.getLocatie());
                                                System.out.println("Pret: " + prop_selectata.getPret()+ " EUR");
                                                System.out.println("Tip proprietate: " + prop_selectata.getTipProprietate());
                                                System.out.println("Suprafata: " + prop_selectata.getSuprafata());
                                                System.out.println("Proprietate adaugata de utilizatorul: " + prop_selectata.getNumeUtilizator());
                                                System.out.println("\n\n");

        }


        public void procesareVanzare(model_proprietate prop_selectata,ProprietateDAO dao){

            UtilizatorDAO cumparatordao = new UtilizatorDAO(utilizator);
            UtilizatorDAO vanzatordao = new UtilizatorDAO();
            Utilizator vanzator = vanzatordao.ReturneazaUtilizator(prop_selectata.getNumeUtilizator());

            if(utilizator.getBalanta() < prop_selectata.getPret()) System.out.println("Fonduri insuficiente!");
                                                    
            else{                                        
            
            tdao.InregistrareTranzactie(vanzator.getNumeUtilizator(), utilizator.getNumeUtilizator(),
            prop_selectata.getTitlu(), prop_selectata.getTipProprietate(),prop_selectata.getPret(), prop_selectata.getDeVanzare()
            , prop_selectata.getDeInchiriat());
            cumparatordao.RetragereBani(prop_selectata.getPret(), utilizator.getNumeUtilizator());
            vanzatordao.AdaugareBani(prop_selectata.getPret(), vanzator.getNumeUtilizator());
            utilizator.setBalanta(cumparatordao.BalantaActualizata(utilizator.getNumeUtilizator()));
            prop_selectata.setStatus("INACTIV");
            dao.AcualizareStatus(prop_selectata.getStatus(), prop_selectata.getID());
            tdao.TransferProprietar(utilizator.getNumeUtilizator(),prop_selectata.getID());
            System.out.println("Tranzactie efectuata cu succes! Accesati Proprietatile mele pentru a vedea noua ta proprietate.");
            }
                 
                                                     
        }

        public void procesareChirie(model_proprietate prop_selectata, ProprietateDAO dao){

            try{

            UtilizatorDAO cumparatordao = new UtilizatorDAO(utilizator);
            UtilizatorDAO vanzatordao = new UtilizatorDAO();
            Utilizator vanzator = vanzatordao.ReturneazaUtilizator(prop_selectata.getNumeUtilizator());

            

                tdao.InregistrareTranzactie(vanzator.getNumeUtilizator(), utilizator.getNumeUtilizator(),
                prop_selectata.getTitlu(), prop_selectata.getTipProprietate(),prop_selectata.getPret(), prop_selectata.getDeVanzare()
                , prop_selectata.getDeInchiriat());
                 cumparatordao.RetragereBani(prop_selectata.getPret(), utilizator.getNumeUtilizator());
                 vanzatordao.AdaugareBani(prop_selectata.getPret(), vanzator.getNumeUtilizator());
                 utilizator.setBalanta(cumparatordao.BalantaActualizata(utilizator.getNumeUtilizator()));
                 prop_selectata.setStatus("CHIRIE");
                 prop_selectata.setProfit(prop_selectata.getPret());
                 dao.AcualizareStatus(prop_selectata.getStatus(), prop_selectata.getID());
                 dao.ActualizareCumparator(utilizator.getNumeUtilizator(), prop_selectata.getID());
                 dao.ActualizareProfit(prop_selectata.getProfit(), prop_selectata.getID());
            }catch(Exception e){
                e.printStackTrace();
            }
                 
        }

        
                                                    
                
        


        public void meniu() throws SQLException{
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println("Bine ai venit "+ utilizator.getNume() + " " + utilizator.getPrenume());
            System.out.println("===================EstateMarket====================");

            ProprietateDAO dao = new ProprietateDAO();


            while (true) { 
                System.out.println("1.Afiseaza proprietati");
                System.out.println("2.Cauta proprietate");
                System.out.println("3.Adauga proprietate");
                System.out.println("4.Proprietatile mele");
                System.out.println("5.Profilul meu");
                System.out.println("6.Balanta");
                System.out.println("7.Deconectare");

                int optiune = scanner.nextInt();
                scanner.nextLine();
                
                switch (optiune) {
                    case 1 -> {
                                    System.out.println("===================Proprietati====================");
                                    List<model_proprietate> lista_proprietati = dao.AfisajProprietati();
                                    System.out.println("\n\n");
                                    
                                    System.out.println("1.Selectare proprietate");
                                    System.out.println("2.Inapoi");
                                    int optiune_proprietati = scanner.nextInt();
                                    scanner.nextLine();
                                    

                                    switch(optiune_proprietati){
                                        case 1 -> {
                                            System.out.println(lista_proprietati.size());
                                            System.out.println("Introdu numarul proprietatii dorite:");
                                             int numar_proprietate = scanner.nextInt();
                                            scanner.nextLine();
                                            if(numar_proprietate>=0 && numar_proprietate<=lista_proprietati.size()){
                                                model_proprietate prop_selectata = lista_proprietati.get(numar_proprietate-1);
                                                System.out.println(prop_selectata.getID());
                                                afisareAnunt(prop_selectata, numar_proprietate);
                                                System.out.println("Doriti achizitionarea/inchirierea acestei proprietati?");
                                                System.out.println("1.Da");
                                                System.out.println("2.Nu");

                                                int optiune_achizitie = scanner.nextInt();
                                                scanner.nextLine();
                                                
                                                if(optiune_achizitie==1){
                                                    
                                                    if(prop_selectata.getDeVanzare())
                                                         procesareVanzare(prop_selectata,dao);
                                                    else if(prop_selectata.getDeInchiriat())
                                                        procesareChirie(prop_selectata, dao);
                                                    
                                                }
                                                else if(optiune_achizitie ==2){
                                                    System.out.println("Tranzactie anulata!");
                                                    meniu();
                                            }
                                            
                                        }
                        }

                                         
                                        
                                        }
                                    }

                    case 2 -> {
                        System.out.println("===================CautareProprietate====================");               
                        
                        System.out.println("Introduceti datele de cautare:");
                        
                        String tip_proprietate_f;
                        String locatie_f;
                        double suprafata_f;
                        double pret_f;
                        
                        System.out.println("Tip Proprietate:");
                        tip_proprietate_f = scanner.nextLine();
                        System.out.println("Locatie:"); 
                        locatie_f = scanner.nextLine();
                        System.out.println("Suprafata:");
                        suprafata_f = scanner.nextDouble();
                        scanner.nextLine();
                        System.out.println("Pret:");
                        pret_f = scanner.nextDouble();
                        scanner.nextLine();
                        dao.Filtrare(tip_proprietate_f, locatie_f, suprafata_f, pret_f);
                    }
                    case 3 -> {
                        System.out.println("===================Adauga proprietate====================");
                        
                        model_proprietate proprietate = new model_proprietate();
                        proprietate.setNumeUtilizator(utilizator.getNumeUtilizator());
                        System.out.println();
                        System.out.println();
                        
                        System.out.println("Titlu:");
                        String titlu = scanner.nextLine();
                        proprietate.setTitlu(titlu);
                        
                        System.out.println("Descriere:");
                        String descriere = scanner.nextLine();
                        proprietate.setDescriere(descriere);
                        
                        System.out.println("Locatie:");
                        String locatie = scanner.nextLine();
                        proprietate.setLocatie(locatie);
                        
                        System.out.println("Pret:");
                        double pret = scanner.nextDouble();
                        proprietate.setPret(pret);
                        scanner.nextLine();
                        
                        System.out.println("TipProprietate:");
                        String tipProprietate = scanner.nextLine();
                        proprietate.setTipProprietate(tipProprietate);
                        
                        System.out.println("Suprafata:");
                        double suprafata = scanner.nextDouble();
                        proprietate.setSuprafata(suprafata);
                        scanner.nextLine();
                        
                        System.out.println("Selecteaza tipul de tranzactie:");
                        System.out.println("1.Vanzare");
                        System.out.println("2.Inchiriere");
                        int optiune_tranzactie = scanner.nextInt();
                        
                        if(optiune_tranzactie==1){
                            proprietate.setDeVanzare(true);
                        }
                        
                        else if(optiune_tranzactie==2){
                            proprietate.setDeInchiriat(true);
                            
                        }

                        proprietate.setStatus("INACTIV");
                        
                        
                        
                        dao.AdaugaProprietate(proprietate);
                    }
                    case 4 -> {
                        
                        System.out.println("===================Proprietatile mele====================");
                        List<model_proprietate> lista_proprietatile_mele;
                        lista_proprietatile_mele = dao.ProprietatileMele(utilizator.getNumeUtilizator());

                        System.out.println("\n\n");
                        System.out.println("1.Selectare proprietate");
                        System.out.println("2.Inapoi");

                        int optiune_proprietatile_mele  = scanner.nextInt();
                        scanner.nextLine();
                        if(optiune_proprietatile_mele==1){
                            System.out.println("Introdu numarul proprietatii dorite:");
                            int numar_proprietate = scanner.nextInt();
                            scanner.nextLine();
                            System.out.println(lista_proprietatile_mele.size());
                            if(numar_proprietate>0 && numar_proprietate<=lista_proprietatile_mele.size()){
                                model_proprietate prop_selectata = lista_proprietatile_mele.get(numar_proprietate-1);
                                afisareAnunt(prop_selectata, numar_proprietate);

                                System.out.println("Optiuni:");


                                if(prop_selectata.getStatus().equals("CHIRIE")){
                                    System.out.println("1.Anulare chirie");
                                    System.out.println("2.Vizualizare profit");
                                    System.out.println("3.Inapoi");

                                    int optiune_anunt = scanner.nextInt();
                                    scanner.nextLine();

                                    switch (optiune_anunt) {
                                        case 1 -> {
                                            System.out.println("Chirie anulata cu succes!");
                                            ServiciuChirii schirii = new ServiciuChirii(null, null, dao);
                                            schirii.IncetareChirie(prop_selectata, dao);
                                        }
                                        case 2 -> {
                                            if(prop_selectata.getNumeUtilizator().equals(utilizator.getNumeUtilizator()))
                                                System.out.println("Profitul proprietatii: " + prop_selectata.getProfit()+ "EUR/n");
                                            else System.out.println("Nu poti vedea profitul acestei proprietati deoarece nu esti proprietarul acesteia!/n");
                                        }
                                        case 3 -> meniu();
                                        default -> { System.out.println("Optiune invalida! Te rog incearca din nou!");
                                        }
                                    }
                                }

                                else if(prop_selectata.getStatus().equals("INACTIV")){


                                System.out.println("Doriti sa publicati anunt pentru aceasta proprietate?");
                                System.out.println("1.Da");
                                System.out.println("2.Nu");
                                int optiune_publicare = scanner.nextInt();
                                scanner.nextLine();

                                if(optiune_publicare == 1){
                                    System.out.println("===================Editare Anunt====================");
                                    System.out.println("Tip achizitie(1-Vanzare/2-Inchiriere):");
                                    int optiune_achizitie_edit = scanner.nextInt();
                                    scanner.nextLine();
                                    if(optiune_achizitie_edit ==1){
                                            prop_selectata.setDeVanzare(true);
                                            prop_selectata.setDeInchiriat(false);
                                                                                                          }
                                    else if(optiune_achizitie_edit == 2){
                                            prop_selectata.setDeVanzare(false);
                                            prop_selectata.setDeInchiriat(true);
                                    }
                                    if(prop_selectata.getDeVanzare()){
                                        System.out.println("Pret proprietate ");
                                        double pret_proprietate_edit = scanner.nextDouble();
                                        scanner.nextLine();
                                        prop_selectata.setPret(pret_proprietate_edit);

                                        System.out.println("Doriti sa confirmati datele?(1-Da/2-Nu)");
                                        int optiune_confirmare = scanner.nextInt();
                                        scanner.nextLine();
                                        prop_selectata.setStatus("ACTIV");
                                        if(optiune_confirmare==1){
                                            System.out.println(prop_selectata.getStatus());
                                            dao.ActualizareProprietate(prop_selectata.getPret(), prop_selectata.getDeVanzare(), 
                                            prop_selectata.getDeInchiriat(), prop_selectata.getStatus(), prop_selectata.getTitlu());

                                           
                                        
                                        }
                                        else meniu();
                                   


                                }
                                else if(prop_selectata.getDeInchiriat()){
                                    System.out.println("Pret lunar proprietate ");
                                    double pret_lunar_prop = scanner.nextInt();
                                    scanner.nextLine();
                                    prop_selectata.setPret(pret_lunar_prop);

                                    System.out.println("Doriti sa confirmati datele?(1-Da/2-Nu");
                                    int optiune_confirmare_ch = scanner.nextInt();
                                    scanner.nextLine();
                                    prop_selectata.setStatus("ACTIV");
                                    if(optiune_confirmare_ch==1){
                                        System.out.println(prop_selectata.getStatus());
                                        dao.ActualizareProprietate(prop_selectata.getPret(), prop_selectata.getDeVanzare(), 
                                        prop_selectata.getDeInchiriat(), prop_selectata.getStatus(), prop_selectata.getTitlu());

                                        
                                    }
                                    else meniu();
                                    

                                }
                                else if(optiune_publicare == 2){
                                    meniu();
                                }
                            } 

                        }
                        }

                        
                        }

                    }
                    case 5 -> {
                        System.out.println("===================Profil====================");
                        System.out.println("Nume:" + utilizator.getNume());
                        System.out.println("Prenume:" + utilizator.getPrenume());
                        System.out.println("NumeUtilizator:" + utilizator.getNumeUtilizator());
                        System.out.println("Email:" + utilizator.getEmail());
                        System.out.println("Parola:" + utilizator.getParola());
                        System.out.println("Tara:"+ utilizator.getTara());
                        System.out.println("Oras:"+ utilizator.getOras());
                        System.out.println("Telefon:"+ utilizator.getTelefon());
                        System.out.println("Balanta: "+ utilizator.getBalanta());
                        System.out.println("\n\n");
                    }
                    case 6 -> {
                        System.out.println("===================Balanta====================");
                        System.out.println("Balanta ta este de :"+ utilizator.getBalanta()+ " EUR");
                        System.out.println("1.Tranzactiile mele");
                        System.out.println("2.Adauga bani");
                        System.out.println("3.Retrage bani");
                        System.out.println("4.Inapoi");
                        int optiune_balanta = scanner.nextInt();
                        scanner.nextLine();
                        UtilizatorDAO utilizatordao = new UtilizatorDAO(utilizator);
                        
                        switch(optiune_balanta){

                            case 1 -> {
                                System.out.println("===================Tranzactiile mele====================");
                                List<Tranzactii> tranzactii = new ArrayList<>();

                                tranzactii = tdao.AfisareTranzactii(utilizator.getNumeUtilizator());
                                
                                for(int i=0;i<tranzactii.size();i++){
                                    Tranzactii tranzactie = tranzactii.get(i);
                                
                                    System.out.println((i+1)+" " +tranzactie.getTitluProprietate()+" | "+(
                                    tranzactie.getVanzator().equals(utilizator.getNumeUtilizator())?"+" +tranzactie.getPret():"-"+tranzactie.getPret())+
                                    " | " + tranzactie.getVanzator() + "-> "+ tranzactie.getCumparator() );
                                }
                                    
                                
                            }
                            case 2 -> {
                                System.out.println();   
                                System.out.println("Introdu suma dorita:");
                                double suma_adaugare = scanner.nextDouble();
                                scanner.nextLine();
                                
                                utilizatordao.AdaugareBani(suma_adaugare, utilizator.getNumeUtilizator());
                                utilizator.setBalanta(utilizatordao.BalantaActualizata(utilizator.getNumeUtilizator()));
                                System.out.println("Bani adaugati cu succes!");
                        }
                            case 3 -> {
                                System.out.println("Introdu suma dorita:");
                                double suma_retragere = scanner.nextDouble();
                                scanner.nextLine();
                                utilizatordao.RetragereBani(suma_retragere, utilizator.getNumeUtilizator());
                                utilizator.setBalanta(utilizatordao.BalantaActualizata(utilizator.getNumeUtilizator()));
                                System.out.println("Bani retrasi cu succes!");
                        }
                            case 4 ->{
                                    meniu();
                            }
                                
                            default -> System.out.println("Optiune invalida! Te rog incearca din nou");
                                
                                
                                
                        }
                    }
                    
                        case 7 -> {
                            PaginaPrincipala.main(args);
                    }
                    default -> System.out.println("Optiune invalida!Te rog incearca din nou");
                }

            }
        
         }


     }


