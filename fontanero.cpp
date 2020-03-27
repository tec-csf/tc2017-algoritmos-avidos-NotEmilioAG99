#include <iostream>
#include <vector>
using namespace std;
struct trabajos{
 int tiempo;
 string satisfaccio= "Aun no se completa";
};
void imprimirEst(trabajos *e,int n)
{
    for(int i=0;i<n;i++)
    {
       cout<<"tiempo: "<< e[i].tiempo<<endl;
        cout<< "satisfaccion: "<<e[i].satisfaccio<<endl;
    }
}
void OrdenarTiempo(trabajos *e, int n)
{
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++)
        {
            if(e[j].tiempo>e[j+1].tiempo)
            {
                trabajos aux= e[j];
                e[j]=e[j+1];
                e[j+1]=aux; 
            }
        }
    }
}
void realizarTrabajo(trabajos *e, int numerodeTrabajos)
{
    float tiempoEspera=0.0;
    for(int i=0; i<numerodeTrabajos;i++)
    {
        tiempoEspera+=e[i].tiempo;
        if(tiempoEspera<(e[i].tiempo*1.5))
        {
            e[i].satisfaccio = "Satisfecho";
        cout<<"tiempo de trabajo: "<< e[i].tiempo<<endl;
         cout<<"tiempo que tardo: "<< tiempoEspera<<endl;
        cout<< "satisfaccion: "<<e[i].satisfaccio<<endl;
        }
        else if(tiempoEspera>(e[i].tiempo*1.5)&&tiempoEspera<(e[i].tiempo*2))
        {
         e[i].satisfaccio = "Medio Satisfecho";
        cout<<"tiempo de trabajo: "<< e[i].tiempo<<endl;
        cout<<"tiempo que tardo: "<< tiempoEspera<<endl;
        cout<< "satisfaccion: "<<e[i].satisfaccio<<endl;
        }
        else{
            e[i].satisfaccio = "No Satisfecho";
            cout<<"tiempo de trabajo: "<< e[i].tiempo<<endl;
            cout<<"tiempo que tardo: "<< tiempoEspera<<endl;
            cout<< "satisfaccion: "<<e[i].satisfaccio<<endl;
        }
        cout<<endl;
    }
}
int main()
{
    trabajos Clientes[4];
    Clientes[0].tiempo=45;
    Clientes[1].tiempo=60;
    Clientes[2].tiempo=30;
    Clientes[3].tiempo=5;
    OrdenarTiempo(Clientes,4);
    realizarTrabajo(Clientes,4);
    return 0;
}