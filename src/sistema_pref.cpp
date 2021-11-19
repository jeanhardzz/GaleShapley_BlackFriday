#include "headers/sistema_pref.h"

SistemaPref::SistemaPref(){

}

SistemaPref::~SistemaPref(){    
}

void SistemaPref::Leitura(){
    //std::cout<<"leitura\n";        

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

    //std::cout<<"\nlojas: "<<n_lojas;

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
    std::cout << std::fixed;
    std::cout.precision(2);
    for(unsigned int i=0; i<clientes.size();i++){
        std::cout<<"\nCliente "<<clientes[i].GetId()<<std::endl;
        std::cout<<"Idade: "<<clientes[i].GetIdade()<<std::endl;
        std::cout<<"Estado: "<<clientes[i].GetEstado()<<std::endl;
        std::cout<<"Pagamento: "<<clientes[i].GetPagamento()<<std::endl;
        std::cout<<"Loc: "<<clientes[i].GetX()<<", "<<clientes[i].GetY()<<"\n";
        std::cout<<"Score: "<<clientes[i].GetTicket()<<std::endl;
    }
}

void SistemaPref::CalculaTicket(){
    for(unsigned int i=0; i<clientes.size();i++){
        clientes[i].CalculaTicket();
    }
}

void SistemaPref::OrdenaPrefLojas(){
    
    std::vector<Cliente> v;
    Cliente aux;
    int i,j;
    int n = (int) clientes.size();   

    for(i=0; i<n;i++){
        v.push_back(clientes[i]);
    }
    
    
    for (i=1; i<n;i++) {
        aux = v[i];
        j = i - 1;                

        while (( j >= 0 ) && (aux.GetTicket() > v[j].GetTicket())) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
        
    }

    /*
    std::cout<<"fiz o v";
    for (i=1; i<v.size();i++) {
        std::cout<<v[i].GetId()<<" - ";
    }
    */

    this->pref_lojas_vetor = v;
    
    
}

void SistemaPref::OrdernaPrefClientes(){
    /*Fazer um vetor de pares para cada cliente de loja-distancia.
    *Depois ordernar esse map para saber as menores distancias.
    *Depois criar o rankeamento para acessar em O(1).
    */
    int n = (int) clientes.size();
    int m = (int) lojas.size();
    std::pair<Loja,int> paraux;
    int l;

    for(int i=0;i<n;i++){
        std::vector<std::pair<Loja,int>> v;

        for(int j=0;j<m;j++){
            int dist;
            dist = clientes[i].CalculaDistancia(lojas[j].GetX(),lojas[j].GetY());
            std::pair<Loja,int> aux(lojas[j],dist);
            v.push_back(aux);
        }
        //std::cout<<"\nLoja: "<<v[0].first.GetId()<<" Distancia: "<<v[0].second;
        
        //Ordenando o vetor de lojas-distancia
        for (int k=1; k<m;k++) {
            paraux = v[k];
            l = k - 1;                

            while (( l >= 0 ) && (paraux.second < v[l].second)) {
                v[l + 1] = v[l];
                l--;
            }
            v[l + 1] = paraux;
        
        }

        //Criando rankeamento.
        std::map<int,int> rank;
        for (int k=0; k<m;k++) {
            rank[v[k].first.GetId()] = k;
        }
        pref_clientes[i] = rank;
        
        /*
        //Imprimindo a ordenação
        std::cout<<"\nCliente: "<<clientes[i].GetId()<<"\n";
        for (int k=0; k<m;k++) {
            std::cout<<"\nLoja: "<<v[k].first.GetId()<<" Distancia: "<<v[k].second;
        }
        std::cout<<"\n";
        for (int k=0; k<m;k++) {
            std::cout<<"\nLoja: "<<k<<" Posicao: "<<pref_clientes[i][k];
        }
        std::cout<<"\n\n";
        */


    }    
}

std::vector<Cliente> SistemaPref::GetPrefLojas(){
    //pref_lojas.Imprimir();
    return this->pref_lojas_vetor;
}

std::map<int,std::map<int,int>> SistemaPref::GetPrefClientes(){
    return this->pref_clientes;

}

std::map<int,Loja> SistemaPref::Getlojas(){
    return this->lojas;
}