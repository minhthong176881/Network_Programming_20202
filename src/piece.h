#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "common.cpp"
#include "keyboard.h"

using namespace std;
using namespace sf;

const static int PIECE_O[4][4] =
    {{0, 0, 0, 0},
     {0, 1, 1, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}};

const static int PIECE_L[4][4] =
    {{0, 1, 0, 0},
     {0, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}};

const static int PIECE_J[4][4] =
    {{0, 0, 1, 0},
     {0, 0, 1, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}};

const static int PIECE_Z[4][4] =
    {{0, 0, 0, 0},
     {0, 1, 1, 0},
     {1, 1, 0, 0},
     {0, 0, 0, 0}};

const static int PIECE_ZZ[4][4] =
    {{0, 0, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 1, 1},
     {0, 0, 0, 0}};

const static int PIECE_T[4][4] =
    {{0, 0, 0, 0},
     {0, 1, 0, 0},
     {1, 1, 1, 0},
     {0, 0, 0, 0}};

const static int PIECE_I[4][4] =
    {{0, 1, 0, 0},
     {0, 1, 0, 0},
     {0, 1, 0, 0},
     {0, 1, 0, 0}};

const static Color PIECE_COLOR[7] = {
    Color(255, 51, 0),
    Color(255, 255, 0),
    Color(0, 102, 255),
    Color(0, 255, 255),
    Color(204, 51, 255),
    Color(255, 153, 51),
    Color(0, 255, 0)};

class Piece
{
private:
    int type;

    Sprite sprites[4][4];
    int piece[4][4];

    int x = 3;
    float y = -3;
    int shadowY = -3;

    float moveRightTimer = 0;
    float moveLeftTimer = 0;
    float placeTimer = 0;

    bool isPlaced = false;
    bool isDropping = false;
    float dropSpeed = 0;

    bool gameOver = false;

public:
    Piece();
    void update(float alpha, float speed, int (&world)[10][20]);
    void rotate(int (&world)[10][20]);
    bool placeFree(int x, int y, int (&world)[10][20]);
    void fillWorld(int (&world)[10][20]);
    void draw(RenderTexture *render, Texture texture);
    float getX();
    float getY();
    int *getBlock();
    bool isPiecePlaced();
    bool isGameOver();
};

#endif
