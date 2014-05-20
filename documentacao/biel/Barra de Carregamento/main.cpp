#include <iostream>
#include <SDL.h>
#include <string>
#include <SDL_image.h>

using namespace std;

enum
{
    IMG_A, IMG_B, IMG_C, IMG_D, IMG_E, IMG_F, IMG_G, IMG_H, IMG_I, IMG_J, IMG_K, IMG_L, IMG_M, IMG_N, IMG_O, IMG_P, IMG_Q,
    IMG_R, IMG_S, IMG_T, IMG_U, IMG_V, IMG_W, IMG_X, IMG_Y, IMG_Z, IMG_1, IMG_2, IMG_3, IMG_4, IMG_5, IMG_6, IMG_7, IMG_8,
    IMG_9, IMG_0, TOTAL_IMAGES
};

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Variáveis:
SDL_Window* gWindow = NULL;
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gLoadedImage = NULL;
SDL_Surface* gImages[TOTAL_IMAGES] = {};
SDL_Event e;
SDL_Surface* gCar = NULL;
bool sair = false;
int estado = 0;
SDL_Rect stretchRect;

//Funções:
void init();
SDL_Surface* load_PNG(string);
void pintar(SDL_Surface*, int, int, int);
void load_media();
void event_key();
void carregamento();

void init(){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "Ocorreu um erro na inicializacao do SDL, Erro: " << SDL_GetError() << endl;
    }
    else
    {
        gWindow = SDL_CreateWindow( "Jogo da memoria", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            cout << "A Janela falhou em ser criada, Erro: " << SDL_GetError() << endl;
        }
        else
        {
            int imgFlags = IMG_INIT_PNG;
            IMG_Init(imgFlags);
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
}

SDL_Surface* load_PNG(string path){
    SDL_Surface* ggOptimizedSurface = NULL;
    SDL_Surface* ggLoadedSurface = IMG_Load( path.c_str() );

    if(ggLoadedSurface == NULL)
    {
        cout << "Erro ao carregar imagem " << path << "." << endl;
    }
    else
    {
        ggOptimizedSurface = SDL_ConvertSurface( ggLoadedSurface, gScreenSurface->format, 0);
        if(ggOptimizedSurface == NULL)
        {
            cout <<"Erro ao converter imagem." << endl;
        }
    }
    SDL_FreeSurface(ggLoadedSurface);

    return ggOptimizedSurface;
}

void pintar(SDL_Surface* target, int a, int b, int c){
    SDL_FillRect( target, NULL, SDL_MapRGB( gScreenSurface->format, a, b, c ) );
}

void load_media(){
    gCar = load_PNG("Arquivos/Imagens/barra.png");
    int estado = 0;
    gImages[IMG_0] = load_PNG("Arquivos/Imagens/0.png");
    carregamento();
    gImages[IMG_1] = load_PNG("Arquivos/Imagens/1.png");
    carregamento();
    gImages[IMG_2] = load_PNG("Arquivos/Imagens/2.png");
    carregamento();
    gImages[IMG_3] = load_PNG("Arquivos/Imagens/3.png");
    carregamento();
    gImages[IMG_4] = load_PNG("Arquivos/Imagens/4.png");
    carregamento();
    gImages[IMG_5] = load_PNG("Arquivos/Imagens/5.png");
    carregamento();
    gImages[IMG_6] = load_PNG("Arquivos/Imagens/6.png");
    carregamento();
    gImages[IMG_7] = load_PNG("Arquivos/Imagens/7.png");
    carregamento();
    gImages[IMG_8] = load_PNG("Arquivos/Imagens/8.png");
    carregamento();
    gImages[IMG_9] = load_PNG("Arquivos/Imagens/9.png");
    carregamento();
    gImages[IMG_A] = load_PNG("Arquivos/Imagens/A.png");
    carregamento();
    gImages[IMG_B] = load_PNG("Arquivos/Imagens/B.png");
    carregamento();
    gImages[IMG_C] = load_PNG("Arquivos/Imagens/C.png");
    carregamento();
    gImages[IMG_D] = load_PNG("Arquivos/Imagens/D.png");
    carregamento();
    gImages[IMG_E] = load_PNG("Arquivos/Imagens/E.png");
    carregamento();
    gImages[IMG_F] = load_PNG("Arquivos/Imagens/F.png");
    carregamento();
    gImages[IMG_G] = load_PNG("Arquivos/Imagens/G.png");
    carregamento();
    gImages[IMG_H] = load_PNG("Arquivos/Imagens/H.png");
    carregamento();
    gImages[IMG_I] = load_PNG("Arquivos/Imagens/I.png");
    carregamento();
    gImages[IMG_J] = load_PNG("Arquivos/Imagens/J.png");
    carregamento();
    gImages[IMG_K] = load_PNG("Arquivos/Imagens/K.png");
    carregamento();
    gImages[IMG_L] = load_PNG("Arquivos/Imagens/L.png");
    carregamento();
    gImages[IMG_M] = load_PNG("Arquivos/Imagens/M.png");
    carregamento();
    gImages[IMG_N] = load_PNG("Arquivos/Imagens/N.png");
    carregamento();
    gImages[IMG_O] = load_PNG("Arquivos/Imagens/O.png");
    carregamento();
    gImages[IMG_P] = load_PNG("Arquivos/Imagens/P.png");
    carregamento();
    gImages[IMG_Q] = load_PNG("Arquivos/Imagens/Q.png");
    carregamento();
    gImages[IMG_R] = load_PNG("Arquivos/Imagens/R.png");
    carregamento();
    gImages[IMG_S] = load_PNG("Arquivos/Imagens/S.png");
    carregamento();
    gImages[IMG_T] = load_PNG("Arquivos/Imagens/T.png");
    carregamento();
    gImages[IMG_U] = load_PNG("Arquivos/Imagens/U.png");
    carregamento();
    gImages[IMG_V] = load_PNG("Arquivos/Imagens/V.png");
    carregamento();
    gImages[IMG_W] = load_PNG("Arquivos/Imagens/W.png");
    carregamento();
    gImages[IMG_X] = load_PNG("Arquivos/Imagens/X.png");
    carregamento();
    gImages[IMG_Y] = load_PNG("Arquivos/Imagens/Y.png");
    carregamento();
    gImages[IMG_Z] = load_PNG("Arquivos/Imagens/Z.png");
    carregamento();
    cout << "Carregou!" << endl;
}

void carregamento(){
    estado++;
    cout << estado << endl;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = estado * SCREEN_WIDTH / 36;
    stretchRect.h = SCREEN_HEIGHT;
    SDL_BlitScaled (gCar, NULL, gScreenSurface, &stretchRect);
    SDL_UpdateWindowSurface( gWindow );
}

void event_key(){
    SDL_PollEvent( &e );

    if(e.type == SDL_QUIT)
    {
        sair = true;
    }
    else if( e.type == SDL_KEYDOWN )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_0:
                gCurrentSurface = gImages[IMG_0];
                break;
            case SDLK_1:
                gCurrentSurface = gImages[IMG_1];
                break;
            case SDLK_2:
                gCurrentSurface = gImages[IMG_2];
                break;
            case SDLK_3:
                gCurrentSurface = gImages[IMG_3];
                break;
            case SDLK_4:
                gCurrentSurface = gImages[IMG_4];
                break;
            case SDLK_5:
                gCurrentSurface = gImages[IMG_5];
                break;
            case SDLK_6:
                gCurrentSurface = gImages[IMG_6];
                break;
            case SDLK_7:
                gCurrentSurface = gImages[IMG_7];
                break;
            case SDLK_8:
                gCurrentSurface = gImages[IMG_8];
                break;
            case SDLK_9:
                gCurrentSurface = gImages[IMG_9];
                break;
            case SDLK_a:
                gCurrentSurface = gImages[IMG_A];
                break;
            case SDLK_b:
                gCurrentSurface = gImages[IMG_B];
                break;
            case SDLK_c:
                gCurrentSurface = gImages[IMG_C];
                break;
            case SDLK_d:
                gCurrentSurface = gImages[IMG_D];
                break;
            case SDLK_e:
                gCurrentSurface = gImages[IMG_E];
                break;
            case SDLK_f:
                gCurrentSurface = gImages[IMG_F];
                break;
            case SDLK_g:
                gCurrentSurface = gImages[IMG_G];
                break;
            case SDLK_h:
                gCurrentSurface = gImages[IMG_H];
                break;
            case SDLK_i:
                gCurrentSurface = gImages[IMG_I];
                break;
            case SDLK_j:
                gCurrentSurface = gImages[IMG_J];
                break;
            case SDLK_k:
                gCurrentSurface = gImages[IMG_K];
                break;
            case SDLK_l:
                gCurrentSurface = gImages[IMG_L];
                break;
            case SDLK_m:
                gCurrentSurface = gImages[IMG_M];
                break;
            case SDLK_n:
                gCurrentSurface = gImages[IMG_N];
                break;
            case SDLK_o:
                gCurrentSurface = gImages[IMG_O];
                break;
            case SDLK_p:
                gCurrentSurface = gImages[IMG_P];
                break;
            case SDLK_q:
                gCurrentSurface = gImages[IMG_Q];
                break;
            case SDLK_r:
                gCurrentSurface = gImages[IMG_R];
                break;
            case SDLK_s:
                gCurrentSurface = gImages[IMG_S];
                break;
            case SDLK_t:
                gCurrentSurface = gImages[IMG_T];
                break;
            case SDLK_u:
                gCurrentSurface = gImages[IMG_U];
                break;
            case SDLK_v:
                gCurrentSurface = gImages[IMG_V];
                break;
            case SDLK_w:
                gCurrentSurface = gImages[IMG_W];
                break;
            case SDLK_x:
                gCurrentSurface = gImages[IMG_X];
                break;
            case SDLK_y:
                gCurrentSurface = gImages[IMG_Y];
                break;
            case SDLK_z:
                gCurrentSurface = gImages[IMG_Z];
                break;
            case SDLK_ESCAPE:
                sair = true;
                break;
        }
    }
}

int main( int argc, char* args[] ){
    init();

    pintar( gScreenSurface, 255, 255, 255 );
    SDL_UpdateWindowSurface( gWindow );

    load_media();

    SDL_FreeSurface(gCar);

    pintar(gScreenSurface, 0, 0, 0);
    SDL_UpdateWindowSurface( gWindow );

    while(sair == false)
    {
        event_key();

        stretchRect.w = SCREEN_WIDTH;
        stretchRect.h = SCREEN_HEIGHT;
        SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
        SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &stretchRect);
        SDL_UpdateWindowSurface( gWindow );
    }

    return 0;
}
