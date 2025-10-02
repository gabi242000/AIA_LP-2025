#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *v, *v2,ma,cnt=0,s=0,cnt_v2=0;
    scanf("%d",&n);

    v = (int*)malloc(n*sizeof(int));
    if(v == NULL){
        printf("Eroare la alocarea memoriei pentru vectorul v");
        return 1;
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        cnt++;
        s+=v[i];
    }

    ma = (int)s/cnt;

    v2 = (int*)malloc(n* sizeof(int));
    if(v2==NULL){
        printf("Eroare la alocarea memoriei pentru vectorul v2");
        return 1;
    }

    for(int i=1;i<=n;i++)
        if(v[i]>=ma) {
            cnt_v2++;
            v2[cnt_v2] =v[i];
        }

    for(int i=1;i<=cnt_v2;i++)
        printf("%d ", v2[i]);
}