void create_bola(){
	Bola *temp = new Bola; 
	bolas.push_back(*temp);
	free(temp);

	int i = bolas.size()-1;
	int randomx, randomt;

	//differ

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
	bolas[i].attached = false;//Bolas spawnam com atributo attached false (logicamente)
	bolas[i].Rect.x = randomx;//Posição X inicial
	bolas[i].Rect.y = 0;//Posição Y inicial = 0 (bolas spawnam no canto superior da tela)
	bolas[i].Rect.w = 45;
	bolas[i].Rect.h = 45;
}