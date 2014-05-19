void Drifts::Render(){




    SDL_RenderClear(Renderer);

    //TextureBank::Get("Test")->Render(0, 0); // You should really check your pointers

	SDL_RenderPresent(Renderer);
}