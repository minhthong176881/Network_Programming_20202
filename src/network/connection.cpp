#include <iostream>
#include <thread>
#include <SFML/Network.hpp>

#include "connection.h"
#include "../common.cpp"

using namespace sf;
using namespace std;

Connection::Connection(int id, Server *server, TcpSocket *socket)
{

    cout << "Starting client connection " << endl;

    this->id = id;
    this->server = server;
    this->socket = socket;

    running = true;

    thread th(&Connection::run, this);
    th.detach();
}

void Connection::send(Packet packet)
{
    if (socket->send(packet) != sf::Socket::Done)
    {
        cout << "Server failed to send packet to " << username << endl;
        running = false;
        server->disconnect(id);
    }
}

void Connection::stop()
{
    running = false;
    socket->disconnect();
}

void Connection::run()
{
    cout << "Getting client name... " << endl;

    // Create a packet to receive player's name
    Packet namePacket;

    if (socket->receive(namePacket) != Socket::Done)
    {
        cout << "Server couldnt get username from client " << endl;
        running = false;
        server->disconnect(id);
        return;
    }

    // Read player name from the packet
    namePacket >> username;
    cout << "Server got name: " << username << endl;

    // Create a packet to write player's id
    Packet idPacket;
    // Write player's id into the packet
    idPacket << id;
    send(idPacket);

    // Update lobby data
    server->sendLobbyData();

    while (running)
    {
        // Create a packet to receive data
        Packet packet;
        if (socket->receive(packet) != Socket::Done)
        {
            cout << "Failed to receive pack from client " << endl;
            running = false;
            server->disconnect(id);
            break;
        }

        int type;
        // Read packet type from the packet
        packet >> type;

        if (type == PACKET_TYPE_WORLD)
        {

            // Create player's world
            int world[10 * 20];

            // Read player's world data from the packet
            for (int i = 0; i < 10 * 20; i++)
            {
                packet >> world[i];
            }

            // Create a packet to send world data
            Packet wPack;

            // Write world type, player's id and player's world data to the packet
            wPack << (int)PACKET_TYPE_WORLD;
            wPack << id;

            for (int i = 0; i < 10 * 20; i++)
                wPack << world[i];

            // Send player's world data to other players
            server->sendAllExcept(id, wPack);
        }
        else if (type == PACKET_TYPE_PIECE)
        {

            float x, y;

            // Read the position of the piece from the packet
            packet >> x;
            packet >> y;

            // Read the piece from the packet
            int piece[4 * 4];
            for (int i = 0; i < 4 * 4; i++)
            {
                packet >> piece[i];
            }

            // Create a packet to send piece data of the player
            Packet pPack;
            // Write piece type into the packet
            pPack << (int)PACKET_TYPE_PIECE;
            // Write piece's position into the packet
            pPack << id << x << y;

            // Write piece form into the packet
            for (int i = 0; i < 4 * 4; i++)
                pPack << piece[i];

            server->sendAllExcept(id, pPack);
        }
        else if (type == PACKET_TYPE_BLOCK)
        {
            // Create a packet to send block data
            Packet scPack;
            // Write block type and player's id into the packet
            scPack << (int)PACKET_TYPE_BLOCK;
            scPack << id;
            server->sendAllExcept(id, scPack);
        }
        else if (type == PACKET_TYPE_GAMEOVER)
        {
            // Create a packet to send game over state of the player
            Packet goPack;
            // Write gameover type and player's id into the packet
            goPack << (int)PACKET_TYPE_GAMEOVER;
            goPack << id;
            server->sendAllExcept(id, goPack);
            server->setGameOver(id);
        }
    }
}

string Connection::getName()
{
    return username;
}
