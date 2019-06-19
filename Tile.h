#pragma once
#include <iostream>
#include "Piece.h"
class Piece;
class Tile{
public:
    Tile();
    Tile(int square);
    Tile(int square, Piece *piece_type);
    ~Tile();
    void set_piece(Piece *piece_type);
    void remove_piece();
    Piece* get_piece();
    int get_tile();
private:
    int tile_number;
    Piece *piece;
};