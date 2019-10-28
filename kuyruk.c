#include<string.h>

int giseSayisi = 1;
int isimNo = 1;
int enFazlaBekleyen = 0;
int toplamBeklemeSuresi=0;
int enUzunBekleyen = 0;
int kuyrukUzunlugu = 20;
int name = 1;
int gecenSure = 0;

typedef struct Musteri{
	char *isim;
	int isimNo;
	char *islem;
	int beklemeSuresi;
	int kalanSure;
	int siradaBeklemeSuresi;
	struct Musteri *next;
}Musteri;

typedef struct{
	int cnt; 
 	Musteri *front;
  	Musteri *rear;
}queue;

typedef struct Gise{
 	Musteri *bekleyenMusteri;
 	short giseNo;
 	int islemSayisi;
 	int islemSuresi;
}gise;

queue *q;



void initialize(queue *q)
{ 
	q->cnt =0;
	q->front=NULL;
	q->rear=NULL; 
}
void initializeGise(gise *g)
{ 
	g->bekleyenMusteri = NULL;
	g->giseNo=giseSayisi;
	g->islemSayisi = 0;
	g->islemSuresi = 0; 
	giseSayisi++;
}

void enqueu(queue *q)
{ 
	Musteri *m = malloc(sizeof(Musteri)); 
	m->kalanSure = 1;
	m->next = NULL;
	m->isim= malloc(9);
	m->isimNo = isimNo;
	m->siradaBeklemeSuresi = 0;
	strcpy(m->isim,"Musteri");
	 
	if(isempty(q)) {
		q->front=q->rear=m;
	}		
	else{ 
		q->rear->next=m; 
		q->rear=m; 
	}
	q->cnt++; 
	isimNo++;
}

int isempty(queue *q)
{ 
	if(q->cnt == 0){
		return 1;
	}
	return 0;
}



void dequeu(queue *q)
{ 
//	Musteri *temp = q->front;
	if(!isempty(q))
	{ 
		q->front = q->front->next;
	   	//free(temp); 
	   	q->cnt--;
	 } 
}
void bilgiYazdir1(gise *g){
	printf("G%d in %s%d isimli musterisi %s islemini %d dakikada tamamladi ve gitti.\n",g->giseNo,g->bekleyenMusteri->isim,g->bekleyenMusteri->isimNo,g->bekleyenMusteri->islem,g->bekleyenMusteri->beklemeSuresi);
}

void bilgiYazdir2(gise *g){
printf("%d-Nolu Giseye %s%d isimli musteri %s islemini(%d) yapmak icin geldi.\n",g->giseNo,g->bekleyenMusteri->isim,g->bekleyenMusteri->isimNo,g->bekleyenMusteri->islem,g->bekleyenMusteri->beklemeSuresi);
}

void islemSec(gise *g){
	int islem = rand()%4+1;
	switch(islem){

	 case 1:
	 	g->bekleyenMusteri->islem = malloc(4*sizeof(char));
	 	strcpy(g->bekleyenMusteri->islem,"EFT");
		g->bekleyenMusteri->beklemeSuresi = rand()%8+3;
	 	g->bekleyenMusteri->kalanSure = g->bekleyenMusteri->beklemeSuresi;
	 	break;
	case 2:
	 	g->bekleyenMusteri->islem = malloc(12);
	 	strcpy(g->bekleyenMusteri->islem,"Kredi Cekme");
	 	g->bekleyenMusteri->beklemeSuresi = rand()%11+10;
	 	g->bekleyenMusteri->kalanSure = g->bekleyenMusteri->beklemeSuresi;
	 	break;
	case 3:
	 	g->bekleyenMusteri->islem = malloc(13);
	 	strcpy(g->bekleyenMusteri->islem,"Fatura Odeme");
	 	g->bekleyenMusteri->beklemeSuresi = rand()%11+2;
	 	g->bekleyenMusteri->kalanSure = g->bekleyenMusteri->beklemeSuresi;
	 	break;
	case 4:
	 	g->bekleyenMusteri->islem = malloc(11);
	 	strcpy(g->bekleyenMusteri->islem,"Para Cekme");
	 	g->bekleyenMusteri->beklemeSuresi = rand()%7+1;
	 	g->bekleyenMusteri->kalanSure = g->bekleyenMusteri->beklemeSuresi;
	 	break;	
	}
}


void giseKontrol(gise *g){
	if(g->bekleyenMusteri != NULL){
		g->islemSuresi++;
		g->bekleyenMusteri->kalanSure--;
		if(g->bekleyenMusteri->siradaBeklemeSuresi > enUzunBekleyen){
			enUzunBekleyen = g->bekleyenMusteri->siradaBeklemeSuresi;
		}
		toplamBeklemeSuresi+=g->bekleyenMusteri->siradaBeklemeSuresi;
			if(g->bekleyenMusteri->kalanSure ==0){
				bilgiYazdir1(g);
				free(g->bekleyenMusteri);
				g->bekleyenMusteri = NULL;
				g->islemSayisi++;
			}
		}else if(q->cnt >0){
			g->bekleyenMusteri = q->front;
			islemSec(g);
			bilgiYazdir2(g);
			dequeu(q);
		}
}






