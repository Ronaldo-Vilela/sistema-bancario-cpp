#ifndef CONTA_BANCARIA_HPP
#define CONTA_BANCARIA_HPP

#include <string>

class ContaBancaria {
private:
    int numeroConta;
    std::string titular;
    double saldo;

public:
    ContaBancaria(int numero, const std::string& nomeTitular, double saldoInicial = 0.0);

    bool depositar(double valor);
    bool sacar(double valor);
    void exibirDados() const;

    int getNumeroConta() const;
    std::string getTitular() const;
    double getSaldo() const;
};

#endif // CONTA_BANCARIA_HPP

