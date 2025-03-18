#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// função merge: combinar duas metades ordenadas de um vetor em uma unica sublista ordenada
// parâmetros:
// vetor - o vetor original com os elementos
// inicio - indice inicial da sublista a ser mesclada
// meio - representa o final da primeira metade (sublista da esquerda)
// fim - indice final da segunda metade (sublista da direita)
void merge(vector<int>& vetor, int inicio, int meio, int fim){
    // calcular o numero de elementos na primeira metade (esquerda)
    int n1= meio - inicio + 1;

    // calcula o num de elementos na metade da direita
    int n2 = fim - meio;

    // cria vetores temporários para armazenar as duas metades
    vector<int> esquerda(n1), direita(n2);

    // copiar os elementos da primeira metade do vetor original para o vetor esquerda
    for(int i = 0; i < n1; i++){
        esquerda[i] = vetor[inicio + i];
        // 'vetor[inicio + i]' percorre os elementos do sub vetor esquerdo
    }
    // elementos direita
    for (int j = 0; j < n2; j++){
        direita[j] = vetor[meio + 1 + j];
    }

    // inicializa os indices para percorrer os vetores temporarios
    int i = 0; // esquerda
    int j = 0; // direita
    int k = inicio; // indice para inserir os elementos no vetor original

    // while para enquanto houver elementos em ambos vetores temporários continua comparando
    while (i < n1 && j < n2) {
        // se o elemento da esquerda é menor ou igual ao elemento da direita
        if (esquerda[i] <= direita[j]){
            vetor[k] = esquerda[i]; // vetor recebe o elemento da esquerda já ordenado
            i++; // avança o prox da esquerda
        } else {
            vetor [k] = direita[j]; // vetor recebe o elemento da direita
            j++; // avança o prox da direita
        }
        k++; // avança para a proxima posição do vetor
    }

    // se ainda restarem elementos no vetor da esquerda, desce
    while(i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    // mesma coisa se sobrar elementos na direita
    while(j < n2){
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

// Exemplo de uso da função merge dentro do Merge Sort.
// O Merge Sort é um algoritmo de "divisão e conquista": ele divide o vetor recursivamente
// até obter subvetores com um único elemento (que são ordenados por definição),
// e então utiliza a função merge para combiná-los em um vetor ordenado.
void mergeSort(vector<int>& vetor, int inicio, int fim) {
    // Se o subvetor tem mais de um elemento
    if (inicio < fim) {
        // Calcula o índice do meio para dividir o vetor
        int meio = inicio + (fim - inicio) / 2;
        
        // Ordena recursivamente a primeira metade
        mergeSort(vetor, inicio, meio);
        
        // Ordena recursivamente a segunda metade
        mergeSort(vetor, meio + 1, fim);
        
        // Mescla as duas metades ordenadas
        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    // Exemplo de vetor para ordenação
    vector<int> vetor = {9, 2, 18, 47, 8, 1};
    
    // Exibe o vetor original
    cout << "Vetor original: ";
    for (size_t i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
    
    // Chama o Merge Sort para ordenar o vetor
    mergeSort(vetor, 0, vetor.size() - 1);
    
    // Exibe o vetor ordenado
    cout << "Vetor ordenado: ";
    for (size_t i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
    
    return 0;
}
