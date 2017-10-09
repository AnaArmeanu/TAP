using namespace std;
#include <iostream>
#include "header.h"


void meniu()
{
    cout << "Nr de elemente : ";
    int n;
    cin>>n;
    int i;
    cout<<"Introduceti elementele vectorului:\n";
    vector <int> A(n);
    for(i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<"Introduceti suma: ";
    int S;
    cin>>S;
    cout<<"\n\tMENIU 1\n";
    cout<<"Alegeti: \n\t1. Cautati 2 nr(indicii lor) din vector cu suma S;";
    cout<<"\n\t2. Cautati 3 nr(indicii lor) din vector cu suma S;\n\t0.Stop.\n...";
    int o;
    cin>>o;
    while(o)
    {
        switch(o)
        {
        case 1:
            cout<<"\n\tMENIU 2.1\n";
            cout<<"Optiuni: \n\t1. Varianta n^2;\n\t2. Varianta nlogn;";
            cout<<"\n\t3. Varianta n.\n\t 0.Va intoarceti la meniul 1.";
            cout<<"\nIntroduceti optiunea:... ";
            int opt;
            cin>>opt;
            indici X;

            while(opt)
            {
                switch(opt)
                {
                case 1:
                    X = Suma_patratica(n,A,S,-1);
                    if(X.i==-1)
                        cout<<"Nu s-au gasit 2 nr cu suma S...";
                    else
                        cout<<"2 indici ai caror elemente insumate dau S: "<<X.i<<" "<<X.j;

                    break;
                case 2:
                    X=Suma_nlogn(n,A,S,-1);
                    if(X.i==-1)
                        cout<<"Nu s-au gasit 2 nr cu suma S...";
                    else
                        cout<<"2 indici ai caror elemente insumate dau S: "<<X.i<<" "<<X.j;
                    break;
                case 3:
                    X=Suma_n(n,A,S,-1);
                    if(X.i==-1)
                        cout<<"Nu s-au gasit 2 nr cu suma S...";
                    else
                        cout<<"2 indici ai caror elemente insumate dau S: "<<X.i<<" "<<X.j;
                    break;
                default:
                    cout<<"\nAti introdus o optiune gresita.";
                }
                cout<<"\nAlegeti alta optine.";
                cin>>opt;
            }
            break;

        case 2:
            cout<<"\n\tMENIU 2.2\n";
            cout<<"Optiuni: \n\t1. Varianta n^3;\n\t2. Varianta n^2logn;";
            cout<<"\n\t3. Varianta n^2.\n\t 0.Va intoarceti la meniul 1.";
            cout<<"\nIntroduceti optiunea:... ";
            int opt1;
            cin>>opt1;
            t_indici X1;
            while(opt1)
            {
                switch(opt1)
                {
                case 1:
                    X1 = tSuma_cub(n,A,S);
                    if(X1.i==-1)
                        cout<<"Nu s-au gasit 3 nr cu suma S...";
                    else
                        cout<<"3 indici ai caror elemente insumate dau S: "<<X1.k<<" "<<X1.i<<" "<<X1.j;

                    break;
                case 2:
                    X1 = tSuma_n2logn(n,A,S);
                    if(X1.i==-1)
                        cout<<"Nu s-au gasit 3 nr cu suma S...";
                    else
                        cout<<"3 indici ai caror elemente insumate dau S: "<<X1.k<<" "<<X1.i<<" "<<X1.j;
                    break;
                case 3:
                    X1 = tSuma_n2(n,A,S);
                    if(X1.i==-1)
                        cout<<"Nu s-au gasit 3 nr cu suma S...";
                    else
                        cout<<"3 indici ai caror elemente insumate dau S: "<<X1.k<<" "<<X1.i<<" "<<X1.j;
                    break;
                default:
                    cout<<"\nAti introdus o optiune gresita.";
                }
                cout<<"\nAlegeti alta optine.";
                cin>>opt1;
            }
            break;
        default:
            cout<<"\nAti introdus o optiune gresita.";
        }
        cout<<"\nAlegeti altceva...";
        cin>>o;
    }

}
