#include <stdio.h>

int main()
{
    int n;
	printf("Introduceti nota primita: ");
	scanf("%d", &n);
	while (n < 1 || n >10)
	{
		printf("Nota %d nu este acceptabila. Va rugam introduceti o nota intre 0 si 10\nNota primita: ");
		scanf("%d",&n);
	}
	switch(n)
	{
		case 1:
			printf("Jalnic... foarte jalnic... U_U");
			break;
		case 2:
			printf("OOoooof... ce ai facut... ;-;");
			break;
		case 3:
			printf("Nuuuuu! Hai ma puteai mai mult! >:(");
			break;
		case 4: 
			printf("CE?? UN PUNCT MAI aveai!!! Un punct pentru trecere!! X000");
			break;
		case 5:
			printf("DA!!! Macar ai trecut! Bravo!! :DDD");
			break;
		case 6:
			printf("OhohoHOOO, macar nu e 5!!! Bineee!! >:DDD");
			break;
		case 7:
			printf("AH, sfantul si norocosul numar 7! Excelent, domne! UwU");
			break;
		case 8:
			printf("OHOHOOOO! Stati asa, fiti pe faza! Tocmai utilizatorul asta a intrat in scara infinitului al intelectualitatii!!! FELICITARI!!! O 0 O");
			break;
		case 9:
			printf("DAAAAAAAA!!! SUNTEM IN LIGA!!! BRAVO, RUPE-I, TATA!!! >:000000");
			break;
		case 10:
			printf("EEEEXCELEEEEEEEENT!!!! IMPERIAL!!!\nSuntem pe SPATE, BAIETI! CHAT! AVEM PESTE CINCI MII DE OAMENI PE LIVE!!! :DDDDDD\n\nFun fact: Str3su a facut si el hidrotehnica ;)))");
			break;
	}
	return 0;
}
