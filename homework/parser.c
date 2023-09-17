#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Ebubekir Sýddýk Nazlý
//02210224005

int main(){
	
	char dizi[1000];
	char dosya[20];
	char kelime[500][10];
	char word[1000];
	FILE *fp;
	
	int i,j;
	int m=0;
	int n=0;
	
	printf("dosya ismini giriniz:");
	scanf("%s",&dosya);
	
	if(fp=fopen(dosya,"r")){		//Dosya a?iliyor
		i=0;
		while(!feof(fp)){				//Dosyadan okuma islemi yapiliyor	 
			fscanf(fp,"%c",&dizi[i]);
			printf("%c",dizi[i]);
			i++;
		}
		fclose(fp);				//Dosya kapatiliyor
		int j=0;
		printf("\n");
		while(j<i){							
			if(dizi[j]!=(int)10&&dizi[j]!=(int)32&&dizi[j]!=(int)44&&dizi[j]!=(int)91&&dizi[j]!=(int)93&&dizi[j]!=(int)58){	//ayraclar kontrol ediliyor	
				kelime[m][n]=dizi[j];
				j++;
				n++;		
			}
			else
			{
				switch (n){			//parser 
					
					case 0:
						return 0;
						break;
					case 1:						//1 basamakli sayilar kontrol ediliyor
						n=0;
							if(kelime[m][n]>=(int)48&&kelime[m][n]<=(int)57){
								printf("%c",kelime[m][n]);
							}
							else{
								printf("\nhata");
								return 0;
							}
							break;
											
					case 2:				//2 basamakli sayilar,operatorler ve mant?ksal islemler kontrol ediliyor		
						n=0;
							if(kelime[m][n]>=(int)48&&kelime[m][n+1]<=(int)57&&kelime[m][n+2]<=(int)57){
								printf("%c",kelime[m][n]);
							}
							else if(kelime[m][n]==(int)68&&kelime[m][n+1]==(int)75){
								printf("DK ");
							}
							else if(kelime[m][n]==(int)68&&kelime[m][n+1]==(int)66){
								printf("DB ");
							}
							else if(kelime[m][n]==(int)86&&kelime[m][n+1]==(int)69){
								printf("VE ");
							}
							else if(kelime[m][n]==(int)68&&kelime[m][n+1]==(int)83){
								printf("DS ");
							}
							else if(kelime[m][n]==(int)65&&kelime[m][n+1]==(int)88){
								printf("AX ");
							}
							else if(kelime[m][n]==(int)66&&kelime[m][n+1]==(int)88){
								printf("BX ");
							}
							else if(kelime[m][n]==(int)67&&kelime[m][n+1]==(int)88){
								printf("CX ");
							}
							else if(kelime[m][n]==(int)68&&kelime[m][n+1]==(int)88){
								printf("DX ");
							}
							else{
								printf("\nhata");
								return 0;
							}
							break;	
					case 3:				//3 basamakli sayilar,aritmetik islemler,dallanmalar kontrol ediliyor	
						n=0;
							if(kelime[m][n]>=(int)49&&kelime[m][n]<=(int)50&&kelime[m][n+1]<=(int)53&&kelime[m][n+2]<=53){
								printf("%c",kelime[m][n]);
							}
							else if(kelime[m][n]==(int)84&&kelime[m][n+1]==(int)79&&kelime[m][n+2]==80){
								printf("TOP ");
							}
							else if(kelime[m][n]==(int)67&&kelime[m][n+1]==(int)73&&kelime[m][n+2]==(int)75){
								printf("CIK ");
							}
							else if(kelime[m][n]==(int)67&&kelime[m][n+1]==(int)82&&kelime[m][n+2]==(int)80){
								printf("CRP ");
							}
							else if(kelime[m][n]==(int)66&&kelime[m][n+1]==(int)79&&kelime[m][n+2]==(int)76){
								printf("BOL ");
							}
							else if(kelime[m][n]==(int)65&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)77){
								printf("ATM ");
							}
							else if(kelime[m][n]==(int)68&&kelime[m][n+1]==(int)65&&kelime[m][n+2]==(int)76){
								printf("DAL ");
							}
							else if(kelime[m][n]==(int)86&&kelime[m][n+1]==(int)69&&kelime[m][n+2]==(int)121){
								printf("VEY ");
							}
							else if(kelime[m][n]==(int)68&&kelime[m][n+1]==(int)83&&kelime[m][n+2]==(int)68){
								printf("DSD ");
							}
							else{
								printf("\nhata");
								return 0;
							}
							break;
			
					case 7:					//Etiketler kontrol ediliyor
						n=0;
							if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)49){
								printf("ETIKET1 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)50){
								printf("ETIKET2 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)51){
								printf("ETIKET3 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)52){
								printf("ETIKET4 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)53){
								printf("ETIKET5 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)54){
								printf("ETIKET6 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)55){
								printf("ETIKET7 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)56){
								printf("ETIKET8 ");
							}
							else if(kelime[m][n]==(int)69&&kelime[m][n+1]==(int)84&&kelime[m][n+2]==(int)73&&kelime[m][n+3]==(int)75&&kelime[m][n+4]==(int)69&&kelime[m][n+5]==(int)84&&kelime[m][n+6]==(int)57){
								printf("ETIKET9 ");
							}
							else{
								printf("\nhata");
								return 0;
							}
							break;
						default:
							printf("\nhata");
							return 0;
				}
				m++;
				j++;
			
			}
		}
		printf("\nhata yok");	
	}
	else{					//Dosyada hata olusmasi ya da olusmamasi kontrol ediliyor 
		printf("dosya acilamadi");			
	}
}
