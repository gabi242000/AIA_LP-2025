package com.example.demo.client;
import com.example.demo.Message;
import javax.swing.*;
import java.util.concurrent.ExecutionException;

public class App {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                String username = JOptionPane.showInputDialog(null, "Enter your name:", "Whatsapp ripoff", JOptionPane.QUESTION_MESSAGE);
                if(username==null || username.isEmpty()){
                    JOptionPane.showMessageDialog(null,"Invalid Username", "ERROR", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                ClientGui clientGui = null;
                try {
                    clientGui = new ClientGui(username);
                } catch (ExecutionException e) {
                    throw new RuntimeException(e);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                clientGui.setVisible(true);
            }
        });
    }
}
