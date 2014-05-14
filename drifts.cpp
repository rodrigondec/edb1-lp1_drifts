#include <iostream>
#include <cstdlib>
#include <SDL/SDL.h>
#include "estaticos/drifts_includes.h"


Drifts::Drifts() {
    Running = true;
}
 
int Drifts::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}
 
int main(int argc, char* argv[]){
    Drifts theApp;
 
    return theApp.OnExecute();
}