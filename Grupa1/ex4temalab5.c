#include <stdio.h>
#include <ctype.h>

void cifra_cezar(char *text, int p){
    for(int i=0; text[i]!='\0';i++){
        if(isalpha(text[i])){
            char baza;
            if(islower(text[i])){
                baza='a';
            }else{ 
                baza='A';
            }
            text[i]=baza+(text[i]-baza+p)%26;
        }
    }
}

int main(){
    char text[100];
    int p;
    printf("Introduceti sirul format din litere mici si mari: ");
    fgets(text, sizeof(text), stdin);
    printf("Introduceti un numar natural 'p': ");
    scanf("%d", &p);

    cifra_cezar(text,p);
    printf("%s", text);

    return 0;
}