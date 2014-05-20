#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
using namespace std;

enum Animations
{
    ANIMATION1 = 0, ANIMATION2, ANIMATION3, ANIMATION4, TOTAL_ANIMATIONS, BACKGROUND
};

//Screen Dimensions constants:
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Texture Wrapper Class:
class LTexture
{
    public:
        //Initializes variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( string );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render( int, int, int, int, SDL_Rect* );

        //Set color modulation
        void setColor(int, int, int, int);

        void setBlendMode( SDL_BlendMode );

        //Get image dimensions
        int getWidth();
        int getHeight();

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window Renderer
SDL_Renderer* gRenderer = NULL;

//Scene sprites
LTexture gSquare;
SDL_Rect gSpriteClips[4];

int num_ale( int de, int ate )
{
    int random;
    ate -= de;
    random = rand() % (ate + 1) + de;

    return random;
}

LTexture::LTexture()
{
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    free();
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}

bool LTexture::loadFromFile( string path )
{
    //Apagar os dados anteriores
    free();

    //Textura final
    SDL_Texture* newTexture = NULL;

    //Surface da imagem sem transparência
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

    //Surface da imagem com transparência
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 255, 255 ) );

    //Criando a textura a partir da Surface
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

    //Adquirindo as informações de tamanho da imagem
    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;

    SDL_FreeSurface( loadedSurface );

    mTexture = newTexture;

    //Return success
    return (newTexture != NULL);
}

void LTexture::free()
{
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render( int x, int y, int w, int h, SDL_Rect* clip = NULL )
{
    //Área do renderer em que a imagem será renderizada.
    SDL_Rect renderQuad{ x, y };

    if( clip != NULL )
    {
        renderQuad.w = w;
        renderQuad.h = h;
    }

    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

void LTexture::setColor( int red, int green, int blue , int alpha)
{
    SDL_SetTextureColorMod( mTexture, red, green, blue);

    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}

bool init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "Erro na inicialização de video. SDL_Error: " << SDL_GetError() << "." << endl;
        success = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            cout << "Aviso: filtro de textura linear não foi habilitado!" << endl;
            success = false;
        }

        gWindow = SDL_CreateWindow( "Clip Rendering + Color Keying!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        if( gWindow == NULL )
        {
            cout << "Erro: a janela principal nao pode ser criada. SDL_Error: " << SDL_GetError() << "." << endl;
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

            if( gRenderer == NULL )
            {
                cout << "Erro: nao foi possivel criar o renderer! SDL_Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255 );

                int imgFlags = IMG_INIT_PNG;
                if( !(IMG_Init(imgFlags) & imgFlags) )
                {
                    cout << "Erro: SDL_Image nao pode ser inicializado! SDL_Image error: " << IMG_GetError() << "." << endl;
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;

    if( !gSquare.loadFromFile( "Sprites/Animation.png" ) )
    {
        cout << "Falha ao carregar a sprite principal." << endl;
        success = false;
    }
    else
    {
        gSpriteClips[ANIMATION1].x = 0;
        gSpriteClips[ANIMATION1].y = 0;
        gSpriteClips[ANIMATION1].w = 250;
        gSpriteClips[ANIMATION1].h = 300;

        gSpriteClips[ANIMATION2].x = 250;
        gSpriteClips[ANIMATION2].y = 0;
        gSpriteClips[ANIMATION2].w = 250;
        gSpriteClips[ANIMATION2].h = 300;

        gSpriteClips[ANIMATION3].x = 500;
        gSpriteClips[ANIMATION3].y = 0;
        gSpriteClips[ANIMATION3].w = 250;
        gSpriteClips[ANIMATION3].h = 300;

        gSpriteClips[ANIMATION4].x = 750;
        gSpriteClips[ANIMATION4].y = 0;
        gSpriteClips[ANIMATION4].w = 250;
        gSpriteClips[ANIMATION4].h = 300;
    }

    return success;
}

void close()
{
    //Free loaded images
	gSquare.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[] )
{
    srand( time( NULL ));

    if( !init() )
    {
        cout << "Falha ao inicializar o programa!" << endl;
    }
    else
    {
        if( !loadMedia() )
        {
            cout << "Falha ao carregar media!" << endl;
        }
        else
        {
            bool quit = false;
            SDL_Event e;

            int x = 0;

            //Limpando a tela.
            SDL_RenderClear( gRenderer );

            Uint8 r = 255;
            Uint8 g = 255;
            Uint8 b = 255;

            while( !quit )
            {
                while( SDL_PollEvent( &e) != 0 )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    if( e.type == SDL_KEYDOWN )
                    {
                        if( e.key.keysym.sym == SDLK_RETURN )
                        {
                            SDL_RenderClear( gRenderer );
                        }
                        else if( e.key.keysym.sym == SDLK_q )
                        {
                            r += 5;
                        }
                        else if( e.key.keysym.sym == SDLK_w )
                        {
                            g += 5;
                        }
                        else if( e.key.keysym.sym == SDLK_e )
                        {
                            b += 5;
                        }
                        else if( e.key.keysym.sym == SDLK_a )
                        {
                            r -= 5;
                        }
                        else if( e.key.keysym.sym == SDLK_s )
                        {
                            g -= 5;
                        }
                        else if( e.key.keysym.sym == SDLK_d )
                        {
                            b -= 5;
                        }
                    }
                }
                //Altera a cor.
                gSquare.setColor( num_ale(0, r), num_ale(0, g), num_ale(0, b), num_ale(0, 255) );

                //Render Animation.
                gSquare.render( num_ale(0, SCREEN_WIDTH) - gSpriteClips[0].w / 32, num_ale(0, SCREEN_HEIGHT) - gSpriteClips[0].h / 32, gSpriteClips[0].w / 16, gSpriteClips[0].h / 16, &gSpriteClips[x] );

                SDL_RenderPresent( gRenderer );
            }
        }
    }

    return 0;
}
