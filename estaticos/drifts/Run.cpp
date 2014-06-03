void Drifts::Run(){
    if(!Init()) {
        return;
    }
    
    Create_Bola(); 
    cout<<bolas[0].get_type()<<endl;
    
    cout<<rand()<<endl;
    cout<<get_secs()<<endl;

    while(Running) {
        while(SDL_PollEvent(&Event) != 0){
            OnEvent(&Event);
        }

        Loop();
        Render();

        SDL_Delay(1); // Breath
    }

    Cleanup();
}