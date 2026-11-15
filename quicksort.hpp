#pragma once
#include <vector>

inline int PARTITION(std::vector<unsigned short>& A, int p, int r) {
    int meio = p + (r - p) / 2;
    unsigned short temp_piv = A[meio];
    A[meio] = A[r];
    A[r] = temp_piv;

    unsigned short pivo = A[r]; 
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= pivo) {
            i++;
            unsigned short temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    unsigned short temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1; 
}

inline void QUICKSORT(std::vector<unsigned short>& A, int p, int r) {
    while (p < r) {
        int q = PARTITION(A, p, r); // Encontra a posição do pivô

        // Ordena recursivamente o menor lado e usa o laço para o maior lado
        if (q - p < r - q) {
            QUICKSORT(A, p, q - 1);
            p = q + 1; // O laço assume o lado direito
        } else {
            QUICKSORT(A, q + 1, r);
            r = q - 1; // O laço assume o lado esquerdo
        }
    }
}