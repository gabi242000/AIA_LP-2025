import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;



public class UtilizatorDAO {

    

    private Utilizator utilizator;

    public UtilizatorDAO(Utilizator utilizator){
        this.utilizator = utilizator;
    }

    public UtilizatorDAO(){
        
    }

    
    private final String url = "jdbc:sqlite:realestate.db?busy_timeout=5000";


    public Utilizator ReturneazaUtilizator(String nume_utilizator){
        String sql = "SELECT  * FROM Utilizatori WHERE NumeUtilizator = ?";
        

        Utilizator localUtilizator = null;
        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){
                
                
                pstmt.setString(1,nume_utilizator);
                ResultSet rs =pstmt.executeQuery();

                if(rs.next()){
                    localUtilizator = new Utilizator();

                    localUtilizator.setNume(rs.getString("Nume"));
                    localUtilizator.setPrenume(rs.getString("Prenume"));
                    localUtilizator.setNumeUtilizator(rs.getString("NumeUtilizator"));
                    localUtilizator.setEmail(rs.getString("Email"));
                    localUtilizator.setParola(rs.getString("Parola"));
                    localUtilizator.setTara(rs.getString("Tara"));
                    localUtilizator.setOras(rs.getString("Oras"));
                    localUtilizator.setTelefon(rs.getString("Telefon"));
                    localUtilizator.setBalanta(rs.getDouble("Balanta"));

                }

            }catch(SQLException e){
                System.out.println("Eroare la conectare: "+ e.getMessage());
            }
            return localUtilizator;
    }

    

    public void AdaugareBani(double suma,String nume_utilizator){

        
        String sql = "UPDATE Utilizatori SET Balanta  = Balanta + ? WHERE NumeUtilizator = ?";

        try(Connection conn  = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

            pstmt.setDouble(1,suma);
            pstmt.setString(2,nume_utilizator);

            pstmt.executeUpdate();

            }catch(SQLException e){
                System.out.println("Eroare la conectare:"+ e.getMessage());
                        }

        
    }

    public void RetragereBani(double suma, String nume_utilizator){
       
        String sql = "UPDATE Utilizatori SET Balanta  = Balanta - ? WHERE NumeUtilizator = ?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){
                pstmt.setDouble(1,suma);
                pstmt.setString(2,nume_utilizator);

                pstmt.executeUpdate();
            } catch(SQLException e){
                System.out.println("Eroare la conecyare: "+ e.getMessage());
            }


    }

    public double BalantaActualizata(String nume_utilizator){

        String sql = "SELECT Balanta FROM Utilizatori WHERE NumeUtilizator = ?";

        try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setString(1,nume_utilizator);

                ResultSet rs = pstmt.executeQuery();

                if(rs.next()){
                    return rs.getDouble("Balanta");
                }


            }catch(SQLException e){
                System.out.println("Eroare la conectare:" + e.getMessage());
            }
        return 0;

    }

    
    
}
