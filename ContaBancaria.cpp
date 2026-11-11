#include "ContaBancaria.hpp"
#include <iostream>
#include <iomanip>

ContaBancaria::ContaBancaria(int numero, const std::string& nomeTitular, double saldoInicial)
    : numeroConta(numero), titular(nomeTitular), saldo(saldoInicial >= 0.0 ? saldoInicial : 0.0) {}

bool ContaBancaria::depositar(double valor) {
    if (valor <= 0.0) {
        std::cout << "[Erro] O valor de deposito deve ser maior que zero.\n";
        return false;
    }
    saldo += valor;
    std::cout << "[Sucesso] Deposito de R$ " << std::fixed << std::setprecision(2) << valor << " realizado.\n";
    return true;
}

bool ContaBancaria::sacar(double valor) {
    if (valor <= 0.0) {
        std::cout << "[Erro] O valor de saque deve ser maior que zero.\n";
        return false;
    }
    if (valor > saldo) {
        std::cout << "[Erro] Saldo insuficiente! Saldo atual: R$ " << std::fixed << std::setprecision(2) << saldo << "\n";
        return false;
    }
    saldo -= valor;
    std::cout << "[Sucesso] Saque de R$ " << std::fixed << std::setprecision(2) << valor << " realizado.\n";
    return true;
}

void ContaBancaria::exibirDados() const {
    std::cout << "----------------------------------------\n";
    std::cout << "Conta:   " << numeroConta << "\n";
    std::cout << "Titular: " << titular << "\n";
    std::cout << "Saldo:   R$ " << std::fixed << std::setprecision(2) << saldo << "\n";
    std::cout << "----------------------------------------\n";
}

int ContaBancaria::getNumeroConta() const {
    return numeroConta;
}

std::string ContaBancaria::getTitular() const {
    return titular;
}

double ContaBancaria::getSaldo() const {
    return saldo;
}

