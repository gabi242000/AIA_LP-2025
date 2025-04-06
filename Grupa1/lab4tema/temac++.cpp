#include <iostream>
#include <vector>

using namespace std;

void ex1()
{
    int N , sum_max[2]={0,0};
    cin>>N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for(int i=0;i<N;i++)
    {
        int sum = 0;
        for(int j=0;j<N;j++)
        {
            cin>>matrix[i][j];
            sum+=matrix[i][j];
        }
        if(sum>sum_max[0])
        {
            sum_max[0]=sum;
            sum_max[1]=i;
        }
    }
    cout<<"Linia cu suma maxima este: "<<sum_max[1]+1<<" si suma este: "<<sum_max[0]<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<matrix[sum_max[1]][i]<<" ";
    }
}

void ex2()
{
    //daca e sub 1000 de numere daca nu ura si la gara :))
    int n, fr[1000]={0};
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        fr[v[i]]++;
    }
    for(int i = 0 ; i < 1000 ; i++)
    {
        if(fr[i]>=1)
        {
            cout<<i<<" ";
        }
    }
}

void ex3()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    int j = 0;
    for(int i = 0 ; i < n ; i++)
    {
        j=i;
        for(int cva = 0 ; j < n ; j++)
        {
            matrix[i][j]=i+j+1;
        }        
    }
    int i = 0;
    for(int cva = 0 ; i < n ; i++)
    {

        for(int j = 0 ; j <= i ; j++)
        {

            matrix[i][j]=matrix[j][i];
        }        
    }
    cout<<"Matricea folosind modelul deasupra diagonalei principale este: \n";
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void ex4()
{
    int n;
    cin>>n;
    bool t = false;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin>>matrix[i][j];
        }
    }
    for(int i = 1 ; i < n-1 ; i++)
    {
        for(int j = 1 ; j < n-1 ; j++)
        {
            if(matrix[i][j]>matrix[i-1][j] && matrix[i][j]>matrix[i+1][j] && matrix[i][j]>matrix[i][j-1] && matrix[i][j]>matrix[i][j+1])
                cout<<matrix[i][j]<<" ";
                t = true;
        }
    }
    if(t == false)
    {
        cout<<"Nu exista elemente care sa fie strict mai mari decat vecinii lor";
    }
}
int main()
{
    int x;
    while(true)
    {
        cout<<endl;
        cout<<"Introduceti nr exercitiului: ";
        cin>>x;
        switch(x)
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
                cout<<"Invalid input";
        }

    }
    return 0;
}