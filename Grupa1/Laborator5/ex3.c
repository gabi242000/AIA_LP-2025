#include <stdio.h>
#include <string.h>
int main()
{
    char cuv[51], voc[]="aeiou";
    bool ok=true;
    fgets(cuv,50,stdin);
    if(cuv[0]!='z')
        printf("cuvantul nu e frumos");
    else if(strlen(cuv)%2==0 )
        printf("cuvantul nu e frumos");
    else
        {
            for(int i=0;i<strlen(cuv)-1;i++)
                if((strchr(voc, cuv[i])!=NULL && strchr(voc,cuv[i+1])!=NULL) or (strchr(voc, cuv[i])==NULL && strchr(voc,cuv[i+1])==NULL) )
                    {ok=false;
                        break;
                    }
            if(ok==true)
                printf("cuvantul e frumos");
            else
                printf("cuvantul nu e frumos");
                }    
    return 0;
}
