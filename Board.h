#pragma once
#include "Piece.h"
#include "Tile.h"
#include <iostream>
#include <vector>
#include <string>

class Board{
public:
    Board();
    ~Board();
    void update_board(int cur_x, int cur_y, int new_x, int new_y);
    void print_board();
    bool get_game_status();
    bool move_piece(std::string old_pos, std::string new_pos);
private:
    bool game_status;
    std::vector<char> alpha_label = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    std::vector<int> number_label = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<Piece> pieces;
    std::vector<Tile> tiles;
};