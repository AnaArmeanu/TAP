#include <iostream>
#include<vector>
#include<fstream>
using namespace std;


ifstream f("date.in");
ofstream g("date.out");

int cautare_binara(int n, vector<int> V)
{
    int st = 0;
    int dr = n-1;
    int m;
    while(st<=dr)
    {
        m=(st+dr)/2;

        if(m==V[m])
            return m;
        else
        {
            if(V[m]<m)
                st=m+1;
            else
                dr=m-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    f>>n;

    int i;
    vector<int>V;
    for(i=0;i<n;i++)
    {
        int x;
        f>>x;
        V.push_back(x);
    }
    int y=cautare_binara(n,V);
    if(y>0)
    {
        g<<y;
        cout<<y;
    }
    else
    {
        g<<"Nu exista un astfel de element.";
        cout<<"Nu exista un astfel de element.";
    }
    return 0;
}
