#include <iostream>
using namespace std;
const int MAX_SIZE = 100; // tamanho máximo da fila

// Estrutura que representa um produto
struct Produto {
    int codigo;
    float preco;
};

// Estrutura que representa uma fila de produtos
struct Fila {
    Produto elementos[MAX_SIZE]; // Array para armazenar os produtos
    int inicio, fim, quantidade; // Índices para controlar a posição dos elementos na fila
};

// Função para inicializar a fila
void inicializarFila(Fila& fila) {
    fila.inicio = fila.fim = fila.quantidade = 0;
}

// Função para verificar se a fila está cheia
bool filaCheia(const Fila& fila) {
    return fila.quantidade == MAX_SIZE;
}

// Função para verificar se a fila está vazia
bool filaVazia(const Fila& fila) {
    return fila.quantidade == 0;
}

// Função para inserir um produto na fila
void inserirProduto(Fila& fila) {
    if (filaCheia(fila)) { // Verifica se a fila está cheia
        cout << "A fila está cheia.\n";
        return;
    }

    Produto produto;
    cout << "Digite o código do produto: ";
    cin >> produto.codigo;
// Verifica se o código do produto já existe na fila
    for (int i = fila.inicio; i < fila.fim; i++) {
        if (fila.elementos[i].codigo == produto.codigo) {
            cout << "Produto com código repetido. Insira outro código.\n";
            return;
        }
    }
    cout << "Digite o preço do produto: ";
    cin >> produto.preco;
// Insere o produto no final da fila
    fila.elementos[fila.fim] = produto;
    fila.fim++;
    fila.quantidade++;

    cout << "Produto inserido com sucesso.\n";
}

// Função para contar a quantidade de produtos na fila
int contarProdutos(const Fila& fila) {
    return fila.quantidade;
}

// Função para procurar um produto na fila pelo código
void procurarProduto(const Fila& fila) {
    int codigo;
    cout << "Digite o código do produto: ";
    cin >> codigo;

    for (int i = fila.inicio; i < fila.fim; i++) {
         // Verifica se o código do produto foi encontrado
        if (fila.elementos[i].codigo == codigo) {
            cout << "Produto encontrado. Preço: " << fila.elementos[i].preco << "\n";
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}

// Função para mostrar todos os produtos da fila
void mostrarProdutos(const Fila& fila) {
    // Verifica se a fila está vazia
    if (filaVazia(fila)) { 
        cout << "A fila está vazia.\n";
        return;
    }

    cout << "Produtos:\n";
    for (int i = fila.inicio; i < fila.fim; i++) {
        cout << "Código: " << fila.elementos[i].codigo << ", Preço: " << fila.elementos[i].preco << "\n";
    }
}

// Função para remover um produto da fila pelo código
void removerProduto(Fila& fila) {
    // Verifica se a fila está vazia
    if (filaVazia(fila)) {
        cout << "A fila está vazia.\n";
        return;
    }

    int codigo;
    cout << "Digite o código do produto a ser removido: ";
    cin >> codigo;

    for (int i = fila.inicio; i < fila.fim; i++) {
        if (fila.elementos[i].codigo == codigo) { // Verifica se o código do produto foi encontrado
            for (int j = i; j < fila.fim - 1; j++) {
                fila.elementos[j] = fila.elementos[j + 1];
            }

            fila.fim--;
            fila.quantidade--;

            cout << "Produto removido com sucesso.\n";
            return;
        }
    }

    cout << "Produto não encontrado.\n";
}

int main() {
    Fila fila;
    inicializarFila(fila); // Inicializa a fila

    int opcao;

    do {
        cout << "Menu:\n";
        cout << "0 - Sair\n";
        cout << "1 - Inserir um produto\n";
        cout << "2 - Contar a quantidade de produtos na lista\n";
        cout << "3 - Procurar um produto pela chave primária\n";
        cout << "4 - Mostrar todos os produtos da lista\n";
        cout << "5 - Eliminar um produto da lista\n";
        cout << "Digite sua opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa.\n";
                break;
            case 1:
                inserirProduto(fila);
                break;
            case 2:
                cout << "Quantidade de produtos na lista: " << contarProdutos(fila) << "\n";
                break;
            case 3:
                procurarProduto(fila);
                break;
            case 4:
                mostrarProdutos(fila);
                break;
            case 5:
                removerProduto(fila);
                break;
            default:
                cout << "Opção inválida.\n";
        }

        cout << "\n";
    } while (opcao != 0);

    return 0;
}