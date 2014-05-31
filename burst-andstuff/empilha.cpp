void empilha( int y, celula *tp) { 
   celula *nova;
   nova = (celula*)malloc(sizeof (celula));
   nova->valor = y;
   nova->prox  = tp->prox;
   tp->prox = nova; 
}