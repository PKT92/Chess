#include "Board.h"

Board::Board()
: game_status{1}{
    std::cout << "Please enter a move in the following way: <piece location> <new location>" << std::endl;
    std::cout << "Ex. a4 a5" << std::endl;
    // 64 tiles for the chess board
    for(int i = 0; i < 64; i++){
        tiles.push_back(new Tile(i));
    }
    // Kings
    pieces.push_back(new Piece(0, 5, tiles[60]));
    pieces.push_back(new Piece(1, 5, tiles[4]));
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
    pieces.push_back(new Piece(1, 2, tiles[5]));
    pieces.push_back(new Piece(1, 1, tiles[6]));
    pieces.push_back(new Piece(1, 3, tiles[7]));
    // White major pieces
    pieces.push_back(new Piece(0, 3, tiles[56]));
    pieces.push_back(new Piece(0, 1, tiles[57]));
    pieces.push_back(new Piece(0, 2, tiles[58]));
    pieces.push_back(new Piece(0, 4, tiles[59]));
    pieces.push_back(new Piece(0, 2, tiles[61]));
    pieces.push_back(new Piece(0, 1, tiles[62]));
    pieces.push_back(new Piece(0, 3, tiles[63]));
}

void Board::print_board(){
    int labelCount = 0, tileCount = 0;
    int numCount = 7;
    std::cout << "------------------------------ Black ------------------------------" << std::endl;
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
                Piece *tmp_piece = tiles[tileCount]->get_piece();
                if(tmp_piece != nullptr){
                    if(tmp_piece->get_piece() == 0){
                        if(tmp_piece->get_color() == 0){
                            std::cout << "WP";
                        } else{
                            std::cout << "BP";
                        }
                    } else if(tmp_piece->get_piece() == 1){
                        if(tmp_piece->get_color() == 0){
                            std::cout << "WN";
                        } else{
                            std::cout << "BN";
                        }
                    } else if(tmp_piece->get_piece() == 2){
                        if(tmp_piece->get_color() == 0){
                            std::cout << "WB";
                        } else{
                            std::cout << "BB";
                        }
                    } else if(tmp_piece->get_piece() == 3){
                        if(tmp_piece->get_color() == 0){
                            std::cout << "WR";
                        } else{
                            std::cout << "BR";
                        }
                    } else if(tmp_piece->get_piece() == 4){
                        if(tmp_piece->get_color() == 0){
                            std::cout << "WQ";
                        } else{
                            std::cout << "BQ";
                        }
                    } else if(tmp_piece->get_piece() == 5){
                        if(tmp_piece->get_color() == 0){
                            std::cout << "WK";
                        } else{
                            std::cout << "BK";
                        }
                    }
                } else{
                    std::cout << "  ";
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
    std::cout << "------------------------------ White ------------------------------" << std::endl;
}

bool Board::get_game_status(){
    return game_status;
}

bool Board::move_piece(std::string old_pos, std::string new_pos, int color){
    int swapped[] = {7, 6, 5, 4, 3, 2, 1, 0};
    if(old_pos.length() != 2 || new_pos.length() != 2){
        return false;
    }
    int old_int, new_int;
    int old_char, new_char;
    int old_tile, new_tile;
    if(isdigit(old_pos[0])){
        old_int = int(old_pos[0]) - 48 - 1;
        old_char = int(tolower(old_pos[1])) - 97;
    } else{
        old_char = int(tolower(old_pos[0])) - 97;
        old_int = int(old_pos[1]) - 48 - 1;
    }
    if(isdigit(new_pos[0])){
        new_int = int(new_pos[0]) - 48 - 1;
        new_char = int(tolower(new_pos[1])) - 97;
    } else{
        new_char = int(tolower(new_pos[0])) - 97;
        new_int = int(new_pos[1]) - 48 - 1;
    }
    old_int = swapped[old_int];
    new_int = swapped[new_int];
    old_tile = (old_int*8) + old_char;
    if(tiles[old_tile]->get_piece()->move_piece(tiles, old_char, old_int, new_char, new_int, color)){
        return true;
    }
    return false;
}