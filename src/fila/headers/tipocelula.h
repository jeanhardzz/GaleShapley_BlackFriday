#ifndef TIPOCELULA
#define TIPOCELULA

#include "../../headers/cliente.h"
class TipoCelula{
    public:
        TipoCelula();
    private:
        Cliente cliente;
        TipoCelula *prox;
    
    friend class FilaEncadeada;
};

#endif