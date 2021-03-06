#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctype.h>

#include "network/server.h"
#include "network/client.h"
#include "game.cpp"
#include "keyboard.h"

using namespace sf;
using namespace std;

class Lobby
{

private:
    enum State
    {
        None,
        Join,
        Host,
        Singleplayer,
        // Exit
    };

    enum Typing
    {
        Name,
        Address,
        Nothing
    };

    State state;
    Font lobbyFont;
    Text lobbyText;
    Texture texture;

    Server *server;
    Client *client;

    Game *game;

    bool gameStarted = false;

    Typing typing = Nothing;
    string typeText = "";
    string address = "127.0.0.1";

    string options[3] =
        {
            "Single player",
            "Join game",
            "Host game",
            // "Exit game"
        };

    int selected = 0;

public:

    Lobby()
    {
        state = None;
        lobbyFont.loadFromFile("assets/font.TTF");
        lobbyText.setFont(lobbyFont);
        lobbyText.setCharacterSize(48);
        texture.loadFromFile("assets/tile.png");
    }

    void update(float delta)
    {

        if (gameStarted)
        {
            game->update(delta);

            if (client != NULL)
            {
                if (!client->isConnected())
                    gameStarted = false;
                if (client->isGameFinished())
                    gameStarted = false;
            }

            return;
        }

        if (state == None)
        {
            if (KeyboardManager::keyDown(Keyboard::Key::Down))
            {
                selected++;
                if (selected > 2)
                    selected = 2;
            }

            if (KeyboardManager::keyDown(Keyboard::Key::Up))
            {
                selected--;
                if (selected < 0)
                    selected = 0;
            }

            if (KeyboardManager::keyDown(Keyboard::Key::Enter) || KeyboardManager::keyDown(Keyboard::Key::Space))
            {
                switch (selected)
                {
                case 0:
                    state = Singleplayer;
                    game = new Game(NULL);
                    gameStarted = true;
                    break;
                case 1:
                    state = Join;
                    typing = Address;
                    typeText = "127.0.0.1";
                    break;
                case 2:
                    server = new Server();
                    state = Host;
                    typing = Name;
                    break;
                }
            }
            return;
        }

        if (typing != Nothing)
        {

            if (KeyboardManager::keyDown(Keyboard::Key::BackSpace))
            {
                typeText = typeText.substr(0, typeText.length() - 1);
            }

            if (KeyboardManager::keyDown(Keyboard::Key::Enter) && typeText.compare("") != 0)
            {
                if (typing == Address)
                {
                    typing = Name;
                    address = typeText;
                    typeText = "";
                }
                else
                    typing = Nothing;

                if (typing == Nothing)
                    client = new Client(typeText, address);
            }
        }

        if (state == Host)
        {
            if (typing == Nothing)
            {
                if (server->isRunning() && KeyboardManager::keyDown(Keyboard::Key::Enter))
                {
                    server->startGame();
                    game = new Game(client);
                    gameStarted = true;
                }
            }

            if (!server->isRunning())
            {
                typing = Nothing;
            }

            if (KeyboardManager::keyDown(Keyboard::Key::Escape))
            {
                state = None;
                typeText = "";
                server->stop();
                delete server;
            }
        }

        if (state == Join && typing == Nothing)
        {
            if (client->isGameStarted() && client->isConnected())
            {
                game = new Game(client);
                gameStarted = true;
            }
            else if (!client->isConnected())
            {
                if (KeyboardManager::keyDown(Keyboard::Key::Escape))
                {
                    state = None;
                    typeText = "";
                }
            }
        }
    }

    void textInput(char c)
    {
        if (!isalpha(c) && !isdigit(c) && !(c == ' ') && !(c == '.'))
            return;
        if (typing != Nothing)
        {
            typeText += c;
        }
    }

    void draw(RenderWindow &window)
    {

        if (gameStarted)
        {
            game->draw();

            RectangleShape outline = RectangleShape(Vector2f(TILE_SIZE * 10 + 50, TILE_SIZE * 20 + 50));
            outline.setFillColor(Color(50, 50, 50));
            outline.setPosition(25, 25);
            window.draw(outline);

            Sprite spr = Sprite(game->getRenderTexture()->getTexture());
            spr.setPosition(50, 50);
            window.draw(spr);

            if (state != Singleplayer)
            {
                drawNextPieceWindow(window);
                drawUserWorlds(window);
            }

            return;
        }

        lobbyText.setFillColor(Color(255, 255, 255));
        lobbyText.setCharacterSize(64);
        lobbyText.setString("Tetris++");
        lobbyText.setPosition(70, 380);
        window.draw(lobbyText);

        if (state == None)
        {
            lobbyText.setCharacterSize(48);
            for (int i = 0; i < 3; i++)
            {
                lobbyText.setString(options[i]);
                lobbyText.setPosition(90 + (i == selected ? 45 : 0), 700 + 60 * i);
                window.draw(lobbyText);
            }
            return;
        }

        if (typing != Nothing)
        {
            lobbyText.setCharacterSize(48);
            lobbyText.setPosition(100, 500);
            lobbyText.setFillColor(Color(100, 100, 100));
            if (typing == Name)
                lobbyText.setString("Enter name: ");
            else
                lobbyText.setString("Enter address: ");
            window.draw(lobbyText);
            lobbyText.setFillColor(Color(255, 255, 0));
            lobbyText.setPosition(100, 550);
            lobbyText.setString(typeText + "");
            window.draw(lobbyText);
            lobbyText.setFillColor(Color(255, 255, 255));
        }

        if (state == Host)
        {
            lobbyText.setCharacterSize(48);
            lobbyText.setPosition(70, 450);
            lobbyText.setFillColor(Color(255, 0, 0));

            if (server->isRunning())
            {
                lobbyText.setString("Hosting server.");
                window.draw(lobbyText);
            }
            else
            {
                lobbyText.setString("Failed to start server.");
                window.draw(lobbyText);

                lobbyText.setPosition(70, 820);
                lobbyText.setFillColor(Color(255, 255, 0));
                lobbyText.setString("Press ESC to exit");
                window.draw(lobbyText);

                return;
            }

            lobbyText.setFillColor(Color(255, 255, 255));
            lobbyText.setCharacterSize(48);
            lobbyText.setPosition(70, 600);
            lobbyText.setString("Players:");
            window.draw(lobbyText);

            lobbyText.setFillColor(Color(100, 100, 100));

            for (int i = 0; i < 4; i++)
            {
                lobbyText.setPosition(70, 650 + 50 * i);
                lobbyText.setString(server->getName(i));
                window.draw(lobbyText);
            }

            if (typing == Nothing)
            {
                lobbyText.setFillColor(Color(0, 255, 0));
                lobbyText.setCharacterSize(48);
                lobbyText.setPosition(70, 850);
                lobbyText.setString("Press ENTER to start");
                window.draw(lobbyText);
            }
        }

        if (state == Join && typing == Nothing)
        {

            lobbyText.setCharacterSize(48);
            lobbyText.setPosition(70, 500);
            lobbyText.setFillColor(Color(255, 0, 0));

            if (client->isConnected())
            {
                lobbyText.setString("Waiting for host...");
                window.draw(lobbyText);

                lobbyText.setFillColor(Color(255, 255, 255));
                lobbyText.setCharacterSize(48);
                lobbyText.setPosition(70, 600);
                lobbyText.setString("Players:");
                window.draw(lobbyText);

                lobbyText.setFillColor(Color(100, 100, 100));

                int index = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (client->getName(i).compare("") != 0)
                    {
                        lobbyText.setPosition(70, 750 + 50 * index);
                        lobbyText.setString(client->getName(i));
                        window.draw(lobbyText);
                        index++;
                    }
                }
            }
            else
            {
                lobbyText.setString("Failed to connect");
                window.draw(lobbyText);

                lobbyText.setPosition(70, 750);
                lobbyText.setFillColor(Color(255, 255, 0));

                lobbyText.setString("Press ESC to exit");
                window.draw(lobbyText);
            }
        }

        if (client != NULL && client->isGameFinished())
        {
            lobbyText.setFillColor(Color(0, 255, 255));
            lobbyText.setCharacterSize(48);
            lobbyText.setPosition(70, 300);
            lobbyText.setString(client->getName(client->getGameWinner()) + " won the round!");
            client->resetState();
            window.draw(lobbyText);
        }
    }

    void drawNextPieceWindow(RenderWindow &window)
    {
        int start_posx = 30 + TILE_SIZE * 10 + 50;
        int start_posy = 25;
        int tile = 24;
        int border = 10;
        int width = TILE_SIZE * 4 + 50;
        int height = TILE_SIZE * 4 + 50;
        int posx = start_posx + border + 10;
        int posy = start_posy + border + 10;
        RectangleShape outline = RectangleShape(Vector2f(width, height));
        outline.setFillColor(Color(50, 50, 50));
        outline.setPosition(start_posx, start_posy);
        window.draw(outline);

        Sprite block(texture);
        block.setScale(tile / 16.0, tile / 16.0);
        int piece_x = client->getPiecePosition(0)[0];
        int piece_y = client->getPiecePosition(0)[1];
        int *piece = client->getPiece(0);
        for (int p = 0; p < 4 * 4; p++)
        {
            if (piece[p])
            {
                block.setColor(PIECE_COLOR[piece[p] - 1]);
                block.setPosition(posx + (p % 4 + piece_x) * tile, posy + (p / 4 + piece_y) * tile);
                window.draw(block);
            }
        }
    }

    void drawUserWorlds(RenderWindow &window)
    {
        int tile = 24;
        int border = 10;
        int starty = 25;
        int startx = TILE_SIZE * 12 + 125;

        lobbyText.setFillColor(Color(255, 255, 255));
        lobbyText.setCharacterSize(28);

        int usr = -1;

        for (int i = 0; i < 3; i++)
        {
            int opponent_window_width = tile * 10 + border;
            int opponent_window_height = tile * 20 + border;

            int posx = startx + border + i * opponent_window_width;
            int posy = starty + border;

            usr++;
            if (client->getId() == usr)
            {
                usr++;
            }

            if (client->getName(usr).compare("") == 0)
                continue;

            RectangleShape outline(Vector2f(opponent_window_width, opponent_window_height));
            outline.setFillColor(Color(50, 50, 50));
            outline.setPosition(posx - border, posy - border);
            window.draw(outline);

            Sprite block(texture);
            block.setScale(tile / 16.0, tile / 16.0);

            int *world = client->getUserWorld(usr);

            for (int x = 0; x < 10; x++)
            {
                for (int y = 0; y < 20; y++)
                {
                    block.setPosition(posx + x * tile, posy + y * tile);

                    if (world[x + y * 10] > 0)
                    {
                        block.setColor(PIECE_COLOR[world[x + y * 10] - 1]);
                    }
                    else
                        block.setColor(Color::Black);

                    window.draw(block);
                }
            }

            //Game over
            if (client->getGameOver(usr))
            {
                RectangleShape bg(Vector2f(tile * 10, tile * 3));
                bg.setFillColor(Color::Red);
                bg.setPosition(posx, posy + tile * 8);
                window.draw(bg);
                lobbyText.setString("Game Over");
                lobbyText.setPosition(posx + tile * 5 - 90, posy + tile * 9 - 10);
                window.draw(lobbyText);
            }
            else
            {

                // Draw piece
                int piece_x = client->getPiecePosition(usr)[0];
                int piece_y = client->getPiecePosition(usr)[1];
                int *piece = client->getPiece(usr);

                for (int p = 0; p < 4 * 4; p++)
                {
                    if (piece[p])
                    {
                        block.setColor(PIECE_COLOR[piece[p] - 1]);
                        block.setPosition(posx + (p % 4 + piece_x) * tile - 4, posy + (p / 4 + piece_y) * tile);
                        window.draw(block);
                    }
                }
            }

            //Name

            lobbyText.setString(client->getName(usr));
            lobbyText.setPosition(posx, posy - 45);
            window.draw(lobbyText);
        }
    }
};