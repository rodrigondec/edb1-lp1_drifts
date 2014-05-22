#include "estaticos/includes_lib.h"

using std::cout;
using std::endl;
using std::string;

enum{
    IMG_CREDITS, IMG_BACKGROUND, IMG_PLAYER, IMG_POINTER, IMG_MURDERER, IMG_SAVER, TOTAL_IMG
};

struct Bola{
    bool attached;
    string tipo;
    SDL_Rect Rect;
};

bool Running;
int screen;

Bola *bolas = new Bola[1];

const int WindowWidth = 640;
const int WindowHeight = 480;

SDL_Window* Window = NULL;
SDL_Texture* TextureBank[TOTAL_IMG] = {};
SDL_Renderer* Renderer = NULL;
SDL_Rect playerRect;
SDL_Event Event;

#include "estaticos/includes_templates.h"

int main(int argc, char* argv[]) {
    if(!Init()) {
        return 0;
    }
    while(1){
        Bola temp = new Bola[]; 
        temp.attached = true;
        cout<<"temp.attached = "<<temp.attached<<endl;
    }
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