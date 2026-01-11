import java.sql.*;



public class ConfigDB {

    
    private static final String url = "jdbc:sqlite:realestate.db";

    public static void activeazaWAL(){
        try(Connection conn = DriverManager.getConnection(url);
         Statement stmt = conn.createStatement()){

            stmt.execute("PRAGMA  journal_mode=WAL;");
            

         }catch(SQLException e){
            System.out.println("Eroare la activarea WAL: " + e.getMessage());
         }
    }
}
