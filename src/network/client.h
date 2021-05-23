#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <SFML/Network.hpp>
#include "../piece.h"

using namespace std;
using namespace sf;

class Client {

private:

    TcpSocket socket;
    bool connected = false;

    string address;

    char username[25];
    int id;

    string * users = new string[4];
    int userWorlds[4][10*20]; // 4 players and size of the world 10*20

    int addBlockCount = 0;
    int blockSender = 0; 

    float userPiecePosition[4][2]; // 4 players and 2 positions of x and y
    int userPiece[4][4*4]; // 4 player and form of the piece

    bool gameOver[4];

    bool gameStarted = false;
    bool gameFinished = false;
    int gameWinner = 0;

    void connect();
    void send(Packet packet);

public:
    Client(string name, string address);
    // Reset the state of player
    void resetState();
    // Update the world data of the player
    void updateState(int (&world)[10][20]);
    // Update the piece state of the player
    void updatePieceState(Piece* piece);
    // Send game over state to the server
    void sendGameOver();
    // Send block to the server
    void sendBlock();
    // Check if the player is connected
    bool isConnected();
    // Get the player's name
    string getName(int i);
    // Check if the game is started
    bool isGameStarted();
    // Get the user world data
    int* getUserWorld(int usr);
    // Get the current piece position
    float * getPiecePosition(int usr);
    // Get the current piece
    int * getPiece(int usr);
    // Get the game over state of the player
    bool getGameOver(int usr);
    // Check if the game finished
    bool isGameFinished();
    // Get the winner of the game
    int getGameWinner();
    bool addBlock();
    // Get the block sender
    string getBlockSender();
    int getId();
};

#endif //CLIENT_H

