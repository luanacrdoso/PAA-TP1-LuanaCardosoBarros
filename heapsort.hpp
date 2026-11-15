#pragma once
#include <vector>

inline void HEAPIFY(std::vector<unsigned short>& A, size_t n, size_t i) {
    size_t maior = i;
    size_t esq = 2 * i + 1; // filho esquerdo
    size_t dir = 2 * i + 2; // filho direito 

    // compara com o filho esquerdo
    if (esq < n && A[esq] > A[maior]) {
        maior = esq;
    }
    // compara com o filho direito
    if (dir < n && A[dir] > A[maior]) {
        maior = dir;
    }
    // Se o maior não for o pai i, faz a troca e chama o HEAPIFY na posição alterada
    if (maior != i) {
        unsigned short temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;

        HEAPIFY(A, n, maior);
    }
}

inline void BUILD_HEAP(std::vector<unsigned short>& A, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        HEAPIFY(A, n, i);
    }
}

inline void HEAPSORT(std::vector<unsigned short>& A) {
    int n = A.size(); 
    if (n <= 1) return;

    BUILD_HEAP(A, n);

    for (int i = n - 1; i > 0; i--) {
        unsigned short temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        HEAPIFY(A, i, 0);
    }
}