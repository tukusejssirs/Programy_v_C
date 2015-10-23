/*
 *  Jednosmerny zoznam
 */


#include <stdio.h>
#include <stdlib.h>
#define ML (ATOM*)malloc(sizeof(ATOM))  // 

typedef struct atom{  // struktura ATOM
	int h;
	struct atom *nasl;
}ATOM;

int main(){
	ATOM *q;  // vytvorenie premennej s identifikatorom `q`, ktory je typu `pointer na typ ATOM`
	q = ML;  // alakacia pamate

	q->h = 3;  // alt k `(*q).h`
	q->nasl = NULL;  // alt k `(*q).nasl`

	q->nasl = ML;
	q->nasl->h = 4;
	q->nasl->nasl = NULL;

	q->nasl->nasl = ML;
	q->nasl->nasl-> h = 5;
	q->nasl->nasl->nasl = NULL;

	ATOM *p;
	p = q;
	while(p->nasl != NULL)  // prirad pointer `p' k poslednemu `vagoniku'
		p = p->nasl;
	p->nasl = ML;

	p = p->nasl;
	p->h = 67;
	p->nasl = NULL;

	p = ML;
	p->h = 0;
	p-> nasl = q;
	q = p;

	p = q;
	while(p != NULL){
		printf("%d\n", p->h);
		p = p->nasl;
	}

/*	free((void*)q);  // miesto, na ktore ukazuje q, sa oznaci ako volne
	q = NULL;  // miesto, na ktore ukazuje q, sa vymaze */
	return (0);
}
