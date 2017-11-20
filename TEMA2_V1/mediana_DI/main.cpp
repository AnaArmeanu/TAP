#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

void citire(int &n, int &m,vector<int> &v1,vector<int> &v2)
{
    f>>n;
    int x;
    for(int i=0; i<n; i++)
    {
        f>>x;
        v1.push_back(x);
    }
    f>>m;
    if(m>n)//vreau ca v1 sa aiba mai multe el. decat v2
    {
        for(int i=0; i<n; i++)
        {
            v2.push_back(v1[i]);
        }
        swap(m,n);//ca sa stiu ca primul vector, cu n el e cel mai mare
        v1.clear();
        for(int i=0; i<n; i++)
        {
            f>>x;
            v1.push_back(x);
        }
    }
    else
    {
        for(int i=0; i<m; i++)
        {
            f>>x;
            v2.push_back(x);
        }
    }
}

int cauta_bin_mediana(int stg,int dr,vector<int> A,vector<int> B,int n,int m)//in primul caz va fi cel mai mic vector
{
    int sol;
    if(stg<=dr)
    {
        int i = (stg+dr)/2;
        int j = (m+n+1)/2 - i; // observatie LeetCode
       cout<<"i : "<<i<<" j: "<<j<<endl;
        if(i<dr && B[j-1]>A[i])
        {
            sol = cauta_bin_mediana(stg+1,dr,A,B,n,m);
        }
        else
        {
            if(i>stg && A[i-1]>B[j])
            {
                sol = cauta_bin_mediana(stg,dr-1,A,B,n,m);
            }
            else
            {
                return i;
            }
        }
    }
    return sol;
}

double mediana(int n,int m, vector<int> A,vector<int> B)
{
    int poz;
    poz=cauta_bin_mediana(0,m,A,B,n,m);
    int i=poz;
    cout<<"i = "<<poz<<endl;
    int j = (m+n+1)/2 - i;
    int maxStg = 0;
    if(i==0)
        maxStg = B[j-1];
    else
    {
        if(j==0)
        {
            maxStg = A[i-1];
        }
        else
        {
            maxStg = max(A[i-1],B[j-1]);
        }
    } //am gasit mediana partii stangi; daca sirul final e de lg impara, e si mediana finala
    if((m+n)%2)
        return maxStg;
    int minDr;
    if(i==m)
        minDr = B[j];
    else
    {
        if(j==n)
        {
            minDr = B[i];
        }
        else
        {
            minDr = max(A[i],B[j]);
        }
    }
    return ((maxStg+minDr)/2.0);
}

int main()
{
    int n,m;
    vector<int> v1;
    vector<int> v2;
    citire(n,m,v1,v2);
    cout<<"Mediana este "<<mediana(n,m,v2,v1);
    g<<mediana(n,m,v2,v1);
    return 0;
}
s
