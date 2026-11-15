#pragma once
#include <vector>
#include <random>
#include <cmath> 

// estrutura para guardar as estatísticas de tempo
struct EstatisticasTempo {
    double media;
    double desvio_padrao;
};

// Função que gera um vetor com números aleatórios entre 0 e 65.535
inline std::vector<unsigned short> gerar_vetor_aleatorio(size_t tamanho, unsigned int semente) {
    std::mt19937 gerador(semente);
    std::uniform_int_distribution<unsigned short> distribuicao(0, 65535);
    std::vector<unsigned short> vetor(tamanho);

    // preenchendo vetor
    for (size_t i = 0; i < tamanho; i++) {
        vetor[i] = distribuicao(gerador);
    }

    return vetor;
}

// calcular média e desvio padrão dos tempos de execução
inline EstatisticasTempo calcular_estatisticas(const std::vector<double>& tempos) {
    double soma = 0.0;
    size_t total_elementos = tempos.size();

    // somar todos os tempos do vetor 
    for (size_t i = 0; i < total_elementos; i++) {
        soma = soma + tempos[i];
    }
    
    // calcular média dos tempos
    double media = soma / total_elementos;

    // calcular desvio padrão dos tempos
    double soma_diferencas_quadrado = 0.0;
    for (size_t i = 0; i < total_elementos; i++) {
        double diferenca = tempos[i] - media;
        soma_diferencas_quadrado = soma_diferencas_quadrado + (diferenca * diferenca);
    }
    
    // raiz quadrada da média das diferenças
    double desvio_padrao = std::sqrt(soma_diferencas_quadrado / total_elementos);

    // retornar estrutura com média e desvio padrão
    EstatisticasTempo resultado;
    resultado.media = media;
    resultado.desvio_padrao = desvio_padrao;
    return resultado;
}