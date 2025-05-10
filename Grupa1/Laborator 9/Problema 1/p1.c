/**
Scrie o funcție recursivă care primește un număr natural n și îl returnează cu cifrele în 
ordine inversă.Funcția trebuie să extragă ultima cifră a numărului (n % 10) și să 
construiască recursiv restul.Se poate transmite un parametru suplimentar pentru a construi 
rezultatul (ex: int invers(int n, int acc)). 
**/
#include <stdio.h>

int invers (int n, int m){
    m = m + n%10;
    if (n/10 == 0) return m;
    else return invers(n/10, m*10);
}

int main(){
    int n, inv = 0, ceva;
    printf("Introdu numarul pe care vrei sa il inversezi: ");
    scanf("%d", &n); 
    printf("Numarul inversat este: %d", invers(n, inv));
    return 0;
}