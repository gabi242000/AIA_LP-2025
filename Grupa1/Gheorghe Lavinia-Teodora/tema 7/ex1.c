#include <stdio.h>

using namespace std;

int nr_invers(int n, int inv) {
    if (n == 0) return inv;
    return nr_invers(n / 10, inv * 10 + n % 10);
}


int main() {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    int invv = nr_invers(n, 0);
    printf("Numarul inversat este: %d", invv);

    return 0;
}
