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
        std::vector<Cliente> pref_lojas_vetor;
        int n_clientes;
        std::map<int,Cliente> clientes; // id do cliente e o cliente
        std::map<int,std::map<int,int>> pref_clientes;// colcoca id cliente e sai sua lista pref de lojas
        
    public:
        SistemaPref();
        ~SistemaPref();
        void Leitura();
        void ImprimeLojas();
        void ImprimeClientes();
        void CalculaTicket();
        void OrdenaPrefLojas();
        void OrdernaPrefClientes();

        std::vector<Cliente> GetPrefLojas();
        std::map<int,std::map<int,int>> GetPrefClientes();
        std::map<int,Loja> Getlojas();


        
};

#endif