#ifndef CONNECTION_H
#define CONNECTION_H

#include "server.h"
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Connection {

private:
    Server *server;
    TcpSocket* socket;
    string username;
    int id;
    bool running;
public:
    Connection(int id, Server* server, TcpSocket* socket);
    void send(Packet packet);
    void run();
    void stop();
    string getName();
};

#endif //CONNECTION_H
