#ifndef FILA
#define FILA

#include "../../headers/cliente.h"

class Fila
{
    public:
        Fila() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        virtual void Enfileira(Cliente cliente) = 0;
        virtual Cliente Desenfileira() = 0;
        virtual void Limpa() = 0;
    protected:
        int tamanho;
};

#endif