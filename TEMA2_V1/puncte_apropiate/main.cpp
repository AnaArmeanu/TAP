#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include<stdlib.h>
#include<climits>

using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");

vector < pair <long long, long long> > banda(100001), X, Y;//100 001 din textul pb de pe InfoArena

struct solutie
{
    long long d;
    pair <long long, long long> p1,p2;
};

long long distanta(pair <long long, long long> &a,pair <long long, long long> &b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);//las in long long pentru ca voi face radical la sfarsit (sa micsorez timpul de rulare; altfel depaseste testele )
}

/*long long distanta_bruta(pair <long long, long long> &a, int S, int D)
{

    long long dist = MAX_N;
    for (int i = S; i < D; i++)
        for (int j = i + 1; j <= D; j++)
            dist = min(dist, distanta(a[i],a[j]));

    return dist;
}*/

solutie divide(int S, int D)
{
    solutie Sol;
    if (S >= D-1)
    {
        if (S >= D - 1){Sol.d =LLONG_MAX; return Sol;}
    }
    else
    {
        /* if (S - D <= 3)
         {
             return distanta_bruta(Y,S,D);
         }*/
        if (D - S == 2)
        {
            if (Y[S] > Y[S + 1])
                swap(Y[S], Y[S + 1]);
            Sol.d = distanta(X[S], X[S + 1]);
            Sol.p1 = X[S];
            Sol.p2 = X[S+1];
            return Sol;
        }
    }

    int mij = (S + D) / 2;
    long long dist;
    solutie stg = divide(S, mij);
    solutie dr = divide(mij, D);
    if(stg.d < dr.d)
    {
        Sol = stg;
        dist = stg.d;
    }
    else
    {
        Sol = dr;
        dist = dr.d;
    }
    merge(Y.begin() + S, Y.begin() + mij, Y.begin() + mij, Y.begin() + D, banda.begin());
    copy(banda.begin(), banda.begin() + (D - S), Y.begin() + S);

    int k = 0;
    for (int i = S; i < D;  i++ )
        if (abs(Y[i].second - X[mij].first) <= dist)
            banda[k ++] = Y[i];
    for (int i = 0; i < k - 1;  i ++)
    {
        for (int j = i + 1; j < k && j - i < 8;  j ++)
            {
                if(distanta(banda[i], banda[j])<dist)
                {
                    dist = distanta(banda[i], banda[j]);
                    Sol.d = dist;
                    Sol.p1= banda[i];
                    Sol.p2 = banda[j];
                }
            }
    }
    return Sol;
}

int main()
{
    int n;
    //citesc datele
    f>>n;
    X.resize(n),Y.resize(n);
    for (int i = 0; i <(int) X.size(); i++)
        f >> X[i].first >> X[i].second;
    //sortex X si creez Y
    sort(X.begin(), X.end());
    for (int i = 0; i <(int)  X.size(); i++)
        Y[i] = make_pair(X[i].second, X[i].first);

    solutie S = divide(0,X.size());
    cout<<"Punctele cele mai apropiate sunt: {( "<<S.p1.first<<" , "<<S.p1.second<<" ),( "<<S.p2.first<<" , "<<S.p2.second<<" )},";
    cout<<" cu distanta: "<< fixed << setprecision(6) << sqrt(S.d) << "\n";
    g<<"Punctele cele mai apropiate sunt: {( "<<S.p1.first<<" , "<<S.p1.second<<" ),( "<<S.p2.first<<" , "<<S.p2.second<<" )},";
    g<<" cu distanta: "<< fixed << setprecision(6) << sqrt(S.d) << "\n";
    g.close();
    f.close();
    return 0;
}
