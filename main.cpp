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
        if(count % 2 == 0){
            cout << "White to move." << endl;
        } else{
            cout << "Black to move." << endl;
        }
        cout << "Please enter next move: ";
        cin >> old_pos >> new_pos;
        count++;
    }
    return 0;
}