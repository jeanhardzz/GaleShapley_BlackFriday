#include "headers/sistema_pref.h"

SistemaPref::SistemaPref(){

}

void SistemaPref::Leitura(){
    std::cout<<"leitura\n";        

    std::string linha;
    std::stringstream s1;              
    std::stringstream s2; 

    //Lendo o GRID
    int grid_x,grid_y;
    getline(std::cin, linha);
    s1 << linha;
    s1 >> grid_x;
    s1 >> grid_y;

    //Lendo as LOJAS
    getline(std::cin, linha);
    s2 << linha;
    s2 >> n_lojas;

    std::cout<<"\nlojas: "<<n_lojas;

    for(int i=0;i<n_lojas;i++){
        int cap, x, y;
        std::stringstream ss;

        getline(std::cin, linha);

        ss << linha;
        ss >> cap;
        ss >> x;
        ss >> y;

        Loja l(i,cap,x,y);
        lojas[l.GetId()] = l;
    }
}

void SistemaPref::ImprimeLojas(){
    for(unsigned int i=0; i<lojas.size();i++){
        std::cout<<"Loja "<<lojas[i].GetId()<<std::endl;
        std::cout<<"Capacidade: "<<lojas[i].GetCapacidade()<<std::endl;
        std::cout<<"Loc: "<<lojas[i].GetX()<<", "<<lojas[i].GetY()<<std::endl;
    }
}