#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <jpeg-9a/jpeglib.h> //Windows
//#include <jpeglib.h> //Unity


#include "Log.h"


#include "texture/Texture.h"
#include "texture/Texture.cpp"


#include "drifts/Init.cpp"
#include "drifts/Loop.cpp"
#include "drifts/OnEvent.cpp"
#include "drifts/Render.cpp"
#include "drifts/Cleanup.cpp"