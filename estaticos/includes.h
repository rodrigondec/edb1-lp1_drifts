#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
<<<<<<< HEAD
#include <jpeg-9a/jpeglib.h> //Windows
//#include <jpeglib.h> //Unity
=======
#include <jpeglib.h>
//#include <jpeg-9a/jpeglib.h>
//#include <libpng12/libpng>
>>>>>>> ab38e433afc2bcac755e1fce79963e8129bded01

#include "Log.h"

#include "texture/Texture.h"
#include "texture/Texture.cpp"


#include "drifts/Execute.cpp"
#include "drifts/Init.cpp"
#include "drifts/Loop.cpp"
#include "drifts/OnEvent.cpp"
#include "drifts/Render.cpp"
#include "drifts/Cleanup.cpp"

#include "drifts/GetRenderer.cpp"
#include "drifts/GetInstance.cpp"
#include "drifts/GetWindowWidth.cpp"
#include "drifts/GetWindowHeight.cpp"