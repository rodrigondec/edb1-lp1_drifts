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
    SDL_Surface* loadsurf = IMG_Load("C:/Users/Rodrigo/Downloads/prog/drifts/images/balls/player.png");
    
    SDL_SetWindowIcon(Window, loadsurf);

    SDL_FreeSurface(loadsurf);
//++++++++++++++ END ICONE APP +++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++ LOADING IMG'S +++++++++++++++++++++++++++++++++++++++++//
    TextureBank[IMG_INITIALSCREEN] = load_PNG("images/background/initialscreen.png");
    TextureBank[IMG_BACKGROUND] = load_PNG("images/background/background.png");
    
    TextureBank[IMG_STARTGAME] = load_PNG("images/menu/startgame.png");
    TextureBank[IMG_GAMEOVER] = load_PNG("images/menu/gameover.png");

    TextureBank[IMG_0] = load_PNG("images/numeros/0.png");
    TextureBank[IMG_1] = load_PNG("images/numeros/1.png");
    TextureBank[IMG_2] = load_PNG("images/numeros/2.png");
    TextureBank[IMG_3] = load_PNG("images/numeros/3.png");
    TextureBank[IMG_4] = load_PNG("images/numeros/4.png");
    TextureBank[IMG_5] = load_PNG("images/numeros/5.png");
    TextureBank[IMG_6] = load_PNG("images/numeros/6.png");
    TextureBank[IMG_7] = load_PNG("images/numeros/7.png");
    TextureBank[IMG_8] = load_PNG("images/numeros/8.png");
    TextureBank[IMG_9] = load_PNG("images/numeros/9.png");


    TextureBank[IMG_A] = load_PNG("images/letras/A.png");
    TextureBank[IMG_B] = load_PNG("images/letras/B.png");
    TextureBank[IMG_C] = load_PNG("images/letras/C.png");
    TextureBank[IMG_D] = load_PNG("images/letras/D.png");
    TextureBank[IMG_E] = load_PNG("images/letras/E.png");
    TextureBank[IMG_F] = load_PNG("images/letras/F.png");
    TextureBank[IMG_G] = load_PNG("images/letras/G.png");
    TextureBank[IMG_H] = load_PNG("images/letras/H.png");
    TextureBank[IMG_I] = load_PNG("images/letras/I.png");
    TextureBank[IMG_J] = load_PNG("images/letras/J.png");
    TextureBank[IMG_K] = load_PNG("images/letras/K.png");
    TextureBank[IMG_L] = load_PNG("images/letras/L.png");
    TextureBank[IMG_M] = load_PNG("images/letras/M.png");
    TextureBank[IMG_N] = load_PNG("images/letras/N.png");
    TextureBank[IMG_O] = load_PNG("images/letras/O.png");
    TextureBank[IMG_P] = load_PNG("images/letras/P.png");
    TextureBank[IMG_Q] = load_PNG("images/letras/Q.png");
    TextureBank[IMG_R] = load_PNG("images/letras/R.png");
    TextureBank[IMG_S] = load_PNG("images/letras/S.png");
    TextureBank[IMG_T] = load_PNG("images/letras/T.png");
    TextureBank[IMG_U] = load_PNG("images/letras/U.png");
    TextureBank[IMG_V] = load_PNG("images/letras/V.png");
    TextureBank[IMG_W] = load_PNG("images/letras/W.png");
    TextureBank[IMG_Y] = load_PNG("images/letras/Y.png");
    TextureBank[IMG_Z] = load_PNG("images/letras/Z.png");

    TextureBank[IMG_REWIND] = load_PNG("images/icons/rewind.png");
    TextureBank[IMG_USERLIFE] = load_PNG("images/icons/user_life.png");
    TextureBank[IMG_PLAY] = load_PNG("images/icons/play.png");
    TextureBank[IMG_PAUSE] = load_PNG("images/icons/pause.png");
    TextureBank[IMG_PLAYAGAIN] = load_PNG("images/icons/play_again.png");
    TextureBank[IMG_SOUNDON] = load_PNG("images/icons/sound.png");
    TextureBank[IMG_SOUNDOFF] = load_PNG("images/icons/sound_off.png");

    TextureBank[IMG_PLAYER] = load_PNG("images/balls/player.png");
    TextureBank[IMG_POINTER] = load_PNG("images/balls/pointer.png");
    TextureBank[IMG_MURDERER] = load_PNG("images/balls/murderer.png");
    TextureBank[IMG_SAVER] = load_PNG("images/balls/saver.png");
//++++++++++++++ END LOADING ++++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++ SETING VAR'S +++++++++++++++++++++++++++++++++++++++++//
    Running = true;
    screen = 0;

    playerRect.w = 45;//Mouse Width
    playerRect.h = 45;//Mouse Height

    startgameRect.y = ((WindowHeight-120)/2);
    startgameRect.x = -50;
    startgameRect.w = 800;
    startgameRect.h = 80;

    rewindRect.x = 10;
    rewindRect.y = 10;
    rewindRect.w = 80;
    rewindRect.h = 80;
//++++++++++++++ END VAR'S +++++++++++++++++++++++++++++++++++++++++++//
    system("cls");
    return true;
}