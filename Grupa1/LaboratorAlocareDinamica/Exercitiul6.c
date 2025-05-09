        #include <stdio.h>
        #include <string.h>
        #include <stdlib.h>

        int main(){
            char *A,*B,*C;
            int nr_caractere1,nr_caractere2;

            scanf("%d",&nr_caractere1);
            scanf("%d",&nr_caractere2);

            A = (char*)malloc(nr_caractere1 * sizeof(char));
            if(A == NULL){
                printf("Eroare la alocarea memoriei pentru primul cuvant\n");
                return 1;
            }
            B = (char*)malloc(nr_caractere2 * sizeof(char));
            if(B == NULL){
                printf("Eroare la alocarea memoriei pentru al doilea cuvant\n");
                return 1;
            }

            C = (char*)malloc((nr_caractere1+nr_caractere2) * sizeof(char));

            for(int i=0;i<nr_caractere1;i++)
                scanf(" %c",&A[i]);

            for(int i=0;i<nr_caractere2;i++)
                scanf(" %c",&B[i]);
                

            strcpy(C,strcat(A,B));

            printf("%s",C);

            free(A);
            free(B);
            free(C);
            



        }