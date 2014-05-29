SDL_Texture* load_PNG(string path){
    SDL_Texture* OptimizedTexture = NULL;
    SDL_Surface* LoadedSurface = IMG_Load( path.c_str() );

    if(LoadedSurface == NULL){
        cout << "Unable to load image " << path << "! SDL_Image Error: " << IMG_GetError() << endl;
    }
    else{
        OptimizedTexture = SDL_CreateTextureFromSurface(Renderer, LoadedSurface );
        if(OptimizedTexture == NULL){
            cout <<"Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << endl;
        }
    }
    SDL_FreeSurface(LoadedSurface);
//differ
    return OptimizedTexture;
}