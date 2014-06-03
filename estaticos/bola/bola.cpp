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
	attached = false;
	Rect.x = randomx;
	Rect.y = 0;
	Rect.w = 45;
	Rect.h = 45;
}

Bola::~Bola(){}

void Bola::mover(){
	Rect.x = Rect.x;
	Rect.y = Rect.y;
}

void Bola::attach(){
	attached = true;
}

bool Bola::get_status(){
	return attached;
}

string Bola::get_type(){
	return tipo;
}