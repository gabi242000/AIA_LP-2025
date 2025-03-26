//  Exercitiul 1:
 #include <stdio.h>

 int main()
 {
     int n;
     printf("Introdu dimensiunea matricei: ");
     scanf("%d", &n);
     int a[n][n]
     printf("Introdu elementele matricei: ");
     for (int i=0; i<n; i++){
         int s=0;
         for(int j=0; j<n; j++){
             scanf("%d", &a[i][j]);
             s=s+a[i][j];
         }
     }
}