#include <exception>
#include <string>

class InitError: public std::exception {
    public:
        InitError();
        InitError(const std::string&);
        virtual ~InitError() throw();
        virtual const char* what() const throw();
    private:
        std::string msg;
};

InitError::InitError():
  exception(), msg(SDL_GetError()) {}
InitError::InitError(const std::string& m):
  exception(), msg(m) {}
InitError::~InitError() throw() {}
const char* InitError::what() const throw() {
    return msg.c_str();
}

class SDL {
    public:
        SDL(Uint32 flags = 0) throw(InitError);
        virtual ~SDL();
};

SDL::SDL(Uint32 flags) throw(InitError) {
    if (SDL_Init(flags) != 0)
        throw InitError();
}

SDL::~SDL() {
    SDL_Quit();
}



int main(int argc, char **argv) {
    try {
        SDL sdl(SDL_INIT_VIDEO|SDL_INIT_TIMER);

        /* ... */

        return 0;
    }

    catch (const InitError& err) {
        std::cerr
            << "Error while initializing SDL:  "
            << err.what() << std::endl;
    }

    return 1;
}