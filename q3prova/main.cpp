#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Produto {
    int codigo;
    float preco;
};

class Pilha {
private:
    Produto elementos[MAX_SIZE];
    int topo;
public:
    Pilha() : topo(-1) {} // Construtor da classe Pilha

    bool estaVazia() { // Verifica se a pilha está vazia
        return (topo == -1);
    }

    bool estaCheia() { // Verifica se a pilha está cheia
        return (topo == MAX_SIZE - 1);
    }

    void inserirElemento(int codigo, float preco) { // Insere um elemento na pilha
        if (estaCheia()) {
            cout << "Erro: a pilha esta cheia.\n";
            return;
        }

        elementos[++topo] = {codigo, preco};
        cout << "Elemento inserido com sucesso.\n";
    }

    void removerElemento() { // Remove um elemento da pilha
        if (estaVazia()) {
            cout << "Erro: a pilha esta vazia.\n";
            return;
        }

        topo--;
        cout << "Elemento removido com sucesso.\n";
    }

    void verElementos() { // Mostra todos os elementos da pilha
        if (estaVazia()) {
            cout << "A pilha esta vazia.\n";
            return;
        }

        cout << "Elementos da pilha:\n";
        for (int i = topo; i >= 0; i--) {
            cout << "Codigo: " << elementos[i].codigo << ", Preco: " << elementos[i].preco << "\n";
        }
    }

    int getTamanho() { // Retorna o tamanho da pilha
        return topo + 1;
    }

    void buscarElemento(int codigo) { // Busca por um elemento na pilha
        if (estaVazia()) {
            cout << "A pilha esta vazia.\n";
            return;
        }

        for (int i = topo; i >= 0; i--) {
            if (elementos[i].codigo == codigo) {
                cout << "Elemento encontrado: Codigo: " << elementos[i].codigo << ", Preco: " << elementos[i].preco << "\n";
                return;
            }
        }

        cout << "Elemento nao encontrado.\n";
    }
};

int main() {
    Pilha pilhas[2]; // Cria um array de objetos Pilha para gerenciar as duas pilhas
    int opcao1, opcao2, pilhaIndex;

    do {
        cout << "Menu Principal\n";
        cout << "0 para sair.\n";
        cout << "1 para gerenciar a pilha 1.\n";
        cout << "2 para gerenciar a pilha 2.\n";
        cout << "Digite sua opcao: ";
        cin >> opcao1;

        if (opcao1 == 0) {
            cout << "Saindo do programa.\n";
            break;
        }

        if (opcao1 < 1 || opcao1 > 2) {
            cout << "Opcao invalida.\n";
            continue;
        }

        pilhaIndex = opcao1 - 1; // Determina o índice da pilha selecionada no array de pilhas

        do {
            cout << "\nMenu da Pilha " << opcao1 << "\n";
            cout << "0 para voltar para o menu anterior.\n";
            cout << "1 para inserir um elemento.\n";
            cout << "2 para remover um elemento.\n";
            cout << "3 para ver todos os elementos da pilha.\n";
            cout << "4 para ver o tamanho da pilha.\n";
            cout << "5 para buscar por um elemento.\n";
            cout << "Digite sua opcao: ";
            cin >> opcao2;

            switch (opcao2) {
                case 0:
                    break;

                case 1:
                    int codigo;
                    float preco;
                    cout << "Digite o codigo do produto: ";
                    cin >> codigo;
                    cout << "Digite o preco do produto: ";
                    cin >> preco;
                    pilhas[pilhaIndex].inserirElemento(codigo, preco);
                    break;

                case 2:
                    pilhas[pilhaIndex].removerElemento();
                    break;

                case 3:
                    pilhas[pilhaIndex].verElementos();
                    break;

                case 4:
                    cout << "Tamanho da pilha: " << pilhas[pilhaIndex].getTamanho() << "\n";
                    break;

                case 5:
                    int codigoBusca;
                    cout << "Digite o codigo do produto a ser buscado: ";
                    cin >> codigoBusca;
                    pilhas[pilhaIndex].buscarElemento(codigoBusca);
                    break;

                default:
                    cout << "Opcao invalida.\n";
            }
        } while (opcao2 != 0);

    } while (opcao1 != 0);

    return 0;
}