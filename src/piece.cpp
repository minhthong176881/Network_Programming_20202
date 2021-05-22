#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstring>
#include "common.cpp"
#include "keyboard.h"
#include "piece.h"

using namespace std;
using namespace sf;

Piece::Piece()
{
    type = rand() % 7;
    switch (type)
    {
    case 0:
        memcpy(piece, PIECE_O, sizeof(PIECE_O));
        break;
    case 1:
        memcpy(piece, PIECE_L, sizeof(PIECE_L));
        break;
    case 2:
        memcpy(piece, PIECE_J, sizeof(PIECE_J));
        break;
    case 3:
        memcpy(piece, PIECE_Z, sizeof(PIECE_Z));
        break;
    case 4:
        memcpy(piece, PIECE_ZZ, sizeof(PIECE_ZZ));
        break;
    case 5:
        memcpy(piece, PIECE_T, sizeof(PIECE_T));
        break;
    case 6:
        memcpy(piece, PIECE_I, sizeof(PIECE_I));
        break;
    default:
        break;
    }

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            sprites[y][x].setColor(PIECE_COLOR[type]);
            sprites[y][x].setScale(TILE_SIZE / 16.0f, TILE_SIZE / 16.0f);
        }
    }
}

void Piece::update(float delta, float speed, int (&world)[10][20])
{
    int py = (int)y;

    if (!isDropping)
    {
        if (KeyboardManager::keyDown(Keyboard::Up))
        {
            rotate(world);
        }

        if (KeyboardManager::keyPressed(Keyboard::Left))
        {
            if (moveLeftTimer >= 0)
            {
                moveLeftTimer = -.1f;
                if (placeFree(x - 1, py, world))
                    x--;
            }
            moveLeftTimer += delta;
        }
        else
            moveLeftTimer = 0;

        if (KeyboardManager::keyPressed(Keyboard::Right))
        {
            if (moveRightTimer >= 0)
            {
                moveRightTimer = -.1f;
                if (placeFree(x + 1, py, world))
                    x++;
            }
            moveRightTimer += delta;
        }
        else
            moveRightTimer = 0;

        shadowY = y;

        while (placeFree(x, shadowY + 1, world))
        {
            shadowY++;
        }

        if (KeyboardManager::keyDown(Keyboard::Space))
        {
            isDropping = true;
        }
    }

    y += delta * 3 * speed;

    if (isDropping) {
        y += delta * dropSpeed;
        dropSpeed += delta * 500;
    } else if (KeyboardManager::keyPressed(Keyboard::Down))
        y += delta * 9 * speed;

    if (!placeFree(x, py + 1, world)) {
        y = shadowY;
        placeTimer += delta;
        if (placeTimer > .4f || isDropping) {
            isPlaced = true;
            fillWorld(world);
        }
    } else placeTimer = 0;
}

void Piece::rotate(int (&world)[10][20]) {
    // Rotate piece
    int pn[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            pn[i][j] = piece[4 - j - 1][i];
        }
    }

    int tmp[4][4];
    memcpy(tmp, piece, sizeof(piece));
    memcpy(piece, pn, sizeof(piece));

    // Validate new position
    if (!placeFree(x, (int)y, world)) {
        int d = x >= 5 ? 1 : -1;
        if (placeFree(x + d, (int) y, world)) {
            x += d;
            return;
        } else if (placeFree(x - d, (int) y, world)) {
            x -= d;
            return;
        }
        memcpy(piece, tmp, sizeof(piece));
    }
}

bool Piece::placeFree(int px, int py, int (&world)[10][20]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece[j][i]) {
                if (py + j < 0) continue;
                if (px + i >= 10 || px + i < 0) return false;
                if (py + j >= 20) return false;
                if (world[px + i][py + j] > 0) return false;
            }
        }
    }
    return true;
}

void Piece::fillWorld(int (&world)[10][20]){
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if((int)y + j < 0){
                gameOver = true;
                return;
            }
            if (piece[j][i]) {
                if (x + i >= 0 && x + i < 10)
                    if ((int)y + j >= 0 && (int)y + j < 20) {
                        world[x + i][(int)y + j] = type + 1;
                    }
            }
        }
    }
}

void Piece::draw(RenderTexture *renderer, Texture texture) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece[i][j]) {
                sprites[i][j].setTexture(texture);
                if (!isPlaced) {
                    Color col = PIECE_COLOR[type];
                    sprites[i][j].setColor(Color(col.r/3, col.g/3, col.b/3));
                    sprites[i][j].setPosition(Vector2f((x + j) * TILE_SIZE, (shadowY + i) * TILE_SIZE));
                    renderer->draw(sprites[i][j]);
                }
                sprites[i][j].setColor(PIECE_COLOR[type]);
                sprites[i][j].setPosition(Vector2f((x + j) * TILE_SIZE, (y + i) * TILE_SIZE));
                renderer->draw(sprites[i][j]);
            }
        }
    }
} 

float Piece::getX() {
    return x;
}

float Piece::getY() {
    return y;
}

int *Piece::getBlock() {
    int * blocks = new int[4*4];
    for (int i = 0; i < 4 * 4; i++) {
        blocks[i] = piece[i/4][i%4] ? type + 1 : 0;
    }
    return blocks;
}

bool Piece::isPiecePlaced() {
    return isPlaced;
}

bool Piece::isGameOver() {
    return gameOver;
}
