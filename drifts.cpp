#include "estaticos/includes_lib.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum{
    IMG_INITIALSCREEN, IMG_BACKGROUND, 
    IMG_STARTGAME, IMG_GAMEOVER, 
    IMG_0, IMG_1, IMG_2, IMG_3, IMG_4, IMG_5, IMG_6, IMG_7, IMG_8, IMG_9, 
    IMG_A, IMG_B, IMG_C, IMG_D, IMG_E, IMG_F, IMG_G, IMG_H, IMG_I, IMG_J, IMG_K, IMG_L, 
    IMG_M, IMG_N, IMG_O, IMG_P, IMG_Q, IMG_R, IMG_S, IMG_T, IMG_U, IMG_V, IMG_W, IMG_Y, IMG_Z, 
    IMG_REWIND, IMG_USERLIFE, IMG_PLAY, IMG_PAUSE, IMG_PLAYAGAIN, IMG_SOUNDON, IMG_SOUNDOFF, 
    IMG_PLAYER, IMG_POINTER, IMG_MURDERER, IMG_SAVER, TOTAL_IMG
};

#include "estaticos/includes_templates.h"

Drifts::Drifts(){
    WindowWidth = 640;
    WindowHeight = 480;

    Window = NULL;
    Renderer = NULL;
    Music = NULL;

    checker_create_bola = true;
    checker_move_bola = 1;
    clock_spawn = 5;
    get_more_pointers = 0;
    paused = 0;
    rip = 0;

    srand(time(NULL));
}

Drifts::~Drifts(){}

int main(int argc, char* argv[]){
    Drifts jogo;
    jogo.Run();
    return 0;
}