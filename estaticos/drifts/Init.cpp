bool Drifts::Init(){
//+++++++++++++++++ INITIALIZING VIDEO ++++++++++++++++++++++++++++++++++++//
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        cout<<"Unable to Init SDL: "<<SDL_GetError();
        return false;
    }
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        cout<<"Unable to Init hinting: "<<SDL_GetError();
    }
//+++++++++++++++++ END INIT VIDEO ++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ CREATING WINDOW +++++++++++++++++++++++++++++++++++++++//
    if((Window = SDL_CreateWindow(
        "Drifts",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
    ) == NULL) {
        cout<<"Unable to create SDL Window: "<<SDL_GetError();
        return false;
    }
//+++++++++++++++++ END WINDOW +++++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ RENDERING WINDOW +++++++++++++++++++++++++++++++++++++//
    if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        cout<<"Unable to create renderer";
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);
//+++++++++++++++++ END RENDERING +++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ INITIALIZING PNG LIB ++++++++++++++++++++++++++++++++//
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        cout<<"Unable to init SDL_image: "<<IMG_GetError();
        return false;
    }
//+++++++++++++++++ END PNG LIB +++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ INITIALIZING MIXER ++++++++++++++++++++++++++++++++//
    if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0){
        cout<<"SDL_mixer could not initialize! SDL_mixer Error: "<<Mix_GetError()<<endl;
        return false;
    }
//+++++++++++++++++ END MIXER ++++++++++++++++++++++++++++++++//

//+++++++++++++++++ SETANDO ICONE DO APP ++++++++++++++++++++++++++++++++//    
    SDL_Surface* loadsurf = IMG_Load("images/balls/player.png");
    
    SDL_SetWindowIcon(Window, loadsurf);

    SDL_FreeSurface(loadsurf);
//++++++++++++++ END ICONE APP +++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++ LOADING MUSIC +++++++++++++++++++++++++++++++++++++++++//
    load_WAV("sounds/The Prodigy - Hot Ride.wav");
//++++++++++++++ END LOADING +++++++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++ LOADING IMG'S +++++++++++++++++++++++++++++++++++++++++//
    TextureBank[IMG_INITIALSCREEN] = load_PNG("images/background/initialscreen.png");
    TextureBank[IMG_BACKGROUND] = load_PNG("images/background/background.png");
    
    TextureBank[IMG_STARTGAME] = load_PNG("images/menu/startgame.png");
    TextureBank[IMG_GAMEOVER] = load_PNG("images/menu/gameover.png");

    TextureBank[IMG_INSTRUCAO1] = load_PNG("images/instrucao/instrucao1.png");
    TextureBank[IMG_INSTRUCAO2] = load_PNG("images/instrucao/instrucao2.png");
    TextureBank[IMG_INSTRUCAO3] = load_PNG("images/instrucao/instrucao3.png");

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
    TextureBank[IMG_FORWARD] = load_PNG("images/icons/forward.png");
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
    srand(time(NULL));

    Running = true;
    screen = CREDITOS;

    checker_create_bola = true;
    checker_move_bola = 1;
    clock_spawn = 5;
    get_more_pointers = 0;
    paused = 0;
    rip = 0;
    instrucao = 1;
    bolas_attached = false;

    startgameRect.x = 220;
    startgameRect.y = 200;
    startgameRect.w = 200;
    startgameRect.h = 80;

    gameoverRect.x = 120;
    gameoverRect.y = 120;
    gameoverRect.w = 400;
    gameoverRect.h = 160;

    letraRect.w = 45;
    letraRect.h = 45;

    pauseplayRect.x = 10;
    pauseplayRect.y = 10;
    pauseplayRect.w = 35;
    pauseplayRect.h = 35;

    rewindRect.x = 10;
    rewindRect.y = 10;
    rewindRect.w = 35;
    rewindRect.h = 35;

    forwardRect.x = 10;
    forwardRect.y = 55;
    forwardRect.w = 35;
    forwardRect.h = 35;

    soundRect.x = 60;
    soundRect.y = 10;
    soundRect.w = 35;
    soundRect.h = 35;

    instrucao1Rect.x = 0;
    instrucao1Rect.y = 120;
    instrucao1Rect.w = 200;
    instrucao1Rect.h = 200;

    instrucao2Rect.x = 220;
    instrucao2Rect.y = 120;
    instrucao2Rect.w = 200;
    instrucao2Rect.h = 200;

    instrucao3Rect.x = 440;
    instrucao3Rect.y = 120;
    instrucao3Rect.w = 200;
    instrucao3Rect.h = 200;
//++++++++++++++ END VAR'S +++++++++++++++++++++++++++++++++++++++++++//
    Mix_PlayMusic(Music, -1);
    system("cls");
    system("clear");

    return true;
}