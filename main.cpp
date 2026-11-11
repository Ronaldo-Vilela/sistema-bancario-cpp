#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "ContaBancaria.hpp"

ContaBancaria* buscarConta(std::vector<ContaBancaria>& contas, int numero) {
    for (auto& conta : contas) {
        if (conta.getNumeroConta() == numero) {
            return &conta;
        }
    }
    return nullptr;
}

void limparBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<ContaBancaria> contas;
    int opcao = 0;

    do {
        std::cout << "\n===== SISTEMA BANCARIO =====\n";
        std::cout << "1. Criar nova conta\n";
        std::cout << "2. Consultar saldo / dados da conta\n";
        std::cout << "3. Depositar\n";
        std::cout << "4. Sacar\n";
        std::cout << "5. Listar todas as contas\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cout << "[Erro] Entrada invalida! Digite um numero.\n";
            limparBuffer();
            continue;
        }

        switch (opcao) {
            case 1: {
                int numero;
                std::string nome;
                double saldoInicial;

                std::cout << "Numero da conta: ";
                if (!(std::cin >> numero)) {
                    std::cout << "[Erro] Numero de conta invalido.\n";
                    limparBuffer();
                    break;
                }

                if (buscarConta(contas, numero) != nullptr) {
                    std::cout << "[Erro] Ja existe uma conta com esse numero!\n";
                    break;
                }

                limparBuffer();
                std::cout << "Nome do titular: ";
                std::getline(std::cin, nome);

                std::cout << "Saldo inicial (R$): ";
                if (!(std::cin >> saldoInicial)) {
                    std::cout << "[Erro] Valor invalido.\n";
                    limparBuffer();
                    break;
                }

                contas.emplace_back(numero, nome, saldoInicial);
                std::cout << "[Sucesso] Conta criada com sucesso!\n";
                break;
            }
            case 2: {
                int numero;
                std::cout << "Informe o numero da conta: ";
                std::cin >> numero;

                ContaBancaria* conta = buscarConta(contas, numero);
                if (conta) {
                    conta->exibirDados();
                } else {
                    std::cout << "[Erro] Conta nao encontrada.\n";
                }
                break;
            }
            case 3: {
                int numero;
                double valor;
                std::cout << "Informe o numero da conta: ";
                std::cin >> numero;

                ContaBancaria* conta = buscarConta(contas, numero);
                if (conta) {
                    std::cout << "Valor para deposito (R$): ";
                    std::cin >> valor;
                    conta->depositar(valor);
                } else {
                    std::cout << "[Erro] Conta nao encontrada.\n";
                }
                break;
            }
            case 4: {
                int numero;
                double valor;
                std::cout << "Informe o numero da conta: ";
                std::cin >> numero;

                ContaBancaria* conta = buscarConta(contas, numero);
                if (conta) {
                    std::cout << "Valor para saque (R$): ";
                    std::cin >> valor;
                    conta->sacar(valor);
                } else {
                    std::cout << "[Erro] Conta nao encontrada.\n";
                }
                break;
            }
            case 5: {
                if (contas.empty()) {
                    std::cout << "Nenhuma conta cadastrada.\n";
                } else {
                    std::cout << "\n--- Lista de Contas ---\n";
                    for (const auto& conta : contas) {
                        conta.exibirDados();
                    }
                }
                break;
            }
            case 0:
                std::cout << "Encerrando o sistema bancario. Ate logo!\n";
                break;
            default:
                std::cout << "[Erro] Opcao invalida!\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}

