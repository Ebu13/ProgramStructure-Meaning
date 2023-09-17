#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Ebubekir Sýddýk Nazlý
//02210224005

int main(){
	
	char dosya[100];
	FILE *file;
	printf("dosya adini giriniz:");
	gets(dosya);
	char dizi[100];
	char kelime[100];
	int i=0;
	
	if((file=fopen(dosya,"r"))==NULL){	//dosya a??l??? kontrol ediliyor
		
		printf("Dosya okuma basarisiz");
		
	}
	else{
		printf("Dosya okuma basarili\n");//dosya ba?ar?l? bir ?ekilde a??ld?ysa
		while(!feof(file)){					//kaynak kodu dosyas? ekrana yaz?l?yor 
			fscanf(file,"%c",&dizi[i]);
			printf("%c",dizi[i]);
			i++;
		}
		fclose(file);						//dosya kapat?ld?
		int j=0;
		printf("\n");
		while(j<i){							//ayra?lar kaynak koddan ayr?l?yor
			if(dizi[j]!=(int)10){			//enter tu?u kontrol ediliyor
				kelime[j]=dizi[j];
				if(kelime[j]==(int)32||kelime[j]==(int)44||kelime[j]==(int)91||kelime[j]==(int)93){//di?er ayra?lar kontrol ediliyor
					kelime[j]=kelime[j+1];
				}
				else{
					printf("%c",kelime[j]);		//kelimele?tirilmi? hali ekrana ard???l bir ?ekilde yaz?l?yor
				}	
			}
			else{
				dizi[j]=dizi[j+1];
			}
			j++;
		}	
	}	
}
