#include "Board.h"

Board::Board()
: game_status{1}{
    std::cout << "Please enter a move in the following way: <piece location> <new location>" << std::endl;
    std::cout << "Ex. a4 a5" << std::endl;
    for(int i = 0; i < 64; i++){
        tiles.push_back(Tile(i));
    }
    for(int i = 0; i < 8; i++){
        pieces.push_back(Piece(1, 0, tiles[i+8]));
    }
    for(int i = 0; i < 8; i++){
        pieces.push_back(Piece(0, 0, tiles[i+48]));
    }
    pieces.push_back(Piece(1, 3, tiles[0]));
    pieces.push_back(Piece(1, 1, tiles[1]));
    pieces.push_back(Piece(1, 2, tiles[2]));
    pieces.push_back(Piece(1, 4, tiles[3]));
    pieces.push_back(Piece(1, 5, tiles[4]));
    pieces.push_back(Piece(1, 2, tiles[5]));
    pieces.push_back(Piece(1, 1, tiles[6]));
    pieces.push_back(Piece(1, 3, tiles[7]));
}
// TODO:
// Need to modify the board production to start getting piece information
void Board::print_board(){
    int labelCount = 0, numCount = 0;
    std::cout << "----------------------------- Black -----------------------------" << std::endl;
    for(int i = 0; i < 34; i++){
        for(int j = 0; j < 34; j++){
            if(i == 0){
                if(j % 4 == 3){
                    std::cout << alpha_label[labelCount] << " ";
                    labelCount++;
                } else{
                    std::cout << "  ";
                }
            } else if(j == 0){
                if(i % 4 == 3){
                    std::cout << number_label[numCount] << " ";
                    numCount++;
                } else{
                    std::cout << "  ";
                }
            }else if(j % 4 == 1 && i % 4 != 1){
                std::cout << "# ";
            } else if (i% 4 == 1){
                std::cout << "# ";
            } else{
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------- White -----------------------------" << std::endl;
}

bool Board::get_game_status(){
    return game_status;
}

bool Board::move_piece(std::string old_pos, std::string new_pos){
    if(old_pos.length() != 2 || new_pos.length() != 2){
        return false;
    }

}