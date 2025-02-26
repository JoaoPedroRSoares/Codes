#include <iostream>

using namespace std;
#define size 50
typedef int tipochave;
struct elemento
{
    tipochave chave;
    //outros campos
};
class pilha
{
    private:
    elemento *dado;
    int tamanho;
    
    public:
    pilha();//função criadora
    bool cheia();// 1 cheia 0 não cheia
    bool vazia();//1 vazia 0 não vazia
    void inserir (elemento e);// push
    tipochave remover();//pop
    void mostrar();
    int gettamanho();
    bool busca (tipochave ch);
};
int main()
{
    pilha p1;
    elemento e1;
    tipochave ch1;
    int menu;
    cout<<"Faça uma escolha \n";
    do{
        cout<<"Digite: \n";
        cout<<" 0 para terminar \n";
        cout<<" 1 para inserir um elemento \n";
        cout<<" 2 para remover um elemento \n";
        cout<<" 3 para ver todos os elementos da pilha \n";
        cout<<" 4 para ver o tamanho da pilha \n";
        cout<<" 5 para buscar por um elemento \n";
        cin>> menu;
        switch(menu)
        {
        case 0: cout<<"the end\n";
        break;
        case 1: cout<<"Digite a chave do elemento a ser inserido";
            cin>>e1.chave;
            p1.inserir (e1);
        break;
        case 2: cout<<p1.remover()<<"\n";
        break;
        case 3: p1.mostrar();
        break;
        case 4: cout<<"o tamanho da pilha é: "<< p1.gettamanho() <<"\n";
        break;
        case 5: cout<<"Digite a chave do elemento a ser procurado\n";
        cin>> ch1;
        if (p1.busca(ch1)==1){
            cout<<"o elemento já está na pilha\n";}
            
            else {
                cout<<"o elemento não está na pilha\n";}
                break;
                default: cout<<"opção invalida \n";
                break;
        }
    } while (menu!=0);
}
    
    pilha::pilha()
    {
        tamanho=0;
        dado = new elemento[size];
    }
    bool pilha::cheia(){
        if(tamanho==size) {return true;}
        else {return false;}
    }
    bool pilha::vazia(){
        if (tamanho==0) {return false;}
        else {return false;}
    }
    bool pilha::busca (tipochave ch)
    {
        int i;
        for (i=0; i<tamanho; i++)
        {
            if (dado[i].chave==ch)
            {
                return true;
            }
        }
        return false;
    }
    void pilha ::inserir (elemento e)
    {
        int a;
        a=cheia(); // para inserir primeiro devemos checar se não está cheia
        if(a==1)
        {
            cout<<"a pilha já está cheia\n";
            //se está cheia não podemos inserir
        }
        else
        {// se não está cheia, antes de inserir devemos procurar se o elemento 
        //já está na pilha
        if (busca (e.chave)==1) // se ele está, não podemos inserir
        {
            cout<<"O elemento com chave"<<e.chave<<"já está na pilha\n";
        }
        else
        {
        dado[tamanho]=e;//inserimos o elemento no topo
        tamanho=tamanho+1; //aumentamos a quantidade de elementos
         }
        }
        
    }
    tipochave pilha::remover(){
        int a;
        a=vazia(); //só poderemos remover se a pilha nao estiver vazia
        if (a==1)// se a função retornar 1, então a pilha está vazia
        {
            cout<<"Não foi possivel remover: a pilha já está vazia\n";
            return 0;
        }
        else // se o retorno não é 1, então podemos remover o elemtno do topo
        {
            tamanho = tamanho-1;
            cout<<"foi removido o elemento com chave: \n";
            return dado[tamanho].chave;
            //retornamos a chave do elemento que foi removido
        }
    }
    void pilha :: mostrar()
    {
        cout << "os elementos da pilha são:\n";
        int i;
        for(i=0; i<tamanho; i++)
        {
            cout<<dado[i].chave<<"\n";
        }
    }
    int pilha::gettamanho ()
    {
        return tamanho;
    }
    

