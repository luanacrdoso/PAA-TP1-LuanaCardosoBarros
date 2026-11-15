#pragma once
#include <vector>

inline void MERGE(std::vector<unsigned short>& A, std::vector<unsigned short>& aux, size_t p, size_t q, size_t r) {
    size_t i = p;      // Ponteiro para a metade esquerda 
    size_t j = q + 1;  // Ponteiro para a metade direita
    size_t k = p;      // Ponteiro para o vetor auxiliar

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            aux[k] = A[i];
            i++;
        } else {
            aux[k] = A[j];
            j++;
        }
        k++;
    }
    // copia os elementos restantes da esquerda
    while (i <= q) {
        aux[k] = A[i];
        i++;
        k++;
    }
    // copia os elementos restantes da direita
    while (j <= r) {
        aux[k] = A[j];
        j++;
        k++;
    }
    // copia de volta do vetor auxiliar para o vetor A
    for (size_t pos = p; pos <= r; pos++) {
        A[pos] = aux[pos];
    }
}

// MERGE-SORT(A, p, r)
inline void MERGE_SORT(std::vector<unsigned short>& A, std::vector<unsigned short>& aux, size_t p, size_t r) {
    if (p < r) {
        size_t q = p + (r - p) / 2;    // calcula o ponto médio q = (p + r) / 2
        MERGE_SORT(A, aux, p, q);      // ordena a metade esquerda A[p...q]
        MERGE_SORT(A, aux, q + 1, r);  // ordena a metade direita A[q+1...r]
        MERGE(A, aux, p, q, r);        // intercala as duas metades ordenadas
    }
}
