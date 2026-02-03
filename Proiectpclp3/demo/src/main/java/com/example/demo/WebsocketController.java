package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.simp.SimpMessagingTemplate;
import org.springframework.stereotype.Controller;

@Controller
public class WebsocketController {
    private final SimpMessagingTemplate messagingTemplate;
    private final WebSocketSessionManager webSocketSessionManager;

    @Autowired
    public WebsocketController(SimpMessagingTemplate messagingTemplate,  WebSocketSessionManager webSocketSessionManager) {
        this.messagingTemplate = messagingTemplate;
        this.webSocketSessionManager = webSocketSessionManager;
    }
    @MessageMapping("/message")
    public void handleMessage(Message message){
        System.out.println("Received message from user: " + message.getUser() + ": " + message.getMessage());
        messagingTemplate.convertAndSend("/topic/messages", message);
        System.out.println("Sent message to chat: " +  message.getUser() + ": " + message.getMessage());
    }
    @MessageMapping("/connect")
    public void connectUser(String username){
        webSocketSessionManager.addUsername(username);
        webSocketSessionManager.broadcastActiveUsernames();
        System.out.println("Connected user: " + username);
    }
    @MessageMapping("/disconnect")
    public void disconnectUser(String username){
        webSocketSessionManager.removeUsername(username);
        webSocketSessionManager.broadcastActiveUsernames();
        System.out.println("Disconnected user: " + username);
    }
    @MessageMapping("/request-users")
    public void requestusers(String username){
        webSocketSessionManager.broadcastActiveUsernames();
        System.out.println("Requesting users" + username);
    }
}
