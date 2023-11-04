#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Bagli{
	int eleman;
	int sonraki;
};

int main(){
	struct Bagli dizi[10000];
	
	int deger;
	int sonraki;
	int index;
	int i;
	int ilk=-1;
	int gecici;
	srand(time(NULL));
	
	for(i=0;i<10000;i++){
		dizi[i].eleman=-1;
		dizi[i].sonraki=-1;
	}
	
	while(1){
		printf("eleman giriniz(eleman girisini bitirmek icin -1 giriniz!!!):");
		scanf("%d",&deger);
		if(deger==-1){
			break;
		}
		if(ilk==-1){
			ilk=0;
			dizi[ilk].eleman=deger;
		}
		else{
			index=rand()%10000;
			gecici=ilk;
			while(dizi[gecici].sonraki!=-1){
				gecici=dizi[gecici].sonraki;
			}
			dizi[gecici].sonraki=index;
			dizi[index].eleman=deger;
		}	
		
	}
	
	gecici=ilk;
	
	while(gecici!=-1){
		if(dizi[gecici].eleman!=-1){
			printf("%d->",dizi[gecici].eleman);
			gecici=dizi[gecici].sonraki;
		}
	}	
}
