#pragma once
#include "Tile.h"
#include <vector>
class Tile;
class Piece
{
public:
    Piece();
    Piece(bool start_color, int piece_type, Tile *tile_num);
    ~Piece();
    void set_piece_status(bool status);
    bool pawn_check(Tile *tile, std::vector<Tile*> tiles);
    bool bishop_check(Tile *tile, int old_col, int new_col, int old_row, int new_row);
    bool knight_check(Tile *tile, int old_col, int new_col, int old_row, int new_row);
    bool rook_check(Tile *tile, int old_col, int new_col, int old_row, int new_row);
    bool move_piece(std::vector<Tile*> tiles, int old_col, int new_col, int old_row, int new_row, int moving_color);
    int get_piece();
    bool move_check(std::vector<Tile*> tiles, Tile *new_tile, int old_col, int new_col, int old_row, int new_row);
    bool get_color();
    bool is_enpassant();
private:
    bool first_move = true;
    bool enpassant = false;
    int piece; // 0 pawn, 1 knight, 2 bishop, 3 rook, 4 queen, 5 king
    int value; // 100 pawn, 300 bishop, 300 knight, 500 rook, 1000 queen, 5000 king
    bool alive; // 1 alive, 0 dead
    bool color; // 1 black, 0 white
    Tile *tile;
};