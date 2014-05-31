void empty(celula *topo){
	celula *dead;
	while(topo->prox!=NULL){
		dead=topo->prox;
		topo->prox=dead->prox;
		free(dead);
	}
}
