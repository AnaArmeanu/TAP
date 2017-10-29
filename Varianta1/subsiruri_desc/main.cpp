#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

void citire(int &n, vector<int> &V)
{
    f>>n;
    int c;
    for(int i=0; i<n; i++)
    {
        f>>c;
        V.push_back(c);
    }
}

int binarySearch(vector<int> *Sol, int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
        // verific daca mijlocul e bun
        if (Sol[m][Sol[m].size()-1] >= x)
        {
            //verific sa fiu sigur pe cea mai din stanga pozitie
            if(m>l)
            {
                if(Sol[m-1][Sol[m].size()-1] >= x)
                {
                    r = m - 1;
                }
                else
                    return m;
            }
            else
                return m;
        }

        // x mai mare => ignor stanga
        if (Sol[m][Sol[m].size()-1] < x)
            l = m + 1;

        // x mai mic => ignor dreapta
        else
            r = m - 1;
    }

    // nu am gasit nimic bun
    return -1;
}

/// o sa tin un vector v de vectori wi,i<=n;
///initial, wi sunt goi;
///parcurg lista de nr. si caut locul nr. in vectorii care nu sunt goi, prin
///cautare binara=> nlogn
/// vectorii wi vor fi asezati in ordine crescatoare dupa ultimul el. adaugat
int main()
{
    if(f.fail()||g.fail())
    {
        cout<<"Nu s-au putut deschide fisierele...";
        return 0;
    }
    int n;
    vector<int> V;

    citire(n,V);

    vector<int> *Sol;
    Sol=new vector<int>[n];

    int k=-1; //cate wi contin elemente
    for(int i=0; i<n; i++)//O(nlogn)
    {

        int loc;
        loc = binarySearch(Sol,0,k,V[i]);//O(logn)
        if(loc==-1)
        {
            k++;
            Sol[k].push_back(V[i]);
        }
        else
            Sol[loc].push_back(V[i]);
    }

    //afisare
    for(int i=0; i<=k; i++) //O(n)
    {
        for(int j=0; j<(int)Sol[i].size(); j++)
            g<<Sol[i][j]<<" ";
        g<<endl;
    }

    return 0;
}
//Complexitate finala: O(nlogn)