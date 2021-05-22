#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Server {
public:
    Server();
    string getName(int player);
    void sendLobbyData();
    void sendAll(Packet packet);
    void sendAllExcept(int id, Packet packet);
    void run();
    void startGame();
    void setGameOver(int id);
    bool isRunning();
    void disconnect(int id);
    void stop();
};

#endif //SERVER_H
