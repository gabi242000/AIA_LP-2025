int cmmdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return cmmdc(b, a % b);
}

int main() {
    int a, b;
    
    printf("a: ");
    scanf("%d", &a);
    
    printf("b: ");
    scanf("%d", &b);
    
    int rezultat = cmmdc(a, b);
    
    printf("CMMDC dintre  %d si %d este: %d\n", a, b, rezultat);
    
    return 0;
}