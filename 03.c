#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ML (ATOM*)malloc(sizeof(ATOM))

typedef struct atom{
	int h;
	struct atom *nasl;
}ATOM;

void ini (ATOM **q){
	*q = ML;
	(*q)->nasl = NULL;
}

void vloz(ATOM *q, int x){
	ATOM *p  =  q;
	while(p->nasl != NULL)
		p = p->nasl;
	p->h = x;
	p->nasl = ML;
	p = p->nasl;
	p->nasl = NULL;
}

int test(ATOM *q){
	return q->nasl == NULL;
}

void odober(ATOM **q){
	if(!test(*q)){
		ATOM *p;
		p = *q;
		*q = p->nasl;
		free((void*)p);
	}
}

void hodnota(ATOM *q, int *x){
	if(!test(q))
		*x = q->h;
	else
		*x = '#';
}

int main(){
	ATOM *r;
	char s[] = "Life is too short to remove USB safely.";
	char c;
	int i;
	ini(&r);
	for(i = 0; i < strlen(s); i++){
		vloz(r,s[i]);
	}

	while(!test(r)){
		hodnota(r,&c);
		printf("%c",c);
		putchar('\n');
		odober(&r);
	}

	return (0);
}

// lifo, fifo, fifa = zasobnik, rad, futbalova organizacia
