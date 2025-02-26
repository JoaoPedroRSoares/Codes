#include <iostream>
using namespace std;

// Definindo o registro "endereco"
struct endereco {
    int numero_rua;
    int numero_casa;
};

// Definindo o registro "aluno"
struct aluno {
    int matricula;
    float nota;
    endereco end;
};

int main() {
    // Criando um vetor de alunos com 3 elementos
    aluno alunos[3];

    // Preenchendo o primeiro aluno
    alunos[0].matricula = 123;
    alunos[0].nota = 8.5;
    alunos[0].end.numero_rua = 10;
    alunos[0].end.numero_casa = 20;

    // Preenchendo o segundo aluno
    alunos[1].matricula = 456;
    alunos[1].nota = 7.0;
    alunos[1].end.numero_rua = 30;
    alunos[1].end.numero_casa = 40;

    // Preenchendo o terceiro aluno
    alunos[2].matricula = 789;
    alunos[2].nota = 9.0;
    alunos[2].end.numero_rua = 50;
    alunos[2].end.numero_casa = 60;

    // Exibindo os valores dos campos de todos os alunos
    for (int i = 0; i < 3; i++) {
        cout << "Aluno " << i+1 << endl;
        cout << "Matrícula: " << alunos[i].matricula << endl;
        cout << "Nota: " << alunos[i].nota << endl;
        cout << "Endereço: " << alunos[i].end.numero_rua << " - " << alunos[i].end.numero_casa << endl;
        cout << endl;
    }

    return 0;
}