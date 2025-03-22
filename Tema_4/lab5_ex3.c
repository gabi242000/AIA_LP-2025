#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char s[101],c1,c2;
    int i,cv=1,vocala1,vocala2,l;
    printf("Introdu un cuvant pentru a-l verifica daca este 'frumos':\n");
    fgets(s,101,stdin);
    s[strcspn(s,"\n")]=0;
    l=strlen(s);
    for(i=0;s[i]!='\0';i++)
    {
        c1=s[i];
        c2=s[i+1];
        vocala1=(c1=='a'||c1=='e'||c1=='i'||c1=='o'||c1=='u');
        vocala2=(c2=='a'||c2=='e'||c2=='i'||c2=='o'||c2=='u');     
    
    if(vocala1==vocala2)
    {   cv=0;
        break;
    }
}
    if(s[0]=='z' && l%2==0 && cv==1)
        printf("Cuvantul introdus este 'frumos' ");
    else
        printf("Cuvantul introdus nu este 'frumos' ");
    return 0;
}