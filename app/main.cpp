#include <iostream>
#include "ai_player.hpp"


int main() {
    pamsi::tic_tac_toe::SinglePlayerGame game(4, 3);
    while(!game.loop())
        ;
    return 0;
}