#include "Board.h"

Board::Board()
: game_status{1}{
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