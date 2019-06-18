#pragma once
#include <iostream>

class Tile{
public:
    Tile();
    Tile(bool left, bool right, bool top, bool bottom, int tile, char alpha_label, int number_label);
    Tile(bool left, bool right, bool top, bool bottom, int tile, char alpha_label, int number_label, char piece_type);
    ~Tile();
    void set_piece(char piece_type);
    void remove_piece();
    void draw();
private:
    int tile_number;
    bool left_border, right_border, top_border, bot_border;
    char alpha_square;
    char piece;
    int number_square; 
};