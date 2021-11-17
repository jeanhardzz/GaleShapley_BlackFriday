#ifndef SISTEMA_PREF
#define SISTEMA_PREF

#include "../fila/headers/fila_encadeada.h"
#include "loja.h"
#include "cliente.h"
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

class SistemaPref{
    private:
        int n_lojas;
        std::map<int,Loja> lojas; // id da loja e a loja
        std::map<int,FilaEncadeada> pref_lojas;//id loja e sua lista pref
        int n_clientes;
        std::map<int,Cliente> clientes; // id do cliente e o cliente
        std::map<int,FilaEncadeada> pref_clientes;// id cliente e sua lista pref
        
    public:
        SistemaPref();
        void Leitura();
        void ImprimeLojas();
        void ImprimeClientes();
        
};

#endif