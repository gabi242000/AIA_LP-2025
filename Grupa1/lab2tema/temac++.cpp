#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<endl;
    cout << "Nota :";
    cin >> n;
    if(n == 10)
        cout<<"Excelent";
    else if(n < 10 && n >= 5)
        cout<<"Satisfacator";
    else if(n < 5)
        cout<<"Insuficient";
    return 0;
}