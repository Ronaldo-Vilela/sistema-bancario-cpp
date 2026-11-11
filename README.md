# Sistema Bancário em C++

Projeto simples de um sistema bancário em C++ orientado a objetos com suporte a criação de contas, consulta de saldo, depósito e saque.

## Estrutura do Projeto

- `ContaBancaria.hpp`: Declaração da classe `ContaBancaria`.
- `ContaBancaria.cpp`: Implementação dos métodos de depósito, saque e exibição de saldo.
- `main.cpp`: Menu interativo no console para gerenciar múltiplas contas.

## Como Compilar e Executar

Caso tenha o compilador `g++` (MinGW/GCC) instalado:

```bash
g++ -std=c++17 main.cpp ContaBancaria.cpp -o banco.exe
./banco.exe
```

Caso utilize o compilador da Microsoft (`cl` via Developer Command Prompt):

```bash
cl /EHsc main.cpp ContaBancaria.cpp /Fe:banco.exe
banco.exe
```

