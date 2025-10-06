#include <stdio.h>
#include <string.h>
#include <ctype.h>


// EXERCITIUL 1
// int main() {

//     char s[101];

//     printf("introduceti un sir de caractere: ");

//     fgets(s, sizeof(s), stdin);

//     for(int i = 0; s[i] != '\0'; i++){
//         s[i] = toupper(s[i]);
//     }

//     printf("sir in majuscule: %s", s);
   
//     return 0;
// }

// EXERCITIUL 2
// int main(){

//     char s[101];
//     int x, y, z;

//     printf("introduceti, va rog frumos, un cuvant format din litere mici: ");

//     fgets(s, sizeof(s), stdin);
//     s[strcspn(s, "\n")] = 0;
//     printf("%s", s);

//     printf("ce pozitii vreti sa schimbati (incepe de la 0 la n - 1): ");
//     scanf("%d %d", &x, &y); 
//     printf("%d, %d \n", x, y);

//     if(x >= 0 && x < strlen(s) && y >=0 && y < strlen(s)){
//         z = s[x];
//         s[x] = s[y];
//         s[y] = z;
//     }
//     else{
//         printf("te rog alege din intervalul [0, n-1]\n");
//     }
    
//     printf("%s", s);

//     return 0;
// }

// EXERCITIUL 3
// int verfic_cuvant(char s[]);

// int main(){

//     char s[101];

//     printf("Scrie un cuvant: ");
//     fgets(s, sizeof(s), stdin);
//     s[strcspn(s, "\n")] = 0;

//     if(verfic_cuvant(s) == 1 && strlen(s) % 2 == 0){
//         printf("Cuvantul este frumos!");
//     }
//     else
//     {
//         printf("Cuvantul este urat!");
//     }
    
//     return 0;
// }

// int verfic_cuvant(char s[]){

//     if(s[0] == 'z'){
//         for(int i = 0; s[i] != '\0'; i+=2){
//             if(strchr("aeiou", s[i]))
//             return 0;
//         }

//         for(int i = 1; s[i] != '\0'; i+=2){
//             if(!strchr("aeiou", s[i]))
//             return 0;
//         }

//     }
//     else {
//         return 0;
//     }

//     return 1;
// }

// EXERCITIUL 4

// int main(){

//     char s[101], *c;
//     int p;

//     printf("Scrie un enunt si alege o valoare p: \n");
//     fgets(s, 101, stdin);
//     s[strcspn(s, "\n")] = '\0';

//     scanf("%d", &p); 

//     c = strtok(s, " ");  

//     printf("Textul criptat cu ajutorul codului Cezar este: \n");
//     while(c != NULL){
//         for(int i = 0; c[i] != '\0'; i++)

//         if((islower(c[i]) && (int)c[i] + p > 'z') || (isupper(c[i]) && (int)c[i] + p > 'Z'))
//         {
//             c[i] = (char)((int)c[i] - 26 + p);
//         }
//         else
//         {
//             c[i] = (char)(c[i] + p);
//         }

//         printf("%s ", c);
//         c = strtok(NULL, " ");
//     }

//     return 0;

// }
