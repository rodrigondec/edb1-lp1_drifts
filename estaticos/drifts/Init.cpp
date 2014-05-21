bool Init(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        Log("Unable to Init SDL: %s", SDL_GetError());
        return false;
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        Log("Unable to Init hinting: %s", SDL_GetError());
    }

    if((Window = SDL_CreateWindow(
        "Drifts",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
    ) == NULL) {
        Log("Unable to create SDL Window: %s", SDL_GetError());
        return false;
    }

    if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        Log("Unable to create renderer");
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);

    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        Log("Unable to init SDL_image: %s", IMG_GetError());
        return false;
    }

//+++++++++++++++++ SETANDO ICONE DO APP ++++++++++++++++++++++++++++++++//    
    SDL_Surface* gScreenSurface = SDL_GetWindowSurface(Window);
    SDL_Surface* ggOptimizedSurface = NULL;
    SDL_Surface* ggLoadedSurface = IMG_Load("estaticos/images/player.png");

    if(ggLoadedSurface == NULL)
    {
        cout << "Erro ao carregar imagem " << endl;
    }
    else
    {
        ggOptimizedSurface = SDL_ConvertSurface( ggLoadedSurface, gScreenSurface->format, 0);
        if(ggOptimizedSurface == NULL)
        {
            cout <<"Erro ao converter imagem." << endl;
        }
    }
    SDL_FreeSurface(gScreenSurface);
    SDL_FreeSurface(ggLoadedSurface);

    SDL_SetWindowIcon(Window, ggOptimizedSurface);
    SDL_FreeSurface(ggOptimizedSurface);
//++++++++++++++ END ICONE APP +++++++++++++++++++++++++++++++++++++++++//
    Running = true;
    screen = 0;

    playerRect.w = 45;
    playerRect.h = 45;
    
    return true;
}