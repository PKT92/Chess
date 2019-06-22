#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

int main(int argc, char *argv[]){
    Board *b = new Board();
    int count = 0;
    string old_pos, new_pos;
    while(b->get_game_status()){
        b->print_board();
        int color = count%2;
        if(color == 0){
            cout << "White to move." << endl;
        } else{
            cout << "Black to move." << endl;
        }
        cout << "Please enter next move: ";
        cin >> old_pos >> new_pos;
        if(!b->move_piece(old_pos, new_pos, color)){
            cout << "Invalid move." << endl;
        } else{
            count++;
        }
    }
    return 0;
}