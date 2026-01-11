
/// DAO - Data Access Object

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProprietateDAO {

    Scanner scanner = new Scanner(System.in);


    private  int ID=0; 
   private final String url = "jdbc:sqlite:realestate.db?busy_timeout=5000";

   public ProprietateDAO() {
    
    String sql = "SELECT MAX(ID) FROM Proprietati";
    
    try (Connection conn = DriverManager.getConnection(url);
         Statement stmt = conn.createStatement();
         ResultSet rs = stmt.executeQuery(sql)) {
        
        if (rs.next()) {
           
            this.ID = rs.getInt(1); 
        }
    } catch (SQLException e) {
        System.out.println("Eroare la initializarea ID-ului: " + e.getMessage());
    }
}


    


    

    public void afisareRS(ResultSet rs,List<model_proprietate> proprietati) throws SQLException{
        int contor = 0;
        while(rs.next()){
            contor++;
            model_proprietate prop = new model_proprietate();

            prop.setTitlu(rs.getString("Titlu"));
            prop.setDescriere(rs.getString("Descriere"));
            prop.setLocatie(rs.getString("Locatie"));
            prop.setPret(rs.getDouble("Pret"));
            prop.setTipProprietate(rs.getString("TipProprietate"));
            prop.setSuprafata(rs.getDouble("Suprafata"));
            prop.setNumeUtilizator(rs.getString("NumeUtilizator"));
            prop.setID(rs.getInt("ID"));
            prop.setProfit(rs.getDouble("Profit"));

            String tipCumparare = rs.getString("TipCumparare");

            if(tipCumparare != null)
                if(tipCumparare.equalsIgnoreCase("Inchiriere"))
                    prop.setDeInchiriat(true);
                else if(tipCumparare.equalsIgnoreCase("Vanzare"))
                    prop.setDeVanzare(true);

            prop.setStatus(rs.getString("Status"));
            proprietati.add(prop);

            
            if(prop.getDeInchiriat()==true)
                System.out.printf("%d %s | %s | %.2f EUR /luna | %s| %s | %s | %s %n",contor,
            prop.getTitlu(), prop.getLocatie(), prop.getPret(), prop.getTipProprietate(),"inchiriere",prop.getNumeUtilizator(),prop.getStatus());

            else if(prop.getDeVanzare()==true)
                System.out.printf("%d %s | %s | %.2f EUR | %s | %s | %s | %s %n",contor,
            prop.getTitlu(), prop.getLocatie(), prop.getPret(), prop.getTipProprietate(),"vanzare",prop.getNumeUtilizator(),prop.getStatus());

        }
    }

    public void Filtrare(String tip_proprietate , String locatie, double suprafata, double pret){
        

        List<model_proprietate> proprietati_filtrate = new ArrayList<>();

        double minSuprafata = suprafata -30;
        double maxSuprafata = suprafata +30;
        double minPret = pret -1500;
        double maxPret = pret +1500;

        String sql = "SELECT * FROM Proprietati WHERE TipProprietate = ? AND Locatie = ? AND Suprafata BETWEEN ? AND ? AND Pret BETWEEN ? AND ?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setString(1,tip_proprietate);
                pstmt.setString(2,locatie);
                pstmt.setDouble(3,minSuprafata);
                pstmt.setDouble(4,maxSuprafata);
                pstmt.setDouble(5,minPret);
                pstmt.setDouble(6,maxPret);
                System.out.println("Lista proprietatilor disponibile:");

                ResultSet rs = pstmt.executeQuery();

                afisareRS(rs, proprietati_filtrate);


            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }


        

    }

    public void AcualizareStatus(String status,int ID){
        String sql = "UPDATE Proprietati SET Status = ? WHERE ID = ?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setString(1,status);
                pstmt.setInt(2,ID);

                pstmt.executeUpdate();


            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }
    }

    public void ActualizareProprietate(double pret,boolean vanzare, boolean inchiriere,String status,String titlu){
        String sql = "UPDATE Proprietati SET Pret = ? ,TipCumparare = ?, Status = ? WHERE Titlu = ? ";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setDouble(1,pret);
                if(vanzare) pstmt.setString(2,"Vanzare");
                else if(inchiriere) pstmt.setString(2,"Inchiriere");

                pstmt.setString(3,status);
                pstmt.setString(4,titlu);

                pstmt.executeUpdate();
                System.out.println("Anunt publicat cu succes!");

            }catch(SQLException e){
                System.out.println("Eroare la conectare:"+ e.getMessage());
            }

    }

    public List<model_proprietate> ProprietatileMele(String nume_utilizator){

        List<model_proprietate> proprietatile_mele = new ArrayList<>();
        String sql = "SELECT * FROM Proprietati WHERE NumeUtilizator = ? OR Status='CHIRIE'";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setString(1,nume_utilizator);

                ResultSet rs = pstmt.executeQuery();

                

                afisareRS(rs, proprietatile_mele);




            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }


            return proprietatile_mele;

        }

    public void StergeProprietate(int ID,String nume_utilizator){
        String sql = "DELETE FROM Proprietati WHERE ID = ?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setInt(1,ID);

                pstmt.executeUpdate();
                
                System.out.println("Proprietatea a fost stearsa cu succes!");


            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }
    }

    public void AdaugaProprietate(model_proprietate proprietate){

        String sql = "INSERT INTO Proprietati(Titlu,Descriere,Locatie,Pret,TipProprietate,Suprafata,NumeUtilizator,TipCumparare,Status,NumeCumparator,ID) VALUES (?,?,?,?,?,?,?,?,?,?,?)";
        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){
            ID++;
            
            pstmt.setString(1,proprietate.getTitlu());
            pstmt.setString(2,proprietate.getDescriere());
            pstmt.setString(3,proprietate.getLocatie());
            pstmt.setDouble(4,proprietate.getPret());
            pstmt.setString(5,proprietate.getTipProprietate());
            pstmt.setDouble(6,proprietate.getSuprafata());
            pstmt.setString(7,proprietate.getNumeUtilizator());
            if(proprietate.getDeInchiriat()) 
                pstmt.setString(8,"Inchiriere");
            else if(proprietate.getDeVanzare()) 
                pstmt.setString(8,"Vanzare");

            pstmt.setString(9,"INACTIV");
            pstmt.setString(10,"");
            pstmt.setInt(11,ID);

            pstmt.executeUpdate();
            System.out.println("Proprietatea a fost adaugata cu succes!");


            

            }catch(SQLException e){
                System.out.println("Eroare la conectare: " + e.getMessage());;
            }       

        

    }

    public List<model_proprietate> AfisajProprietati() throws SQLException{

        List<model_proprietate> proprietati = new ArrayList<>();
        String sql = "SELECT * FROM Proprietati WHERE Status = 'ACTIV'";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql);
            ResultSet rs = pstmt.executeQuery()){

                System.out.println("Lista proprietatilor disponibile:");

                
                afisareRS(rs, proprietati);
            }
                
            
            catch(SQLException e){
                System.out.println("Eroare la conectare:" + e.getMessage());
            }

            return proprietati;
    }


   
    public List<ChirieInfo> ChiriiActive(){

        List<ChirieInfo> chirii = new ArrayList<>();

        String sql = "SELECT * FROM Proprietati WHERE Status='CHIRIE'";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                ResultSet rs = pstmt.executeQuery();

                while(rs.next()){
                    String titlu = rs.getString("Titlu");
                    String proprietar = rs.getString("NumeUtilizator");
                    String cumparator = rs.getString("NumeCumparator");
                    double pret = rs.getDouble("Pret");
                    String tip_proprietate = rs.getString("TipProprietate");
                    boolean exista = chirii.stream().anyMatch(c->c.getTitlu().equals(titlu));
                    int ID = rs.getInt("ID");
                    double profit = rs.getDouble("Profit");

                    if(!exista) chirii.add(new ChirieInfo(titlu,proprietar,cumparator,pret,tip_proprietate,ID,profit));    
                }


               

            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }



        return chirii;
    }


    public void ActualizareCumparator(String nume_cumparator, int ID){
        String sql = "UPDATE Proprietati SET NumeCumparator = ? WHERE ID = ? ";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setString(1,nume_cumparator);
                pstmt.setInt(2,ID);

                pstmt.executeUpdate();

            }catch(SQLException e){
                System.out.println("Eroare la conectare:"  + e.getMessage());

            }
    }

    public void ActualizareProfit(double profit,int ID){
        String sql = "UPDATE Proprietati SET Profit = ? WHERE ID = ?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setDouble(1,profit);
                pstmt.setInt(2,ID);


                pstmt.executeUpdate();



            }catch(SQLException e){
                System.out.println("Eroare la conectare"+ e.getMessage());
            }
    }



            
    
}
