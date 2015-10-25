#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ML (ATOM*)malloc(sizeof(ATOM))

typedef struct atom {
	int h;
	struct atom *nasl, *pred;
}ATOM;

typedef struct {
	ATOM *zac, *kon, *kur;
}ZOZNAM;

void ini(ZOZNAM *k){
	k->kon = k->kur = k->zac = NULL;
}

int test(ZOZNAM k){
	return k.kur == NULL;
}

int test_kon(ZOZNAM k) {
	return k.kon == k.kur;
}

int test_zac(ZOZNAM k) {
	return k.kur == k.zac;
}

int vloz(ZOZNAM *k, int x){
	if(test(*k)){
		k->kur = ML;
		k->kon = k->zac = k->kur;
		k->kur->h = x;
		k->kur->nasl = k->kur->pred = NULL;
	}else
		if(test_kon(*k)){
			k->kon->nasl = ML;
			k->kon = k->kon->nasl;
			k->kon->nasl = NULL;
			k->kon->h = x;
			k->kon->pred = k->kur;
			k->kur = k->kur->nasl;
		}
		else {
			ATOM *p;
			p = ML;
			p->h = x;
			p->nasl = k->kur->nasl;
			p->pred = k->kur;
			k->kur->nasl->pred = p;
			k->kur->nasl = p;
			k->kur = p;
		}
}

void odober(ZOZNAM *k){
	if(!test(*k))
	if(k->zac->nasl == NULL){
		free((void*)k->kur);
		k->zac = k->kur = k->kon = NULL;
	}else
		if(test_kon(*k)){
			k->kur = k->kur->pred;
			free((void*)k->kon);
			k->kon = k->kur;
			k->kon->nasl = NULL;
		}else
			if(test_zac(*k)){
				k->kur = k->kur->nasl;
				free((void*)k->zac);
				k->zac = k->kur;
				k->zac->pred = NULL;
			}else{
				ATOM *p;
				p = k->kur;
				k->kur = k->kur->pred;
				p->nasl->pred = k->kur;
				k->kur->nasl = p->nasl;
				free((void*)p);
			}
}

void skok_vpred(ZOZNAM *k){
	if(!test(*k))
		k->kur = k->zac;
}

void skok_vzad(ZOZNAM *k){
	if(!test(*k))
		k->kur = k->kon;
}

void vpred(ZOZNAM *k){
	if(!test(*k))
		if(!test_zac(*k))
		k->kur = k->kur->pred;
}

void vzad(ZOZNAM *k){
	if(!test(*k))
		if(!test_kon(*k))
		k->kur = k->kur->nasl;
}

void hodnota(ZOZNAM k, int *x){
	if(!test(k))
		*x = k.kur->h;
}

int main()
{
	ZOZNAM li;
	char s[] = "Life is too short to remove USB safely.";
	int i;
	ini(&li);
	for(i = 0; i<strlen(s); i++)
		vloz(&li,s[i]);
	char c;

	skok_vpred(&li);
	while(!test_kon(li)){
		hodnota(li,&c);
		printf("%c",c);
		vzad(&li);
	}
	putchar('\n');
		vpred(&li);	   vpred(&li);	   vpred(&li);	   vpred(&li);
		hodnota(li,&c);
		printf("%c",c);

	while(!test(li))
		odober(&li);
	return 0;
}
