#include <stdio.h>

//     EXERCITIUL 2
// int main() {
//     float pret, pret_final;
//     int cod;

//     printf("Introduceti pretul produsului: ");
//     scanf("%f", &pret);

//     printf("Introduceti codul de reducere (1 - 10%%, 2 - 20%%, 3 - 30%%): ");
//     scanf("%d", &cod);

//     // Aplicăm reducerea în funcție de cod
//     if (cod == 1) {
//         pret_final = pret * 0.9;  // Reducere de 10%
//     } else if (cod == 2) {
//         pret_final = pret * 0.8;  // Reducere de 20%
//     } else if (cod == 3) {
//         pret_final = pret * 0.7;  // Reducere de 30%
//     } else {
//         printf("Cod invalid! Nu se aplica reducere.\n");
//         pret_final = pret;
//     }

//     printf("Pretul final este: %.2f\n", pret_final);

//     return 0;
// }


//     EXERCITIUL 3
// #include <stdio.h>

// int main() {
//     float salariu_brut, salariu_net, impozit;
//     int cod;

//     printf("Cod 1: salariu pentru angajat full-time\n");
//     printf("Cod 2: Salariu pentru contract de colaborare\n");
//     printf("Cod 3: Salariu pentru PFA\n");
//     printf("Alegeti un cod (1-3): \n");
//     scanf("%i", &cod);  

//     printf("Introduceti salariul brut: ");  
//     scanf("%f", &salariu_brut);  

   
//     if(cod == 1) {
//         impozit = 0.25; 
//         salariu_net = salariu_brut - (salariu_brut * impozit);
//         printf("Salariu pentru angajat full-time: %.2f\n", salariu_net);
//     }
//     else if(cod == 2) {
//         impozit = 0.1;  
//         salariu_net = salariu_brut - (salariu_brut * impozit);
//         printf("Salariu pentru contract de colaborare: %.2f\n", salariu_net);
//     }
//     else if(cod == 3) {
//         impozit = 0.05;  
//         salariu_net = salariu_brut - (salariu_brut * impozit);
//         printf("Salariu pentru PFA: %.2f\n", salariu_net);
//     }
//     else {
//         printf("ERROR!! INVALID CODE!\n");
//     }

//     return 0;
// }
