#include <iostream>
#include <fstream>
#include <vector>
#include<stack>
#include <queue>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
/*
    Patience Sort: voi folosi implementarea de la punctul a), dar cu stive in loc de vectori. Dupa ce se formeaza subsirurile descrescatoare,
    vor fi adaugate intr-o coada de prioritati (nlogn), pentru a fi afisate si sortate, in ordine crescatoare.
*/
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

int binarySearch(stack<int> *Sol, int l, int r, int x)//logn
{

    while (l <= r)
    {
        int m = (r+l)/2;

        // Verific daca mijlocul e un raspuns bun
        if (Sol[m].top() >= x)
        {
            //verific sa fiu sigur pe cea mai din stanga pozitie
            if(m>l)
            {
                if(Sol[m-1].top() >= x)
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
        if (Sol[m].top() < x)
            l = m + 1;

        // x mai mic => ignor dreapta
        else
            r = m - 1;
    }

    // nu am gasit nimic bun
    return -1;
}

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

    stack<int> *Sol;
    Sol = new stack<int>[n];
    int k=-1; //cate wi contin elemente
    for(int i=0; i<n; i++)//O(nlogn)
    {

        int loc;
        loc = binarySearch(Sol,0,k,V[i]);//O(logn)
        if(loc==-1)
        {
            k++;
            Sol[k].push(V[i]);
        }
        else
            Sol[loc].push(V[i]);
    }
    //lipire: pornesc de la cel mai din stanga vector(stiva) si bag in solutie fiecare element, apoi fac la fel spre dreapta => ordine crescatoare
    //Q-ul va contine elementele sortate
    priority_queue<int,vector<int>,greater<int>> Q;
    for(int i=0; i<=k; i++)
    {
        while(Sol[i].size())
        {
            Q.push(Sol[i].top());
            Sol[i].pop();
        }
    }
    //afisare
    cout<<"Vectorul sortat cu metoda Patience Sort: \n";
    g<<"Vectorul sortat cu metoda Patience Sort: \n";
    while ( !Q.empty() )
    {
        cout << Q.top() << endl;
        g << Q.top() << endl;
        Q.pop();
    }


    return 0;
}

//Complexitate finala: O(nlogn)
