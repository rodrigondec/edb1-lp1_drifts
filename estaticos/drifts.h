#ifndef _DRIFTS_H_
#define _DRIFTS_H_

class Drifts{
    private:
        bool Running;
 
    public:
        Drifts();
 
        int OnExecute();
 
    public:
 
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
};
 
#endif