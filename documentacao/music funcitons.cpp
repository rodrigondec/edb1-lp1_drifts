//If there is no music playing
if( Mix_PlayingMusic() == 0 )
{
    //Play the music
    Mix_PlayMusic( gMusic, -1 );
}
//If music is being played
else
{
    //If the music is paused
    if( Mix_PausedMusic() == 1 )
    {
        //Resume the music
        Mix_ResumeMusic();
    }
    //If the music is playing
    else
    {
        //Pause the music
        Mix_PauseMusic();
    }
}
break;

case SDLK_0:
//Stop the music
Mix_HaltMusic();