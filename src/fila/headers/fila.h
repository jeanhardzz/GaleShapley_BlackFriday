#ifndef FILA
#define FILA

#include "../../headers/loja.h"

class Fila
{
    public:
        Fila() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        virtual void Enfileira(Loja loja) = 0;
        virtual Loja Desenfileira() = 0;
        virtual void Limpa() = 0;
    protected:
        int tamanho;
};

#endif