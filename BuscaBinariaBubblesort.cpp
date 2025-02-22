/*
Busca Binária com Bubble Sort
*/

#include <iostream>     // Para entrada e saída (cout, cin)
#include <vector>       // Para usar o container vector
#include <string>       // Para manipular strings
#include <ctime>        // Para medir o tempo (clock, CLOCKS_PER_SEC)
#include <iomanip>      // Para formatar a saída (fixed, setprecision)
#include <algorithm>    // Para usar swap()

using namespace std;

// Função Bubble Sort
// Ordena o vetor 'nomes' em ordem lexicográfica (crescente)
void bubbleSort(vector<string>& nomes) {
    bool trocou;  // Flag para indicar se houve troca nesta passagem

    // Laço externo: determina quantas passagens serão feitas.
    // Para um vetor com n elementos, são necessárias (n - 1) passagens no pior caso.
    // Se nomes.size() for 200, i varia de 0 até 198 (totalizando 199 passagens).
    for (size_t i = 0; i < nomes.size() - 1; i++) {
        trocou = false;  // Reinicia a flag para cada passagem

        // Laço interno: percorre o vetor até o último elemento não ordenado.
        // A condição "j < nomes.size() - 1 - i" garante que:
        // 1) "- 1" evita acesso fora do limite, já que comparamos nomes[j] com nomes[j+1].
        // 2) "- i" descarta os últimos 'i' elementos, que já estão ordenados.
        // Exemplo:
        // - Na primeira passagem (i = 0): j varia de 0 até (200 - 1 - 0) = 199, ou seja, 199 iterações.
        // - Na segunda passagem (i = 1): j varia de 0 até (200 - 1 - 1) = 198 iterações.
        // ...
        // No pior caso, o total de iterações é:
        // 199 + 198 + 197 + ... + 1 = (199 * 200) / 2 = 19.900 iterações.
        for (size_t j = 0; j < nomes.size() - 1 - i; j++) {
            // Se o elemento atual for maior que o próximo, troca-os.
            if (nomes[j] > nomes[j + 1]) {
                swap(nomes[j], nomes[j + 1]);
                trocou = true;  // Indica que houve uma troca nesta passagem
            }
        }
        // Se não ocorrer nenhuma troca, o vetor já está ordenado, então podemos sair do laço.
        if (!trocou)
            break;
    }
}

// Função de Busca Binária
// Pressupõe que o vetor 'nomes' esteja ordenado.
// Procura a 'chave' no vetor e retorna o índice se encontrada, ou -1 se não encontrada.
int buscaBinaria(const vector<string>& nomes, const string& chave) {
    int inicio = 0;  // Início do intervalo de busca
    // Calcula o índice do último elemento. Como os índices vão de 0 a (size - 1),
    // usamos static_cast<int>(nomes.size()) - 1 para converter o tamanho para int e subtrair 1.
    int fim = static_cast<int>(nomes.size()) - 1;
    
    // Enquanto o intervalo for válido
    while (inicio <= fim) {
        // Calcula o índice do elemento do meio
        int meio = inicio + (fim - inicio) / 2;
        // Se o elemento do meio for igual à chave, retorna o índice
        if (nomes[meio] == chave)
            return meio;
        // Se o elemento do meio for menor que a chave, a chave deve estar na metade superior
        else if (nomes[meio] < chave)
            inicio = meio + 1;
        // Caso contrário, a chave deve estar na metade inferior
        else
            fim = meio - 1;
    }
    // Retorna -1 se a chave não for encontrada
    return -1;
}

int main() {
    // Cria um array de ponteiros para const char com os nomes.
    // Cada elemento do array é um ponteiro para uma string literal (o texto em si é armazenado em outra área de memória).
    const char* arr[] = {
        "Gustavo Costa", "Fabiana Barbosa", "Igor Martins", "Natália Souza", "Bruno Martins", 
        "Otávio Lima", "Carlos Almeida", "Paula Silva", "Alice Lima", "Beatriz Lima", 
        "Beatriz Souza", "Helena Fernandes", "Marcos Almeida", "Daniel Barbosa", "Otávio Dias", 
        "Igor Barbosa", "Marcos Lima", "Eduardo Costa", "Eduardo Fernandes", "Fernanda Silva", 
        "Cecilia Azevedo", "Fernanda Lima", "Juliana Silva", "Larissa Almeida", "Beatriz Silva", 
        "Juliana Barbosa", "Amanda Martins", "Gustavo Barbosa", "Otávio Costa", "Larissa Martins", 
        "Paula Fernandes", "Marcos Dias", "Helena Lima", "Amanda Lima", "Gabriel Almeida", 
        "Carlos Dias", "Helena Costa", "Daniel Silva", "Fernanda Martins", "Marcos Barbosa", 
        "Otávio Barbosa", "Marcos Silva", "Larissa Silva", "Fernanda Fernandes", "Larissa Barbosa", 
        "Cecilia Silva", "Fernanda Souza", "Daniel Dias", "Cecilia Martins", "Eduardo Almeida", 
        "Juliana Almeida", "Fabiana Martins", "Igor Fernandes", "Amanda Fernandes", "Carlos Silva", 
        "Cecilia Souza", "Beatriz Dias", "Marcos Fernandes", "Amanda Barbosa", "Carlos Souza", 
        "Natália Costa", "Helena Silva", "Fabiana Almeida", "Amanda Souza", "Igor Dias", 
        "Amanda Almeida", "Bruno Souza", "Amanda Costa", "Eduardo Dias", "Gabriel Azevedo", 
        "Natália Silva", "Alice Martins", "Carlos Costa", "Alice Silva", "Natália Barbosa", 
        "Bruno Barbosa", "Paula Azevedo", "Bruno Dias", "Daniel Azevedo", "Paula Lima", 
        "Otávio Fernandes", "Larissa Souza", "Fabiana Souza", "Daniel Lima", "Fernanda Azevedo", 
        "Beatriz Almeida", "Fabiana Lima", "Cecilia Dias", "Juliana Souza", "Amanda Azevedo", 
        "Juliana Costa", "Alice Souza", "Fabiana Azevedo", "Igor Lima", "Cecilia Almeida", 
        "Fernanda Costa", "Natália Martins", "Gustavo Fernandes", "Fabiana Silva", "Fabiana Costa", 
        "Fernanda Almeida", "Gabriel Lima", "Beatriz Azevedo", "Cecilia Lima", "Larissa Lima", 
        "Carlos Fernandes", "Natália Almeida", "Alice Fernandes", "Eduardo Martins", "Paula Dias", 
        "Fabiana Fernandes", "Eduardo Souza", "Bruno Lima", "Gustavo Martins", "Alice Barbosa", 
        "Gabriel Costa", "Eduardo Barbosa", "Igor Souza", "Gustavo Lima", "Otávio Almeida", 
        "Beatriz Barbosa", "Natália Azevedo", "Juliana Fernandes", "Bruno Almeida", "Amanda Dias", 
        "Gustavo Souza", "Helena Barbosa", "Igor Almeida", "Cecilia Fernandes", "Helena Dias", 
        "Natália Fernandes", "Alice Costa", "Beatriz Costa", "Juliana Azevedo", "Igor Silva", 
        "Marcos Souza", "Carlos Lima", "Larissa Costa", "Paula Martins", "Paula Almeida", 
        "Daniel Costa", "Daniel Souza", "Daniel Almeida", "Otávio Martins", "Otávio Souza", 
        "Helena Souza", "Eduardo Silva", "Beatriz Martins", "Carlos Martins", "Fabiana Dias", 
        "Fernanda Barbosa", "Gustavo Silva", "Eduardo Lima", "Gabriel Silva", "Natália Dias", 
        "Marcos Azevedo", "Fernanda Dias", "Otávio Silva", "Gustavo Almeida", "Paula Barbosa", 
        "Helena Almeida", "Larissa Azevedo", "Marcos Martins", "Cecilia Costa", "Juliana Dias", 
        "Carlos Barbosa", "Gabriel Fernandes", "Igor Costa", "Bruno Silva", "Gabriel Barbosa", 
        "Daniel Martins", "Eduardo Azevedo", "Bruno Fernandes", "Alice Almeida", "Paula Souza", 
        "Alice Azevedo", "Cecilia Barbosa", "Natália Lima", "Juliana Lima", "Paula Costa", 
        "Larissa Fernandes", "Beatriz Fernandes", "Juliana Martins", "Larissa Dias", "Igor Azevedo", 
        "Marcos Costa", "Gustavo Dias", "Gabriel Martins", "Gustavo Azevedo", "Gabriel Souza", 
        "Daniel Fernandes", "Helena Martins", "Helena Azevedo", "Otávio Azevedo", "Alice Dias", 
        "Amanda Silva", "Bruno Azevedo", "Gabriel Dias", "Carlos Azevedo", "Bruno Costa"
    };

    // Calcula o número de elementos do array.
    // sizeof(arr) retorna o tamanho total do array em bytes.
    // sizeof(arr[0]) retorna o tamanho de um único elemento (um ponteiro para char).
    // A divisão resulta no número total de elementos.
    int n = sizeof(arr) / sizeof(arr[0]);

    // Preenche o vetor 'nomes' utilizando o intervalo do array.
    // O construtor vector<string>(arr, arr + n) copia os elementos do intervalo [arr, arr + n)
    // para dentro do vetor, convertendo cada const char* para um objeto string.
    vector<string> nomes(arr, arr + n);

    // Ordena o vetor usando o Bubble Sort (exemplo de algoritmo de ordenação)
    bubbleSort(nomes);

    // Solicita a entrada do usuário para o nome a ser procurado.
    string chave;
    cout << "Busca Binária com Bubble Sort - Digite o nome completo a ser procurado: ";
    getline(cin, chave);  // Lê a linha inteira, permitindo espaços na entrada

    /*
    Comparação Lexicográfica de Strings
    
    Ordenação de Strings:
    Em C++, quando você compara duas strings usando os operadores <, == ou >, a comparação é feita lexicograficamente. Isso significa que as strings são comparadas caractere a caractere, da esquerda para a direita, utilizando os valores numéricos dos caracteres (por exemplo, os códigos ASCII ou Unicode).

    Exemplo:
    Se você comparar "Alice" e "Bruno", o operador < verificará primeiro os caracteres 'A' e 'B'. Como 'A' (65) é menor que 'B' (66) na tabela ASCII, a comparação determinará que "Alice" é menor que "Bruno".
    */

    // Mede o tempo da busca binária usando clock()
    clock_t inicio = clock();
    // Chama a função buscaBinaria para procurar a chave no vetor ordenado
    int indice = buscaBinaria(nomes, chave);
    clock_t fim = clock();
    // Calcula a duração em segundos, convertendo ticks para segundos
    double duracao = double(fim - inicio) / CLOCKS_PER_SEC;

    // Configura a saída para exibir números com notação fixa e 6 casas decimais
    cout << fixed << setprecision(6);
    // Verifica se o elemento foi encontrado e exibe o resultado
    if (indice != -1)
        cout << "Busca Binária: '" << chave << "' encontrado no índice " << indice;
    else
        cout << "Busca Binária: '" << chave << "' não encontrado.";
    // Exibe o tempo de execução da busca
    cout << " Tempo: " << duracao << " segundos.\n";

    return 0;  // Indica que o programa terminou com sucesso
}