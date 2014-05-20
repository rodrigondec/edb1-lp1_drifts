#include <iostream>
#include <SDL.h>
#include <string>
#include <SDL_image.h>

using namespace std;

enum
{
    IMG_A, IMG_B, IMG_C, IMG_D, IMG_E, IMG_F, IMG_G, IMG_H, IMG_I, IMG_J, IMG_K, IMG_L, IMG_M, IMG_N, IMG_O, IMG_P, IMG_Q,
    IMG_R, IMG_S, IMG_T, IMG_U, IMG_V, IMG_W, IMG_X, IMG_Y, IMG_Z, IMG_1, IMG_2, IMG_3, IMG_4, IMG_5, IMG_6, IMG_7, IMG_8,
    IMG_9, IMG_0, BARRA, TOTAL_IMAGES
};

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Variáveis:
SDL_Window* gWindow = NULL;
SDL_Texture* gCurrentTexture = NULL;
SDL_Texture* gScreenTexture = NULL;
SDL_Texture* gLoadedImage = NULL;
SDL_Texture* gImages[TOTAL_IMAGES] = {};
SDL_Renderer* gRenderer = NULL;
SDL_Event e;
SDL_Texture* gCar = NULL;
bool sair = false;
int estado = 0;
SDL_Rect stretchRect;

//Funções:
void init();
SDL_Texture* load_PNG(string);
//void pintar(SDL_Surface*, int, int, int);
void load_media();
void event_key();
void carregamento();

void init()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "Ocorreu um erro na inicializacao do SDL, Erro: " << SDL_GetError() << endl;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1") )
        {
            cout << "Warning: Linear texture filtering not enabled." << endl;
        }

        gWindow = SDL_CreateWindow( "Barra de Carregamento usando Textures", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            cout << "The window cold not be created! SDL Error: " << SDL_GetError() << endl;
        }
        else
        {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if(gRenderer == NULL)
            {
                cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
            }
            else
            {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !IMG_Init(imgFlags) && !imgFlags )
                {
                    cout << "SDL coud not be initialized! SDL Error: " << IMG_GetError() << endl;
                }
            }
        }
    }
}

SDL_Texture* load_PNG(string path)
{
    SDL_Texture* ggOptimizedTexture = NULL;
    SDL_Surface* ggLoadedSurface = IMG_Load( path.c_str() );

    if(ggLoadedSurface == NULL)
    {
        cout << "Unable to load image " << path << "! SDL_Image Error: " << IMG_GetError() << endl;
    }
    else
    {
        ggOptimizedTexture = SDL_CreateTextureFromSurface( gRenderer, ggLoadedSurface );
        if(ggOptimizedTexture == NULL)
        {
            cout <<"Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << endl;
        }
    }
    SDL_FreeSurface(ggLoadedSurface);

    return ggOptimizedTexture;
}

void load_media()
{
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
    gImages[BARRA] = load_PNG("Arquivos/Imagens/barra.png");
    carregamento();
    cout << "Carregou!" << endl;
}

void carregamento()
{
    estado++;
    cout << estado << endl;

    stretchRect.x = 0;
    stretchRect.y = (SCREEN_HEIGHT / 10) * 8;
    stretchRect.w = estado * SCREEN_WIDTH / 37;
    stretchRect.h = SCREEN_HEIGHT / 10;

    SDL_RenderCopy( gRenderer, gCar, NULL, &stretchRect);
    SDL_RenderPresent( gRenderer );
}

void event_key()
{
    SDL_PollEvent( &e );

    if(e.type == SDL_QUIT)
    {
        sair = true;
    }
    else if( e.type == SDL_KEYDOWN )
    {
        SDL_RenderClear( gRenderer );
        switch( e.key.keysym.sym )
        {
            case SDLK_0:
                gCurrentTexture = gImages[IMG_0];
                break;
            case SDLK_1:
                gCurrentTexture = gImages[IMG_1];
                break;
            case SDLK_2:
                gCurrentTexture = gImages[IMG_2];
                break;
            case SDLK_3:
                gCurrentTexture = gImages[IMG_3];
                break;
            case SDLK_4:
                gCurrentTexture = gImages[IMG_4];
                break;
            case SDLK_5:
                gCurrentTexture = gImages[IMG_5];
                break;
            case SDLK_6:
                gCurrentTexture = gImages[IMG_6];
                break;
            case SDLK_7:
                gCurrentTexture = gImages[IMG_7];
                break;
            case SDLK_8:
                gCurrentTexture = gImages[IMG_8];
                break;
            case SDLK_9:
                gCurrentTexture = gImages[IMG_9];
                break;
            case SDLK_a:
                gCurrentTexture = gImages[IMG_A];
                break;
            case SDLK_b:
                gCurrentTexture = gImages[IMG_B];
                break;
            case SDLK_c:
                gCurrentTexture = gImages[IMG_C];
                break;
            case SDLK_d:
                gCurrentTexture = gImages[IMG_D];
                break;
            case SDLK_e:
                gCurrentTexture = gImages[IMG_E];
                break;
            case SDLK_f:
                gCurrentTexture = gImages[IMG_F];
                break;
            case SDLK_g:
                gCurrentTexture = gImages[IMG_G];
                break;
            case SDLK_h:
                gCurrentTexture = gImages[IMG_H];
                break;
            case SDLK_i:
                gCurrentTexture = gImages[IMG_I];
                break;
            case SDLK_j:
                gCurrentTexture = gImages[IMG_J];
                break;
            case SDLK_k:
                gCurrentTexture = gImages[IMG_K];
                break;
            case SDLK_l:
                gCurrentTexture = gImages[IMG_L];
                break;
            case SDLK_m:
                gCurrentTexture = gImages[IMG_M];
                break;
            case SDLK_n:
                gCurrentTexture = gImages[IMG_N];
                break;
            case SDLK_o:
                gCurrentTexture = gImages[IMG_O];
                break;
            case SDLK_p:
                gCurrentTexture = gImages[IMG_P];
                break;
            case SDLK_q:
                gCurrentTexture = gImages[IMG_Q];
                break;
            case SDLK_r:
                gCurrentTexture = gImages[IMG_R];
                break;
            case SDLK_s:
                gCurrentTexture = gImages[IMG_S];
                break;
            case SDLK_t:
                gCurrentTexture = gImages[IMG_T];
                break;
            case SDLK_u:
                gCurrentTexture = gImages[IMG_U];
                break;
            case SDLK_v:
                gCurrentTexture = gImages[IMG_V];
                break;
            case SDLK_w:
                gCurrentTexture = gImages[IMG_W];
                break;
            case SDLK_x:
                gCurrentTexture = gImages[IMG_X];
                break;
            case SDLK_y:
                gCurrentTexture = gImages[IMG_Y];
                break;
            case SDLK_z:
                gCurrentTexture = gImages[IMG_Z];
                break;
            case SDLK_ESCAPE:
                sair = true;
                break;
        }
    }
    else if(e.type == SDL_KEYUP)
    {
        //nothing.
    }
}

int main( int argc, char* args[] )
{
    init();

    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
    SDL_RenderPresent( gRenderer );

    load_media();

    while(sair == false)
    {
        event_key();

        stretchRect.x = (SCREEN_WIDTH / 2) - (397 / 2);
        stretchRect.y = (SCREEN_HEIGHT / 2) - (325 / 2);
        stretchRect.w = 397;
        stretchRect.h = 325;
        SDL_RenderCopy( gRenderer, gCurrentTexture, NULL, &stretchRect);
        SDL_RenderPresent( gRenderer );
    }

    return 0;
}
