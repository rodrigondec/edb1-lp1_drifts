void create_bola(){
	Bola *temp = new Bola; 
	bolas.push_back(*temp);
	free(temp);

	int i = bolas.size()-1;
	int randomx, randomt;



	randomx = 0;


	
	randomt = 1;



	if(randomt == 1){
		bolas[i].tipo = "pointer";
	}
	else if(randomt == 2){
		bolas[i].tipo = "murderer";
	}
	else if(randomt == 3){
		bolas[i].tipo = "saver";
	}
	bolas[i].attached = false;
	bolas[i].Rect.x = randomx;
	bolas[i].Rect.y = 0;
	bolas[i].Rect.w = 35;
	bolas[i].Rect.h = 35;
}