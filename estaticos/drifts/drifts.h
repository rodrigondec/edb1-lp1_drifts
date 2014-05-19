#ifndef _DRIFTS_H_
    #define _DRIFTS_H_

class Drifts{
    private:
        static Drifts Instance;

        bool Running;

        SDL_Window* Window = NULL;
        SDL_Renderer* Renderer = NULL;
        SDL_Surface* PrimarySurface = NULL;

        static const int WindowWidth = 640;
        static const int WindowHeight = 480;

        Texture* TestTexture;
 
    private:
        Drifts();

        // Capture SDL Events
        void OnEvent(SDL_Event* Event);

        // Initialize our SDL game / Drifts
        bool Init();

        // Logic loop
        void Loop();

        // Render loop (draw)
        void Render();

        // Free up resources
        void Cleanup();

    public:
        int Execute(int argc, char* argv[]);

    public:
        SDL_Renderer* GetRenderer();

    public:
        static Drifts* GetInstance();

        static int GetWindowWidth();
        static int GetWindowHeight();
};
 
#endif