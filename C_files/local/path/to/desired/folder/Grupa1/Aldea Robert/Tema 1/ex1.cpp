#include <iostream>
using namespace std;
int n;
int main()
{
    cout << "Introduceti nota : ";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "Foarte dezamagitor!";
        break;

    case 2:
        cout << "Dezamagitor!";
        break;
    case 3:
        cout << "Rau!";
        break;
    case 4:
        cout << "Slab!";
        break;
    case 5:
        cout << "Satisfacator!";
        break;
    case 6:
        cout << "Decent!";
        break;
    case 7:
        cout << "Binisor!";
        break;
    case 8:
        cout << "Foarte bine!";
        break;
    case 9:
        cout << "Excelent!";
        break;
    case 10:
        cout << "Perfect!";
        break;
    default:
        cout << "Nu ai dat testul!";
        break;
    }
    return 0;
}