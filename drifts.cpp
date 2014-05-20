#include "estaticos/includes.h"

bool Running;

const int WindowWidth = 640;
const int WindowHeight = 480;

SDL_Window* Window = NULL;

SDL_Texture* gCurrentTexture = NULL;
SDL_Texture* gScreenTexture = NULL;
SDL_Texture* gLoadedImage = NULL;
SDL_Texture* gImages[TOTAL_IMAGES] = {};

SDL_Surface* PrimarySurface = NULL;


int main(int argc, char* argv[]) {
    if(!Init()) {
        return 0;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event) != 0) {
            OnEvent(&Event);

            if(Event.type == SDL_QUIT) Running = false;
        }

        Loop();
        Render();

        SDL_Delay(1); // Breath
    }

    Cleanup();
    return 1;
}