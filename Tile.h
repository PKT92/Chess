#pragma once
#include <iostream>
#include "Piece.h"

class Tile{
public:
    Tile();
    Tile(int square);
    Tile(int square, Piece *piece_type);
    ~Tile();
    void set_piece(Piece *piece_type);
    void remove_piece();
    int get_piece();
private:
    int tile_number;
    Piece *piece;
};