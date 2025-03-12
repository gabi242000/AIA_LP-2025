# include <stdio.h>

int main()
{   int salariu_brut,salariu_net, varianta; 
    printf("Introduceti salariul brut: ");
    scanf("%d", &salariu_brut);
    printf("Alegeti tipul de salariu pentru fiecare contract din urmatoarele variante: \n");
    printf("1. Salariu pentru angajat full-time\n");
    printf("2. Salariu pentru contract de colaborare\n");
    printf("3. Salariu pentru PFA\n");
    printf("Introduceti varianta aleasa:");
    scanf("%d", &varianta);
    switch (varianta)
    { case 1: salariu_net= salariu_brut-(salariu_brut*0.25);
        printf("Salariul net este %d", salariu_net);
        break;
    case 2: salariu_net= salariu_brut-(salariu_brut*0.1);
        printf("Salariul net este %d", salariu_net);
        break;
    case 3: salariu_net= salariu_brut-(salariu_brut*0.05);
        printf("Salariul net este %d", salariu_net);
        break;
    default: printf("Nu ati introdus o varianta valida!");
    break;

    }
    return 0;
}