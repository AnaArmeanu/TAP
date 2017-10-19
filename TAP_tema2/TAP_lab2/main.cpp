//GREEDY: Se dau n intervale. Se cere nr. maxim de intervale disjuncte
#include <iostream>
#include <stdlib.h>
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
    return (A->t - B->t);
}

int main()
{
    int n;
    cout<<"Introduceti nr de intervale: ";
    cin>>n;
    interval V[n];
    cout<<"Introduceti intervalele: \n";
    for(int i=0;i<n;i++)
    {
        cin>>V[i].s;
        cin>>V[i].t;
    }

    //Sortez intervalele dupa timpul de terminare
    qsort(V,n,sizeof(interval),cmpfct);
    cout<<"Vectorul sortat dupa timpul la care se termina : \n";
      for(int i=0;i<n;i++)
    {
        cout<<V[i].s<<" "<<V[i].t<<endl;
    }

    vector<interval> Sol; //solutia, initial goala
    Sol.push_back(V[0]); //primul el. din solutie este intervalul cu cel mai mic timp de finalizare
    for(int i=1; i<n;i++)
    {
        if(V[i].s >= Sol[Sol.size()-1].t) //daca timpul de incepere al int. i >= timpul de finalizare al
                Sol.push_back(V[i]);   //ultimului int din sol, adaug la solutie (nu se suprapun)

    }

    //afisez solutia
    cout<<"Solutia: \n";
    for(int i=0 ; i< (const) Sol.size(); i++)
        cout<<Sol[i].s<<" , "<<Sol[i].t<<endl;
    return 0;
}
