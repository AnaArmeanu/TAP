//Problema partitiilor de cardinal minim
//Se dau n intervale. Se cere nr minim de partitii ai intervalele dintr-o partritie sa fie disjuncte
//Rezolvare: * sortez S-ul crescator dupa finalul intervalului
//           *
#include <iostream>
#include <stdlib.h>
#include<stack>
#include<vector>
using namespace std;

struct interval
{
    int s, t;
};

int cmpfct (void const* a, void const* b)
{
    interval* A = (interval*) a;
    interval* B = (interval*) b;
    if (A->t - B->t == 0) // in caz de sunt egale, le sortez dupa timpul de incepere
        return (A->s - B->s);
    else
        return (A->t - B->t);
}
int main()
{
    int n;
    cout<<"Introduceti nr de intervale: \n";
    cin>>n;
    interval V[n];
    cout<<"Introduceti intervalele: \n";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<".\n";
        cin>>V[i].s;
        cin>>V[i].t;
    }

    //Sortez intervalele dupa timpul de terminare
    qsort(V,n,sizeof(interval),cmpfct);
    cout<<"Vectorul sortat dupa timpul la care se termina : \n";
    for(int i=0; i<n; i++)
    {
        cout<<V[i].s<<" "<<V[i].t<<endl;
    }


    vector <interval> *Vsol; // Ve o multime ce contine multimi (partitiile) de intervale
    Vsol = new vector<interval>[n]; //pun de dimeniune n pentru ca e posibil sa existe n partitii, cu cate 1 interval

    int k=0;//k = nr de partitii
    int ok;
    Vsol[0].push_back(V[0]);
    for(int i=1;i<n;i++)
    {
        ok = 0;
        for(int j=0;j<=k;j++)
        {
            if( (Vsol[j].size()-1 >= 0)&&Vsol[j][Vsol[j].size()-1].t <= V[i].s) /// nu se suprapun ( nu stiu daca < sau <= ; pentru problema orarului cu nr de clase, <= )
            {
                ok=1;
                // => il bag in partitia asta
                Vsol[j].push_back(V[i]);
                break;
            }
        }
        if(!ok) //nu am gasit o partitie in care pot baga intervalul => partitie noua
        {
         k++;
         cout<<"\nk\n";
         Vsol[k].push_back(V[i]);
        }
    }

    //Afisez solutia

    cout<<"Nr minim de partitii: "<<k+1<<endl;
    cout<<"Partitiile sunt: \n";
    for(int i=0;i<=k;i++)
    {
        cout<<i+1<<". {";
        for(int j=0; j<(const) Vsol[i].size(); j++)
        {
            cout<<" ( "<< Vsol[i][j].s << "-" << Vsol[i][j].t << " ) ";
        }
        cout<<"}"<<endl;
    }

}
