import java.sql.*;
import java.util.*;

public class TranzactiiDAO {

    private final String url = "jdbc:sqlite:realestate.db?busy_timeout=5000";

    public void TransferProprietar(String nume_cumparator, int ID){
        String sql = "UPDATE Proprietati SET NumeUtilizator = ? WHERE ID =?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setString(1, nume_cumparator);
                pstmt.setInt(2,ID);

                pstmt.executeUpdate();
                

            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }

    }


    public void InregistrareTranzactie(String nume_vanzator, String nume_cumparator,
                                        String titlu_proprietate,String tip_proprietate, double suma_tranzactie, 
                                            boolean  vanzare, boolean inchiriere){


            String sql = "INSERT INTO Tranzactii(NumeVanzator ,TitluProprietate, TipProprietate, PretAchizitie, NumeCumparator, TipAchizitie) VALUES(?,?,?,?,?,?)";

            try(Connection conn = DriverManager.getConnection(url);
                PreparedStatement pstmt = conn.prepareStatement(sql)){

                    pstmt.setString(1,nume_vanzator);
                    pstmt.setString(2,titlu_proprietate);
                    pstmt.setString(3,tip_proprietate);
                    pstmt.setDouble(4,suma_tranzactie);
                    pstmt.setString(5,nume_cumparator);
                    if(vanzare) pstmt.setString(6, "Vanzare");
                    else if(inchiriere) pstmt.setString(6, "Inchiriere");

                    pstmt.executeUpdate(); 

                    
                



                    }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
                                            }

                
    
      }


      public List<Tranzactii>  AfisareTranzactii(String nume_utilizator){
        List<Tranzactii> tranzactii = new ArrayList<>();
        String sql = "SELECT * FROM Tranzactii WHERE NumeCumparator = ? OR NumeVanzator = ?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){
                pstmt.setString(1,nume_utilizator);
                pstmt.setString(2,nume_utilizator);

                ResultSet rs = pstmt.executeQuery();

                while(rs.next()){
                    Tranzactii tranzactie = new Tranzactii();

                    tranzactie.setTitluProprietate(rs.getString("TitluProprietate"));
                    tranzactie.setVanzator(rs.getString("NumeVanzator"));
                    tranzactie.setCumparator(rs.getString("NumeCumparator"));
                    tranzactie.setPret(rs.getDouble("PretAchizitie"));
                    tranzactie.setTipAchizitie(rs.getString("TipAchizitie"));

                    tranzactii.add(tranzactie);
                }

                

            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }


            return tranzactii;
      }


    

      
}
