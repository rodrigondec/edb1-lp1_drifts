Bola::Bola(){
	int randomx, randomt, randomax;

	randomx = rand()%640;
	randomt = (rand()%10)+1;
	randomax = rand()%3;

	if(randomt >= 1 && randomt <= 4){
		tipo = "pointer";
	}
	else if(randomt >= 5 && randomt <= 8){
		tipo = "murderer";
	}
	else if(randomt >= 9 && randomt <= 10){
		tipo = "saver";
	}

	accel_y = rand()%2;

	if(randomax == 0){
		accel_x = -1;
	}
	else if(randomax == 1){
		accel_x = 0;
	}
	else if(randomax == 2){
		accel_x = 1;
	}

	if(accel_x == 0 && accel_y == 0){
		accel_y = 1;
	}

	attached = false;
	Rect.x = randomx;
	Rect.y = 0;
	Rect.w = 45;
	Rect.h = 45;
}

Bola::~Bola(){}

void Bola::mover(){
	Rect.x += accel_x;
	Rect.y += accel_y;
}

void Bola::attach(int mouse_x, int mouse_y){
	bola_to_mouse[0] = Rect.x;
	bola_to_mouse[1] = Rect.y;
	bola_to_mouse[2] = mouse_x;
	bola_to_mouse[3] = mouse_y;
	attached = true;
}

void Bola::seguir_mouse(int mouse_x, int mouse_y){
	Rect.x = bola_to_mouse[0] + (mouse_x - bola_to_mouse[2]);
	Rect.y = bola_to_mouse[1] + (mouse_y - bola_to_mouse[3]);
}

void Bola::invert_accel_x(){
	int uni = rand()%2;
	if(uni == 1){
		uni = rand()%2;
		if(accel_x == -1){
			if(uni == 1){
				accel_x = 1;
			}
			else if(uni == 0){
				accel_x = 0;
			}
		}
		else if(accel_x == 0){
			if(uni == 1){
				accel_x = 1;
			}
			else if(uni == 0){
				accel_x = -1;
			}
		}
		else if(accel_x == 1){
			if(uni == 1){
				accel_x = 0;
			}
			else if(uni == 0){
				accel_x = -1;
			}
		}
	}
}

void Bola::invert_accel_y(){
	int uni = rand()%2;
	if(uni == 1){
		if(accel_y == 1){
			accel_y = 0;
		}
		else{
			accel_y = 1;
		}
	}
}

void Bola::parada(){
	if(accel_x == 0 && accel_y == 0){
		accel_y = 1;
	}
}

bool Bola::get_status(){
	return attached;
}

int Bola::get_accel_x(){
	return accel_x;
}

int Bola::get_accel_y(){
	return accel_y;
}

string Bola::get_type(){
	return tipo;
}