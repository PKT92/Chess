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

// TODO:
//   Enpassant movement
bool Piece::pawn_check(Tile *new_tile){
    int next_tile = new_tile->get_tile();
    if(new_tile->get_piece() == nullptr){
        if(first_move){
            if((next_tile == (tile->get_tile() + 16) || next_tile == (tile->get_tile() + 8)) && color == 1){
                enpassant = true;
                first_move = false;
                return true;
            } else if((next_tile == (tile->get_tile() - 16) || next_tile == (tile->get_tile() + 8)) && color == 0){
                enpassant = true;
                first_move = false;
                return true;
            }
        } else if(next_tile == (tile->get_tile() + 8) && color == 1){
            return true;
        } else if(next_tile == (tile->get_tile() - 8) && color == 0){
            return true;
        }
    } else{
        if((next_tile == (tile->get_tile() + 9) || next_tile == (tile->get_tile() + 7)) && color == 1){
            return true;
        } else if((next_tile == (tile->get_tile() - 9) || next_tile == (tile->get_tile() - 7)) && color == 0){
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
    std::cout << "This workd" << std::endl;
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

bool Piece::move_check(Tile *new_tile,  int old_col, int new_col, int old_row, int new_row){
    if(piece == 0 && pawn_check(new_tile)){
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
bool Piece::move_piece(Tile *x, int old_col, int old_row, int new_col, int new_row){
    if(x->get_piece() != nullptr){
        if(x->get_piece()->get_color() != color){
            if(move_check(x, old_col, new_col, old_row, new_row)){
                x->get_piece()->set_piece_status(false); 
                tile->remove_piece();
                tile = x;
                tile->set_piece(this);
                return true;
            }
        }
    } else if(move_check(x, old_col, new_col, old_row, new_row)){
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