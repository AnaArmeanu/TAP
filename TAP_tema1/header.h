#include <unordered_map>
#include <vector>
#include<stdlib.h>
using namespace std;

/**
   Desi stiu ca adaugarea lui "poz" in subprograme creste complexitatea, ati
   spus sa folosim rezolvarile de la problema cu 2 indici pentru a le rezolva pe
   cele cu 3 si aceasta este cea mai simpla idee pe care am avut-o.
   Daca nu vi se pare o idee prea "fericita", va rog sa ma anuntati si voi reface subprogramele.
   Va multumesc in avans! :)
**/
struct indici
{
    int i;
    int j;
};

indici Suma_patratica(int n, vector<int> vect, int S, int poz) ///am adaugat "poz" pentru cazul cu 3 nr
{
    indici SOL;
    SOL.i=SOL.j=-1; // in caz de esec
    int a,b;
    for(a=0; a<n-1; a++)
    {
        for(b=a+1; b<n; b++) //b porneste de la a+1 ca sa evit indicii (i,i)
        {
            if(vect[a]+vect[b]==S && a!=poz && b!=poz)//am adaugat "poz" pentru cazul cu 3 nr
            {
                SOL.i = a;
                SOL.j = b;
                return SOL;
            }
        }
    }
    return SOL;
}

struct vect_sort_index// o structura pentru a nu modifica vectorul primit ca parametru si, in acelasi timp, sa memorez indicii initiali
{
    int val,ind;
};

int cmpfunc (const void* a, const void* b)
{
    vect_sort_index* A = (vect_sort_index* ) a;
    vect_sort_index* B = (vect_sort_index* ) b;

    return (A->val - B->val);
}

indici Suma_nlogn(int n, vector<int> vect, int S, int poz)//am adaugat "poz" pentru cazul cu 3 nr
{
    indici SOL;
    SOL.i=SOL.j=-1;

    vector<vect_sort_index> A(n);
    for(int i=0; i<n; i++)
    {
        A[i].val = vect[i];
        A[i].ind = i;
    }

    qsort(&A[0],n,sizeof(vect_sort_index),cmpfunc);

    int y=0,u=n-1;//capetele vectorului sortat

    while(y<u)
    {
        int sum = A[y].val + A[u].val;
        if(sum == S && A[y].ind!=poz && A[u].ind!=poz)//am adaugat "poz" pentru cazul cu 3 nr
        {
            SOL.i = A[y].ind;
            SOL.j = A[u].ind;
            return SOL;
        }
        else
        {
            if(sum<S)
            {
                y++;
            }
            else
            {
                u--;
            }
        }
    }

    return SOL;
}

indici Suma_n(int n, vector<int> vect, int S, int poz)//am adaugat "poz" pentru cazul cu 3 nr
{
    indici SOL;
    SOL.i=SOL.j=-1;
    unordered_map<int,int> m;/// o eroare "experimental..." si a trebuit sa activez c++ 11
    for(int i=0; i<n; i++)
    {
        m.insert({vect[i],i});
    }

    for(int i = 0; i<n; i++)
    {
        int b=S-vect[i];
        if (m.find(b)!= m.end())
            if(m.find(b)->second != i )// s-a gasit si exit cazul de element de pe aceeasi pozitie luat de 2 ori
            {
                if(i!= poz && m.find(b)->second != poz)//am adaugat "poz" pentru cazul cu 3 nr
                {
                    SOL.i= i;
                    SOL.j= m.find(b)->second;
                    return SOL;
                }
            }
    }
    return SOL;

}

///--------------------------------------------------------------------- PART 2
struct t_indici
{
    int i,j,k;
};


t_indici tSuma_cub(int n, vector<int> vect, int S)
{
    int sum;
    t_indici S1;
    S1.i = S1.j = S1.k = -1;
    indici sol_1;
    for(int i=0; i<n; i++)
    {
        sum = S-vect[i];
        sol_1 = Suma_patratica(n, vect, sum, i);
        if(sol_1.i!=-1)
        {
            S1.i = sol_1.i;
            S1.j = sol_1.j;
            S1.k = i;
            return S1;
        }
    }
    return S1;
}

t_indici tSuma_n2logn(int n, vector<int> vect, int S)
{
    int sum;
    t_indici S1;
    S1.i = S1.j = S1.k = -1;
    indici sol_1;
    for(int i=0; i<n; i++)
    {
        sum = S-vect[i];
        sol_1 = Suma_nlogn(n, vect, sum, i);
        if(sol_1.i!=-1)
        {
            S1.i = sol_1.i;
            S1.j = sol_1.j;
            S1.k = i;
            return S1;
        }
    }
    return S1;
}

t_indici tSuma_n2(int n, vector<int> vect, int S)
{
    int sum;
    t_indici S1;
    S1.i = S1.j = S1.k = -1;
    indici sol_1;
    for(int i=0; i<n; i++)
    {
        sum = S-vect[i];
        sol_1 = Suma_n(n, vect, sum, i);
        if(sol_1.i!=-1)
        {
            S1.i = sol_1.i;
            S1.j = sol_1.j;
            S1.k = i;
            return S1;
        }
    }
    return S1;
}
