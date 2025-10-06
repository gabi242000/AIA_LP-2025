#include <iostream>
#include <cstring>
using namespace std;
char c;
int main()
{
    ///Ex1
    /*int n;
    cin >> n;
    for (int i = 2 ; i<= n ; i+=2)
    {
        cout << i << " ";

    }
        */
    ///Ex2.
    /*
    int n;
    int f=0,r=1;
    cin >> n;
    n = n - 2;
    if (n == 2)
    cout << f << r << r;
    else{
        cout << f<<" "<< r << " ";
        f = r; 
    for (int i = 1; i<= n;i++)
    {
        int x;
        x = f+r;
        cout << x << " ";
        f = r;
        r = x; 

    }
    */
   ///Ex3.
   /*
   char v[100][100];
   int n;
   cin >>n;
    v[1][50]= c ;
   for (int i = 2 ; i<=n;i++)
   {
    for (int j = 1; j<=n;j++)
    {
        if( j < n/2 - 1 || j> n/2 - 1)
        v[i][j] = c ;
    }
   }
   for (int i = 1; i<= n ; i++)
    for (int j = 1;j<=n;j++)
    cout << v[i][j];
   return 0;
   */
}
  
    
