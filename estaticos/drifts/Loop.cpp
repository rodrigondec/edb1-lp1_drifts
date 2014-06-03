void Drifts::Loop(){
	if(screen == 2){
		if(get_secs()%clock_spawn == 0 && checker_create_bola){
        Create_Bola();
        checker_create_bola = 0;
	    }
	    else if(get_secs()%clock_spawn != 0){
	        checker_create_bola = 1;
	    }
	}
	


}