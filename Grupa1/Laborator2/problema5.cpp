#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    switch (x)
    {
    case 10:
        cout<<"Excelent";
        break;
    case 9:
        cout<<"Foarte bine";
        break;
    case 8:
        cout<<"Bine";
        break;
    case 7:
        cout<<"Binisor";
        break;
    case 6:
        cout<<"Acceptabil";
        break;
    case 5:
        cout<<"Satisfacator";
        break;
    case 4:
        cout<<"Nesatisfacator";
        break;
    case 3:
        cout<<"Insuficient";
        break;
    case 2:
        cout<<"Inadecvat";
        break;
    case 1:
        cout<<"Inacceptabil";
        break;
    default:
        break;
    }
    return 0;
}
