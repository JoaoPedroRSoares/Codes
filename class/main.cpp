#include <iostream>

using namespace std;
class carro
{
    private:
    int ano;
    float valor;
    float kmrodados;
    public:
    carro (int a, float v, float kms);
    int getano();
    float getvalor();
    float exibekms();
    
    };
int main()
{
   carro fusca(1974, 4000, 1000000);
   cout<<"o ano do fusca é: "<< fusca.getano()<<"\n";
   cout<<"O valor do fusca é: "<<fusca.getvalor()<<"\n";
   cout<<"O fusca já rodou: "<<fusca.exibekms()<<"Km \n";
    return 0;
}
carro::carro(int a, float v, float kms){
    ano=a;
    valor=v;
    kmrodados=kms;
}
int carro::getano(){
    return ano;
}
float carro::getvalor(){
    return valor;
}
float carro::exibekms(){
    return kmrodados;
}
