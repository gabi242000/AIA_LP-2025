#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v,*vnou;
    int n,i,s=0;
    int contor=0;
    float ma;
    printf("Introdu nr de elemente: ");
    scanf("%d",&n);
    v=(int*)malloc(n * sizeof(int));
    if(v == NULL){
        printf("Eroare la alocarea memoriei vectorului\n");
        return 1;
    }
    printf("Introduceti elementele vectorului: \n");
    for(int i=0; i<n; i++){
        printf("v[%d]= ",i);
        scanf("%d",&v[i]);
     }
    for(i=0; i<n; i++) s=s+v[i];
    ma=(float)s/n;
    printf("Media aritmetica= %.2f\n",ma);
    vnou=(int*)malloc(n * sizeof(int));
    if(vnou == NULL){
        printf("Eroare la alocarea memoriei vectorului nou\n");
        return 1;
    }
    for(i=0;i<n;i++) if(v[i]>=(int)ma) {
        vnou[contor]=v[i];
        contor++;
    }
    printf("Valorile din vector mai mari sau egale cu media aritmetica sunt: ");
    for(i=0;i<contor;i++) printf("%d ",vnou[i]);
    free(v);
    free(vnou);
    return 0;
}


