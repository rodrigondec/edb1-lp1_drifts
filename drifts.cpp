#include "estaticos/includes_lib.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum{
    IMG_INITIALSCREEN, IMG_BACKGROUND, IMG_STARTGAME, IMG_GAMEOVER, 
    IMG_0, IMG_1, IMG_2, IMG_3, IMG_4, IMG_5, IMG_6, IMG_7, IMG_8, IMG_9, 
    IMG_A, IMG_B, IMG_C, IMG_D, IMG_E, IMG_F, IMG_G, IMG_H, IMG_I, IMG_J, IMG_K, IMG_L, 
    IMG_M, IMG_N, IMG_O, IMG_P, IMG_Q, IMG_R, IMG_S, IMG_T, IMG_U, IMG_V, IMG_W, IMG_Y, IMG_Z, 
    IMG_REWIND, IMG_USERLIFE, IMG_PLAY, IMG_PAUSE, IMG_PLAYAGAIN, IMG_SOUNDON, IMG_SOUNDOFF, 
    IMG_PLAYER, IMG_POINTER, IMG_MURDERER, IMG_SAVER, TOTAL_IMG
};

struct Bola{
    bool attached;
    string tipo;
    SDL_Rect Rect;
};

bool Running;
int screen;

vector <Bola> bolas;

const int WindowWidth = 640;
const int WindowHeight = 480;

SDL_Window* Window = NULL;
SDL_Texture* TextureBank[TOTAL_IMG] = {};
SDL_Renderer* Renderer = NULL;
SDL_Event Event;

SDL_Rect playerRect;
SDL_Rect startgameRect;
SDL_Rect rewindRect;
SDL_Rect geralRect;

#include "estaticos/includes_templates.h"

int main(int argc, char* argv[]) {
    if(!Init()) {
        return 0;
    }
    //while(1){
        create_bola();
        bolas[0].attached = true;
        create_bola();
        cout<<"bolas[0].rect.x = "<<bolas[0].attached<<endl;
        cout<<"bolas[1].rect.x = "<<bolas[1].attached<<endl;
    //}
    while(Running) {
        while(SDL_PollEvent(&Event) != 0) {
            OnEvent(&Event);
        }

        Loop();
        Render();

        SDL_Delay(1); // Breath
    }

    Cleanup();
    return 1;
}