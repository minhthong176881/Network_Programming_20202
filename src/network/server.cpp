#include <iostream>
#include <thread>
#include <SFML/Network.hpp>
#include <string>

#include "connection.h"
#include "server.h"
#include "../common.cpp"

using namespace std;
using namespace sf;

Connection *connections[4];

bool gameOver[4];
int gameOverCount = 0;
bool inGame = false;

int num_connections = 0;
bool running = true;
TcpListener tcpListener;

Server::Server()
{
    cout << "Starting server..." << endl;
    thread th(&Server::run, this);
    th.detach();
}

string Server::getName(int player)
{
    if (connections[player] != NULL)
        return connections[player]->getName();
    else
        return "";
}

void Server::sendLobbyData()
{

    Packet pack;
    // Write lobby type into packet
    pack << (int)PACKET_TYPE_LOBBY;

    for (int i = 0; i < 4; i++)
    {
        if (connections[i] == NULL)
            pack << "";
        else
            // Write name of the players to the packet
            pack << connections[i]->getName();
    }

    // Send packet to all user
    Server::sendAll(pack);
}

void Server::setGameOver(int id)
{

    gameOver[id] = true;

    int gameOverCount = 0;
    int winner = 0;

    for (int i = 0; i < 4; i++)
    {
        // Count game over number
        if (gameOver[i] || connections[i] == NULL)
            gameOverCount++;
        else
            winner = i;
    }

    // If all games are over -> send finish packet to all players
    if (gameOverCount >= 3)
    {

        for (int i = 0; i < 4; i++)
        {
            gameOver[id] = false;
        }

        inGame = false;

        Packet finPack;
        // Write finishgame type into the packet
        finPack << (int)PACKET_TYPE_FINISHGAME;
        finPack << winner;
        sendAll(finPack);
    }
}

void Server::startGame()
{
    inGame = true;
    // Set game over state of players to false
    for (int i = 0; i < 4; i++)
        gameOver[i] = false;
    Packet pack;
    // Write start type into the packet
    pack << (int)PACKET_TYPE_START;
    Server::sendAll(pack);
}

void Server::sendAll(Packet packet)
{
    // Send the packet to all connected players
    for (int i = 0; i < 4; i++)
    {
        if (connections[i] == NULL)
            continue;
        connections[i]->send(packet);
    }
}

void Server::sendAllExcept(int id, Packet packet)
{
    for (int i = 0; i < 4; i++)
    {
        if (id == i || connections[i] == NULL)
            continue;
        connections[i]->send(packet);
    }
}

void Server::disconnect(int id)
{

    if (connections[id] == NULL)
        return;

    cout << "Client with id " << id << " disconnected." << endl;

    // Delete the connection of current player
    delete connections[id];
    connections[id] = NULL;
    num_connections--;

    // Set game over status to the player
    if (inGame)
    {
        setGameOver(id);
    }
    // Update the data to other players
    sendLobbyData();
}

void Server::run()
{

    running = true;

    // Set tcp socket listen on default port 31621
    if (tcpListener.listen((unsigned short)31621) != Socket::Done)
    {
        cout << "Failed to start server." << endl;
        running = false;
        return;
    }
    cout << "Server listening on port 31621" << endl;

    while (running)
    {

        // If the connection number is maximum, stop listening for more connections
        if (num_connections == 4)
            continue;

        cout << "Listening for clients..." << endl;

        TcpSocket *socket = new TcpSocket;

        if (tcpListener.accept(*socket) != Socket::Done)
        {
            cout << "Accepting client failed." << endl;
            continue;
        }

        cout << "Client connected!" << endl;

        for (int i = 0; i < 4; i++)
        {
            if (connections[i] == NULL)
            {
                // Construct new connection for each connected socket
                connections[i] = new Connection(i, this, socket);
                // Increase the connection number
                num_connections++;
                break;
            }
        }
    }
}

bool Server::isRunning()
{
    return running;
}

void Server::stop()
{
    running = false;
    // Stop all connections
    for (int i = 0; i < 4; i++)
    {
        if (connections[i] != NULL)
        {
            connections[i]->stop();
        }
    }
    // Close the tcp socket
    tcpListener.close();
    num_connections = 0;
}
