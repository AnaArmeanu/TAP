#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

struct activitate
{
    int l,t,nr;
};

void citire(int &n, vector<activitate> &V)//O(n)
{
    f>>n;
    //citesc n activitati
    activitate S;
    for(int i=0; i<n; i++)
    {
        f>>S.l>>S.t;
        S.nr=i+1; //nr activitatii
        V.push_back(S);
    }

}

int cmpfunct (activitate A, activitate B)//ordine crescatoare dupa t
{

    if(A.t==B.t)
        return (A.l > B.l);
    else
        return (A.t < B.t);
}

void Greedy(int n, vector<activitate> V)
{
    sort(V.begin(),V.end(),cmpfunct);//O(nlogn)
    int P=0; //intarzierea maxima
    int k=0;//pentru intervalul fiecarei activitati
    for( int i=0 ; i<(int)V.size(); i++)//O(n)
    {
        g<<"activitatea: "<<V[i].nr<<" - intervalul: "<<k<<" "<<k+V[i].l<<" - intarziere: ";
        k=k+V[i].l;
        g<<k - V[i].t<<endl;
        if(k - V[i].t > P)
            P=k - V[i].t;
    }
    cout<<"Intarzierea maxima: "<<P<<endl;

}


int main()
{
    //verific fisierele
    if(f.fail()||g.fail())
    {
        cout<<"Nu s-au putut deschide fisierele...\n";
        return 0;
    }

    int n;
    vector<activitate> V;

    citire(n,V);

    Greedy(n,V);
    return 0;
}

//Complexitate finala: O(nlogn)
