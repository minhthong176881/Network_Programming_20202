#include <string>
#include <iostream>
#include <thread>
#include <SFML/Network.hpp>
#include <cstring>

#include "client.h"
#include "../common.cpp"

using namespace sf;
using namespace std;

void Client::connect()
{

    connected = true;

    // Request to connect to the server at port 31621
    if (socket.connect(this->address, 31621) != Socket::Done)
    {
        cout << "Client failed to connect to server" << endl;
        connected = false;
        return;
    }

    cout << "Sending username to server... " << endl;
    // Create a packet to send player's data
    Packet userPacket;
    // Write player's name into the packet
    userPacket << username;
    // Send the packet to the server
    if (socket.send(userPacket) != Socket::Done)
    {
        cout << "Failed to send username" << endl;
        connected = false;
        return;
    }

    // Create a packet to recieve the id from the server
    Packet idPacket;
    if (socket.receive(idPacket) != Socket::Done)
    {
        cout << "Failed to get ID from server" << endl;
        connected = false;
        return;
    }
    // Read the id of the player from the packet
    idPacket >> id;
    cout << "Client started with ID " << id << endl;

    while (connected)
    {

        // Create a packet to recieve data from the server
        Packet dPack;
        if (socket.receive(dPack) != Socket::Done)
        {
            cout << "Server couldn't get pack from client " << endl;
            connected = false;
            return;
        }

        int type;
        // Read the type from the packet
        dPack >> type;

        if (type == PACKET_TYPE_LOBBY)
        {
            // Read the players's name from the packet
            for (int i = 0; i < 4; i++)
            {
                dPack >> users[i];
            }
        }
        else if (type == PACKET_TYPE_START)
        {
            // Set game state to start
            gameStarted = true;
            gameFinished = false;
        }
        else if (type == PACKET_TYPE_WORLD)
        {

            int id = 0;
            int world[10 * 20];

            // Read the player's id from the packet
            dPack >> id;

            // Read the player's world data from the packet
            for (int i = 0; i < 10 * 20; i++)
            {
                dPack >> world[i];
            }

            cout << "Client got world from " << id << endl;
            // Copy the reveived world data to coresponding player's world
            memcpy(userWorlds[id], world, sizeof(world));
        }
        else if (type == PACKET_TYPE_PIECE)
        {

            int id;
            float x, y;

            // Read the player's id, position x and y of the piece from the packet
            dPack >> id;
            dPack >> x;
            dPack >> y;

            // Set piece position of player with id = id
            userPiecePosition[id][0] = x;
            userPiecePosition[id][1] = y;

            // Read the piece from the packet
            for (int i = 0; i < 4 * 4; i++)
                dPack >> userPiece[id][i];
        }
        else if (type == PACKET_TYPE_BLOCK)
        {

            // Read the block sender from the packet
            addBlockCount++;
            dPack >> blockSender;
        }
        else if (type == PACKET_TYPE_GAMEOVER)
        {

            int id;
            // Read player's id from the packet
            dPack >> id;

            // Set game over state of corresponding player to true
            gameOver[id] = true;
        }
        else if (type == PACKET_TYPE_FINISHGAME)
        {

            int winner;
            // Read the winner of the game from the packet
            dPack >> winner;

            // Reset the state of the game
            resetState();

            gameStarted = false;
            gameFinished = true;
            gameWinner = winner;
        }
        else
        {
            cout << "Client got unknown pack type " << type;
        }
    }
}

void Client::send(Packet packet)
{
    if (socket.send(packet) != Socket::Done)
    {
        cout << "Failed to send pack from client " << endl;
    }
}

Client::Client(string name, string addr)
{

    // Initialize players
    for (int i = 0; i < 4; i++)
        users[i] = "";

    resetState();

    this->address = addr;

    cout << "Starting client with name " << name << endl;

    for (int i = 0; i < 4; i++)
    {
        users[i] = "?";
    }

    // Set the current player's name
    memcpy(username, name.c_str(), 25);
    thread th(&Client::connect, this);
    th.detach();
}

void Client::resetState()
{
    cout << "Client reset state " << endl;
    // Reset players
    for (int i = 0; i < 4; i++)
    {
        gameOver[i] = false;
        // Reset worlds
        for (int x = 0; x < 10 * 20; x++)
            userWorlds[i][x] = 0;
        // Reset pieces
        for (int x = 0; x < 4 * 4; x++)
            userPiece[i][x] = 0;
    }
    addBlockCount = 0;
}

void Client::updateState(int (&world)[10][20])
{
    // Create a packet to send updated world to the server
    Packet packet;
    // Write world type and world data into the packet
    packet << (int)PACKET_TYPE_WORLD;
    for (int i = 0; i < 10 * 20; i++)
    {
        packet << world[i % 10][i / 10];
    }
    cout << "Client sending world" << endl;
    send(packet);
}

void Client::updatePieceState(Piece *piece)
{
    // Create a packet to send piece state to the server
    Packet packet;
    // Write piece type and positions of the piece into the packet
    packet << (int)PACKET_TYPE_PIECE;
    packet << piece->getX();
    packet << piece->getY();

    // Get block of the piece
    int *block = piece->getBlock();
    // Write the block into the packet
    for (int i = 0; i < 4 * 4; i++)
    {
        packet << block[i];
    }

    send(packet);
}

void Client::sendGameOver()
{
    // Create a packet to send game over type to the server
    Packet packet;
    // Write game over type into the packet
    packet << (int)PACKET_TYPE_GAMEOVER;
    send(packet);
}

void Client::sendBlock()
{
    // Create a packet to send block type to the server
    Packet packet;
    // Write block type into the packet
    packet << (int)PACKET_TYPE_BLOCK;
    send(packet);
}

bool Client::isConnected()
{
    return connected;
}

int Client::getId()
{
    return id;
}

string Client::getName(int i)
{
    return users[i];
}

bool Client::isGameStarted()
{
    return gameStarted;
}

int *Client::getUserWorld(int usr)
{
    return userWorlds[usr];
}

float *Client::getPiecePosition(int usr)
{
    return userPiecePosition[usr];
}

int *Client::getPiece(int usr)
{
    return userPiece[usr];
}
bool Client::getGameOver(int usr)
{
    return gameOver[usr];
}

bool Client::addBlock()
{
    if (addBlockCount > 0)
    {
        addBlockCount--;
        return true;
    }
    return false;
}

string Client::getBlockSender()
{
    return users[blockSender];
}

bool Client::isGameFinished()
{
    return gameFinished;
}

int Client::getGameWinner()
{
    return gameWinner;
}
