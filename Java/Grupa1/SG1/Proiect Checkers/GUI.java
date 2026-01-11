package Checkers;
import javax.swing.*;
public class GUI extends JFrame {
public GUI(){
    setTitle("Checkers");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setVisible(true);
    add (new BoardPanel());
    pack();
    setLocationRelativeTo(null);
}
}
