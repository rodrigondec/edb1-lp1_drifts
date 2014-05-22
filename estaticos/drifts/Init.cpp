bool Init(){
//+++++++++++++++++ INITIALIZING VIDEO ++++++++++++++++++++++++++++++++++++//
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        Log("Unable to Init SDL: %s", SDL_GetError());
        return false;
    }
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        Log("Unable to Init hinting: %s", SDL_GetError());
    }
//+++++++++++++++++ END INIT VIDEO ++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ CREATING WINDOW +++++++++++++++++++++++++++++++++++++++//
    if((Window = SDL_CreateWindow(
        "Drifts",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
    ) == NULL) {
        Log("Unable to create SDL Window: %s", SDL_GetError());
        return false;
    }
//+++++++++++++++++ END WINDOW +++++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ RENDERING WINDOW +++++++++++++++++++++++++++++++++++++//
    if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        Log("Unable to create renderer");
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);
//+++++++++++++++++ END RENDERING +++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ INITIALIZING PNG LIB ++++++++++++++++++++++++++++++++//
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        Log("Unable to init SDL_image: %s", IMG_GetError());
        return false;
    }
//+++++++++++++++++ END PNG LIB +++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ SETANDO ICONE DO APP ++++++++++++++++++++++++++++++++//    
    SDL_Surface* gScreenSurface = SDL_GetWindowSurface(Window);
    SDL_Surface* ggOptimizedSurface = NULL;
    SDL_Surface* ggLoadedSurface = IMG_Load("images/player.png");

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

//++++++++++++++ LOADING IMG'S +++++++++++++++++++++++++++++++++++++++++//
    TextureBank[IMG_CREDITS] = load_PNG("images/background.png");
    TextureBank[IMG_BACKGROUND] = load_PNG("images/background.png");
    TextureBank[IMG_PLAYER] = load_PNG("images/player.png");
    TextureBank[IMG_POINTER] = load_PNG("images/pointer.png");
    TextureBank[IMG_MURDERER] = load_PNG("images/murderer.png");
    TextureBank[IMG_SAVER] = load_PNG("images/saver.png");
//++++++++++++++ END LOADING ++++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++ SETING VAR'S +++++++++++++++++++++++++++++++++++++++++//
    Running = true;
    screen = 0;

    playerRect.w = 45;//Mouse Width
    playerRect.h = 45;//Mouse Height
//++++++++++++++ END VAR'S +++++++++++++++++++++++++++++++++++++++++++//
    return true;
}