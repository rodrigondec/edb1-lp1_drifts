#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "Log.h"

#include "texture/Texture.h"
#include "texture/Texture.cpp"


#include "drifts/drifts.h"

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