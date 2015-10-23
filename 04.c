#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ML (ATOM*)malloc(sizeof(ATOM))

typedef struct atom {
	int h;
	struct atom *nasl;
}ATOM;

void ini(ATOM **z){
	*z = ML;
	(*z)->nasl = NULL;
}

int test(ATOM *z){
	return z->nasl == NULL;
}

void vloz(ATOM **z,int x) {
	ATOM *p = ML;
	p->h = x;
	p->nasl = *z;
	*z = p;
}

void odober(ATOM **z){
	if(!test(*z)){
		ATOM *p = *z;
		*z = p->nasl;
		free((void*)p);
	}
}

void hodnota(ATOM *z, int *x){
	if(!test(z))
		*x = z->h;
}

int main()
{
	ATOM *a;
	ini(&a);
	char s[] = "Douwe Egdberts";
	int i;
	char c;
	for(i = 0; i < strlen(s); i++)
		vloz(&a,s[i]);
	while(!test(a)){
		hodnota(a,&c);
		printf("%c",c);
		odober(&a);
	}
	printf("\n");
	return 0;
}
