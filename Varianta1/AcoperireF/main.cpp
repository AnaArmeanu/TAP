#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/*

Se dau un interval închis [a,b] si o multime de alte n intervale închise [a i ,b i ], 1 = i =
N. Scrieti un program care determina si afiseaza o submultime de cardinal minim de intervale închise
din multimea data cu proprietatea ca prin reuniunea acestora se obtine un interval care include pe
[a,b]. Daca prin reuniunea tuturor intervalelor nu putem obtine un interval care sa includa intervalul
[a,b], se va afisa -1 O(n logn)

*/

ifstream f("date.in");
ofstream g("date.out");

struct interval
{
    int a,b;
};

void citire(int &n, interval &x, vector<interval> &V);

int cmpfunct (interval A, interval B);

void Greedy(int n, interval x, vector<interval> V);

int main()
{

    //verific fisierele
    if(f.fail()||g.fail())
    {
        cout<<"Nu s-au putut deschide fisierele...\n";
        return 0;
    }


    int n;
    interval x;
    vector<interval> V;

    citire(n,x,V);
    Greedy(n,x,V);

    f.close();
    g.close();
    return 0;
}
void citire(int &n, interval &x, vector<interval> &V)//O(n)
{
    f>>x.a>>x.b;
    f>>n;
    //citesc n intervale
    interval S;
    for(int i=0; i<n; i++)
    {
        f>>S.a>>S.b;
        V.push_back(S);
    }

}

int cmpfunct (interval A, interval B)
{

    if(A.a==B.a)
        return (A.b < B.b);
    else
        return (A.a < B.a);
}
/*Idee:
    Ordonez crescator vectorii dupa ai; daca ai == aj, ii ordonez crescator dupa b, astfel incat cel mai lung vector sa fie mai jos.
    Caut in vectorul ordonat ultimul interval care are ai < a-ul dat si cu cel mai lung bi; dupa ce il gasesc, a-ul dat devine bi-ul gasit si repeta
    pana cand i>n sau i nu mai creste (nu mai am vectori pe care ii pot folosi) sau pana cand am gasit o solutie;
*/
void Greedy(int n, interval x, vector<interval> V)
{

    vector<interval> Sol;
    sort(V.begin(),V.end(),cmpfunct);//O(nlogn)
    int i;
    interval m; //maximul
    m.a = m.b = 0;
    i=0;
    int iaux;
    while(i<n)// desi contine alt while, complexitatea per total este O(n), intrucat nu fac altceva decat sa traversez ce a mai ramas netraversat din vectorul de intervale, cu i
    {
        iaux = i;
        if(Sol.size())
            if(Sol[Sol.size()-1].b >= x.b) //daca a gasit soutia, sa nu mai faca alte operatii inutile
            {
                break;
            }

        while(i<n && V[i].a <= x.a)// <= O(n)
        {
            if(V[i].b>=m.b)
            {
                if(Sol.size())
                {

                    if(Sol.back().b<V[i].b)
                    {
                        m.b = V[i].b;
                        m.a = V[i].a;
                    }
                }
                else
                {
                    m.b = V[i].b;
                    m.a = V[i].a;
                }

            }
            i=i+1;

        }
        Sol.push_back(m);
        x.a = m.b;
        m.a = m.b =0;
        if(iaux == i)
        {
            g<<"-1";
            cout<<"-1";
            return;
        }
    }
    if(Sol[Sol.size()-1].b<x.b)
    {
        g<<"-1";
        cout<<"-1";
        return ;
    }
    for( i=0 ; i<(int)Sol.size(); i++)//O(n)
    {
        g<<Sol[i].a<<" "<<Sol[i].b<<endl;
        cout<<Sol[i].a<<" "<<Sol[i].b<<endl;
    }

}

//Complexitate : O(n+n+n+nlogn) = O(nlogn)
