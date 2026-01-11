package Checkers;
public class Piece
{
    public enum Color{Red, Black}
    private Color color;
    private boolean king_status;
    
    public Piece(Color color)
    {
        this.color=color;
        this.king_status=false;
    }
    public Color getColor() {return color;}
    public boolean isKing() {return king_status;}
    public void makeKing() {this.king_status=true;}
}
