#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct cel {
	int valor;
	struct cel *prox;
} celula;

void empilha( int y, celula *tp) { 
   celula *nova;
   nova = (celula*)malloc(sizeof (celula));
   nova->valor = y;
   nova->prox  = tp->prox;
   tp->prox = nova; 
}

void empty(celula *topo){
	celula *dead;
	while(topo->prox!=NULL){
		dead=topo->prox;
		topo->prox=dead->prox;
		free(dead);
	}
}

void imprima(celula *topo) { 
   celula *p;
   for (p = topo->prox; p != NULL; p = p->prox){
      cout<<p->valor<<" ";
   }
   cout<<"FIM";
   cout<<endl;  //necessário apenas nesse código separado
}

int main(){
	celula cabeca, *topo;
	topo=&cabeca;
	topo->prox=NULL;

	int i, greens, valor;
	int points=0;
	cout<<"How many green balls?"<<endl;	//
	cin>> greens;							//
	for(i=0;i<greens;i++){					//	
		cout<<"Ball value: ";				//none of this junk is needed
		cin>>valor;							//
		empilha(valor, topo);				//
	}										//
	imprima(topo);							//
	
	if(greens>=3){
		points++;		//3a bola vale 1 ponto
		for(i=greens;i>3;i--){
			points=points+i; 
			if(i%2!=0){ points++; }
		}
		cout<<points<<endl;
		int ordenado = 1, x, y;
		celula *c;
		for(c=topo->prox; c->prox!=NULL ; c=c->prox){
		 	if(c->valor-c->prox->valor!=1){
		 		ordenado=0;
		 	}
		}
		if(ordenado==1){ points=points*greens; }
	}
	cout<<points<<endl;
	empty(topo);
	imprima(topo);
	greens=0;

	return 0;
}