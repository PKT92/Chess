#include "Tile.h"

// Tile();
// Tile(bool left, bool right, bool top, bool bottom, int x, int y, char alpha_label, int number_label);
// Tile(bool left, bool right, bool top, bool bottom, int x, int y, char alpha_label, int number_label, char piece_type);
// ~Tile();
// void set_piece(char piece_type);
// void remove_piece();
// void draw();
Tile::Tile(): bot_border{1}, top_border{1}, right_border{1}, left_border{1}{}

Tile::Tile(bool left, bool right, bool top, bool bottom, int tile, char alpha_label, int number_label)

: left_border{left}, right_border{right}, top_border{top}, bot_border{bottom}, tile_number{tile}, alpha_square{alpha_label}, number_square{number_label}{}

Tile::Tile(bool left, bool right, bool top, bool bottom, int tile, char alpha_label, int number_label, char piece_type)
: left_border{left}, right_border{right}, top_border{top}, bot_border{bottom}, tile_number{tile}, alpha_square{alpha_label}, number_square{number_label}, piece{piece_type}{}

void Tile::set_piece(char piece_type){piece = piece_type;}

void Tile::remove_piece(){piece = ' ';}

void Tile::draw(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 2 && j == 2){
                std::cout << piece;
            }
        }
    }
}