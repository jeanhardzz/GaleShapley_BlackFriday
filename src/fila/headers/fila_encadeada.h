#ifndef FILA_ENCADEADA
#define FILA_ENCADEADA

#include "fila.h"
#include "tipocelula.h"
#include <iostream>

class FilaEncadeada : public Fila{
    public:
        FilaEncadeada();
        virtual ~FilaEncadeada();
        void Enfileira(Loja loja);
        Loja Desenfileira();
        void Limpa();
        void Imprimir();
    private:
        TipoCelula* frente;
        TipoCelula* tras;
};

#endif