#include "estaticos/includes_lib.h"

using std::cout;
using std::endl;
using std::string;

bool Running;
int screen;

const int WindowWidth = 640;
const int WindowHeight = 480;

SDL_Window* Window = NULL;

/*SDL_Texture* CurrentTexture = NULL;
SDL_Texture* ScreenTexture = NULL;
SDL_Texture* LoadedImage = NULL;*/

SDL_Renderer* Renderer = NULL;

SDL_Event Event;

SDL_Rect backgroundRect;

SDL_Rect playerRect;

#include "estaticos/includes_templates.h"

int main(int argc, char* argv[]) {
    if(!Init()) {
        return 0;
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