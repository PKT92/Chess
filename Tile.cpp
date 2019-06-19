#include "Tile.h"

// Tile();
// Tile(int square, char piece_type);
// ~Tile();
// void set_piece(char piece_type);
// void remove_piece();

Tile::Tile(){}

Tile::Tile(int square): tile_number{square}, piece{nullptr}{}

Tile::Tile(int square, Piece *piece_type)
: tile_number{square}, piece{piece_type}{}

void Tile::set_piece(Piece *piece_type){
    piece = piece_type;
}

void Tile::remove_piece(){
    piece = nullptr;
}

Piece* Tile::get_piece(){
    return piece;
}