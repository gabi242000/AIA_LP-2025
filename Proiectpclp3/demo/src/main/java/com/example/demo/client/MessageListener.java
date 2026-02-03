package com.example.demo.client;


import com.example.demo.Message;

import java.util.ArrayList;

public interface MessageListener {
    void onmessagereceived(Message message);
    void activeusersupdate(ArrayList<String> users);

}
