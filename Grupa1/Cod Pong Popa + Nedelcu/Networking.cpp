#include "Networking.h"
#include <SFML/Network.hpp>
#include<iostream>
sf::TcpSocket socket;
void host_tick()
{
    //Receive client input
    sf::Packet recvPacket;
    if (socket.receive(recvPacket) == sf::Socket::Done) {
        recvPacket >> paddle2_x >> paddle2_y;
    }

    //Send full game states
    sf::Packet sendPacket;
    sendPacket << paddle1_x << paddle1_y
        << ball_x << ball_y
        << ball_speed_x << ball_speed_y
        << score1 << score2;

    if (socket.send(sendPacket) != sf::Socket::Done) {
        //didn't send
    }
    //std::cout << paddle2_x << " " << paddle2_y;
}
void host()
{
    sf::TcpListener listener;

    listener.listen(50001);
    listener.setBlocking(true);
    socket.setBlocking(true);

    std::cout << "Waiting for client to connect...\n";
    while (listener.accept(socket) != sf::Socket::Done) {
        //Waiting for connection...
    }
    std::cout << "Client connected!\n";
}
void client_tick()
{
    //Send paddle2 position
    sf::Packet sendPacket;
    sendPacket << paddle2_x << paddle2_y;
    socket.send(sendPacket);

    //Receive game state
    sf::Packet recvPacket;
    if (socket.receive(recvPacket) == sf::Socket::Done) {
        recvPacket >> paddle1_x >> paddle1_y
            >> ball_x >> ball_y
            >> ball_speed_x >> ball_speed_y
            >> score1 >> score2;
        //std::cout << paddle1_x <<" " << paddle1_y;
    }
}

void client()
{
    bool ok = 1;
    socket.setBlocking(true);
    //sf::IpAddress::getLocalAddress()
    if (socket.connect(ip, 50001, sf::seconds(5)) != sf::Socket::Done) {
        std::cerr << "Failed to connect.\n";
        ok = 0;
    }
    if (ok)
    {
        std::cout << "Connected to server!\n";
    }
}
