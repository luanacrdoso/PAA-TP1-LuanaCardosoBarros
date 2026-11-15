# 📊 TP1 — Análise Empírica de Algoritmos de Ordenação

**Disciplina:** Projeto e Análise de Algoritmos (PAA)  
**Instituição:** Escola Superior de Tecnologia — Universidade do Estado do Amazonas (EST/UEA)  
**Professor:** Dr. Márcio Palheta Piedade  
**Aluna:** Luana Cardoso Barros  

---

## 📌 Descrição do Projeto

Este projeto tem como objetivo realizar a análise empírica do tempo de execução de três algoritmos clássicos de ordenação baseados em comparação:

* **Mergesort** (Divisão e Conquista)
* **Heapsort** (Baseado na estrutura de Max-Heap)
* **Quicksort** (Divisão e Conquista com pivô no último elemento)

O programa avalia a performance dos três algoritmos sobre vetores aleatórios com elementos do tipo `unsigned short` em **5 tamanhos diferentes**:
* \\(N = 1.000\\)
* \\(N = 10.000\\)
* \\(N = 100.000\\)
* \\(N = 1.000.000\\)
* \\(N = 10.000.000\\)

Para cada tamanho \\(N\\), são executadas **50 repetições** com sementes pseudoaleatórias idênticas para garantir a equidade dos testes entre os algoritmos. Ao final, são exibidos no terminal a **Média** e o **Desvio Padrão** do tempo de execução (em segundos).

---

## 📁 Estrutura do Código-Fonte

O projeto foi modularizado em arquivos de cabeçalho (`.hpp`) e no arquivo principal de execução (`.cpp`):

```text
PAA-TP1-LuanaCardosoBarros/
├── main.cpp          # Fluxo principal, cronometria (std::chrono) e laços de repetição
├── utils.hpp         # Geração de vetores aleatórios e cálculos estatísticos (Média e Desvio Padrão)
├── mergesort.hpp     # Funções MERGE e MERGE_SORT (C++ 0-indexed)
├── heapsort.hpp      # Funções HEAPIFY, BUILD_HEAP e HEAPSORT
├── quicksort.hpp     # Funções PARTITION e QUICKSORT
└── README.md         # Manual de compilação e execução do projeto

---

## 🛠️ Pré-requisitos e Compilação

### Pré-requisitos
* Compilador C++ compatível com o padrão C++11 ou superior (recomendado: **g++ / GCC**).
* Terminal (Prompt de Comando, PowerShell, Git Bash ou Terminal Linux/macOS).

### Comando de Compilação

Abra o terminal no diretório do projeto e execute o comando correspondente ao seu sistema operacional:

* **No Windows (Prompt de Comando / PowerShell):**
  ```cmd
  g++ -O3 main.cpp -o tp1.exe

* **No Linux / macOS / Git Bash:**
  ```cmd
  g++ -O3 main.cpp -o tp1

---
🚀 Como Executar
Após a compilação bem-sucedida, execute o binário gerado:
* **No Windows (PowerShell / Prompt de Comando):**
  ```cmd
  .\tp1.exe
* **No Linux / macOS / Git Bash:
  ```cmd
  ./tp1