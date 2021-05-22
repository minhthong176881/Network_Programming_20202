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
    int userWorlds[4][10*20];

    int addBlockCount = 0;
    int blockSender = 0;

    float userPiecePosition[4][2];
    int userPiece[4][4*4];

    bool gameOver[4];

    bool gameStarted = false;
    bool gameFinished = false;
    int gameWinner = 0;

    void connect();
    void send(Packet packet);

public:
    Client(string name, string address);
    void resetState();
    void updateState(int (&world)[10][20]);
    void updatePieceState(Piece* piece);
    void sendGameOver();
    void sendBlock();
    bool isConnected();
    string getName(int i);
    bool isGameStarted();
    int* getUserWorld(int usr);
    float * getPiecePosition(int usr);
    int * getPiece(int usr);
    bool getGameOver(int usr);
    bool isGameFinished();
    int getGameWinner();
    bool addBlock();
    string getBlockSender();
    int getId();
};

#endif //CLIENT_H

