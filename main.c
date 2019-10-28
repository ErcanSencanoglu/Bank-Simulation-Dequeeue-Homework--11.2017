#include "kuyruk.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */






int main(int argc, char *argv[]) {
	//
	char c =13;
	int cekirdek = 0;
	int sure = 0;
	int sonrakiMusteri = 0;
	
	printf("Banka Acildi.\n");
	
	q = malloc(sizeof(queue));
	initialize(q);
	printf("Kuyruk Olusturuldu.\n");
	
	printf("Bir Cekirdek Degeri Girin:");
	scanf("%d",&cekirdek);
	printf("Dakika Cinsinden bir sure girin: ");
	scanf("%d",&sure);
	srand(cekirdek);
	
	sonrakiMusteri = rand()%5+1;
	printf("Ilk Musteri %d dk sonra gelecek\n",sonrakiMusteri);
	//

	//
	gise *g1 = malloc(sizeof(gise));
	initializeGise(g1);
	gise *g2 = malloc(sizeof(gise));
	initializeGise(g2);
	gise *g3 = malloc(sizeof(gise));
	initializeGise(g3);
	//
	

	//her dongü 1 dakikayý temsil eder
	while(sure>=gecenSure){
		printf("*********************************\n");
		printf("Saat:%d\tKalan Sure:%d\n",gecenSure,(sure-gecenSure));
	
		if(q->cnt != kuyrukUzunlugu){	
			if(sonrakiMusteri <= 0){
				enqueu(q);
				if(q->cnt > enFazlaBekleyen){enFazlaBekleyen=q->cnt;}
				printf("%s%d %d. siraya eklendi.\n",q->rear->isim,q->rear->isimNo,q->cnt);
				sonrakiMusteri = rand()%5+1;
				printf("Sonraki musteri %d dakika sonra gelecek.\n",sonrakiMusteri);
			}	
		}else{printf("Kuyruk dolu oldugu icin Musteri gelemedi.\n");}
		
		giseKontrol(g1);
		giseKontrol(g2);
		giseKontrol(g3);
		
		Musteri *temp = q->front;
		while(temp!=NULL){
			temp->siradaBeklemeSuresi++;
			temp= temp->next;
		}


		//scanf("%c",&c);
		sonrakiMusteri--;
		gecenSure++;
	}
	
	while(q->cnt>0&&g1->bekleyenMusteri == NULL && g2->bekleyenMusteri==NULL&&g3->bekleyenMusteri==NULL){
		printf("Kuyruktaki Musterilerin Bitmesi Bekleniyor.\n");
		giseKontrol(g1);
		giseKontrol(g2);
		giseKontrol(g3);
		gecenSure++;
	}
	
	printf("---------------------------------------------\nRapor:\n");
	printf("%Toplam islem Sayisi: %d\tToplam Islem Suresi:%d\n",(g1->islemSayisi+g2->islemSayisi+g3->islemSayisi),(g1->islemSuresi+g2->islemSuresi+g3->islemSuresi));
	printf("1 Nolu Gise %d islemi %d dakika calisarak yapti\n",g1->islemSayisi,g1->islemSuresi);
	printf("2 Nolu Gise %d islemi %d dakika calisarak yapti\n",g2->islemSayisi,g2->islemSuresi);
	printf("3 Nolu Gise %d islemi %d dakika calisarak yapti\n",g3->islemSayisi,g3->islemSuresi);
	printf("Herhangi bir anda sirada bekleyen en fazla musteri sayisi:%d\n",enFazlaBekleyen);
	printf("Kuyrukta en uzun bekleme suresi:%d\n",enUzunBekleyen);


	return 0;
}
