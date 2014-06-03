void Drifts::Loop(){
	if(get_secs()%clock_spawn == 0 && checker_create_bola){
        cout<<endl;
        cout<<"CreateBola()"<<endl;
        checker_create_bola = 0;
    }
    else if(get_secs()%clock_spawn != 0){
        checker_create_bola = 1;
    }


}