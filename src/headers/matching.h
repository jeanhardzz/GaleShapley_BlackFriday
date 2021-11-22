#ifndef MATCHING
#define MATCHING

#include "../fila/headers/fila_encadeada.h"
#include "loja.h"
#include "cliente.h"
#include <map>
#include <vector>
#include <iostream>


class Matching{
    private:
        FilaEncadeada lojas;
        std::map<int,Loja> lojas_map;        
        std::vector<Cliente> pref_lojas;
        std::map<int,std::map<int,int>> pref_clientes;// colcoca id cliente e sai sua lista pref de lojas

        std::map<int,std::vector<int>> putLoutC; //coloca loja e te digo a qual cliente ela esta alocada
        std::map<int,int> putCoutL; //coloca um cliente e te digo a qual loja ele esta alocado

        //variaveis auxiliares
        int p_loja = -1; 
        int p_cliente = -1;        
        
    public:
        Matching(std::map<int,Loja> lojas,std::vector<Cliente> pref_lojas_vetor, std::map<int,std::map<int,int>> pref_clientes);
        void Imprime();
        void GaleShapley();
        bool Condicao(std::vector<std::vector<std::pair<Cliente,int>>> propos);
        int ExistePropos(std::vector<std::vector<std::pair<Cliente,int>>> propos);
        void ImprimirMatching();

};

#endif