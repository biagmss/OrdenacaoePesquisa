#include <iostream>
#include <vector>
#include<ctime>
#include<iomanip>

using namespace std;

//funçao de particionamento: reorganiza o vetor de forma que os elementos menores ficam a esquerda e os elementos maiores a direita,por fim ela retornna o indice da posiçao do pivo

int partition(vector<int>&vetor,int low,int high){

    int pivot = vetor[high];//ultimo elemento como pivo
    int i = low -1 ;

    //loop que percorre o vetor de low ate high -1
    for(int j = low; j<high; j++){
        if(vetor[j]<=pivot){
            int temp = vetor[i];
            vetor [i] = vetor[j];
            vetor[j]=temp;

        }
    }
    //trazer pivot para posiçao correto, i+1
    int temp = vetor[i+1];
    vetor[i+1]= vetor[high];
    vetor[high]= temp;
    return i+1;//retorna a posiçao atual do pivo
}
    //funçao quickSort recursiva para ordenar os dados de low a high
    void quickSort(vector<int>&vetor,int low,int high){
        if(low < high){

            int pi=partition(vetor,low,high);

            //recursivamente,ordenar os elementos antes do pivo
            quickSort(vetor,low,pi-1);

            quickSort(vetor,pi+1,high);
        }
    }

int main(){

    vector<int> vetor = {9,2,18,47,8,1};

    cout<<"Vetor original: ";
        for(size_t i=0;i<vetor.size();i++){
            cout<<vetor[i]<<" ";
        }cout<<endl;

        clock_t inicio = clock();
        quickSort(vetor,0,vetor.size()-1);
        clock_t fim = clock();
        double tempoExecucao = (fim-inicio)/CLOCKS_PER_SEC;

        // Exibe o vetor ordenado
    cout << "Vetor ordenado: ";
    for (size_t i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Exibe o tempo de execução formatado com 6 casas decimais
    cout << "Tempo de execucao do Quick Sort: " << fixed << setprecision(6)
        << tempoExecucao << " segundos." << endl;



    return 0 ;
}






