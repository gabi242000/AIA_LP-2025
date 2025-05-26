#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_BILETE 10
#define NUME_MAX 50
int verifica_format_data(const char *data) {
    int zi, luna, an;
    if (sscanf(data, "%d-%d-%d", &zi, &luna, &an) == 3 &&
        zi >= 1 && zi <= 31 &&
        luna >= 1 && luna <= 12 &&
        an >= 1000 && an <= 9999) {
        return 1;
    }
    return 0;
}

int main() {
    char nume[MAX_BILETE][NUME_MAX];
    int numar_bilet[MAX_BILETE];
    char date[MAX_BILETE][20];
    char mijloc_transport[MAX_BILETE][20];
    char destinatii[MAX_BILETE][50];
    int numar_bilete_cumparate = 0;
    int optiune;

    int locuri_disponibile[3][5] = {
        {3, 12, 1, 29, 30}, 
        {4, 7, 47, 33, 1}, 
        {22, 3, 6, 19, 25}  
    };

    while (1) {
        printf("\nSistem de cumpărare bilete\n");
        printf("1. Cumpără un bilet\n");
        printf("2. Vizualizează biletele cumpărate\n");
        printf("3. Iesire\n");
        printf("Alege o opțiune: ");
        scanf("%d", &optiune);

        if (optiune == 1) {
            if (numar_bilete_cumparate >= MAX_BILETE) {
                printf("Nu mai sunt locuri disponibile!\n");
                continue;
            }

            char data[20];
            printf("\nIntroduce data dorită pentru cumpărare : ");
            scanf("%s", data);

            if (!verifica_format_data(data)) {
                printf("Data NU este în formatul corect DD-MM-YYYY.\n");
                continue;
            }

            int tip_transport;
            printf("\nSelectează tipul de transport:\n");
            printf("1. Tren\n");
            printf("2. Avion\n");
            printf("3. Autocar\n");
            printf("Alege o opțiune: ");
            scanf("%d", &tip_transport);

            if (tip_transport < 1 || tip_transport > 3) {
                printf("Opțiune de transport invalidă.\n");
                continue;
            }

            int destinatie;
            char transport[20];
            char lista_destinatii[5][50];

            if (tip_transport == 1) {
                strcpy(transport, "Tren");
                strcpy(lista_destinatii[0], "București - 08:00");
                strcpy(lista_destinatii[1], "Cluj - 09:30");
                strcpy(lista_destinatii[2], "Brașov - 11:00");
                strcpy(lista_destinatii[3], "Iași - 13:45");
                strcpy(lista_destinatii[4], "Timișoara - 17:20");
            } else if (tip_transport == 2) {
                strcpy(transport, "Avion");
                strcpy(lista_destinatii[0], "Paris - 06:00");
                strcpy(lista_destinatii[1], "Londra - 08:15");
                strcpy(lista_destinatii[2], "Roma - 10:30");
                strcpy(lista_destinatii[3], "Berlin - 14:00");
                strcpy(lista_destinatii[4], "Madrid - 18:45");
            } else {
                strcpy(transport, "Autocar");
                strcpy(lista_destinatii[0], "Sibiu - 07:00");
                strcpy(lista_destinatii[1], "Oradea - 10:00");
                strcpy(lista_destinatii[2], "Constanța - 12:30");
                strcpy(lista_destinatii[3], "Suceava - 15:15");
                strcpy(lista_destinatii[4], "Craiova - 19:00");
            }
            printf("\nDestinații disponibile (%s):\n", transport);
            for (int i = 0; i < 5; i++) {
                printf("%d. %s - Locuri disponibile: %d\n", i + 1, lista_destinatii[i], locuri_disponibile[tip_transport - 1][i]);
            }
            printf("Alege destinația: ");
            scanf("%d", &destinatie);

            if (destinatie < 1 || destinatie > 5) {
                printf("Destinație invalidă.\n");
                continue;
            }
            int nr_bilete;
            printf("Câte bilete dorești să cumperi? ");
            scanf("%d", &nr_bilete);

            if (nr_bilete > locuri_disponibile[tip_transport - 1][destinatie - 1]) {
                printf("Nu sunt suficiente locuri disponibile pentru %d bilete.\n", nr_bilete);
                continue;
            }
            for (int i = 0; i < nr_bilete; i++) {
                int index = numar_bilete_cumparate + i;
                printf("Introduceți numele pentru biletul #%d: ", i + 1);
                scanf("%s", nume[index]);
                strcpy(date[index], data);
                strcpy(mijloc_transport[index], transport);
                strcpy(destinatii[index], lista_destinatii[destinatie - 1]);
                numar_bilet[index] = index + 1;
                printf("Bilet cumpărat cu succes! Număr bilet: %d\n", numar_bilet[index]);
            }
            numar_bilete_cumparate += nr_bilete;
            locuri_disponibile[tip_transport - 1][destinatie - 1] -= nr_bilete;
        } else if (optiune == 2) {
            if (numar_bilete_cumparate == 0) {
                printf("Nu sunt bilete cumpărate.\n");
            } else {
                printf("\nBilete cumpărate:\n");
                for (int i = 0; i < numar_bilete_cumparate; i++) {
                    printf("Biletul #%d – %s, la data de %s, cu %s, către %s\n",
                        numar_bilet[i], nume[i], date[i], mijloc_transport[i], destinatii[i]);
                }
            }

        } else if (optiune == 3) {
            printf("La revedere!\n");
            break;
        } else {
            printf("Opțiune invalidă!\n");
        }
    }

    return 0;
}
