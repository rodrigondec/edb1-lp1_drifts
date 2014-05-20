void Render(){
	SDL_RenderClear(Renderer);
  
  //SDL_Surface *image = IMG_Load ("/home/clara/Documents/UFRN/2014.1/EDBI/drifts/estaticos/images/test.jpg"); //Clara
  SDL_Surface *image = IMG_Load("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/test.jpg"); //Rod
	if( !image ){
    std::cout<<"IMG_Load: "<<IMG_GetError();
    return;
  }

  SDL_Rect rcDest = { 0, 0, 0, 0 };
  SDL_BlitSurface ( image, NULL, PrimarySurface, &rcDest );
  SDL_Texture * testura = SDL_CreateTextureFromSurface(Renderer, image);
  SDL_FreeSurface ( image );
  
  
  SDL_RenderCopy(Renderer, testura, NULL, NULL);

    
	SDL_RenderPresent(Renderer);
}