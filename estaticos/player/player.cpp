Player::Player(){
	life = 3;
    score = 245;

    Rect.w = 45;//Mouse Width
    Rect.h = 45;//Mouse Height

    Icon.x = 560;
    Icon.y = 10;
    Icon.w = 35;
    Icon.h = 35;

    Life.x = 595;
    Life.y = 3;
    Life.w = 50;
    Life.h = 50;

    Score.x = 265;
    Score.y = 3;
    Score.w = 50;
    Score.h = 50;
}
Player::~Player(){}

void Player::reset_life(){
	life = 3;
}
void Player::death(){
	life--;
}
void Player::reset_x_rscore(){
	Score.x = 265;
}
void Player::incr_x_rscore(int n){
	Score.x += n;
}
void Player::incr_score(int n){
	score += n;
}

int Player::get_life(){
	return life;
}
int Player::get_score(){
	return score;
}
SDL_Rect* Player::get_ricon(){
	return &Icon;
}
SDL_Rect* Player::get_rlife(){
	return &Life;
}
SDL_Rect* Player::get_rscore(){
	return &Score;
}
SDL_Rect* Player::get_rrect(){
	return &Rect;
}
int* Player::get_rrect_x(){
	return &Rect.x;
}
int* Player::get_rrect_y(){
	return &Rect.y;
}