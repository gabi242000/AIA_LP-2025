#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char sir[100];
    gets(sir);
    char *cuvant=strtok(sir," ");
    int i=1;
    while(cuvant){
        if(cuvant[0]=='z' && strlen(cuvant)%2==0){
            int ok1=1,ok2=1;

            for(int i=0;i<=strlen(cuvant);i+=2){
                if(strchr("aeiou",cuvant[i])==0){
                    ok1=0;
                }
            }

            for(int i=1;i<=strlen(cuvant);i+=2){
                if(strchr("aeiou",cuvant[i])==0){
                    ok2=0;
                }
            }
            if(ok1||ok2) printf("cuvantul nr %d este frumos (%s)\n", i,cuvant);
        

        }
        i++;
        cuvant=strtok(NULL, " ");

    }

    
    return 0;
}