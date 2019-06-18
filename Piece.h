#pragma once

class Piece
{
public:
    Piece();
    Piece(bool start_color, int piece_type, int startx, int starty);
    ~Piece();
    void move_piece(int newx, int newy);
private:
    int piece; // 0 pawn, 1 knight, 2 bishop, 3 rook, 4 queen, 5 king
    int value; // 100 pawn, 300 bishop, 300 knight, 500 rook, 1000 queen, 5000 king
    bool alive; // 1 alive, 0 dead
    bool color; // 1 black, 0 white
    int x;
    int y;
};