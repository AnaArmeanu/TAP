#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");
struct nod
{
    int info;
    nod*st,*dr;
};

int cauta(vector<int> v, int val, int st, int dr)//complexitate pe cel mai rau caz n; pe caz mediu logn pentru ca se micsoreaza spatiul de cautare
{
    for(int i=st; i<=dr; i++)
        if(v[i]==val)
        {
            return i;
        }
    return -1;

}

/*nod* arbore(int nr nr de nr din vectori,int bSDR, int eSDR, int bSRD, int eSRD,vector<int> &sdr,vector<int> &srd)
{
    int poz = cauta(srd,sdr[nr-1],0,nr-1);//caut pozitia radacinii din vector/subvector in srd
    nod* n=new nod;
    if(poz == -1)
    {
        g<<"Nu.";
        cout<<"Nu.";
        return NULL;
    }
    if(poz==bSRD)
    {
        n->info = sdr[eSDR];
        n->st=NULL;
        n->dr=NULL;

    }
    else
    {
        n->info = sdr[eSDR];
        n->st = arbore(poz,bSDR,poz-1,bSRD,poz-1,sdr,srd);
        n->dr = arbore(nr-poz-1,bSDR+poz,eSDR-1,poz+1,eSRD,sdr,srd);

    }
    return n;
}*/

//bSDR, eSDR, etc sunt pozitiile de inceput/final
nod* arbore(int bSDR, int eSDR, int bSRD, int eSRD,vector<int> &sdr,vector<int> &srd)
{
    int poz = cauta(srd,sdr[eSDR],bSRD,eSRD);//caut pozitia radacinii din vector/subvector in srd

    nod* n=new nod;
    if(poz==-1)
    {
        g<<"Nu.";
        cout<<"Nu.";
        exit(0);
    }
    int nr = poz - bSRD-1;
    if(bSRD == eSRD)
    {
        n->info = sdr[eSDR];
        n->st=NULL;
        n->dr=NULL;
    }
    else//se face apel la arbore de n ori => +cautare : n^2 (cel mai rau caz) ; nlogn (caz mediu)
    {
        n->info = sdr[eSDR];
        if(poz>bSRD)//daca mai am arbore in stanga
        {
          n->st = arbore(bSDR,bSDR+nr,bSRD,poz-1,sdr,srd);
        }
        else
            n->st = NULL;
        if(poz<eSRD)//daca mai am arbore in dreapta
        {
            n->dr = arbore(bSDR+nr+1,eSDR-1,poz+1,eSRD,sdr,srd);
        }
        else
            n->dr = NULL;

    }
    return n;
}
void citire(int &n, vector<int> &sdr,vector<int> &srd)
{

    f>>n;
    int x;
    for(int i=0; i<n; i++)
    {
        f>>x;
        sdr.push_back(x);
    }
    for(int i=0; i<n; i++)
    {
        f>>x;
        srd.push_back(x);
    }
}


void vezi_rsd (nod *rad)
{
    if(rad!=NULL)
    {
        cout<<rad->info<<" ";
        g<<rad->info<<" ";
        vezi_rsd(rad->st);
        vezi_rsd(rad->dr);
    }
}

void vezi_srd (nod *rad)//stanga->rad->dreapta
{
    if(rad)
    {
        vezi_srd(rad->st);
        cout<<rad->info<<" ";
        g<<rad->info<<" ";
        vezi_srd(rad->dr);
    }
}

void vezi_sdr (nod *rad)
{
    if(rad)
    {
        vezi_sdr(rad->st);
        vezi_sdr(rad->dr);
        cout<<rad->info<<" ";
        g<<rad->info<<" ";
    }
}

void elibereaza(nod* rad)
{
    if(rad)
    {
        elibereaza(rad->st);
        elibereaza(rad->dr);
        delete rad;
    }
}
int main()
{
    int n;
    vector<int> sdr;//postordine
    vector<int> srd;//inordine
    citire(n, sdr, srd);
    nod* radacina= new nod;
    radacina=arbore(0,n-1,0,n-1,sdr,srd);
    cout<<"RSD(preordine) : ";
    vezi_rsd(radacina);
    g<<"\n";
    cout<<"\nSRD(inordine) : ";
    vezi_srd(radacina);
    g<<"\n";
    cout<<"\nSDR (postordine) : ";
    vezi_sdr(radacina);
    g<<"\n";


    //eliberare memorie SDR
    elibereaza(radacina);
    return 0;
}
