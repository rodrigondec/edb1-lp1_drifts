void Drifts::Collision(int indice){
	if(bolas[indice].get_type() == "pointer"){
		bolas[indice].attach(player.Rect.x, player.Rect.y);
	}
	else if(bolas[indice].get_type() == "saver"){
		bolas.erase(bolas.begin()+indice);
		counter_pointers = 0;
		for(unsigned i = 0; i < bolas.size(); i++){
			if(bolas[i].get_status()){
				bolas.erase(bolas.begin()+i);
				i--;
				counter_pointers ++;
			}
		}
		if(counter_pointers < 3){
			get_more_pointers = 1;
		}
		else{
			if(counter_pointers == 3){
				player.incr_score(1);
			}
			else if(counter_pointers == 4){
				player.incr_score(5);
			}
			if(counter_pointers == 5){
				player.incr_score(11);
			}	
			if(counter_pointers == 6){
				player.incr_score(17);
			}
			if(counter_pointers == 7){
				player.incr_score(25);
			}
			if(counter_pointers == 8){
				player.incr_score(33);
			}
			if(counter_pointers == 9){
				player.incr_score(41);
			}
			if(counter_pointers >= 10){
				player.incr_score(51);
			}
		}
	}
	else if(bolas[indice].get_type() == "murderer"){
		bolas.erase(bolas.begin()+indice);
		for(unsigned i = 0; i < bolas.size(); i++){
			if(bolas[i].get_status()){
				bolas.erase(bolas.begin()+i);
				i--;
			}
		}
		player.death();
		SDL_WarpMouseInWindow(Window, 295, 190);
		rip = 1;
		get_more_pointers = 0;
	}
}