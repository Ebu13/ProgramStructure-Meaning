#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Ebubekir Sýddýk Nazlý
//02210224005

int main()
{
	char dosya[100];
	FILE * file;
	printf("dosya adini giriniz:");
	gets(dosya);
	char dizi[10000];
	int RAM[255];
	int AX = 0;
	int BX = 0;
	int CX = 0;
	int DX = 0;
	int k;
	int i = 0;

	for (k = 0; k < 256; k++)
	{
		RAM[k] = -1;
	}

	if ((file = fopen(dosya, "r")) == NULL)
	{
		//dosya a??l??? kontrol ediliyor

		printf("Dosya okuma basarisiz");
	}
	else
	{
		printf("Dosya okuma basarili\n");	//dosya ba?ar?l? bir ?ekilde a??ld?ysa
		while (!feof(file))
		{
			//kaynak kodu dosyas? ekrana yaz?l?yor 
			fscanf(file, "%c", &dizi[i]);
			printf("%c", dizi[i]);
			i++;
		}

		fclose(file);	//dosya kapat?ld?
		int j = 0;
		printf("\n");
		while (j < i)
		{
			if (dizi[j] == 'A')
			{
				//ATM
				if (dizi[j + 4] == 'A')
				{
					//AX
					if (dizi[j + 7] == 'A')
					{
						AX = AX;
						j = j + 9;
					}
					else if (dizi[j + 7] == 'B')
					{
						AX = BX;
						j = j + 9;
					}
					else if (dizi[j + 7] == 'C')
					{
						AX = CX;
						j = j + 9;
					}
					else if (dizi[j + 7] == 'D')
					{
						AX = DX;
						j = j + 9;
					}
					else if (dizi[j + 7] == '[')
					{
						//AX-RAM
						if (dizi[j + 9] == ']')
						{
							AX = RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							AX = RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							AX = RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//AX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									AX = ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									AX = ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								AX = (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'B')
				{
					//BX
					if (dizi[j + 7] == 'A')
					{
						BX = AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						BX = BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						BX = CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						BX = DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//BX-RAM
						if (dizi[j + 9] == ']')
						{
							BX = RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							BX = RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							BX = RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//BX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									BX = ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									BX = ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								BX = (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'C')
				{
					//CX
					if (dizi[j + 7] == 'A')
					{
						CX = AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						CX = BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						CX = CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						CX = DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//CX-RAM
						if (dizi[j + 9] == ']')
						{
							CX = RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							CX = RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							CX = RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//CX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									CX = ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									CX = ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								CX = (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'D')
				{
					//DX
					if (dizi[j + 7] == 'A')
					{
						DX = AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						DX = BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						DX = CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						DX = DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//DX-RAM
						if (dizi[j + 9] == ']')
						{
							DX = RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							DX = RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							DX = RAM[(((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//DX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									DX = ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									DX = ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								DX = (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else
				{
					//RAM
					if (dizi[j + 4] == '[')
					{
						if (dizi[j + 6] == ']')
						{
							//RAM[tek bsmk]
							if (dizi[j + 8] == 'A')
							{
								//RAM-AX
								RAM[(int) dizi[j + 5] - 48] = AX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'B')
							{
								//RAM- BX
								RAM[(int) dizi[j + 5] - 48] = BX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'C')
							{
								//RAM-CX
								RAM[(int) dizi[j + 5] - 48] = CX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'D')
							{
								//RAM-DX
								RAM[(int) dizi[j + 5] - 48] = DX;
								j = j + 10;
							}
							else if (dizi[j + 8] == '[')
							{
								//RAM-RAM
								if (dizi[j + 10] == ']')
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 9] - 48];
									j = j + 11;
								}
								else if (dizi[j + 11] == ']')
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48)];
									j = j + 12;
								}
								else
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(((int) dizi[j + 9] - 48) *100) + (((int) dizi[j + 10] - 48) *10) + ((int) dizi[j + 11] - 48)];
									j = j + 13;
								}
							}
							else
							{
								//RAM-sayilar
								if (dizi[j + 9] == (int) 10)
								{
									RAM[(int) dizi[j + 5] - 48] = (int) dizi[j + 8] - 48;
									j = j + 9;
								}
								else if (dizi[j + 10] == (int) 10)
								{
									RAM[(int) dizi[j + 5] - 48] = ((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else
								{
									RAM[(int) dizi[j + 5] - 48] = (((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48);
									j = j + 11;
								}
							}
						}
						else if (dizi[j + 7] == ']')
						{
							//RAM[cift bsmk]
							if (dizi[j + 9] == 'A')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = AX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'B')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = BX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'C')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = CX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'D')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = DX;
								j = j + 11;
							}
							else if (dizi[j + 9] == '[')
							{
								//RAM-RAM
								if (dizi[j + 11] == ']')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[(int) dizi[j + 10] - 48];
									j = j + 12;
								}
								else if (dizi[j + 12] == ']')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((((int) dizi[j + 10] - 48) *10) + (int) dizi[j + 11] - 48) *10 + (int) dizi[j + 12] - 48];
									j = j + 14;
								}
							}
							else
							{
								//RAM-sayilar
								if (dizi[j + 10] == (int) 10)
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = (int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else if (dizi[j + 11] == (int) 10)
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = ((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48;
									j = j + 11;
								}
								else
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = ((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
									j = j + 12;
								}
							}
						}
						else
						{
							//RAM[3 bsmk]
							if (dizi[j + 10] == 'A')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = AX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'B')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = BX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'C')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = CX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'D')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = DX;
								j = j + 12;
							}
							else if (dizi[j + 10] == '[')
							{
								//RAM-RAM
								if (dizi[j + 12] == ']')
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else if (dizi[j + 13] == ']')
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[((int) dizi[j + 11] - 48) *10 + ((int) dizi[j + 12] - 48)];
									j = j + 14;
								}
								else
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 11] - 48) *100) + (((int) dizi[j + 12] - 48) *10) + ((int) dizi[j + 13] - 48)];
									j = j + 15;
								}
							}
							else
							{
								//RAM-sayilar
								if (dizi[j + 11] == (int) 10)
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] = (int) dizi[j + 10] - 48;
									j = j + 11;
								}
								else if (dizi[j + 12] == (int) 10)
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = ((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
									j = j + 12;
								}
								else
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = (((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)) *10 + (int) dizi[j + 12] - 48;
									j = j + 13;
								}
							}
						}
					}
				}
			}

			if (dizi[j] == 'T')
			{
				//TOP
				if (dizi[j + 4] == 'A')
				{
					//TOP-AX
					if (dizi[j + 7] == 'A')
					{
						AX = AX + AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						AX = AX + BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						AX = AX + CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						AX = AX + DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//TOP-AX-RAM
						if (dizi[j + 9] == ']')
						{
							AX = AX + RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							AX = AX + RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							AX = AX + RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//TOP-AX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									AX = AX + ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									AX = AX + ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								AX = AX + (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'B')
				{
					//TOP-BX
					if (dizi[j + 7] == 'A')
					{
						BX = BX + AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						BX = BX + BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						BX = BX + CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						BX = BX + DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//TOP-BX-RAM
						if (dizi[j + 9] == ']')
						{
							BX = BX + RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							BX = BX + RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							BX = BX + RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//TOP-BX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									BX = BX + ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									BX = BX + ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								BX = BX + (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'C')
				{
					//TOP-CX
					if (dizi[j + 7] == 'A')
					{
						CX = CX + AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						CX = CX + BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						CX = CX + CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						CX = CX + DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//TOP-CX-RAM
						if (dizi[j + 9] == ']')
						{
							CX = CX + RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							CX = CX + RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							CX = CX + RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//TOP-CX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									CX = CX + ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									CX = CX + ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								CX = CX + (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'D')
				{
					//TOP-DX
					if (dizi[j + 7] == 'A')
					{
						DX = DX + AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						DX = DX + BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						DX = DX + CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						DX = DX + DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//TOP-DX-RAM
						if (dizi[j + 9] == ']')
						{
							DX = DX + RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							DX = DX + RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							DX = DX + RAM[(((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//TOP-DX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									DX = DX + ((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48);
									j = j + 9;
								}
								else
								{
									DX = DX + ((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
									j = j + 8;
								}
							}
							else
							{
								DX = DX + (int) dizi[j + 7] - 48;
								j = j + 7;
							}
						}
					}
				}
				else
				{
					//TOP-RAM
					if (dizi[j + 4] == '[')
					{
						if (dizi[j + 6] == ']')
						{
							//RAM[tek bsmk]
							if (dizi[j + 8] == 'A')
							{
								//TOP-RAM-AX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + AX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'B')
							{
								//TOP-RAM- BX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + BX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'C')
							{
								//TOP-RAM-CX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + CX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'D')
							{
								//TOP-RAM-DX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + DX;
								j = j + 10;
							}
							else if (dizi[j + 8] == '[')
							{
								//TOP-RAM-RAM
								if (dizi[j + 10] == ']')
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + RAM[(int) dizi[j + 9] - 48];
									j = j + 11;
								}
								else if (dizi[j + 11] == ']')
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + RAM[(((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48)];
									j = j + 12;
								}
								else
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + RAM[(((int) dizi[j + 9] - 48) *100) + (((int) dizi[j + 10] - 48) *10) + ((int) dizi[j + 11] - 48)];
									j = j + 13;
								}
							}
							else
							{
								//TOP-RAM-sayilar
								if (dizi[j + 9] == (int) 10)
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + (int) dizi[j + 8] - 48;
									j = j + 9;
								}
								else if (dizi[j + 10] == (int) 10)
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + ((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] + (((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48);
									j = j + 11;
								}
							}
						}
						else if (dizi[j + 7] == ']')
						{
							//RAM[cift bsmk]
							if (dizi[j + 9] == 'A')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + AX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'B')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + BX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'C')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + CX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'D')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + DX;
								j = j + 11;
							}
							else if (dizi[j + 9] == '[')
							{
								//TOP-RAM-RAM
								if (dizi[j + 11] == ']')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + RAM[(int) dizi[j + 10] - 48];
									j = j + 12;
								}
								else if (dizi[j + 12] == ']')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + RAM[((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + RAM[((((int) dizi[j + 10] - 48) *10) + (int) dizi[j + 11] - 48) *10 + (int) dizi[j + 12] - 48];
									j = j + 14;
								}
							}
							else
							{
								//TOP-RAM-sayilar
								if (dizi[j + 10] == (int) 10)
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + (int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else if (dizi[j + 11] == (int) 10)
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + ((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48;
									j = j + 11;
								}
								else
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] + ((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
									j = j + 12;
								}
							}
						}
						else
						{
							//RAM[3 bsmk]
							if (dizi[j + 10] == 'A')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + AX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'B')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + BX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'C')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + CX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'D')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + DX;
								j = j + 12;
							}
							else if (dizi[j + 10] == '[')
							{
								//TOP-RAM-RAM
								if (dizi[j + 12] == ']')
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + RAM[(int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else if (dizi[j + 13] == ']')
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] + RAM[((int) dizi[j + 11] - 48) *10 + ((int) dizi[j + 12] - 48)];
									j = j + 14;
								}
								else
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + RAM[(((int) dizi[j + 11] - 48) *100) + (((int) dizi[j + 12] - 48) *10) + ((int) dizi[j + 13] - 48)];
									j = j + 15;
								}
							}
							else
							{
								//TOP-RAM-sayilar
								if (dizi[j + 11] == (int) 10)
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + (int) dizi[j + 10] - 48;
									j = j + 11;
								}
								else if (dizi[j + 12] == (int) 10)
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + ((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
									j = j + 12;
								}
								else
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] + (((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)) *10 + (int) dizi[j + 12] - 48;
									j = j + 13;
								}
							}
						}
					}
				}
			}

			if (dizi[j] == 'C')
			{
				//CIK
				if (dizi[j + 1] == 'I')
				{
					if (dizi[j + 4] == 'A')
					{
						//CIK-AX
						if (dizi[j + 7] == 'A')
						{
							AX = AX - AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							AX = AX - BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							AX = AX - CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							AX = AX - DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CIK-AX-RAM
							if (dizi[j + 9] == ']')
							{
								AX = AX - RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								AX = AX - RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								AX = AX - RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CIK-AX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										AX = AX - (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										AX = AX - (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									AX = AX - ((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else if (dizi[j + 4] == 'B')
					{
						//CIK-BX
						if (dizi[j + 7] == 'A')
						{
							BX = BX - AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							BX = BX - BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							BX = BX - CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							BX = BX - DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CIK-BX-RAM
							if (dizi[j + 9] == ']')
							{
								BX = BX - RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								BX = BX - RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								BX = BX - RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CIK-BX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										BX = BX - (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										BX = BX - (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									BX = BX - ((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else if (dizi[j + 4] == 'C')
					{
						//CIK-CX
						if (dizi[j + 7] == 'A')
						{
							CX = CX - AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							CX = CX - BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							CX = CX - CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							CX = CX - DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CIK-CX-RAM
							if (dizi[j + 9] == ']')
							{
								CX = CX - RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								CX = CX - RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								CX = CX - RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CIK-CX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										CX = CX - (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										CX = CX - (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									CX = CX - ((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else if (dizi[j + 4] == 'D')
					{
						//CIK-DX
						if (dizi[j + 7] == 'A')
						{
							DX = DX - AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							DX = DX - BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							DX = DX - CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							DX = DX - DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CIK-DX-RAM
							if (dizi[j + 9] == ']')
							{
								DX = DX - RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								DX = DX - RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								DX = DX - RAM[(((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CIK-DX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										DX = DX - (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										DX = DX - (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									DX = DX - ((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else
					{
						//CIK-RAM
						if (dizi[j + 4] == '[')
						{
							if (dizi[j + 6] == ']')
							{
								//RAM[tek bsmk]
								if (dizi[j + 8] == 'A')
								{
									//CIK-RAM-AX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - AX;
									j = j + 10;
								}
								else if (dizi[j + 8] == 'B')
								{
									//CIK-RAM- BX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - BX;
									j = j + 10;
								}
								else if (dizi[j + 8] == 'C')
								{
									//CIK-RAM-CX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - CX;
									j = j + 10;
								}
								else if (dizi[j + 8] == 'D')
								{
									//CIK-RAM-DX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - DX;
									j = j + 10;
								}
								else if (dizi[j + 8] == '[')
								{
									//CIK-RAM-RAM
									if (dizi[j + 10] == ']')
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - RAM[(int) dizi[j + 9] - 48];
										j = j + 11;
									}
									else if (dizi[j + 11] == ']')
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - RAM[(((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48)];
										j = j + 12;
									}
									else
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - RAM[(((int) dizi[j + 9] - 48) *100) + (((int) dizi[j + 10] - 48) *10) + ((int) dizi[j + 11] - 48)];
										j = j + 13;
									}
								}
								else
								{
									//CIK-RAM-sayilar
									if (dizi[j + 9] == (int) 10)
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - (int) dizi[j + 8] - 48;
										j = j + 9;
									}
									else if (dizi[j + 10] == (int) 10)
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - ((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48;
										j = j + 10;
									}
									else
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] - (((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48);
										j = j + 11;
									}
								}
							}
							else if (dizi[j + 7] == ']')
							{
								//RAM[cift bsmk]
								if (dizi[j + 9] == 'A')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - AX;
									j = j + 11;
								}
								else if (dizi[j + 9] == 'B')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - BX;
									j = j + 11;
								}
								else if (dizi[j + 9] == 'C')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - CX;
									j = j + 11;
								}
								else if (dizi[j + 9] == 'D')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - DX;
									j = j + 11;
								}
								else if (dizi[j + 9] == '[')
								{
									//CIK-RAM-RAM
									if (dizi[j + 11] == ']')
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - RAM[(int) dizi[j + 10] - 48];
										j = j + 12;
									}
									else if (dizi[j + 12] == ']')
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - RAM[((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
										j = j + 13;
									}
									else
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - RAM[((((int) dizi[j + 10] - 48) *10) + (int) dizi[j + 11] - 48) *10 + (int) dizi[j + 12] - 48];
										j = j + 14;
									}
								}
								else
								{
									//CIK-RAM-sayilar
									if (dizi[j + 10] == (int) 10)
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - (int) dizi[j + 9] - 48;
										j = j + 10;
									}
									else if (dizi[j + 11] == (int) 10)
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - ((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48;
										j = j + 11;
									}
									else
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] - ((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
										j = j + 12;
									}
								}
							}
							else
							{
								//RAM[3 bsmk]
								if (dizi[j + 10] == 'A')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - AX;
									j = j + 12;
								}
								else if (dizi[j + 10] == 'B')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - BX;
									j = j + 12;
								}
								else if (dizi[j + 10] == 'C')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - CX;
									j = j + 12;
								}
								else if (dizi[j + 10] == 'D')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - DX;
									j = j + 12;
								}
								else if (dizi[j + 10] == '[')
								{
									//CIK-RAM-RAM
									if (dizi[j + 12] == ']')
									{
										RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - RAM[(int) dizi[j + 11] - 48];
										j = j + 13;
									}
									else if (dizi[j + 13] == ']')
									{
										RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] - RAM[((int) dizi[j + 11] - 48) *10 + ((int) dizi[j + 12] - 48)];
										j = j + 14;
									}
									else
									{
										RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - RAM[(((int) dizi[j + 11] - 48) *100) + (((int) dizi[j + 12] - 48) *10) + ((int) dizi[j + 13] - 48)];
										j = j + 15;
									}
								}
								else
								{
									//CIK-RAM-sayilar
									if (dizi[j + 11] == (int) 10)
									{
										RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - (int) dizi[j + 10] - 48;
										j = j + 11;
									}
									else if (dizi[j + 12] == (int) 10)
									{
										RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - ((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
										j = j + 12;
									}
									else
									{
										RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] - (((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)) *10 + (int) dizi[j + 12] - 48;
										j = j + 13;
									}
								}
							}
						}
					}
				}
			}

			if (dizi[j] == 'C')
			{
				//CRP
				if (dizi[j + 1] == 'R')
				{
					if (dizi[j + 4] == 'A')
					{
						//CRP-AX
						if (dizi[j + 7] == 'A')
						{
							AX = AX * AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							AX = AX * BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							AX = AX * CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							AX = AX * DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CRP-AX-RAM
							if (dizi[j + 9] == ']')
							{
								AX = AX *RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								AX = AX *RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								AX = AX *RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CRP-AX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										AX = AX *(((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										AX = AX *(((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									AX = AX *((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else if (dizi[j + 4] == 'B')
					{
						//CRP-BX
						if (dizi[j + 7] == 'A')
						{
							BX = BX * AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							BX = BX * BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							BX = BX * CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							BX = BX * DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CRP-BX-RAM
							if (dizi[j + 9] == ']')
							{
								BX = BX *RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								BX = BX *RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								BX = BX *RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CRP-BX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										BX = BX *(((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										BX = BX *(((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									BX = BX *((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else if (dizi[j + 4] == 'C')
					{
						//CRP-CX
						if (dizi[j + 7] == 'A')
						{
							CX = CX * AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							CX = CX * BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							CX = CX * CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							CX = CX * DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CRP-CX-RAM
							if (dizi[j + 9] == ']')
							{
								CX = CX *RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								CX = CX *RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								CX = CX *RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CRP-CX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										CX = CX *(((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										CX = CX *(((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									CX = CX *((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else if (dizi[j + 4] == 'D')
					{
						//CRP-DX
						if (dizi[j + 7] == 'A')
						{
							DX = DX * AX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'B')
						{
							DX = DX * BX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'C')
						{
							DX = DX * CX;
							j = j + 10;
						}
						else if (dizi[j + 7] == 'D')
						{
							DX = DX * DX;
							j = j + 10;
						}
						else if (dizi[j + 7] == '[')
						{
							//CRP-DX-RAM
							if (dizi[j + 9] == ']')
							{
								DX = DX *RAM[(int) dizi[j + 8] - 48];
								j = j + 10;
							}
							else if (dizi[j + 10] == ']')
							{
								DX = DX *RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
								j = j + 11;
							}
							else
							{
								DX = DX *RAM[(((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)) *10 + ((int) dizi[j + 10] - 48)];
								j = j + 12;
							}
						}
						else
						{
							//CRP-DX-sayilar
							if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
							{
								if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
								{
									if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
									{
										DX = DX *(((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
										j = j + 9;
									}
									else
									{
										DX = DX *(((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
										j = j + 8;
									}
								}
								else
								{
									DX = DX *((int) dizi[j + 7] - 48);
									j = j + 7;
								}
							}
						}
					}
					else
					{
						//CRP-RAM
						if (dizi[j + 4] == '[')
						{
							if (dizi[j + 6] == ']')
							{
								//RAM[tek bsmk]
								if (dizi[j + 8] == 'A')
								{
									//CRP-RAM-AX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *AX;
									j = j + 10;
								}
								else if (dizi[j + 8] == 'B')
								{
									//CRP-RAM- BX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *BX;
									j = j + 10;
								}
								else if (dizi[j + 8] == 'C')
								{
									//CRP-RAM-CX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *CX;
									j = j + 10;
								}
								else if (dizi[j + 8] == 'D')
								{
									//CRP-RAM-DX
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *DX;
									j = j + 10;
								}
								else if (dizi[j + 8] == '[')
								{
									//CRP-RAM-RAM
									if (dizi[j + 10] == ']')
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *RAM[(int) dizi[j + 9] - 48];
										j = j + 11;
									}
									else if (dizi[j + 11] == ']')
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *RAM[(((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48)];
										j = j + 12;
									}
									else
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *RAM[(((int) dizi[j + 9] - 48) *100) + (((int) dizi[j + 10] - 48) *10) + ((int) dizi[j + 11] - 48)];
										j = j + 13;
									}
								}
								else
								{
									//CRP-RAM-sayilar
									if (dizi[j + 9] == (int) 10)
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *(int) dizi[j + 8] - 48;
										j = j + 9;
									}
									else if (dizi[j + 10] == (int) 10)
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48;
										j = j + 10;
									}
									else
									{
										RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] *(((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48);
										j = j + 11;
									}
								}
							}
							else if (dizi[j + 7] == ']')
							{
								//RAM[cift bsmk]
								if (dizi[j + 9] == 'A')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *AX;
									j = j + 11;
								}
								else if (dizi[j + 9] == 'B')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *BX;
									j = j + 11;
								}
								else if (dizi[j + 9] == 'C')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *CX;
									j = j + 11;
								}
								else if (dizi[j + 9] == 'D')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *DX;
									j = j + 11;
								}
								else if (dizi[j + 9] == '[')
								{
									//CRP-RAM-RAM
									if (dizi[j + 11] == ']')
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *RAM[(int) dizi[j + 10] - 48];
										j = j + 12;
									}
									else if (dizi[j + 12] == ']')
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *RAM[((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
										j = j + 13;
									}
									else
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *RAM[((((int) dizi[j + 10] - 48) *10) + (int) dizi[j + 11] - 48) *10 + (int) dizi[j + 12] - 48];
										j = j + 14;
									}
								}
								else
								{
									//CRP-RAM-sayilar
									if (dizi[j + 10] == (int) 10)
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *(int) dizi[j + 9] - 48;
										j = j + 10;
									}
									else if (dizi[j + 11] == (int) 10)
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48;
										j = j + 11;
									}
									else
									{
										RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] *((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
										j = j + 12;
									}
								}
							}
							else
							{
								//RAM[3 bsmk]
								if (dizi[j + 10] == 'A')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *AX;
									j = j + 12;
								}
								else if (dizi[j + 10] == 'B')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *BX;
									j = j + 12;
								}
								else if (dizi[j + 10] == 'C')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *CX;
									j = j + 12;
								}
								else if (dizi[j + 10] == 'D')
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *DX;
									j = j + 12;
								}
								else if (dizi[j + 10] == '[')
								{
									//CRP-RAM-RAM
									if (dizi[j + 12] == ']')
									{
										RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *RAM[(int) dizi[j + 11] - 48];
										j = j + 13;
									}
									else if (dizi[j + 13] == ']')
									{
										RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] *RAM[((int) dizi[j + 11] - 48) *10 + ((int) dizi[j + 12] - 48)];
										j = j + 14;
									}
									else
									{
										RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *RAM[(((int) dizi[j + 11] - 48) *100) + (((int) dizi[j + 12] - 48) *10) + ((int) dizi[j + 13] - 48)];
										j = j + 15;
									}
								}
								else
								{
									//CRP-RAM-sayilar
									if (dizi[j + 11] == (int) 10)
									{
										RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *(int) dizi[j + 10] - 48;
										j = j + 11;
									}
									else if (dizi[j + 12] == (int) 10)
									{
										RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
										j = j + 12;
									}
									else
									{
										RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] *(((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)) *10 + (int) dizi[j + 12] - 48;
										j = j + 13;
									}
								}
							}
						}
					}
				}
			}

			if (dizi[j] == 'B')
			{
				//BOL
				if (dizi[j + 4] == 'A')
				{
					//BOL-AX
					if (dizi[j + 7] == 'A')
					{
						DX = AX % AX;
						AX = AX / AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						DX = AX % BX;
						AX = AX / BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						DX = AX % CX;
						AX = AX / CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//BOL-AX-RAM
						if (dizi[j + 9] == ']')
						{
							DX = AX % RAM[(int) dizi[j + 8] - 48];
							AX = AX / RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							DX = AX % RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							AX = AX / RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							DX = AX % RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							AX = AX / RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//BOL-AX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									DX = AX % (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									AX = AX / (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									j = j + 9;
								}
								else
								{
									DX = AX % (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									AX = AX / (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									j = j + 8;
								}
							}
							else
							{
								DX = AX % ((int) dizi[j + 7] - 48);
								AX = AX / ((int) dizi[j + 7] - 48);
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'B')
				{
					//BOL-BX
					if (dizi[j + 7] == 'A')
					{
						DX = BX % AX;
						BX = BX / AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						DX = BX % BX;
						BX = BX / BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						DX = BX % CX;
						BX = BX / CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//BOL-BX-RAM
						if (dizi[j + 9] == ']')
						{
							DX = BX % RAM[(int) dizi[j + 8] - 48];
							BX = BX / RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							DX = BX % RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							BX = BX / RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							DX = BX % RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							BX = BX / RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//BOL-BX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									DX = BX % (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									BX = BX / (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									j = j + 9;
								}
								else
								{
									DX = BX % (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									BX = BX / (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									j = j + 8;
								}
							}
							else
							{
								DX = BX % ((int) dizi[j + 7] - 48);
								BX = BX / ((int) dizi[j + 7] - 48);
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'C')
				{
					//BOL-CX
					if (dizi[j + 7] == 'A')
					{
						DX = CX % AX;
						CX = CX / AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						DX = CX % BX;
						CX = CX / BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						DX = CX % CX;
						CX = CX / CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//BOL-CX-RAM
						if (dizi[j + 9] == ']')
						{
							DX = CX % RAM[(int) dizi[j + 8] - 48];
							CX = CX / RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							DX = CX % RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							CX = CX / RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							DX = CX % RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							CX = CX / RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//BOL-CX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									DX = CX % (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									CX = CX / (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									j = j + 9;
								}
								else
								{
									DX = CX % (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									CX = CX / (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									j = j + 8;
								}
							}
							else
							{
								DX = CX % ((int) dizi[j + 7] - 48);
								CX = CX / ((int) dizi[j + 7] - 48);
								j = j + 7;
							}
						}
					}
				}
				else
				{
					//BOL-RAM
					if (dizi[j + 4] == '[')
					{
						if (dizi[j + 6] == ']')
						{
							//RAM[tek bsmk]
							if (dizi[j + 8] == 'A')
							{
								//BOL-RAM-AX
								DX = RAM[(int) dizi[j + 5] - 48] % AX;
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / AX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'B')
							{
								//BOL-RAM- BX
								DX = RAM[(int) dizi[j + 5] - 48] % BX;
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / BX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'C')
							{
								//BOL-RAM-CX
								DX = RAM[(int) dizi[j + 5] - 48] % CX;
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / CX;
								j = j + 10;
							}
							else if (dizi[j + 8] == '[')
							{
								//BOL-RAM-RAM
								if (dizi[j + 10] == ']')
								{
									DX = RAM[(int) dizi[j + 5] - 48] % RAM[(int) dizi[j + 9] - 48];
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / RAM[(int) dizi[j + 9] - 48];
									j = j + 11;
								}
								else if (dizi[j + 11] == ']')
								{
									DX = RAM[(int) dizi[j + 5] - 48] % RAM[(((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48)];
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / RAM[(((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48)];
									j = j + 12;
								}
								else
								{
									DX = RAM[(int) dizi[j + 5] - 48] % RAM[(((int) dizi[j + 9] - 48) *100) + (((int) dizi[j + 10] - 48) *10) + ((int) dizi[j + 11] - 48)];
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / RAM[(((int) dizi[j + 9] - 48) *100) + (((int) dizi[j + 10] - 48) *10) + ((int) dizi[j + 11] - 48)];
									j = j + 13;
								}
							}
							else
							{
								//BOL-RAM-sayilar
								if (dizi[j + 9] == (int) 10)
								{
									DX = RAM[(int) dizi[j + 5] - 48] % ((int) dizi[j + 8] - 48);
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / ((int) dizi[j + 8] - 48);
									j = j + 9;
								}
								else if (dizi[j + 10] == (int) 10)
								{
									DX = RAM[(int) dizi[j + 5] - 48] % (((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48);
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / (((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48);
									j = j + 10;
								}
								else
								{
									DX = RAM[(int) dizi[j + 5] - 48] % ((((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48));
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] / ((((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48));
									j = j + 11;
								}
							}
						}
						else if (dizi[j + 7] == ']')
						{
							//RAM[cift bsmk]
							if (dizi[j + 9] == 'A')
							{
								DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % AX;
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / AX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'B')
							{
								DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % BX;
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / BX;;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'C')
							{
								DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % CX;
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / CX;
								j = j + 11;
							}
							else if (dizi[j + 9] == '[')
							{
								//BOL-RAM-RAM
								if (dizi[j + 11] == ']')
								{
									DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % RAM[(int) dizi[j + 10] - 48];
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / RAM[(int) dizi[j + 10] - 48];
									j = j + 12;
								}
								else if (dizi[j + 12] == ']')
								{
									DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % RAM[((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / RAM[((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else
								{
									DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % RAM[((((int) dizi[j + 10] - 48) *10) + (int) dizi[j + 11] - 48) *10 + (int) dizi[j + 12] - 48];
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / RAM[((((int) dizi[j + 10] - 48) *10) + (int) dizi[j + 11] - 48) *10 + (int) dizi[j + 12] - 48];
									j = j + 14;
								}
							}
							else
							{
								//BOL-RAM-sayilar
								if (dizi[j + 10] == (int) 10)
								{
									DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % ((int) dizi[j + 9] - 48);
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / ((int) dizi[j + 9] - 48);
									j = j + 10;
								}
								else if (dizi[j + 11] == (int) 10)
								{
									DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % (((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48);
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / (((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48);
									j = j + 11;
								}
								else
								{
									DX = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] % (((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48);
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] / (((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48);
									j = j + 12;
								}
							}
						}
						else
						{
							//RAM[3 bsmk]
							if (dizi[j + 10] == 'A')
							{
								DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % AX;
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / AX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'B')
							{
								DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % BX;
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / BX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'C')
							{
								DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % CX;
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / CX;
								j = j + 12;
							}
							else if (dizi[j + 10] == '[')
							{
								//BOL-RAM-RAM
								if (dizi[j + 12] == ']')
								{
									DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % RAM[(int) dizi[j + 11] - 48];
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / RAM[(int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else if (dizi[j + 13] == ']')
								{
									DX = RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] % RAM[((int) dizi[j + 11] - 48) *10 + ((int) dizi[j + 12] - 48)];
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] / RAM[((int) dizi[j + 11] - 48) *10 + ((int) dizi[j + 12] - 48)];
									j = j + 14;
								}
								else
								{
									DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % RAM[(((int) dizi[j + 11] - 48) *100) + (((int) dizi[j + 12] - 48) *10) + ((int) dizi[j + 13] - 48)];
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / RAM[(((int) dizi[j + 11] - 48) *100) + (((int) dizi[j + 12] - 48) *10) + ((int) dizi[j + 13] - 48)];
									j = j + 15;
								}
							}
							else
							{
								//BOL-RAM-sayilar
								if (dizi[j + 11] == (int) 10)
								{
									DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % ((int) dizi[j + 10] - 48);
									RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / ((int) dizi[j + 10] - 48);
									j = j + 11;
								}
								else if (dizi[j + 12] == (int) 10)
								{
									DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % (((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48);
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / (((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48);
									j = j + 12;
								}
								else
								{
									DX = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] % ((((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)) *10 + (int) dizi[j + 12] - 48);
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] / ((((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)) *10 + (int) dizi[j + 12] - 48);
									j = j + 13;
								}
							}
						}
					}
				}
			}

			if (dizi[j] == 'V' && dizi[j + 1] == 'E' && dizi[j + 2] == 'Y')
			{
				if (dizi[j + 4] == 'A')
				{
					//VEY-AX
					if (dizi[j + 7] == 'A')
					{
						AX = AX | AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						AX = AX | BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						AX = AX | CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						AX = AX | DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//VEY-AX-RAM
						if (dizi[j + 9] == ']')
						{
							AX = AX | RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							AX = AX | RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							AX = AX | RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//VEY-AX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									AX = AX | (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									j = j + 9;
								}
								else
								{
									AX = AX | (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									j = j + 8;
								}
							}
							else
							{
								AX = AX | ((int) dizi[j + 7] - 48);
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'B')
				{
					//VEY-BX
					if (dizi[j + 7] == 'A')
					{
						BX = BX | AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						BX = BX | BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						BX = BX | CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						BX = BX | DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//VEY-BX-RAM
						if (dizi[j + 9] == ']')
						{
							BX = BX | RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							BX = BX | RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							BX = BX | RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//VEY-BX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									BX = BX | (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									j = j + 9;
								}
								else
								{
									BX = BX | (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									j = j + 8;
								}
							}
							else
							{
								BX = BX | ((int) dizi[j + 7] - 48);
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'C')
				{
					//VEY-CX
					if (dizi[j + 7] == 'A')
					{
						CX = CX | AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						CX = CX | BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						CX = CX | CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						CX = CX | DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//VEY-CX-RAM
						if (dizi[j + 9] == ']')
						{
							CX = CX | RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							CX = CX | RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							CX = CX | RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//VEY-CX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									CX = CX | (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									j = j + 9;
								}
								else
								{
									CX = CX | (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									j = j + 8;
								}
							}
							else
							{
								CX = CX | ((int) dizi[j + 7] - 48);
								j = j + 7;
							}
						}
					}
				}
				else if (dizi[j + 4] == 'D')
				{
					//VEY-DX
					if (dizi[j + 7] == 'A')
					{
						DX = DX | AX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'B')
					{
						DX = DX | BX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'C')
					{
						DX = DX | CX;
						j = j + 10;
					}
					else if (dizi[j + 7] == 'D')
					{
						DX = DX | DX;
						j = j + 10;
					}
					else if (dizi[j + 7] == '[')
					{
						//VEY-DX-RAM
						if (dizi[j + 9] == ']')
						{
							DX = DX | RAM[(int) dizi[j + 8] - 48];
							j = j + 10;
						}
						else if (dizi[j + 10] == ']')
						{
							DX = DX | RAM[((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
						else
						{
							DX = DX | RAM[(((int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)) *10 + ((int) dizi[j + 10] - 48)];
							j = j + 12;
						}
					}
					else
					{
						//VEY-DX-sayilar
						if (dizi[j + 7] > 47 && dizi[j + 7] < 58)
						{
							if (dizi[j + 8] > 47 && dizi[j + 8] < 58)
							{
								if (dizi[j + 9] > 47 && dizi[j + 9] < 58)
								{
									DX = DX | (((((int) dizi[j + 7] - 48) *10) + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48));
									j = j + 9;
								}
								else
								{
									DX = DX | (((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48));
									j = j + 8;
								}
							}
							else
							{
								DX = DX | ((int) dizi[j + 7] - 48);
								j = j + 7;
							}
						}
					}
				}
				else
				{
					//VEY-RAM
					if (dizi[j + 4] == '[')
					{
						if (dizi[j + 6] == ']')
						{
							//RAM[tek bsmk]
							if (dizi[j + 8] == 'A')
							{
								//VEY-RAM-AX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | AX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'B')
							{
								//VEY-RAM- BX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | BX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'C')
							{
								//VEY-RAM-CX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | CX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'D')
							{
								//VEY-RAM-DX
								RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | DX;
								j = j + 10;
							}
							else if (dizi[j + 8] == '[')
							{
								//VEY-RAM-RAM
								if (dizi[j + 10] == ']')
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | RAM[(int) dizi[j + 9] - 48];
									j = j + 11;
								}
								else if (dizi[j + 11] == ']')
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | RAM[(((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48)];
									j = j + 12;
								}
								else
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | RAM[(((int) dizi[j + 9] - 48) *100) + (((int) dizi[j + 10] - 48) *10) + ((int) dizi[j + 11] - 48)];
									j = j + 13;
								}
							}
							else
							{
								//VEY-RAM-sayilar
								if (dizi[j + 9] == (int) 10)
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | (int) dizi[j + 8] - 48;
									j = j + 9;
								}
								else if (dizi[j + 10] == (int) 10)
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | ((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else
								{
									RAM[(int) dizi[j + 5] - 48] = RAM[(int) dizi[j + 5] - 48] | (((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48);
									j = j + 11;
								}
							}
						}
						else if (dizi[j + 7] == ']')
						{
							//RAM[cift bsmk]
							if (dizi[j + 9] == 'A')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | AX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'B')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | BX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'C')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | CX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'D')
							{
								RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | DX;
								j = j + 11;
							}
							else if (dizi[j + 9] == '[')
							{
								//VEY-RAM-RAM
								if (dizi[j + 11] == ']')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | RAM[(int) dizi[j + 10] - 48];
									j = j + 12;
								}
								else if (dizi[j + 12] == ']')
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | RAM[((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | RAM[((((int) dizi[j + 10] - 48) *10) + (int) dizi[j + 11] - 48) *10 + (int) dizi[j + 12] - 48];
									j = j + 14;
								}
							}
							else
							{
								//VEY-RAM-sayilar
								if (dizi[j + 10] == (int) 10)
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | (int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else if (dizi[j + 11] == (int) 10)
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | ((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48;
									j = j + 11;
								}
								else
								{
									RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] | ((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
									j = j + 12;
								}
							}
						}
						else
						{
							//RAM[3 bsmk]
							if (dizi[j + 10] == 'A')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | AX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'B')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | BX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'C')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | CX;
								j = j + 12;
							}
							else if (dizi[j + 10] == 'D')
							{
								RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | DX;
								j = j + 12;
							}
							else if (dizi[j + 10] == '[')
							{
								//VEY-RAM-RAM
								if (dizi[j + 12] == ']')
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | RAM[(int) dizi[j + 11] - 48];
									j = j + 13;
								}
								else if (dizi[j + 13] == ']')
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] | RAM[((int) dizi[j + 11] - 48) *10 + ((int) dizi[j + 12] - 48)];
									j = j + 14;
								}
								else
								{
									RAM[(((int) dizi[j + 5] - 48) *100) + (((int) dizi[j + 6] - 48) *10) + ((int) dizi[j + 7] - 48)] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | RAM[(((int) dizi[j + 11] - 48) *100) + (((int) dizi[j + 12] - 48) *10) + ((int) dizi[j + 13] - 48)];
									j = j + 15;
								}
							}
							else
							{
								//VEY-RAM-sayilar
								if (dizi[j + 11] == (int) 10)
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | (int) dizi[j + 10] - 48;
									j = j + 11;
								}
								else if (dizi[j + 12] == (int) 10)
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | ((int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48;
									j = j + 12;
								}
								else
								{
									RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48)) *10 + (int) dizi[j + 7] - 48] = RAM[(((int) dizi[j + 5] - 48) *10 + ((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48] | (((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)) *10 + (int) dizi[j + 12] - 48;
									j = j + 13;
								}
							}
						}
					}
				}
			}

			if (dizi[j == 'V' && dizi[j + 1] == 'E'])
			{
				if (dizi[j + 3] == 'A')
				{
					//VE-AX
					if (dizi[j + 6] == 'A')
					{
						AX = AX &AX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'B')
					{
						AX = AX &BX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'C')
					{
						AX = AX &CX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'D')
					{
						AX = AX &DX;
						j = j + 9;
					}
					else if (dizi[j + 6] == '[')
					{
						//VE-AX-RAM
						if (dizi[j + 8] == ']')
						{
							AX = AX &RAM[(int) dizi[j + 7] - 48];
							j = j + 9;
						}
						else if (dizi[j + 9] == ']')
						{
							AX = AX &RAM[((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48)];
							j = j + 10;
						}
						else
						{
							AX = AX &RAM[(((int) dizi[j + 7] - 48) *10 + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
					}
					else
					{
						//VE-AX-sayilar
						if (dizi[j + 7] == (int) 10)
						{
							AX = AX &(int) dizi[j + 6] - 48;
							j = j + 7;
						}
						else if (dizi[j + 8] == (int) 10)
						{
							AX = AX &((int) dizi[j + 6] - 48) *10 + ((int) dizi[j + 7] - 48);
							j = j + 8;
						}
						else
						{
							AX = AX &((((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
							j = j + 9;
						}
					}
				}
				else if (dizi[j + 3] == 'B')
				{
					//VE-BX
					if (dizi[j + 6] == 'A')
					{
						BX = BX &AX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'B')
					{
						BX = BX &BX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'C')
					{
						BX = BX &CX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'D')
					{
						BX = BX &DX;
						j = j + 9;
					}
					else if (dizi[j + 6] == '[')
					{
						//VE-BX-RAM
						if (dizi[j + 8] == ']')
						{
							BX = BX &RAM[(int) dizi[j + 7] - 48];
							j = j + 9;
						}
						else if (dizi[j + 9] == ']')
						{
							BX = BX &RAM[((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48)];
							j = j + 10;
						}
						else
						{
							BX = BX &RAM[(((int) dizi[j + 7] - 48) *10 + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
					}
					else
					{
						//VE-BX-sayilar
						if (dizi[j + 7] == (int) 10)
						{
							BX = BX &(int) dizi[j + 6] - 48;
							j = j + 7;
						}
						else if (dizi[j + 8] == (int) 10)
						{
							BX = BX &((int) dizi[j + 6] - 48) *10 + ((int) dizi[j + 7] - 48);
							j = j + 8;
						}
						else
						{
							BX = BX &((((int) dizi[j + 6] - 48) *10) + (int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48);
							j = j + 9;
						}
					}
				}
				else if (dizi[j + 3] == 'C')
				{
					//VE-CX
					if (dizi[j + 6] == 'A')
					{
						CX = CX &AX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'B')
					{
						CX = CX &BX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'C')
					{
						CX = CX &CX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'D')
					{
						CX = CX &DX;
						j = j + 9;
					}
					else if (dizi[j + 6] == '[')
					{
						//VE-CX-RAM
						if (dizi[j + 8] == ']')
						{
							CX = CX &RAM[(int) dizi[j + 7] - 48];
							j = j + 9;
						}
						else if (dizi[j + 9] == ']')
						{
							CX = CX &RAM[((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48)];
							j = j + 10;
						}
						else
						{
							CX = CX &RAM[(((int) dizi[j + 7] - 48) *10 + (int) dizi[j + 8] - 48) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
					}
					else
					{
						//VE-CX-sayilar
						if (dizi[j + 7] == (int) 10)
						{
							CX = CX &(int) dizi[j + 6] - 48;
							j = j + 7;
						}
						else if (dizi[j + 8] == (int) 10)
						{
							CX = CX &((int) dizi[j + 6] - 48) *10 + ((int) dizi[j + 7] - 48);
							j = j + 8;
						}
						else
						{
							CX = CX &((((int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48) *10 + (int) dizi[j + 8] - 48);
							j = j + 9;
						}
					}
				}
				else if (dizi[j + 3] == 'D')
				{
					//VE-DX
					if (dizi[j + 6] == 'A')
					{
						DX = DX &AX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'B')
					{
						DX = DX &BX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'C')
					{
						DX = DX &CX;
						j = j + 9;
					}
					else if (dizi[j + 6] == 'D')
					{
						DX = DX &DX;
						j = j + 9;
					}
					else if (dizi[j + 6] == '[')
					{
						//VE-DX-RAM
						if (dizi[j + 8] == ']')
						{
							DX = DX &RAM[(int) dizi[j + 7] - 48];
							j = j + 9;
						}
						else if (dizi[j + 9] == ']')
						{
							DX = DX &RAM[((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48)];
							j = j + 10;
						}
						else
						{
							DX = DX &RAM[(((int) dizi[j + 7] - 48) *10 + ((int) dizi[j + 8] - 48)) *10 + ((int) dizi[j + 9] - 48)];
							j = j + 11;
						}
					}
					else
					{
						//VE-DX-sayilar
						if (dizi[j + 7] == (int) 10)
						{
							DX = DX &(int) dizi[j + 6] - 48;
							j = j + 7;
						}
						else if (dizi[j + 8] == (int) 10)
						{
							DX = DX &((int) dizi[j + 6] - 48) *10 + ((int) dizi[j + 7] - 48);
							j = j + 8;
						}
						else
						{
							DX = DX &(((int) dizi[j + 6] - 48) *10 + (int) dizi[j + 7] - 48) *10 + (int) dizi[j + 8] - 48;
							j = j + 9;
						}
					}
				}
				else
				{
					//VE-RAM
					if (dizi[j + 3] == '[')
					{
						if (dizi[j + 5] == ']')
						{
							//RAM[tek bsmk]
							if (dizi[j + 7] == 'A')
							{
								//VE-RAM-AX
								RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &AX;
								j = j + 9;
							}
							else if (dizi[j + 7] == 'B')
							{
								//VE-RAM- BX
								RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &BX;
								j = j + 9;
							}
							else if (dizi[j + 7] == 'C')
							{
								//VE-RAM-CX
								RAM[(int) dizi[j + 6] - 48] = RAM[(int) dizi[j + 4] - 48] &CX;
								j = j + 9;
							}
							else if (dizi[j + 7] == 'D')
							{
								//VE-RAM-DX
								RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &DX;
								j = j + 9;
							}
							else if (dizi[j + 7] == '[')
							{
								//VE-RAM-RAM
								if (dizi[j + 9] == ']')
								{
									RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &RAM[(int) dizi[j + 8] - 48];
									j = j + 10;
								}
								else if (dizi[j + 10] == ']')
								{
									RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &RAM[(((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48)];
									j = j + 11;
								}
								else
								{
									RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &RAM[(((int) dizi[j + 8] - 48) *100) + (((int) dizi[j + 9] - 48) *10) + ((int) dizi[j + 10] - 48)];
									j = j + 12;
								}
							}
							else
							{
								//VE-RAM-sayilar
								if (dizi[j + 8] == (int) 10)
								{
									RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &(int) dizi[j + 7] - 48;
									j = j + 8;
								}
								else if (dizi[j + 9] == (int) 10)
								{
									RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &((int) dizi[j + 7] - 48) *10 + (int) dizi[j + 8] - 48;
									j = j + 9;
								}
								else
								{
									RAM[(int) dizi[j + 4] - 48] = RAM[(int) dizi[j + 4] - 48] &(((int) dizi[j + 7] - 48) *100) + (((int) dizi[j + 8] - 48) *10) + ((int) dizi[j + 9] - 48);
									j = j + 10;
								}
							}
						}
						else if (dizi[j + 6] == ']')
						{
							//RAM[cift bsmk]
							if (dizi[j + 8] == 'A')
							{
								RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &AX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'B')
							{
								RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &BX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'C')
							{
								RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &CX;
								j = j + 10;
							}
							else if (dizi[j + 8] == 'D')
							{
								RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &DX;
								j = j + 10;
							}
							else if (dizi[j + 8] == '[')
							{
								//VE-RAM-RAM
								if (dizi[j + 10] == ']')
								{
									RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &RAM[(int) dizi[j + 9] - 48];
									j = j + 11;
								}
								else if (dizi[j + 11] == ']')
								{
									RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &RAM[((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48];
									j = j + 12;
								}
								else
								{
									RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &RAM[((((int) dizi[j + 9] - 48) *10) + (int) dizi[j + 10] - 48) *10 + (int) dizi[j + 11] - 48];
									j = j + 13;
								}
							}
							else
							{
								//VE-RAM-sayilar
								if (dizi[j + 9] == (int) 10)
								{
									RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &(int) dizi[j + 8] - 48;
									j = j + 9;
								}
								else if (dizi[j + 10] == (int) 10)
								{
									RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &((int) dizi[j + 8] - 48) *10 + (int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else
								{
									RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] = RAM[((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48] &((((int) dizi[j + 8] - 48) *10) + (int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48;
									j = j + 11;
								}
							}
						}
						else
						{
							//RAM[3 bsmk]
							if (dizi[j + 9] == 'A')
							{
								RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &AX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'B')
							{
								RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &BX;
								j = j + 11;
							}
							else if (dizi[j + 9] == 'C')
							{
								RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &CX;
								j = j + 12;
							}
							else if (dizi[j + 9] == 'D')
							{
								RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &DX;
								j = j + 11;
							}
							else if (dizi[j + 9] == '[')
							{
								//VE-RAM-RAM
								if (dizi[j + 11] == ']')
								{
									RAM[(((int) dizi[j + 4] - 48) *100) + (((int) dizi[j + 5] - 48) *10) + ((int) dizi[j + 6] - 48)] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &RAM[(int) dizi[j + 10] - 48];
									j = j + 12;
								}
								else if (dizi[j + 12] == ']')
								{
									RAM[(((int) dizi[j + 4] - 48) *100) + (((int) dizi[j + 5] - 48) *10) + ((int) dizi[j + 6] - 48)] = RAM[(((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] &RAM[((int) dizi[j + 10] - 48) *10 + ((int) dizi[j + 11] - 48)];
									j = j + 13;
								}
								else
								{
									RAM[(((int) dizi[j + 4] - 48) *100) + (((int) dizi[j + 5] - 48) *10) + ((int) dizi[j + 6] - 48)] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &RAM[(((int) dizi[j + 10] - 48) *100) + (((int) dizi[j + 11] - 48) *10) + ((int) dizi[j + 12] - 48)];
									j = j + 14;
								}
							}
							else
							{
								//VE-RAM-sayilar
								if (dizi[j + 10] == (int) 10)
								{
									RAM[(((int) dizi[j + 4] - 48) *10 + (int) dizi[j + 5] - 48) *10 + (int) dizi[j + 6] - 48] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &(int) dizi[j + 9] - 48;
									j = j + 10;
								}
								else if (dizi[j + 11] == (int) 10)
								{
									RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48)) *10 + (int) dizi[j + 6] - 48] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &((int) dizi[j + 9] - 48) *10 + (int) dizi[j + 10] - 48;
									j = j + 11;
								}
								else
								{
									RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48)) *10 + (int) dizi[j + 6] - 48] = RAM[(((int) dizi[j + 4] - 48) *10 + ((int) dizi[j + 5] - 48) *10) + (int) dizi[j + 6] - 48] &(((int) dizi[j + 9] - 48) *10 + ((int) dizi[j + 10] - 48)) *10 + (int) dizi[j + 11] - 48;
									j = j + 12;
								}
							}
						}
					}
				}
			}

			j++;
		}

		printf("AX=%d\n", AX);
		printf("BX=%d\n", BX);
		printf("CX=%d\n", CX);
		printf("DX=%d\n", DX);
		for (k = 0; k < 256; k++)
		{
			if (RAM[k] != -1)
			{
				printf("RAM=%d\n", RAM[k]);
			}
		}
	}
}
