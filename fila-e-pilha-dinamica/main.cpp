#include <iostream>
#include <cstdlib>

using namespace std;

struct Produto {
    int codigo;
    float preco;
};

struct Node {
    Produto produto;
    Node* proximo;
};

class Pilha {
private:
    Node* topo;
public:
    Pilha() : topo(nullptr) {}
    ~Pilha() {
        while (topo) {
            Node* temp = topo;
            topo = topo->proximo;
            delete temp;
        }
    }

    void empilhar(Produto produto) {
        Node* novoNode = new Node;
        novoNode->produto = produto;
        novoNode->proximo = topo;
        topo = novoNode;
    }

    bool desempilhar(Produto& produto) {
        if (topo) {
            produto = topo->produto;
            Node* temp = topo;
            topo = topo->proximo;
            delete temp;
            return true;
        }
        return false;
    }

    void imprimir() {
        Node* atual = topo;
        while (atual) {
            cout << "Código: " << atual->produto.codigo << ", Preço: " << atual->produto.preco << "\n";
            atual = atual->proximo;
        }
    }

    int tamanho() {
        int count = 0;
        Node* atual = topo;
        while (atual) {
            count++;
            atual = atual->proximo;
        }
        return count;
    }

    bool buscar(int codigo) {
        Node* atual = topo;
        while (atual) {
            if (atual->produto.codigo == codigo)
                return true;
            atual = atual->proximo;
        }
        return false;
    }
};

class Fila {
private:
    Node* frente;
    Node* tras;
public:
    Fila() : frente(nullptr), tras(nullptr) {}
    ~Fila() {
        while (frente) {
            Node* temp = frente;
            frente = frente->proximo;
            delete temp;
        }
    }

    void enfileirar(Produto produto) {
        Node* novoNode = new Node;
        novoNode->produto = produto;
        novoNode->proximo = nullptr;
        if (tras)
            tras->proximo = novoNode;
        else
            frente = novoNode;
        tras = novoNode;
    }

    bool desenfileirar(Produto& produto) {
        if (frente) {
            produto = frente->produto;
            Node* temp = frente;
            frente = frente->proximo;
            delete temp;
            if (!frente)
                tras = nullptr;
            return true;
        }
        return false;
    }

    void imprimir() {
        Node* atual = frente;
        while (atual) {
            cout << "Código: " << atual->produto.codigo << ", Preço: " << atual->produto.preco << "\n";
            atual = atual->proximo;
        }
    }

    int tamanho() {
        int count = 0;
        Node* atual = frente;
        while (atual) {
            count++;
            atual = atual->proximo;
        }
        return count;
    }

    bool buscar(int codigo) {
        Node* atual = frente;
        while (atual) {
            if (atual->produto.codigo == codigo)
                return true;
            atual = atual->proximo;
        }
        return false;
    }
};

int main() {
    Pilha pilha;
    Fila fila;

    int opcao1, opcao2, opcao3;

    while (true) {
        cout << "Digite: \n";
        cout << "0 para sair.\n";
        cout << "1 para gerenciar a Pilha.\n";
        cout << "2 para gerenciar a Fila.\n";
        cin >> opcao1;

        if (opcao1 == 0)
            break;

        if (opcao1 == 1) {
            while (true) {
                cout << "Menu da Pilha: \n";
                cout << "0 para voltar para o menu anterior. \n";
                cout << "1 para inserir um elemento. \n";
                cout << "2 para remover um elemento. \n";
                cout << "3 para ver todos os elementos. \n";
                cout << "4 para ver o tamanho da estrutura. \n";
                cout << "5 para buscar por um elemento. \n";
                cin >> opcao2;

                if (opcao2 == 0)
                    break;

                if (opcao2 == 1) {
                    Produto produto;
                    cout << "Digite o código do produto: ";
                    cin >> produto.codigo;
                    cout << "Digite o preço do produto: ";
                    cin >> produto.preco;

                    if (!pilha.buscar(produto.codigo) && !fila.buscar(produto.codigo))
                        pilha.empilhar(produto);
                    else
                        cout << "O produto já está em outra estrutura.\n";
                }

                if (opcao2 == 2) {
                    Produto produto;
                    if (pilha.desempilhar(produto)) {
                        while (true) {
                            cout << "Menu de Remoção: \n";
                            cout << "0 para voltar para o menu anterior.\n";
                            cout << "1 para remover permanentemente.\n";
                            cout << "2 para colocar o elemento em outra estrutura.\n";
                            cin >> opcao3;

                            if (opcao3 == 0) {
                                pilha.empilhar(produto);  // Coloca o elemento de volta na pilha
                                break;
                            }

                            if (opcao3 == 1) {
                                cout << "Produto removido permanentemente.\n";
                                break;
                            }

                            if (opcao3 == 2) {
                                while (true) {
                                    cout << "Menu de Colocação: \n";
                                    cout << "0 para voltar para o menu anterior. \n";
                                    cout << "1 para colocar o elemento no topo da pilha. \n";
                                    cout << "2 para colocar o elemento no início da fila. \n";
                                    cin >> opcao3;

                                    if (opcao3 == 0) {
                                        pilha.empilhar(produto);  // Coloca o elemento de volta na pilha
                                        break;
                                    }

                                    if (opcao3 == 1) {
                                        if (!pilha.buscar(produto.codigo) && !fila.buscar(produto.codigo)) {
                                            pilha.empilhar(produto);
                                            cout << "Produto colocado no topo da pilha.\n";
                                            break;
                                        }
                                        else
                                            cout << "O produto já está em outra estrutura.\n";
                                    }

                                    if (opcao3 == 2) {
                                        if (!pilha.buscar(produto.codigo) && !fila.buscar(produto.codigo)) {
                                            fila.enfileirar(produto);
                                            cout << "Produto colocado no início da fila.\n";
                                            break;
                                        }
                                        else
                                            cout << "O produto já está em outra estrutura.\n";
                                    }
                                }
                                break;
                            }
                        }
                    }
                    else
                        cout << "A pilha está vazia.\n";
                }

                if (opcao2 == 3) {
                    cout << "Elementos na Pilha: \n";
                    pilha.imprimir();
                }

                if (opcao2 == 4) {
                    cout << "Tamanho da Pilha: " << pilha.tamanho() << "\n";
                }

                if (opcao2 == 5) {
                    int codigo;
                    cout << "Digite o código do produto a ser buscado: ";
                    cin >> codigo;
                    if (pilha.buscar(codigo))
                        cout << "O produto está na Pilha.\n";
                    else
                        cout << "O produto não está na Pilha.\n";
                }
            }
        }

        if (opcao1 == 2) {
            while (true) {
                cout << "Menu da Fila: \n";
                cout << "0 para voltar para o menu anterior. \n";
                cout << "1 para inserir um elemento. \n";
                cout << "2 para remover um elemento. \n";
                cout << "3 para ver todos os elementos. \n";
                cout << "4 para ver o tamanho da estrutura. \n";
                cout << "5 para buscar por um elemento. \n";
                cin >> opcao2;

                if (opcao2 == 0)
                    break;

                if (opcao2 == 1) {
                    Produto produto;
                    cout << "Digite o código do produto: ";
                    cin >> produto.codigo;
                    cout << "Digite o preço do produto: ";
                    cin >> produto.preco;

                    if (!pilha.buscar(produto.codigo) && !fila.buscar(produto.codigo))
                        fila.enfileirar(produto);
                    else
                        cout << "O produto já está em outra estrutura.\n";
                }

                if (opcao2 == 2) {
                    Produto produto;
                    if (fila.desenfileirar(produto)) {
                        while (true) {
                            cout << "Menu de Remoção: \n";
                            cout << "0 para voltar para o menu anterior.\n";
                            cout << "1 para remover permanentemente.\n";
                            cout << "2 para colocar o elemento em outra estrutura.\n";
                            cin >> opcao3;

                            if (opcao3 == 0) {
                                fila.enfileirar(produto);  // Coloca o elemento de volta na fila
                                break;
                            }

                            if (opcao3 == 1) {
                                cout << "Produto removido permanentemente.\n";
                                break;
                            }

                            if (opcao3 == 2) {
                                while (true) {
                                    cout << "Menu de Colocação: \n";
                                    cout << "0 para voltar para o menu anterior. \n";
                                    cout << "1 para colocar o elemento no topo da pilha. \n";
                                    cout << "2 para colocar o elemento no início da fila. \n";
                                    cin >> opcao3;

                                    if (opcao3 == 0) {
                                        fila.enfileirar(produto);  // Coloca o elemento de volta na fila
                                        break;
                                    }

                                    if (opcao3 == 1) {
                                        if (!pilha.buscar(produto.codigo) && !fila.buscar(produto.codigo)) {
                                            pilha.empilhar(produto);
                                            cout << "Produto colocado no topo da pilha.\n";
                                            break;
                                        }
                                        else
                                            cout << "O produto já está em outra estrutura.\n";
                                    }

                                    if (opcao3 == 2) {
                                        if (!pilha.buscar(produto.codigo) && !fila.buscar(produto.codigo)) {
                                            fila.enfileirar(produto);
                                            cout << "Produto colocado no início da fila.\n";
                                            break;
                                        }
                                        else
                                            cout << "O produto já está em outra estrutura.\n";
                                    }
                                }
                                break;
                            }
                        }
                    }
                    else
                        cout << "A fila está vazia.\n";
                }

                if (opcao2 == 3) {
                    cout << "Elementos na Fila: \n";
                    fila.imprimir();
                }

                if (opcao2 == 4) {
                    cout << "Tamanho da Fila: " << fila.tamanho() << "\n";
                }

                if (opcao2 == 5) {
                    int codigo;
                    cout << "Digite o código do produto a ser buscado: ";
                    cin >> codigo;
                    if (fila.buscar(codigo))
                        cout << "O produto está na Fila.\n";
                    else
                        cout << "O produto não está na Fila.\n";
                }
            }
        }
    }

    return 0;
}
