#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Estrutura de dados para representar um produto
struct Produto {
    int codigo;
    float preco;
    string dataValidade;
};

// Função para inserir um novo produto na lista
void inserirProduto(vector<Produto>& listaProdutos) {
    Produto novoProduto;
    cout << "Digite o código do produto: ";
    cin >> novoProduto.codigo;

    // Verifica se já existe um produto com o mesmo código na lista
    for (const Produto& produto : listaProdutos) {
        if (produto.codigo == novoProduto.codigo) {
            cout << "Um produto com o mesmo código já existe na lista." << "\n";
            return;
        }
    }

    cout << "Digite o preço do produto: ";
    cin >> novoProduto.preco;

    cout << "Digite a data de validade do produto (dd/mm/aaaa): ";
    cin >> novoProduto.dataValidade;

    // Insere o novo produto na lista
    listaProdutos.push_back(novoProduto);
    cout << "Produto inserido com sucesso." << "\n";
}

// Função para contar a quantidade de produtos na lista
void contarProdutos(const vector<Produto>& listaProdutos) {
    cout << "A lista contém " << listaProdutos.size() << " produto(s)." << "\n";
}

// Função para procurar um produto pelo código
void procurarProduto(const vector<Produto>& listaProdutos) {
    int codigoBusca;
    cout << "Digite o código do produto que deseja procurar: ";
    cin >> codigoBusca;

    // Procura o produto pelo código na lista
    for (const Produto& produto : listaProdutos) {
        if (produto.codigo == codigoBusca) {
            cout << "Produto encontrado:" <<"\n";
            cout << "Código: " << produto.codigo << "\n";
            cout << "Preço: " << produto.preco << "\n";
            cout << "Data de validade: " << produto.dataValidade << "\n";
            return;
        }
    }

    cout << "Produto não encontrado." << "\n";
}

// Função para mostrar todos os produtos da lista (com código e preço)
void mostrarProdutos(const vector<Produto>& listaProdutos) {
    cout << "Lista de produtos:" << "\n";
    for (const Produto& produto : listaProdutos) {
        cout << "Código: " << produto.codigo << ", Preço: " << produto.preco << "\n";
    }
}

// Função para ordenar a lista de produtos pelo código ou pelo preçpreço
void ordenarLista(vector<Produto>& listaProdutos, bool ordenarPorCodigo) {
    // Função lambda para determinar a ordem de comparação
    sort(listaProdutos.begin(), listaProdutos.end(), [ordenarPorCodigo](const Produto& p1, const Produto& p2) {
        return ordenarPorCodigo ? p1.codigo < p2.codigo : p1.preco < p2.preco;
    });

    // Determina o nome do algoritmo usado para ordenação
    string algoritmo = ordenarPorCodigo ? "Algoritmo 1" : "Algoritmo 2";
    cout << "Lista ordenada usando o " << algoritmo << "." << "\n";
}

// Função para excluir um produto da lista
void excluirProduto(vector<Produto>& listaProdutos) {
    int codigoExclusao;
    cout << "Digite o código do produto que deseja excluir: ";
    cin >> codigoExclusao;

    // Procura o produto pelo código na lista
    auto it = find_if(listaProdutos.begin(), listaProdutos.end(), [codigoExclusao](const Produto& produto) {
        return produto.codigo == codigoExclusao;
    });

    if (it == listaProdutos.end()) {
        cout << "Produto não encontrado." << "\n";
    } else {
        // Remove o produto da lista
        listaProdutos.erase(it);
        cout << "Produto excluído com sucesso." << "\n";
    }
}

// Função para contar produtos com preço maior que um valor especificado
void contarProdutosPorPreco(const vector<Produto>& listaProdutos) {
    float p;
    cout << "Digite um número real positivo p: ";
    cin >> p;

    // Conta os produtos usando uma função lambda como critério
    int quantidade = count_if(listaProdutos.begin(), listaProdutos.end(), [p](const Produto& produto) {
        return produto.preco > p;
    });

    cout << "Existem " << quantidade << " produto(s) com preço maior que " << p << "." << "\n";
}
// Principal, onde chama as outras funções
int main() {
    vector<Produto> listaProdutos;

    int escolha;
    do {
        cout << "\n";
        cout << "Selecione uma opção:" << "\n";
        cout << "0 - Sair" << "\n";
        cout << "1 - Inserir um produto" << "\n";
        cout << "2 - Contar a quantidade de produtos na lista" << endl;
        cout << "3 - Procurar um produto pelo código" << "\n";
        cout << "4 - Mostrar todos os produtos da lista (com código e preço)" << "\n";
        cout << "5 - Ordenar a lista pelo código" << "\n";
        cout << "6 - Ordenar a lista pelo preço" << "\n";
        cout << "7 - Excluir um produto da lista" << "\n";
        cout << "8 - Contar produtos com preço maior que p" << "\n";
        cin >> escolha;

        switch (escolha) {
            case 0:
                cout << "Encerrando o programa." << "\n";
                break;
            case 1:
                inserirProduto(listaProdutos);
                break;
            case 2:
                contarProdutos(listaProdutos);
                break;
            case 3:
                procurarProduto(listaProdutos);
                break;
            case 4:
                mostrarProdutos(listaProdutos);
                break;
            case 5:
                ordenarLista(listaProdutos, true);
                break;
            case 6:
                ordenarLista(listaProdutos, false);
                break;
            case 7:
                excluirProduto(listaProdutos);
                break;
            case 8:
                contarProdutosPorPreco(listaProdutos);
                break;
            default:
                cout << "Opção inválida." << "\n";
                break;
        }
    } while (escolha != 0);

    return 0;
}

