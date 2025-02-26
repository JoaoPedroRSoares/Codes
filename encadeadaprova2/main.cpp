#include <iostream>
#include <cstdlib>

using namespace std;

// Definição da estrutura do nó da lista encadeada
struct Produto {
    int codigo;
    float preco;
    Produto* proximo;
};

// Função para sinalizar que o produto foi inserido com sucesso
void sinalizarProdutoInserido() {
    cout << "Produto inserido com sucesso!" << "\n";
}

// Função para inserir um produto de forma ordenada na lista
void inserirProduto(Produto*& lista, int codigo, float preco) {
    Produto* novoProduto = new Produto;
    novoProduto->codigo = codigo;
    novoProduto->preco = preco;
    novoProduto->proximo = nullptr;

    if (lista == nullptr || codigo < lista->codigo) {
        novoProduto->proximo = lista;
        lista = novoProduto;
        sinalizarProdutoInserido(); // Chamada da função de sinalização
    } else {
        Produto* anterior = lista;
        Produto* atual = lista->proximo;

        while (atual != nullptr && codigo > atual->codigo) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == nullptr || codigo != atual->codigo) {
            anterior->proximo = novoProduto;
            novoProduto->proximo = atual;
            sinalizarProdutoInserido(); // Chamada da função de sinalização
        } else {
            cout << "Erro: código repetido. Produto não inserido." << "\n";
            delete novoProduto;
        }
    }
}

// Função para contar a quantidade de produtos na lista
int contarProdutos(const Produto* lista) {
    int contador = 0;
    const Produto* atual = lista;

    while (atual != nullptr) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

// Função para procurar um produto pela chave primária
Produto* procurarProduto(const Produto* lista, int codigo) {
    const Produto* atual = lista;

    while (atual != nullptr) {
        if (atual->codigo == codigo) {
            return const_cast<Produto*>(atual); // Convertendo const Produto* para Produto*
        }
        atual = atual->proximo;
    }

    return nullptr;
}

// Função para mostrar todos os produtos da lista
void mostrarProdutos(const Produto* lista) {
    const Produto* atual = lista;

    while (atual != nullptr) {
        cout <<"\nProdutos encontrados:\n" << "Código: " << atual->codigo << ", Preço: " << atual->preco << "\n";
        atual = atual->proximo;
    }
}

// Função para eliminar um produto da lista
void eliminarProduto(Produto*& lista, int codigo) {
    Produto* anterior = nullptr;
    Produto* atual = lista;

    while (atual != nullptr && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != nullptr) {
        if (anterior == nullptr) {
            lista = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        delete atual;
        cout << "Produto removido com sucesso." << "\n";
    } else {
        cout << "Produto não encontrado." << "\n";
    }
}

// Função para liberar a memória ocupada pela lista
void liberarLista(Produto*& lista) {
    Produto* atual = lista;

    while (atual != nullptr) {
        Produto* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    lista = nullptr;
}

int main() {
    Produto* lista = nullptr;
    int opcao;

    int codigo, chave;
    float preco;
    Produto* produtoEncontrado = nullptr;

    do {
        cout << "Menu:\n"
             << "0 - Sair\n"
             << "1 - Inserir produto\n"
             << "2 - Contar quantidade de produtos\n"
             << "3 - Procurar produto pelo codigo primário\n"
             << "4 - Mostrar todos os produtos\n"
             << "5 - Eliminar produto da lista\n"
             << "Escolha uma opçao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                break;
            case 1:
                cout << "Digite o código do produto: ";
                cin >> codigo;
                cout << "Digite o preço do produto: ";
                cin >> preco;
                inserirProduto(lista, codigo, preco);
                break;
            case 2:
                cout << "Quantidade de produtos na lista: " << contarProdutos(lista) << "\n";
                break;
            case 3:
                cout << "Digite a codigo primário do produto a ser procurado: ";
                cin >> chave;
                produtoEncontrado = procurarProduto(lista, chave);
                if (produtoEncontrado != nullptr) {
                    cout << "\nProduto encontrado: \nCódigo: " << produtoEncontrado->codigo
                         << "\nPreço: " << produtoEncontrado->preco << "\n";
                } else {
                    cout << "Produto não encontrado." << "\n";
                }
                break;
            case 4:
                mostrarProdutos(lista);
                break;
            case 5:
                cout << "Digite o código do produto a ser removido: ";
                cin >> codigo;
                eliminarProduto(lista, codigo);
                break;
            default:
                cout << "Opçao inválida." << "\n";
                break;
        }

        cout << "\n";
    } while (opcao != 0);

    // Liberando a memória ocupada pela lista antes de encerrar o programa
    liberarLista(lista);

    return 0;
}

