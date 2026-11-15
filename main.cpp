#include <iostream>  
#include <vector>    
#include <chrono>    // cronômetro para medir o tempo de execução
#include <fstream>   
#include <iomanip>

#include "utils.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"
#include "quicksort.hpp"

int main() {
    // o 5 tamanhos de vetores a serem testados
    std::vector<int> tamanhos = {1000, 10000, 100000, 1000000, 10000000};
    const int NUM_REPETICOES = 50;

    // exibir números com 7 casas decimais
    std::cout << std::fixed << std::setprecision(7);

    std::cout << "  INICIANDO OS EXPERIMENTOS DE ORDENACAO (TP1)    \n";

    // laço principal que percorre cada um dos 5 tamanhos 'N'
    for (int N : tamanhos) {
        std::cout << "\nTestando para N = " << N << " elementos\n\n";

        //MERGESORT
        {
            std::cout << "Executando Mergesort (50 vezes)" << std::flush;
            std::vector<double> tempos;

            for (int i = 0; i < NUM_REPETICOES; i++) {
                // semente '1000 + i' garante a mesma sequência aleatória para os 3 algoritmos
                auto A = gerar_vetor_aleatorio(N, 1000 + i);
                
                // vetor auxiliar alocado uma única vez para o Mergesort
                std::vector<unsigned short> aux(N);

                // inicia o cronômetro
                auto inicio = std::chrono::high_resolution_clock::now();

                MERGE_SORT(A, aux, 0, N - 1);

                // para o cronômetro
                auto fim = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duracao = fim - inicio;

                tempos.push_back(duracao.count()); // guarda o tempo em segundos
            }

            // calcula a média e o desvio padrão dos tempos de execução
            EstatisticasTempo est = calcular_estatisticas(tempos);
            std::cout << "  OK! ->  Media: " << est.media << " s | Desvio Padrao: " << est.desvio_padrao << " s\n";
        }

        //HEAPSORT
        {
            std::cout << "Executando Heapsort (50 vezes)" << std::flush;
            std::vector<double> tempos;

            for (int i = 0; i < NUM_REPETICOES; i++) {
                // mesma semente '1000 + i'
                auto A = gerar_vetor_aleatorio(N, 1000 + i);

                auto inicio = std::chrono::high_resolution_clock::now();

                HEAPSORT(A);

                auto fim = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duracao = fim - inicio;

                tempos.push_back(duracao.count());
            }

            EstatisticasTempo est = calcular_estatisticas(tempos);
            std::cout << "  OK! ->  Media: " << est.media << " s | Desvio Padrao: " << est.desvio_padrao << " s\n";

        }

        // QUICKSORT
        {
            std::cout << "Executando Quicksort (50 vezes)" << std::flush;
            std::vector<double> tempos;

            for (int i = 0; i < NUM_REPETICOES; i++) {
                // mesma semente '1000 + i'
                auto A = gerar_vetor_aleatorio(N, 1000 + i);

                auto inicio = std::chrono::high_resolution_clock::now();

                QUICKSORT(A, 0, N - 1);

                auto fim = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> duracao = fim - inicio;

                tempos.push_back(duracao.count());
            }

            EstatisticasTempo est = calcular_estatisticas(tempos);
            std::cout << "  OK! ->  Media: " << est.media << " s | Desvio Padrao: " << est.desvio_padrao << " s\n";

        }
    }

    std::cout << "\n===================================================\n";
    std::cout << " Todos os testes concluidos com sucesso!\n";

    return 0;
}