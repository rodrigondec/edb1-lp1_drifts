void Drifts::Loop(){
	if(screen == 2){
		if(get_secs()%clock_spawn == 0 && checker_create_bola){
			int i = (rand()%7)+3;
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
	    		if(!bolas[i].get_status()){
	    			bolas[i].mover();
					if(bolas[i].Rect.x < -35 || bolas[i].Rect.x > WindowWidth){
						bolas.erase(bolas.begin()+i);
						i--;
						continue;
					}
					if(bolas[i].Rect.y > WindowHeight){
						bolas.erase(bolas.begin()+i);
						i--;
						continue;
					}
					invert_accel = rand()%100;
					if(invert_accel < 4){
						invert_accel = rand()%5;
						if(invert_accel == 0){
							bolas[i].invert_accel_x();
							bolas[i].invert_accel_y();
						}
						else if(invert_accel == 1){
							bolas[i].invert_accel_x();
						}
						else if(invert_accel == 2){
							bolas[i].invert_accel_y();
						}
						bolas[i].parada();
					}
	    		}
	    		else{
	    			bolas[i].seguir_mouse(player.Rect.x, player.Rect.y);
	    		}
			}
			checker_move_bola = 2;
	    }
	    else if(checker_move_bola == 2){
	    	checker_move_bola = 3;
	    }
	    else if(checker_move_bola == 3){
	    	checker_move_bola = 4;
	    }
	    else if(checker_move_bola == 4){
	    	checker_move_bola = 5;
	    }
	    else if(checker_move_bola == 5){
	    	checker_move_bola = 6;
	    }
	    else if(checker_move_bola == 6){
	    	checker_move_bola = 7;
	    }
	    else if(checker_move_bola == 7){
	    	checker_move_bola = 8;
	    }
	    else if(checker_move_bola == 8){
	    	checker_move_bola = 9;
	    }
	    else if(checker_move_bola == 9){
	    	checker_move_bola = 10;
	    }
	    else if(checker_move_bola == 10){
	    	checker_move_bola = 11;
	    }
	    else if(checker_move_bola == 11){
	    	checker_move_bola = 12;
	    }
	    else if(checker_move_bola == 12){
	    	checker_move_bola = 13;
	    }
	    else if(checker_move_bola == 13){
	    	checker_move_bola = 14;
	    }
	    else if(checker_move_bola == 14){
	    	checker_move_bola = 15;
	    }
	    else if(checker_move_bola == 15){
	    	checker_move_bola = 16;
	    }
	    else if(checker_move_bola == 16){
	    	checker_move_bola = 17;
	    }
	    else if(checker_move_bola == 17){
	    	checker_move_bola = 18;
	    }
	    else if(checker_move_bola == 18){
	    	checker_move_bola = 19;
	    }
	    else if(checker_move_bola == 19){
	    	checker_move_bola = 20;
	    }
	    else if(checker_move_bola == 20){
	    	checker_move_bola = 21;
	    }
	    else if(checker_move_bola == 21){
	    	checker_move_bola = 22;
	    }
	    else if(checker_move_bola == 22){
	    	checker_move_bola = 23;
	    }
	    else if(checker_move_bola == 23){
	    	checker_move_bola = 24;
	    }
	    else if(checker_move_bola == 24){
	    	checker_move_bola = 25;
	    }
	    else if(checker_move_bola == 25){
	    	checker_move_bola = 1;
	    }
	}
}