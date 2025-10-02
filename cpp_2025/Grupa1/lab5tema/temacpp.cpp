#include <iostream>
#include <cstring>
using namespace std;

void ex1()
{
    char s[100];
    cout<<"Introdu sirul de caractere: ";
    cin.getline(s, 100);
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
    cout<<"Sirul de caractere in majuscule: "<<s;
}

void ex2()
{
    char v[100];
    cout<<"Introdu sirul de caractere: ";
    cin.getline(v, 100);
    int x , y;
    cout<<"Introdu x si y: ";
    cin>>x>>y;
    v[x] += v[y];
    v[y] = v[x] - v[y];
    v[x] = v[x] - v[y];
    cout<<"Sirul de caractere dupa interschimbare: "<<v;
}

void ex3()
{
    bool ok = true;
    char s[100];
    cout<<"Introdu cuvantul: ";
    cin.getline(s, 100);
    int n = strlen(s);
    if(n % 2 == 0 && s[0] == 'z')
    {
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 1)
            {
                if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    ok = false;
                    break;
                }
            }
        }
    }
    else
        ok = false;
    if(ok)
        cout<<"Cuvantul este frumos";
    else
        cout<<"Cuvantul nu este frumos";
}

void ex4()
{
    //trebuia cu strtok ? nu am simitit nevoia
    int n;
    char s[100];
    cout<<"Introduceti nr cu care encriptezi mesajul: ";
    cin>>n;
    cin.ignore();
    cout<<"Introduceti mesajul: ";
    cin.getline(s, 100);
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] + n;
            if(s[i] > 'z')
                s[i] = s[i] - 26;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + n;
            if(s[i] > 'Z')
                s[i] = s[i] - 26;
        }
    }
    cout<<"Mesajul encriptat: "<<s;
}

int main()
{
    while(true)
    {
        cout<<endl;
        int x;
        cout<<"Introdu numarul de exercitiului: ";
        cin>>x;
        cin.ignore();
        switch (x)
        {
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        case 4:
            ex4();
            break;
        default:
            break;
        }
    }
    return 0;
}