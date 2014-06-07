void Drifts::load_WAV(string path){
Music = Mix_LoadMUS(path.c_str());
    if(Music == NULL){
       	cout<<"Failed to load beat music! SDL_mixer Error: "<<Mix_GetError()<<endl;
    }
}
    