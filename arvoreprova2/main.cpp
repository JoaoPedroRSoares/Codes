#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

struct No
{
    int codigo;
    float preco;
    struct No *e;
    struct No *d;
};

typedef No* PN;

PN Inicializar ()
{ 
    return (NULL); 
    
}

PN CriarNovoNo (int cod, float pr)
{
    PN novoNo= (PN)malloc( sizeof(No));
    novoNo->e=NULL;
    novoNo->d=NULL;
    novoNo->codigo = cod;
    novoNo->preco = pr;
    return novoNo;
}

PN adicionarNoNaArv (PN raiz, PN no)
{
    if (raiz==NULL)
    {return (no);}
    if (no->codigo < raiz->codigo)
    { raiz->e= adicionarNoNaArv (raiz->e, no); }
    else
    { raiz->d= adicionarNoNaArv(raiz->d, no); }
return (raiz);
}

PN busca (int cod , PN raiz)
{
    if (raiz==NULL) {return (NULL);}
    if (raiz->codigo == cod) {return (raiz);}
    if (raiz->codigo>cod) {return busca (cod, raiz->e);}
    return busca (cod, raiz->d);
}

int ContarNos (PN raiz)
{
    int Qd=0;
    if( raiz ==NULL) {return 0;}
    else 
    {
      Qd=ContarNos(raiz->e)+1+ContarNos(raiz->d);
    }
    return Qd;
}

int main ()
{
    int menu, codigo;
    float preco;
    int q;
    PN r= Inicializar ();
    do
    {
        cout << "===== MENU =====" << "\n";
        cout << "0 - Sair" << "\n";
        cout << "1 - Inserir produto" << "\n";
        cout << "2 - Contar quantidade de produtos" << "\n";
        cout << "3 - Buscar produto" << "\n";
        cout << "================" << "\n";
        cout << "Escolha uma opção: ";
        cin >> menu;
        switch (menu)
        {
        case 0:
            cout <<"Encerrando o programa..."<< "\n";
            break;
        case 1: 
            cout <<" Digite o código do Nó: ";
            cin>>codigo;
            cout <<" Digite o preço do Nó: ";
            cin>> preco;
            PN p1;
           p1=busca(codigo, r);
            if(p1!=NULL) {cout<<"Já existe um nó com esse código, tente outra opção.\n";}
            else 
            {
            PN no;
            no= CriarNovoNo ( codigo, preco);
           r= adicionarNoNaArv (r, no);
            cout<< "Produto inserido com sucesso!" <<"\n";
            }
            break;
        case 2:
            q=ContarNos(r);
            cout<<"A árvore tem " << q << " nós.\n";
            break;
        case 3: 
            cout<<"Coloque o código do nó a ser buscado.\n";
            cin >>codigo;
            PN  p;
            p=busca (codigo, r);
            if(p==NULL) {cout << "Produto não encontrado." << "\n";}
            else 
                {
                cout << "Produto encontrado: " << "\n";
                cout << "Código: " << p->codigo << "\n";
                cout << "Preço: " << p->preco << "\n";
                }
            break;
            default: cout<<"Opção inválida. \n";
            break;
        }
    } while (menu!=0);
    return 0;
}