int Drifts::Execute(int argc, char* argv[]){
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