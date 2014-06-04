void Drifts::Loop(){
	if(screen == 2){
		if(get_secs()%clock_spawn == 0 && checker_create_bola){
			int i = (rand()%3)+1;
			while(i > 0){ //random 1~3 bolas por tick
				Create_Bola();
				i -= 1;
			}
			
			//Create_Bola(); //1 bola por tick
        checker_create_bola = false;
	    }
	    else if(get_secs()%clock_spawn != 0){
	        checker_create_bola = true;
	    }

	    if(checker_move_bola == 1){
	    	for(unsigned i = 0; i < bolas.size(); i++){
				bolas[i].mover();
			}
			checker_move_bola = 2;
	    }
	    else if(checker_move_bola == 2){
	    	checker_move_bola = 3;
	    }
	    else if(checker_move_bola == 3){
	    	checker_move_bola = 1;
	    }
	}
}