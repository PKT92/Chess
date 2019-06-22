#include "Piece.h"

// Piece();
// Piece(bool color, bool alive, int piece_type, int startx, int starty);
// ~Piece();
// void move_piece(int newx, int newy);
Piece::Piece(): color{0}, alive{1}, piece{0}, tile{nullptr}{}

Piece::Piece(bool start_color, int piece_type, Tile *x)
: color{start_color}, alive{1}, piece{piece_type}, tile{x}{
    tile->set_piece(this);
}

void Piece::set_piece_status(bool status){
    alive = status;
}

bool Piece::get_color(){
    return color;
}

bool Piece::is_enpassant(){
    return enpassant;
}

bool Piece::pawn_check(Tile *new_tile, std::vector<Tile*> tiles){
    std::cout << "This happened here" << std::endl;
    int next_tile = new_tile->get_tile();
    if(new_tile->get_piece() == nullptr){
        if(first_move){
            if((next_tile == (tile->get_tile() + 16) || next_tile == (tile->get_tile() + 8))){
                enpassant = true;
                first_move = false;
                return true;
            } else if((next_tile == (tile->get_tile() - 16) || next_tile == (tile->get_tile() - 8))){
                enpassant = true;
                first_move = false;
                return true;
            }
        } else if(next_tile == (tile->get_tile() - 7)){
            if(tiles[tile->get_tile() + 1]->get_piece() != nullptr && tiles[tile->get_tile() + 1]->get_piece()->is_enpassant()){
                tiles[tile->get_tile() + 1]->get_piece()->set_piece_status(false);
                tiles[tile->get_tile() + 1]->remove_piece();
                return true;
            }
        } else if(next_tile == (tile->get_tile() + 7)){
            if(tiles[tile->get_tile() - 1]->get_piece() != nullptr && tiles[tile->get_tile() - 1]->get_piece()->is_enpassant()){
                tiles[tile->get_tile() - 1]->get_piece()->set_piece_status(false);
                tiles[tile->get_tile() - 1]->remove_piece();
                return true;
            }
        } else if(next_tile == (tile->get_tile() - 9)){
            if(tiles[tile->get_tile() - 1]->get_piece() != nullptr && tiles[tile->get_tile() - 1]->get_piece()->is_enpassant()){
                tiles[tile->get_tile() - 1]->get_piece()->set_piece_status(false);
                tiles[tile->get_tile() - 1]->remove_piece();
                return true;
            }
        } else if(next_tile == (tile->get_tile() + 9)){
            if(tiles[tile->get_tile() + 1]->get_piece() != nullptr && tiles[tile->get_tile() + 1]->get_piece()->is_enpassant()){
                tiles[tile->get_tile() + 1]->get_piece()->set_piece_status(false);
                tiles[tile->get_tile() + 1]->remove_piece();
                return true;
            }
        } else if(next_tile == (tile->get_tile() + 8)){
            return true;
        } else if(next_tile == (tile->get_tile() - 8)){
            return true;
        } 
    } else{
        if((next_tile == (tile->get_tile() + 9) || next_tile == (tile->get_tile() + 7))){
            return true;
        } else if((next_tile == (tile->get_tile() - 9) || next_tile == (tile->get_tile() - 7))){
            return true;
        }
    }
    return false;
}

bool Piece::knight_check(Tile *new_tile, int old_col, int new_col, int old_row, int new_row){
    std::cout << old_col << new_col << old_row << new_row << std::endl;
    if(abs(old_col - new_col) == 2){
        if(abs(old_row - new_row) == 1){
            return true;
        }
    } else if(abs(old_row - new_row) == 2){
        if(abs(old_col - new_col) == 1){
            return true;
        }
    }
    return false;
}

bool Piece::bishop_check(Tile *new_tile, int old_col, int new_col, int old_row, int new_row){
    if(abs(old_col-new_col) == abs(old_row-new_row)){
        return true;
    }
    return false;
}

bool Piece::rook_check(Tile *new_tile, int old_col, int new_col, int old_row, int new_row){
    if(old_col == new_col || old_row == new_row){
        return true;
    }
    return false;
}

bool Piece::move_check(std::vector<Tile*> tiles, Tile *new_tile,  int old_col, int new_col, int old_row, int new_row){
    if(piece == 0 && pawn_check(new_tile, tiles)){
        return true;
    } else if(piece == 1 && knight_check(new_tile, old_col, new_col, old_row, new_row)){
        return true;
    } else if(piece == 2 && bishop_check(new_tile, old_col, new_col, old_row, new_row)){
        return true;
    } else if(piece == 3 && rook_check(new_tile, old_col, new_col, old_row, new_row)){
        return true;
    } else if(piece == 4 && (bishop_check(new_tile, old_col, new_col, old_row, new_row) || rook_check(new_tile, old_col, new_col, old_row, new_row))){
        return true;
    }
    return false;
}

// TODO:
//   Need to implement Queening a pawn
//   Need to stop movement of pieces through other pieces
bool Piece::move_piece(std::vector<Tile*> tiles, int old_col, int old_row, int new_col, int new_row, int moving_color){
    int swapped[] = {7, 6, 5, 4, 3, 2, 1, 0};
    int new_tile;
    std::cout << moving_color << " " << color << std::endl;
    new_tile = (new_row*8) + new_col;
    Tile *x = tiles[new_tile];
    if(x->get_piece() != nullptr){
        if(x->get_piece()->get_color() != color && moving_color == color){
            if(move_check(tiles, x, old_col, new_col, old_row, new_row)){
                x->get_piece()->set_piece_status(false); 
                tile->remove_piece();
                tile = x;
                tile->set_piece(this);
                return true;
            }
        }
    } else if(move_check(tiles, x, old_col, new_col, old_row, new_row) && moving_color == color){
        tile->remove_piece();
        tile = x;
        tile->set_piece(this);
        return true;
    }
    return false;
}

int Piece::get_piece(){
    return piece;
}