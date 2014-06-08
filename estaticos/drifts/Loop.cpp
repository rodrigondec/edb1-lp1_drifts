void Drifts::Loop(){
	if(screen == INSTRUCOES){
		checker_move_bola = 1;
		instrucao = 1;
        bolas_attached = false;
        for(unsigned i = 0; i < bolas.size(); i++){
            bolas.erase(bolas.begin()+i);
            i--;
        }
		player.reset_life();
		player.reset_score();
	}
	else if(screen == INSTRUCAO1){
		if(instrucao == 1){
			player.Rect.x = 295;
			player.Rect.y = 190;
			Create_Bola();bolas[0].set_type("pointer");bolas[0].Rect.x = player.Rect.x + 63;bolas[0].Rect.y = player.Rect.y + (-137);
			Create_Bola();bolas[1].set_type("pointer");bolas[1].Rect.x = player.Rect.x + 45;bolas[1].Rect.y = player.Rect.y + (-120);
			Create_Bola();bolas[2].set_type("pointer");bolas[2].Rect.x = player.Rect.x + 25;bolas[2].Rect.y = player.Rect.y + (-137);
			instrucao++;
		}
		else if(instrucao <= 2350){
			if(instrucao == 2350){
				player.Rect.x -= 1;
				player.Rect.y -= 3;
				player.Rect.x -= 27;
				player.Rect.y -= 27;
				for(unsigned i = 0; i < bolas.size(); i++){
					Collision(i);
				}
				player.Rect.x += 27;
				player.Rect.y += 27;
			}
			if(instrucao%25 == 0){
				player.Rect.x++;
				player.Rect.y--;
			}
			if(instrucao%50 == 0){
				player.Rect.x--;
			}
			instrucao++;
		}
		else if(instrucao > 2350 && instrucao<= 4999){
			if(instrucao%25 == 0){
				player.Rect.x--;
				player.Rect.y++;
			}
			if(instrucao%50 == 0){
				player.Rect.x++;
			}
			for(unsigned i = 0; i < bolas.size(); i++){
				if(bolas[i].get_status()){
					bolas[i].seguir_mouse((player.Rect.x), (player.Rect.y));
				}
	        }
			instrucao++;
		}
		else if(instrucao == 5000){
			instrucao = 1;
			for(unsigned i = 0; i < bolas.size(); i++){
				bolas.erase(bolas.begin()+i);
				i--;
			}
		}
	}
	else if(screen == INSTRUCAO2){
		if(instrucao == 1){
			player.Rect.x = 277;
			player.Rect.y = 230;
			Create_Bola();bolas[0].set_type("pointer");bolas[0].Rect.x = player.Rect.x + 18;bolas[0].Rect.y = player.Rect.y + (-40);
			Create_Bola();bolas[1].set_type("pointer");bolas[1].Rect.x = player.Rect.x + 0;bolas[1].Rect.y = player.Rect.y + (-23);
			Create_Bola();bolas[2].set_type("pointer");bolas[2].Rect.x = player.Rect.x + (-20);bolas[2].Rect.y = player.Rect.y + (-40);
			Create_Bola();bolas[3].set_type("saver");bolas[3].Rect.x = player.Rect.x + 45 + (290 - 277);bolas[3].Rect.y = player.Rect.y + (-120) + (190-230);
			player.Rect.x -= 27;
			player.Rect.y -= 27;
			Collision(0);Collision(1);Collision(2);
			player.Rect.x += 27;
			player.Rect.y += 27;
			instrucao++;
		}
		else if(instrucao <= 2350){
			if(instrucao == 2350){
				player.Rect.x -= 1;
				player.Rect.y -= 3;
			}
			if(instrucao%25 == 0){
				player.Rect.x++;
				player.Rect.y--;
			}
			if(instrucao%50 == 0){
				player.Rect.x--;
			}
			for(unsigned i = 0; i < bolas.size(); i++){
				if(bolas[i].get_status()){
					bolas[i].seguir_mouse((player.Rect.x), (player.Rect.y));
				}
	        }
			instrucao++;
		}
		else if(instrucao > 2350 && instrucao<= 3299){
			if(instrucao == 2351){
				Collision(3);
			}
			instrucao++;
		}
		else if(instrucao == 3300){
			instrucao = 1;
		}
	}
	else if(screen == INSTRUCAO3){
		if(player.get_life() == 0){
			instrucao = 3300;
		}
		if(instrucao == 1){
			player.Rect.x = 277;
			player.Rect.y = 230;
			Create_Bola();bolas[0].set_type("pointer");bolas[0].Rect.x = player.Rect.x + 18;bolas[0].Rect.y = player.Rect.y + (-40);
			Create_Bola();bolas[1].set_type("pointer");bolas[1].Rect.x = player.Rect.x + 0;bolas[1].Rect.y = player.Rect.y + (-23);
			Create_Bola();bolas[2].set_type("pointer");bolas[2].Rect.x = player.Rect.x + (-20);bolas[2].Rect.y = player.Rect.y + (-40);
			Create_Bola();bolas[3].set_type("murderer");bolas[3].Rect.x = player.Rect.x + 45 + (290 - 277);bolas[3].Rect.y = player.Rect.y + (-120) + (190-230);
			player.Rect.x -= 27;
			player.Rect.y -= 27;
			Collision(0);Collision(1);Collision(2);
			player.Rect.x += 27;
			player.Rect.y += 27;
			instrucao++;
		}
		else if(instrucao <= 2350){
			if(instrucao == 2350){
				player.Rect.x -= 1;
				player.Rect.y -= 3;
			}
			if(instrucao%25 == 0){
				player.Rect.x++;
				player.Rect.y--;
			}
			if(instrucao%50 == 0){
				player.Rect.x--;
			}
			for(unsigned i = 0; i < bolas.size(); i++){
				if(bolas[i].get_status()){
					bolas[i].seguir_mouse((player.Rect.x), (player.Rect.y));
				}
	        }
			instrucao++;
		}
		else if(instrucao > 2350 && instrucao<= 3299){
			if(instrucao == 2351){
				for(unsigned i = 0; i < 4; i++){
					bolas.erase(bolas.begin()+i);
		        }
		        player.death();
				player.Rect.x = 295;
				player.Rect.y = 190;
			}
			instrucao++;
		}
		else if(instrucao == 3300){
			instrucao = 1;
		}
	}
	else if(screen == GAME){
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
			    		if(bolas_attached){
 			    			for(unsigned j = 0; j < bolas.size(); j++){
 			    				if(bolas[j].get_status()){
 			    					if((bolas[j].Rect.x + 27) >= bolas[i].Rect.x && (bolas[j].Rect.x + 21) <= (bolas[i].Rect.x + bolas[i].Rect.w) &&
 						            	(bolas[j].Rect.y + 27) >= bolas[i].Rect.y && (bolas[j].Rect.y + 21) <= (bolas[i].Rect.y + bolas[i].Rect.h)){
 							            Collision(i);
 						            }
 			    				}
 			    			}
 			    		}
 			    		if((player.Rect.x + 27) >= bolas[i].Rect.x && (player.Rect.x + 21) <= (bolas[i].Rect.x + bolas[i].Rect.w) &&
			            	(player.Rect.y + 27) >= bolas[i].Rect.y && (player.Rect.y + 21) <= (bolas[i].Rect.y + bolas[i].Rect.h)){
				            Collision(i);
			            }
			        }
		        }
		    }
		// ------------------- SEGUIR MOUSE ---------------------------------------------------
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