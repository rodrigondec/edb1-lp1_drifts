Bola::Bola(){
	int randomx, randomt;

	randomx = rand()%640;
	randomt = (rand()%3)+1;

	if(randomt == 1){
		tipo = "pointer";
	}
	else if(randomt == 2){
		tipo = "murderer";
	}
	else if(randomt == 3){
		tipo = "saver";
	}

	accel_x = rand()%2;
	accel_y = rand()%2;
	attached = false;
	Rect.x = randomx;
	Rect.y = 0;
	Rect.w = 45;
	Rect.h = 45;
}

Bola::~Bola(){}

void Bola::mover(){
	if(accel_x){
		Rect.x += 2;
	}
	else{
		Rect.x -= 2;
	}

	if(accel_y){
		Rect.y += 2;
	}
	else{
		Rect.y -= 2;
	}
}

void Bola::attach(){
	attached = true;
}

bool Bola::get_status(){
	return attached;
}

bool Bola::get_accel_x(){
	return accel_x;
}

bool Bola::get_accel_y(){
	return accel_y;
}

string Bola::get_type(){
	return tipo;
}