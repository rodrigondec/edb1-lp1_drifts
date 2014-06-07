void Drifts::Loop(){
	if(screen == GAME){
		if(!paused){
			// ------------------- IS GAME OVER? -----------------------------------------------
			if(player.get_life() == 0){
				screen = GAMEOVER;
				for(unsigned i = 0; i < bolas.size(); i++){
					bolas.erase(bolas.begin()+i);
					i--;
				}
				player.reset_life();
				player.reset_score();
				SDL_ShowCursor(1);
			}
			// ------------------- IS NOT ENOUGH POINTERS? -----------------------------------------
			if(get_more_pointers >= 1 && get_more_pointers <= 2599){
				get_more_pointers++;
			} 
			else if(get_more_pointers == 2600){
				get_more_pointers = 0;
			}
			// ------------------- IS BOLA SPAWN TIME? -----------------------------------------------
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
		    // ------------------- IS RIP?? ---------------------------------------------------------
		    if(rip >= 1){
		    	if(rip >= 1 && rip <= 2599){
		    		rip++;
		    	}
		    	else if(rip == 2600){
		    		rip = 0;
		    	}
		    }
		    else{
		    	// ------------------- IS COLLISION? ----------------------------------------------------
			    for(unsigned i = 0; i < bolas.size(); i++){
			    	if(!bolas[i].get_status()){
			            if((player.Rect.x + 27) >= bolas[i].Rect.x && (player.Rect.x + 21) <= (bolas[i].Rect.x + bolas[i].Rect.w) &&
			            	(player.Rect.y + 27) >= bolas[i].Rect.y && (player.Rect.y + 21) <= (bolas[i].Rect.y + bolas[i].Rect.h)){
				            	Collision(i);
			            }
			        }
		        		
		        }
		    }
		    for(unsigned i = 0; i < bolas.size(); i++){
	        	if(bolas[i].get_status()){
	        		bolas[i].seguir_mouse((player.Rect.x + 27), (player.Rect.y + 27));
	        	}
	        }
	        // ------------------- IS TIME TO MOVE BOLAS? ----------------------------------------------------
	        
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
				}
				checker_move_bola = 2;
		    }
		    else if(checker_move_bola >= 2 && checker_move_bola <= 24){
		    	checker_move_bola++;
		    }
		    else if(checker_move_bola == 25){
		    	checker_move_bola = 1;
		    }
		}
	}
}