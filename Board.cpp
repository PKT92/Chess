#include "Board.h"

Board::Board()
: game_status{1}{
    std::cout << "Please enter a move in the following way: <piece location> <new location>" << std::endl;
    std::cout << "Ex. a4 a5" << std::endl;
    // 64 tiles for the chess board
    for(int i = 0; i < 64; i++){
        tiles.push_back(new Tile(i));
    }
    // Black Pawns
    for(int i = 0; i < 8; i++){
        pieces.push_back(new Piece(1, 0, tiles[i+8]));
    }
    // White Pawns
    for(int i = 0; i < 8; i++){
        pieces.push_back(new Piece(0, 0, tiles[i+48]));
    }
    // Black major pieces
    pieces.push_back(new Piece(1, 3, tiles[0]));
    pieces.push_back(new Piece(1, 1, tiles[1]));
    pieces.push_back(new Piece(1, 2, tiles[2]));
    pieces.push_back(new Piece(1, 4, tiles[3]));
    pieces.push_back(new Piece(1, 5, tiles[4]));
    pieces.push_back(new Piece(1, 2, tiles[5]));
    pieces.push_back(new Piece(1, 1, tiles[6]));
    pieces.push_back(new Piece(1, 3, tiles[7]));
    // White major pieces
    pieces.push_back(new Piece(0, 3, tiles[56]));
    pieces.push_back(new Piece(0, 1, tiles[57]));
    pieces.push_back(new Piece(0, 2, tiles[58]));
    pieces.push_back(new Piece(0, 4, tiles[59]));
    pieces.push_back(new Piece(0, 5, tiles[60]));
    pieces.push_back(new Piece(0, 2, tiles[61]));
    pieces.push_back(new Piece(0, 1, tiles[62]));
    pieces.push_back(new Piece(0, 3, tiles[63]));
}

void Board::print_board(){
    int labelCount = 0, tileCount = 0;
    int numCount = 7;
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
                    numCount--;
                } else{
                    std::cout << "  ";
                }
            }else if(j % 4 == 1 && i % 4 != 1){
                std::cout << "# ";
            } else if (i% 4 == 1){
                std::cout << "# ";
            } else if(i % 4 == 3 && j % 4 == 3){
                int tmp_piece;
                if(tiles[tileCount]->get_piece() == nullptr){
                    tmp_piece = -1;
                } else{
                    tmp_piece = tiles[tileCount]->get_piece()->get_piece();
                }
                switch(tmp_piece){
                    case 0: std::cout << "P "; break;
                    case 1: std::cout << "N "; break;
                    case 2: std::cout << "B "; break;
                    case 3: std::cout << "R "; break;
                    case 4: std::cout << "Q "; break;
                    case 5: std::cout << "K "; break;
                    default: std::cout << "  ";
                }
                if(tileCount == tiles.size()-1){
                    tileCount = 0;
                }else{
                    tileCount++;
                }
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

// TODO:
// Get movement of pieces right (currently the boards backwards)
bool Board::move_piece(std::string old_pos, std::string new_pos, int color){
    if(old_pos.length() != 2 || new_pos.length() != 2){
        return false;
    }
    int old_int, new_int;
    int old_char, new_char;
    int old_tile, new_tile;
    std::cout << isdigit(old_pos[0]) << std::endl;
    if(isdigit(old_pos[0])){
        old_int = int(old_pos[0]) - 48 - 1;
        old_char = int(old_pos[1]) - 97;
    } else{
        old_char = int(old_pos[0]) - 97;
        old_int = int(old_pos[1]) - 48 - 1;
        std::cout << old_char << old_int << std::endl;
    }
    if(isdigit(new_pos[0])){
        new_int = int(new_pos[0]) - 48 - 1;
        new_char = int(new_pos[1]) - 97;
    } else{
        new_char = int(new_pos[0]) - 97;
        new_int = int(new_pos[1]) - 48 - 1;
        std::cout << new_char << new_int << std::endl;
    }
    old_tile = ((old_int*8 - 8)%8) + old_char;
    new_tile = ((new_int*8 - 8)%8) + new_char;
    std::cout << old_tile << new_tile << std::endl;
    tiles[old_tile]->get_piece()->move_piece(tiles[new_tile]);
    return true;
}