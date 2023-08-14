// Neste problemas iremos lidar com sequências de caracteres, muitas vezes chamadas de strings. Uma sequência é não-trivial se ela possui ao menos dois elementos.

// Dada uma sequência s, dizemos que um trecho si, ... ,sj é monótono se todos seus caracteres são iguais, e dizemos que ela é maximal se este trecho não pode ser estendido à esquerda e nem à direita sem perder a monotonicidade.

//* Dada uma sequência composta apenas por caracteres “a” e “b”, determine quantos caracteres “a”
//* ocorrem em trechos monótonos maximais não-triviais.

//* Entrada
// A entrada é composta por duas linhas. A primeira linha contém um único inteiro N, satisfazendo 1≤  N ≤105. A segunda linha contém uma string, com exatamente N caracteres, composta apenas pelos caracteres “a” e “b”.

//* Saída
// A saída é composta por uma única linha contendo um inteiro correspondente à quantidade total de vezes que o caractere “a” ocorre em trechos monótonos maximais não-triviais.


//Resolução
#include <iostream>
#include <cmath>

using namespace std;

int trechos(string frase, int tamanho);

int main(){
    int tamanho;
    string frase;
    
    while (true){
        cin >> tamanho;
        if(tamanho >= 1 && tamanho <= pow(10, 5)){
            break;
        } else {
            cout << "Tamanho selecionado incorreto, tente novamente";
        }
    }

    while (true){
        cin >> frase;
        if(frase.length() == tamanho){
            break;
        } else {
            cout << "Numero de caracteres excedeu ao tamanho selecionado, tente novamente";
        }
    }
    
    cout << trechos(frase, tamanho);

}

//adicionar uma string em uma stack
int trechos(string frase, int tamanho){
    int ocorrencias = 0;

    for(int index = 0; index < tamanho; index++){
        char atual = frase[index];
        char posterior = frase[index + 1];
        char antecessor = frase[index - 1];
        if(atual == 'a'){
            if(atual == posterior && atual == antecessor){
                ocorrencias++;
            } else if (atual == posterior) {
                ocorrencias = ocorrencias + 2;
            }
        }
    }
    return ocorrencias;
} 