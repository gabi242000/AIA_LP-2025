#include <iostream>
#include <vector>

using namespace std;

void sortareVector(int v[] , int n)
{
    

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int cautareBinara(int v[], int n, int x)
{
    int st = 0;
    int dr = n - 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (v[mij] == x)
        {
            cout << "Elementul " << x << " se afla pe pozitia " << mij << endl;
            return mij;
        }
        else if (v[mij] < x)
        {
            st = mij + 1;
        }
        else
        {
            dr = mij - 1;
        }
    }
    cout << "Elementul nu a fost gasit!" << endl;
    return -1;
}
int main()
{
    cout<<"Selecteaza exercitiul: ";
    int ex;
    while(true)
    {
        cin>>ex;
        switch (ex)
        {
            case 1:
            {
                int n;
                cin>>n;
                int v[n];
                for(int i=0; i<n; i++)
                {
                    cin>>v[i];
                }

                sortareVector(v , n);
                cout<<"Elementul cautat este:";
                int x;
                cin>>x;
                cautareBinara(v , n, x);
                break;
            }
            case 2:
            {
                cout<<"Exercitiul 2"<<endl;
                break;
            }
            case 3:
            {
                cout<<"Exercitiul 3"<<endl;
                break;
            }
            default:
                cout<<"Exercitiul nu exista!"<<endl;
        }
    }
    return 0;
}