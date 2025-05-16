#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *s1, *s2, *s3;
    s1=(char*)malloc(30 * sizeof(char));
    if(s1==NULL){
        printf("eroare la alocare memorie sir 1.");
        return 1;
    }
    s2=(char*)malloc(30 * sizeof(char));
    if(s1==NULL){
        printf("eroare la alocare memorie sir 2.");
        return 1;
    }
    printf("introdu primul sir: ");
    scanf("%s",s1);
    printf("introdu al doilea sir: ");
    scanf("%s",s2);
    s3=(char*)malloc(30 * sizeof(char));
    if(s1==NULL){
        printf("eroare la alocare memorie sir 3.");
        return 1;
    }
    s3=strcat(s1,s2);
    printf("Concatenarea celor 2 siruri ese: %s",s3);
    free(s1);
    free(s2);
    free(s3);
    return 0;

}