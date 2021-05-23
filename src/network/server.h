#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Server {
public:
    Server();
    // Get player name
    string getName(int player);
    // Send name among the player
    void sendLobbyData();
    // Send packet to all players
    void sendAll(Packet packet);
    // Send packet to players other than current player
    void sendAllExcept(int id, Packet packet);
    void run();
    // Start the game
    void startGame();
    // Set game over state to the player
    void setGameOver(int id);
    // Check if the server is running
    bool isRunning();
    // Disconnect the player
    void disconnect(int id);
    // Stop the server
    void stop();
};

#endif //SERVER_H
