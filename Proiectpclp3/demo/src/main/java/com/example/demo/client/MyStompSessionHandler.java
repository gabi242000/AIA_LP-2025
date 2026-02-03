package com.example.demo.client;
import com.example.demo.Message;
import com.example.demo.Message;
import org.springframework.messaging.simp.stomp.StompFrameHandler;
import org.springframework.messaging.simp.stomp.StompHeaders;
import org.springframework.messaging.simp.stomp.StompSession;
import org.springframework.messaging.simp.stomp.StompSessionHandlerAdapter;
import java.lang.reflect.Type;
import java.util.ArrayList;

public class MyStompSessionHandler extends StompSessionHandlerAdapter {
    private String username;
    private MessageListener messageListener;

    public MyStompSessionHandler(MessageListener messageListener,String username){
        this.username = username;
        this.messageListener = messageListener;
    }
    @Override
    public void afterConnected(StompSession session, StompHeaders connectedHeaders) {
        System.out.println("Client connected");
        session.send("/app/connect", this.username);
        session.subscribe("/topic/messages", new StompFrameHandler(){
            @Override
            public  Type getPayloadType(StompHeaders headers){
                return Message.class;
            }

            @Override
            public void handleFrame(StompHeaders headers, Object payload) {
                try{
                    if(payload instanceof Message){
                        Message message = (Message) payload;
                        messageListener.onmessagereceived(message);
                        System.out.println("Received message: " + message.getUser() + ": " + message.getMessage() );
                    }else{
                        System.out.println("Received unexpected payload type " + payload.getClass());
                    }
                }catch(Exception e) {
                    e.printStackTrace();
                }
            }
        });
        session.subscribe("/topic/users", new StompFrameHandler(){
            @Override
            public Type getPayloadType(StompHeaders headers){
                return new ArrayList<String>().getClass();
            }

            @Override
            public void handleFrame(StompHeaders headers, Object payload) {
                try{
                    if(payload instanceof ArrayList){
                        ArrayList<String> activeusers = (ArrayList<String>) payload;
                        messageListener.activeusersupdate(activeusers);
                        System.out.println("Received: " + activeusers);
                    }
                }catch(Exception e) {
                    e.printStackTrace();
                }
            }
        });
        System.out.println("Subscribed to /topic/users");
        session.send("/app/request-users", this.username);
    }
    @Override
    public void handleTransportError(StompSession session, Throwable exception) {
        exception.printStackTrace();
    }
}
