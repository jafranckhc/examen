#include <iostream>
#include <list>

using namespace std;

class Regalo{
public:
    string desc;
    char control_parental;
};

class nino {
   public:
    nino(string n,int spb,int lat, int lon,int e)
    {
       nombre=n;
       se_porto_bien=spb;
       latitud=lat;
       longitud=lon;
       edad=e;
    }
    string nombre;
    int se_porto_bien; //valor del 0 al 10,  0 = Diablillo , 10 = La encarnación del Bien.
    list<Regalo> Regalos;
    int longitud;
    int latitud;
    int edad;
};

class NodoArbol
{
    int *llaves;
    int t;
    NodoArbol **C;
    int n;
    bool hoja;
public:
    NodoArbol(int _t, bool hoja);
    void AgregaCuandoEstaVacio(int k);

    void AgregaHijos(int i, NodoArbol *y);
    void imprimir();
    NodoArbol *buscar(int k);
friend class Arbol;
};



class Arbol
{
    NodoArbol *root;
    int t;
public:
    Arbol(int _t)
    {  root = NULL;  t = _t; }
    void imprimir()
    {
        if (root != NULL) root->imprimir();
    }

    NodoArbol* search(int k)
    {
        return (root == NULL)? NULL : root->buscar(k);
    }

    void insert(int k);

};

NodoArbol::NodoArbol(int t1, bool leaf1)
{
    t = t1;
     hoja =  hoja;
    llaves = new int[2*t-1];
    C = new NodoArbol *[2*t];

    n = 0;
}

void NodoArbol::imprimir()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if ( hoja == false)
            C[i]->imprimir();
        cout << " " << llaves[i];
    }
    if ( hoja == false)
        C[i]->imprimir();
}

NodoArbol *NodoArbol::buscar(int k)
{
    int i = 0;
    while (i < n && k >llaves[i])
        i++;

    if (llaves[i] == k)
        return this;
    if ( hoja == true)
        return NULL;
    return C[i]->buscar(k);
}
void Arbol::insert(int k)
{

    if (root == NULL)
    {

        root = new NodoArbol(t, true);
        root->llaves[0] = k;
        root->n = 1;
    }
    else
    {
        if (root->n == 2*t-1)
        {
            NodoArbol *s = new NodoArbol(t, false);

            s->C[0] = root;

            s->AgregaHijos(0, root);
            int i = 0;
            if (s->llaves[0] < k)
                i++;
            s->C[i]->AgregaCuandoEstaVacio(k);

            root = s;
        }
        else
            root->AgregaCuandoEstaVacio(k);
    }
}
void NodoArbol::AgregaCuandoEstaVacio(int k)
{
    int i = n-1;
    if ( hoja == true)
    {
        while (i >= 0 && llaves[i] > k)
        {
            llaves[i+1] = llaves[i];
            i--;
        }
        llaves[i+1] = k;
        n = n+1;
    }
    else
    {
        while (i >= 0 && llaves[i] > k)
            i--;
        if (C[i+1]->n == 2*t-1)
        {
            AgregaHijos(i+1, C[i+1]);
            if (llaves[i+1] < k)
                i++;
        }
        C[i+1]->AgregaCuandoEstaVacio(k);
    }
}

void NodoArbol::AgregaHijos(int i, NodoArbol *y)
{
    NodoArbol *z = new NodoArbol(y->t, y-> hoja);
    z->n = t - 1;
    for (int j = 0; j < t-1; j++)
        z->llaves[j] = y->llaves[j+t];
    if (y-> hoja == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }
    y->n = t - 1;
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];
    C[i+1] = z;
    for (int j = n-1; j >= i; j--)
        llaves[j+1] = llaves[j];
    llaves[i] = y->llaves[t-1];
    n = n + 1;
}





int main() {
    int op=0;

    do
    {
        cout<<"***MENU***"<<endl;
        cout<<"(1)AGREGAR UN NINO"<<endl;
        cout<<"(2)AGREGAR LISTA DE REGALOS A UN  NINO"<<endl;
        cout<<"(3)BUSCAR NINO"<<endl;
        cout<<"ingrese una opcion"<<endl;
        cin>>op;
        if(op==1){
            cout<<"AGREGAR UN NINO"<<endl;
        }
        if(op==2){
            cout<<"AGREGAR LISTA DE REGALOS A UN  NINO"<<endl;
        }
        if(op==3){
            cout<<"BUSCAR NINO"<<endl;
        }
    }
    while(op!=4);
    return 0;
}
