package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.messaging.simp.SimpMessagingTemplate;
import org.springframework.stereotype.Service;

import java.util.ArrayList;

@Service
public class WebSocketSessionManager {
    private final ArrayList<String> activeUsernames = new ArrayList<>();
    private final SimpMessagingTemplate simpMessagingTemplate;

    @Autowired
    public WebSocketSessionManager(SimpMessagingTemplate simpMessagingTemplate) {
        this.simpMessagingTemplate = simpMessagingTemplate;
    }
    public void addUsername(String username) {
        activeUsernames.add(username);
    }
    public void removeUsername(String username) {
        activeUsernames.remove(username);
    }
    public void broadcastActiveUsernames() {
        simpMessagingTemplate.convertAndSend("/topic/users", activeUsernames);
        System.out.println("Broadcasting active usernames" +  activeUsernames);
    }
}
