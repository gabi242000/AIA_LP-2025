package com.example.demo.client;
import com.example.demo.Message;


import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.SynchronousQueue;

public class ClientGui extends JFrame implements MessageListener{
    private JPanel connecteduserPanel, messagePanel;
    private MyStompClient myStompClient;
    private String username;
    private JScrollPane scrollPane;
    public ClientGui(String username) throws ExecutionException, InterruptedException {
        super("User " + username);
        this.username=username;
        myStompClient = new MyStompClient(this, username);
        setSize(1218, 685);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                int option = JOptionPane.showConfirmDialog(ClientGui.this, "Are you sure you want to close this?", "Exit",JOptionPane.YES_NO_OPTION );
                if(option == JOptionPane.YES_OPTION){
                    myStompClient.disconnectUser(username);
                    ClientGui.this.dispose();
                }
            }
        });

        getContentPane().setBackground(Utilities.PrimaryColor);
        addGuiComponents();
    }
    private void addGuiComponents(){
        addConnectedUserComponents();
        addChatComponents();
    }
    private void addConnectedUserComponents(){
        connecteduserPanel = new JPanel();
        connecteduserPanel.setBorder(Utilities.addPadding(10, 10, 10, 10));
        connecteduserPanel.setLayout(new BoxLayout(connecteduserPanel, BoxLayout.Y_AXIS));
        connecteduserPanel.setBackground(Utilities.SecondaryColor);
        connecteduserPanel.setPreferredSize(new Dimension(200, getHeight()));
        connecteduserPanel.setBorder(BorderFactory.createLineBorder(Utilities.PrimaryColor));
        JLabel connectedUserLabel = new JLabel("Connected Users");
        connectedUserLabel.setFont(new Font("Arial", Font.BOLD, 18));
        connectedUserLabel.setForeground(Utilities.Text_Color);
        connecteduserPanel.add(connectedUserLabel);
        add(connecteduserPanel,  BorderLayout.WEST);
    }
    private void addChatComponents(){
        JPanel chatPanel = new JPanel();
        chatPanel.setLayout(new BorderLayout());
        chatPanel.setBackground(Utilities.Label_Color);

        messagePanel = new JPanel();
        messagePanel.setLayout(new BoxLayout(messagePanel, BoxLayout.Y_AXIS));
        messagePanel.setBackground(Utilities.PrimaryColor);


        scrollPane = new JScrollPane(messagePanel);
        scrollPane.setBackground(Utilities.TransparentColor);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPane.getVerticalScrollBar().setUnitIncrement(17);
        scrollPane.getViewport().addChangeListener(new  ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                revalidate();
                repaint();
            }
        });
        chatPanel.add(scrollPane, BorderLayout.CENTER);

        JPanel inputPanel = new JPanel();
        inputPanel.setBorder(Utilities.addPadding(10, 10, 10, 10));
        inputPanel.setLayout(new BorderLayout());
        inputPanel.setBackground(Utilities.TransparentColor);

        JTextField inputField = new JTextField();
        inputField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                if(e.getKeyChar() == KeyEvent.VK_ENTER){
                    String input = inputField.getText();
                    if(input.isEmpty()){
                        return;
                    }
                    inputField.setText("");


                    myStompClient.sendMessage(new Message(username, input));
                }
            }
        });
        inputField.setBorder(Utilities.addPadding(10, 10, 10, 10));
        inputField.setBackground(Utilities.SecondaryColor);
        inputField.setForeground(Utilities.Text_Color);
        inputField.setFont(new Font("Arial", Font.PLAIN, 16));
        inputField.setPreferredSize(new Dimension(inputPanel.getWidth(), 50));
        inputPanel.add(inputField, BorderLayout.CENTER);
        chatPanel.add(inputPanel, BorderLayout.SOUTH);


        add(chatPanel,  BorderLayout.CENTER);
    }
    private JPanel createchatmessagecomponent(Message message){
        JPanel chatmessage = new JPanel();
        chatmessage.setBackground(Utilities.TransparentColor);
        chatmessage.setBorder(Utilities.addPadding(20, 20, 10, 20));
        chatmessage.setLayout(new BoxLayout(chatmessage, BoxLayout.Y_AXIS));

        JLabel usernamelabel = new JLabel(message.getUser());
        usernamelabel.setFont(new Font("Arial", Font.BOLD, 18));
        usernamelabel.setForeground(Utilities.Text_Color);
        chatmessage.add(usernamelabel);

        JLabel messageLabel = new JLabel();
        messageLabel.setText("<html>" +
                "<body style='width:" + (0.60 * getWidth()) + "'px>" +
                message.getMessage() +
                "</body>"+
                "</html>");
        messageLabel.setFont(new Font("Arial", Font.PLAIN, 18));
        messageLabel.setForeground(Utilities.Text_Color);
        chatmessage.add(messageLabel);
        return chatmessage;
    }

    @Override
    public void onmessagereceived(Message message) {
        messagePanel.add(createchatmessagecomponent(message));
        messagePanel.revalidate();
        messagePanel.repaint();
        SwingUtilities.invokeLater(() -> {
            JScrollBar vertical = scrollPane.getVerticalScrollBar();
            vertical.setValue(vertical.getMaximum());
        });
    }

    @Override
    public void activeusersupdate(ArrayList<String> users) {
        if(connecteduserPanel.getComponents().length >= 2){
            connecteduserPanel.remove(1);
        }
        JPanel userlistpanel = new JPanel();
        userlistpanel.setBackground(Utilities.TransparentColor);
        userlistpanel.setLayout(new BoxLayout(userlistpanel, BoxLayout.Y_AXIS));
        for(String user: users){
            JLabel username = new JLabel(user);
            username.setText(user);
            username.setForeground(Utilities.Text_Color);
            username.setFont(new Font("Arial", Font.BOLD, 18));
            userlistpanel.add(username);
        }
        connecteduserPanel.add(userlistpanel);
        revalidate();
        repaint();
    }
}
