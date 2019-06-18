#include "Piece.h"

// Piece();
// Piece(bool color, bool alive, int piece_type, int startx, int starty);
// ~Piece();
// void move_piece(int newx, int newy);
Piece::Piece(): color{0}, alive{1}, piece{0}, tile{Tile()}{}
Piece::Piece(bool start_color, int piece_type, Tile x)
: color{start_color}, alive{1}, piece{piece_type}, tile{x}{
    tile.set_piece(this);
}
void Piece::move_piece(Tile x){tile = x;}
int Piece::get_piece(){
    return piece;
}