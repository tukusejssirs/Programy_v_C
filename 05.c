#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ML (ATOM*)malloc(sizeof(ATOM))

typedef struct atom {
	int h;
	struct atom *nasl;
}ATOM;

void ini(ATOM **k){
	*k = NULL;
}

int test(ATOM *k){
	return k == NULL;
}

void vloz(ATOM **k, int x) {
	if(test(*k)){
		*k = ML;
		(*k) ->h = x;
		(*k)->nasl = *k;
	}else{
		ATOM *p = ML;
		p->h =  x;
		p->nasl = (*k)->nasl;
		(*k)->nasl = p;
		*k = p;
	}
}

void hodnota(ATOM *k, int *x){
	if(!test(k)){
		*x = k->h;
	}
}

void vpred(ATOM **k){
	if(!test(*k))
		*k = (*k)->nasl;
}

void vzad(ATOM **k){
	if(!test){
		ATOM *p = *k;
		while(!p->nasl !=*k)
			p = p->nasl;
			*k = p;
	}
}

void odober(ATOM **k){
	if(!test(*k)){
			if((*k)->nasl == *k){
				free((void*)*k);
				*k = NULL;
		}else{
			ATOM *p = *k;
			while(p->nasl != *k){
				p = p->nasl;
			}

			p->nasl = (*k)->nasl;
			free((void*)*k);
			*k = p->nasl;
		}
	}	
}

int main()
{
	ATOM *sz;
	ini(&sz);
		char s[] = "Life is too short to remove USB safety.";
	int i;
	char c;
	for(i = 0; i < strlen(s); i++)
		vloz(&sz,s[i]);
/*	while(!test(a)){*/
		vpred(&sz);
		hodnota(sz,&c);
		printf("%c",c);
		vpred(&sz);
		hodnota(sz,&c);
		printf("%c",c);
		vpred(&sz);
		hodnota(sz,&c);
		printf("%c",c);
		vpred(&sz);
		hodnota(sz,&c);
		printf("%c",c);
   /*	 odober(&a);
	}
	printf("\n");*/

	while(!test(sz))
		odober(&sz);
	return 0;
}
