#include "Piece.h"

// Piece();
// Piece(bool color, bool alive, int piece_type, int startx, int starty);
// ~Piece();
// void move_piece(int newx, int newy);
Piece::Piece(): color{0}, alive{1}, piece{0}, x{1}, y{1}{}
Piece::Piece(bool start_color, int piece_type, int startx, int starty)
: color{start_color}, alive{1}, piece{piece_type}, x{startx}, y{starty}{}
void Piece::move_piece(int newx, int newy){x = newx; y = newy;}