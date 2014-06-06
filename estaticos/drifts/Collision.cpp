void Drifts::Collision(int indice){
	if(bolas[indice].get_type() == "pointer"){
		bolas[indice].attach(player.Rect.x, player.Rect.y);
	}
	else if(bolas[indice].get_type() == "saver"){
		int counter = 0;
		for(unsigned i = 0; i < bolas.size(); i++){
			if(bolas[i].get_status()){
				bolas.erase(bolas.begin()+i);
				i--;
				counter ++;
			}
		}
		if(counter < 3){
			cout<<"POINTERS INSUFICIENTES"<<endl;
		}
		else{
			cout<<"SOMAR SCORE DE ACORDO COM A QUANTIDADE DE POINTERS"<<endl;
		}
	}
	else if(bolas[indice].get_type() == "murderer"){
		for(unsigned i = 0; i < bolas.size(); i++){
			if(bolas[i].get_status()){
				bolas.erase(bolas.begin()+i);
				i--;
			}
		}
		player.death();
	}
}