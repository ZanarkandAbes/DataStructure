/* Biblioteca da TAD: Conta Bancária */

#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    float saldo;

}ContaBancaria;

void Inicializa(ContaBancaria *conta, int numero, float saldo);

void Deposito(ContaBancaria *conta, float valor);

void Saque(ContaBancaria *conta, float valor);

void Imprime(ContaBancaria *conta);

void Inicializa(ContaBancaria *conta, int numero, float saldo){
    printf("aaaaa inicializa\n");
    conta->numero = numero;
    conta->saldo = saldo;

}

void Deposito(ContaBancaria *conta, float valor){

    conta->saldo += valor;

}

void Saque(ContaBancaria *conta, float valor){

    conta->saldo -= valor;

}

void Imprime(ContaBancaria *conta){

    printf("Numero: %d\n", conta->numero);
    printf("Saldo: %.2f\n", conta->saldo);

}

#endif
