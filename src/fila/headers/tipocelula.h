#ifndef TIPOCELULA
#define TIPOCELULA

#include "../../headers/loja.h"
class TipoCelula{
    public:
        TipoCelula();
    private:
        Loja loja;
        TipoCelula *prox;
    
    friend class FilaEncadeada;
};

#endif