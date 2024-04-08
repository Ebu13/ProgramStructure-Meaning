#include <stdio.h>
#include <string.h>


void toplama(char s1[100],char s2[100]){
	int num1[100],num2[100],sum[100];
	int l1,l2;
	
	for (l1 = 0; s1[l1] != '\0'; l1++){
		num1[l1] = s1[l1] - '0'; 
	}
	for (l2 = 0; s2[l2] != '\0'; l2++){ 
		num2[l2] = s2[l2] - '0'; 
	}
	
	int carry = 0; 
	int k = 0; 
	int i = l1 - 1; 
	int j = l2 - 1; 
	
	for (; i >= 0 && j >= 0; i--, j--, k++) { 
		sum[k] = (num1[i] + num2[j] + carry) % 10; 
		carry = (num1[i] + num2[j] + carry) / 10; 
	} 
	if (l1 > l2) {  
		while (i >= 0) { 
			sum[k++] = (num1[i] + carry) % 10; 
			carry = (num1[i--] + carry) / 10; 
		} 
	} 
	else if (l1 < l2) { 
		while (j >= 0) { 
			sum[k++] = (num2[j] + carry) % 10; 
			carry = (num2[j--] + carry) / 10; 
		} 
	} 
	else { 
		if (carry > 0) 
			sum[k++] = carry; 
	}  
	if(strlen(s2)>strlen(s1)){
		printf("      %s\n",s2);
		for(i=0;i<strlen(s2)-strlen(s1);i++){
			printf(" ");
		}
		printf("      %s\n",s1);
	}
	else{
		printf("      %s\n",s1);
		for(i=0;i<strlen(s1)-strlen(s2);i++){
			printf(" ");
		}
		printf("      %s\n",s2);
	}
	printf("sonuc:"); 
	for (k--; k >= 0; k--){ 
		printf("%d ", sum[k]); 
	}	
}

void cikarma(char s1[100],char s2[100]){
	int num1[100]={0};
	int num2[100]={0};
	int numg[100]={0};
	int l1=strlen(s1);
	int l2=strlen(s2);
	int i;
	if(l2>l1){
		return cikarma(s2,s1);
	}
	
	for(i=0;i<l1;i++){
		num1[i]=s1[l1-i-1]-'0';
	}
	for(i=0;i<l2;i++){
		num2[i]=s2[l2-i-1]-'0';
	}
	int j;
	if(l1>l2){
		j=l1;
	}
	else if(l2>l1){
		j=l2;
	}
	
	else if(l1=l2){
		for(i=0;i<=l1-1;i++){
			if(num2[i]>num1[i]){
				int k;
				for(k=0;k<l1;k++){
					numg[k]=num1[k];
					num1[k]=num2[k];
					num2[k]=numg[k];
				}
			}
		}
		j=l1;
	}
	for(i=0;i<j;i++){
		num1[i]-=num2[i];
		if(num1[i]<0){
			num1[i+1]--;
			num1[i]+=10;
		}
	}
	i=j;
	while(num1[i]==0){
		i--;
	}
	if(i<0){
		printf("0");
	}
	int k;
	if(strlen(s2)>strlen(s1)){
		printf("      %s\n",s2);
		for(k=0;k<strlen(s2)-strlen(s1);k++){
			printf(" ");
		}
		printf("      %s\n",s1);
	}
	else{
		printf("      %s\n",s1);
		for(k=0;k<strlen(s1)-strlen(s2);k++){
			printf(" ");
		}
		printf("      %s\n",s2);
	}
	printf("sonuc:");
	for(;i>=0;i--){
		printf("%d ",num1[i]);
	}	
}

void carpma(char s1[100],char s2[100]){
	int num1[100],num2[100];
	int product[200]={0};
	int i,j,temp;
	int l1=strlen(s1);
	int l2=strlen(s2);
	
	for(i=l1-1,j=0;i>=0;i--,j++){
		num1[j]=s1[i]-'0';
	}
	for(i=l2-1,j=0;i>=0;i--,j++){
		num2[j]=s2[i]-'0';
	}
	for(i=0;i<l2;i++){
		for(j=0;j<l1;j++){
			product[i+j]+=num2[i]*num1[j];
		}
	}
	for(i=0;i<l1+l2;i++){
		temp=product[i]/10;
		product[i]=product[i]%10;
		product[i+1]=product[i+1]+temp;
	}
	for(i=l1+l2;i>=0;i--){
		if(product[i]>0)
		break;
	}
	int k;
	if(strlen(s2)>strlen(s1)){
		printf("      %s\n",s2);
		for(k=0;k<strlen(s2)-strlen(s1);k++){
			printf(" ");
		}
		printf("      %s\n",s1);
	}
	else{
		printf("      %s\n",s1);
		for(k=0;k<strlen(s1)-strlen(s2);k++){
			printf(" ");
		}
		printf("      %s\n",s2);
	}
	printf("sonuc:");
	for(;i>=0;i--){
		printf("%d ",product[i]);
	}
}

main(){
	int a;
	int i;
	char s1[100],s2[100];
	printf("1.TOPLAMA\n2.CIKARMA\n3.CARPMA\n");
	printf("islem seciniz:");
	scanf("%d",&a);
	if(a!=1&&a!=2&&a!=3){	
		printf("hatali islem sectiniz!!!");
		return 0;
	}
	else if(a==1){
		printf("1. sayiyi giriniz:");
		scanf("%s",&s1);
		for(i=0;i<strlen(s1);i++){
			if(s1[i]<48||s1[i]>57){
				printf("hatali giris!!!");
					return 0;
			}
		}
		printf("2. sayiyi giriniz:");
		scanf("%s",&s2);
		for(i=0;i<strlen(s2);i++){
			if(s2[i]<48||s2[i]>57){
				printf("hatali giris!!!");
				return 0;
			}
		}
		toplama(s1,s2);
	}
	else if(a==2){
		printf("1. sayiyi giriniz:");
		scanf("%s",&s1);
		for(i=0;i<strlen(s1);i++){
			if(s1[i]<48||s1[i]>57){
				printf("hatali giris!!!");
					return 0;
			}
		}
		printf("2. sayiyi giriniz:");
		scanf("%s",&s2);
		for(i=0;i<strlen(s2);i++){
			if(s2[i]<48||s2[i]>57){
				printf("hatali giris!!!");
				return 0;
			}
		}
		cikarma(s1,s2);
	}
	else if(a==3){
		printf("1. sayiyi giriniz:");
		scanf("%s",&s1);
		for(i=0;i<strlen(s1);i++){
			if(s1[i]<48||s1[i]>57){
				printf("hatali giris!!!");
					return 0;
			}
		}
		printf("2. sayiyi giriniz:");
		scanf("%s",&s2);
		for(i=0;i<strlen(s2);i++){
			if(s2[i]<48||s2[i]>57){
				printf("hatali giris!!!");
				return 0;
			}
		}
		carpma(s1,s2);
	}
}
