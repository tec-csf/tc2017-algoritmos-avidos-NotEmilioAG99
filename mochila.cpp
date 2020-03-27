#include <iostream>
#include <vector>
using namespace std;
struct elementos{
 int peso;
 int beneficio;
} ;
void imprimirEst(elementos e[5],int n)
{
    cout<<"Elementos que se tienen ordenados por mayor beneficio"<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<"peso: "<< e[i].peso<<" ";
        cout<<"Beneficio: "<<e[i].beneficio<<endl;
    }
}
void imprimirMochila(vector<elementos> mochila)
{
    cout<<"Elementos en la mochila"<<endl;
    for(int i=0;i<mochila.size();i++)
    {
        cout<<"peso: "<<mochila.at(i).peso<<" ";
        cout<<"beneficio: "<<mochila.at(i).beneficio<<endl;
    }
}
void agregarMochila(elementos e[5], int n , int pesomax, vector <elementos> mochila)
{
   int pesoencurso=0, i=0;
   cout<<"Peso maximo de la mochila: "<<pesomax<<endl;
   while(pesoencurso<pesomax && (i<n))
   {
       if((pesoencurso+e[i].peso)<=pesomax)
       {
           pesoencurso+=e[i].peso;
            mochila.push_back(e[i]);
       }
       i++;
   }
   imprimirMochila(mochila);
}
void ordenarMochila(elementos e[5], int n)
{
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++)
        {
            if(e[j].beneficio<e[j+1].beneficio)
            {
                elementos aux= e[j];
                e[j]=e[j+1];
                e[j+1]=aux; 
            }
        }
    }
    imprimirEst(e,n);
}
int main()
{
   int elementosmax=5;
    elementos registros[elementosmax];
    vector <elementos> mochila;
    registros[0].peso=10;
    registros[0].beneficio=12;
    registros[1].peso=5;
    registros[1].beneficio=3;
    registros[2].peso=6;
    registros[2].beneficio=6;
    registros[3].peso=9;
    registros[3].beneficio=2;
    registros[4].peso=4;
    registros[4].beneficio=7;
    ordenarMochila(registros,elementosmax);
    agregarMochila(registros,elementosmax,20,mochila);
    return 0;
}