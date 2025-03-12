# include <stdio.h>
 int main()
 {
    float pret,pret_final;
    int cod_reducere;
    printf("Introduceti pretul: ");
    scanf("%f", & pret);
    printf("Introduceti un cod de reducere (1, 2 sau 3): ");
    scanf("%d", & cod_reducere);
    printf("Pretul introdus este %.2f lei\n",pret);
    printf("Ati ales codul de reducere %d\n",cod_reducere);
    switch (cod_reducere)
    { 
      case 1: 
      pret_final=pret-pret*0.1;
      printf("Pretul final este %.2f lei \n",pret_final);
      break;
      case 2: 
      pret_final=pret-pret*0.2;
      printf("Pretul final este %.2f lei \n",pret_final);
      break; 
      case 3: 
      pret_final=pret-pret*0.3;
      printf("Pretul final este %.2f lei \n",pret_final);
      break;
      default: printf("Ati introdus un cod de reducere invalid.");
    }
    return 0;

 }