#include "headers/sistema_pref.h"

SistemaPref::SistemaPref(){

}

void SistemaPref::Leitura(){
    std::cout<<"leitura\n";        

    std::string linha;
    std::stringstream s1;              
    std::stringstream s2; 
    std::stringstream s3;

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

    //Lendo os CLIENTES
    getline(std::cin, linha);
    s3 << linha;
    s3 >> n_clientes;

    for(int i=0;i<n_clientes;i++){
        std::string estado, pagamento;
        int idade,x,y;
        std::stringstream ss;

        getline(std::cin, linha);

        ss << linha;
        ss >> idade;
        ss >> estado;
        ss >> pagamento;
        ss >> x;
        ss >> y;

        Cliente c(i,estado,pagamento,idade,x,y);
        clientes[c.GetId()] = c;
    }
}

void SistemaPref::ImprimeLojas(){
    for(unsigned int i=0; i<lojas.size();i++){
        std::cout<<"\nLoja "<<lojas[i].GetId()<<std::endl;
        std::cout<<"Capacidade: "<<lojas[i].GetCapacidade()<<std::endl;
        std::cout<<"Loc: "<<lojas[i].GetX()<<", "<<lojas[i].GetY()<<"\n";
    }
}

void SistemaPref::ImprimeClientes(){
    for(unsigned int i=0; i<clientes.size();i++){
        std::cout<<"\nCliente "<<clientes[i].GetId()<<std::endl;
        std::cout<<"Idade: "<<clientes[i].GetIdade()<<std::endl;
        std::cout<<"Estado: "<<clientes[i].GetEstado()<<std::endl;
        std::cout<<"Pagamento: "<<clientes[i].GetPagamento()<<std::endl;
        std::cout<<"Loc: "<<clientes[i].GetX()<<", "<<clientes[i].GetY()<<"\n";
        std::cout<<"Score: "<<clientes[i].GetScore()<<std::endl;
    }
}