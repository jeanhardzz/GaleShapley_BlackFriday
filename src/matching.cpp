#include "headers/matching.h"

Matching::Matching(std::map<int,Loja> lojas, std::vector<Cliente> pref_lojas_vetor, std::map<int,std::map<int,int>> pref_clientes){
    this->pref_lojas = pref_lojas_vetor;
    this->pref_clientes = pref_clientes;
    this->lojas_map = lojas;

    /*
    for(unsigned int i=0; i<pref_lojas_vetor.size();i++){        
        pref_lojas.Enfileira(pref_lojas_vetor[i]);
    } 
    */ 

    for(unsigned int i=0; i<lojas.size();i++){        
        this->lojas.Enfileira(lojas[i]);
    }   
}

void Matching::Imprime(){            

    for(auto &p:pref_clientes){
        std::cout <<"Cliente: "<< p.first;
        for(auto &q:p.second){
            std::cout<< " " << q.second << ",";
        }
        std::cout <<"\n";
  
    }

    std::vector<Cliente>::iterator iter = pref_lojas.begin();
        for (; iter != pref_lojas.end(); iter++){
            std::cout <<iter->GetId()<<" |";
        }

    //pref_lojas.Imprimir();    
}

void Matching::GaleShapley(){
    //lojas.Imprimir();

    //Preencher os matching com valores iniciais.
    //preenche os cliente alocados com lojas
    for(unsigned int j=0; j<pref_lojas.size(); j++){
        putCoutL[j] = -1;
    }
    //preenche as lojas alocadas com clientes.    
    for(int i=0; i<lojas.GetTamanho(); i++){
        Loja aux = lojas.Desenfileira();
        for(int j=0;j<aux.GetCapacidade();j++){
            putLoutC[i].push_back(-1);
        }
        lojas.Enfileira(aux);
    }

    /*
    //Conferindo se preenchi certo.
    std::cout<<"PutCoutL \n";
    for(unsigned int j=0; j<pref_lojas.size(); j++){
        std::cout<<"Cliente "<<j<<" alocado com "<<putCoutL[j]<<"\n";
    }       
    std::cout<<"PutLoutC \n";
    for(int i=0; i<lojas.GetTamanho(); i++){
        std::cout<<"Loja "<<i<<" alocado com ";  
        for(unsigned int j=0;j<putLoutC[i].size();j++){
            std::cout<<putLoutC[i][j]<<" ";  
        }        
        std::cout<<"\n";  
    }
    */

    //Preenche matriz propos que guarda se hospital ja propos pra aquele cliente com 0.    
    std::vector<std::vector<std::pair<Cliente,int>>> propos(lojas.GetTamanho(),std::vector<std::pair<Cliente,int>>(pref_lojas.size()));

    //Preenchendo a matriz criada com os clientes da lista de preferencia.
    for(int i=0; i<lojas.GetTamanho(); i++){ 
        for(unsigned int j=0; j<pref_lojas.size(); j++){
            std::pair<Cliente,int> p(pref_lojas[j],0);
            propos[i][j] = p;
        }                              
    }

    //std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[0][0].first.GetId();
    //std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[0][0].second<<"\n";
    
    //bool f = Condicao(propos);
    //std::cout<<"A loja: "<<p_loja<<" esta propopondo para o cliente: "<<p_cliente<<"\n";
    
    
    while(Condicao(propos)){
        //std::cout<<"A loja: "<<p_loja<<" esta propopondo para o cliente: "<<p_cliente<<"\n";
        if(putCoutL[p_cliente]<0){
            putCoutL[p_cliente] = p_loja;
            //std::cout<<"A loja: "<<putCoutL[p_cliente]<<" esta alocado para o cliente: "<<p_cliente<<"\n";
            for(unsigned int i=0;i<putLoutC[p_loja].size();i++){
                if(putLoutC[p_loja][i]<0){
                    putLoutC[p_loja][i] = p_cliente;
                    lojas_map[p_loja].OcupaVaga();
                    //std::cout<<"O cliente: "<<putLoutC[p_loja][i]<<" esta alocado para a loja: "<<p_loja<<"\n";
                    break;
                }
            }
        }else if( pref_clientes[p_cliente][p_loja] < pref_clientes[p_cliente][putCoutL[p_cliente]] ){
            //std::cout<<"\n\noi\n\n";
            for(unsigned int i=0;i<putLoutC[putCoutL[p_cliente]].size();i++){
                if(putLoutC[putCoutL[p_cliente]][i]==p_cliente){
                    putLoutC[putCoutL[p_cliente]][i]= -1;
                    break;
                }
            }
            lojas_map[putCoutL[p_cliente]].LiberaVaga();
            putCoutL[p_cliente] = p_loja;
            //std::cout<<"A loja: "<<putCoutL[p_cliente]<<" esta alocado para o cliente: "<<p_cliente<<"\n";
            for(unsigned int i=0;i<putLoutC[p_loja].size();i++){
                if(putLoutC[p_loja][i]<0){
                    putLoutC[p_loja][i] = p_cliente;
                    lojas_map[p_loja].OcupaVaga();
                    //std::cout<<"O cliente: "<<putLoutC[p_loja][i]<<" esta alocado para a loja: "<<p_loja<<"\n";
                    break;
                }
            }
        }
        for(unsigned int j=0; j<pref_lojas.size(); j++){
            if(propos[p_loja][j].first.GetId()==p_cliente){
                propos[p_loja][j].second = 1;
                break;
            }                
        }

                
    }
    /*
    p_loja = 1;
    p_cliente = 156;
    */
   
    
    std::cout<<"\nPutLoutC \n";
    for(int i=0; i<lojas.GetTamanho(); i++){
        std::cout<<"Loja "<<i<<" alocado com ";  
        for(unsigned int j=0;j<putLoutC[i].size();j++){
            std::cout<<putLoutC[i][j]<<" ";  
        }        
        std::cout<<"\n";  
    }
    /*
    //Conferindo se preenchi certo.
    std::cout<<"\nPutCoutL \n";
    for(unsigned int j=0; j<pref_lojas.size(); j++){
        std::cout<<"Cliente "<<j<<" alocado com "<<putCoutL[j]<<"\n";
    }       
    
    
    std::cout<<"\nVagas \n";
    for(unsigned int i=0; i<lojas_map.size();i++){                
        std::cout<<"Loja: "<<i<<" Vagas: ";
        std::cout<<lojas_map[i].GetCapacidade();        
        std::cout<<"\n";        
    }
    
    std::cout<<"\nPROPOSTAS\n";
    for(int i=0; i<lojas.GetTamanho(); i++){
        p_loja=i;
        std::cout<<"\nPropostas da loja "<<p_loja<<"\n";
        for(unsigned int j=0; j<propos[p_loja].size(); j++){
            std::cout<<propos[p_loja][j].first.GetId()<<" - "<<propos[p_loja][j].second<<" | ";
        
        } 
    }
    
    std::cout<<"\n";
    */
    
    
    /*
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[0][0].first.GetId();
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[0][0].second<<"\n"; 
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[0][1].first.GetId();
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[0][1].second<<"\n";
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[1][0].first.GetId();
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[1][0].second<<"\n"; 
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[1][1].first.GetId();
    std::cout<<"\nTeste tabela de proposicao em ordem de preferencia: "<<propos[1][1].second<<"\n"; 
    */    


}

bool Matching::Condicao(std::vector<std::vector<std::pair<Cliente,int>>> propos){
    Loja aux;
    int existe_vaga = 0;
    int existe_nao_propos = 0;
   
    for(unsigned int i=0; i<lojas_map.size();i++){        
        aux = lojas_map[i];
        if(aux.GetCapacidade()>0){
            existe_vaga = 1;
            p_loja = i;
            break;
        }
    }  

    if(existe_vaga!=0){
        if(ExistePropos(propos) >= 0){
            existe_nao_propos = 1;
        }
        if(existe_nao_propos!=0){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }  
}

int Matching::ExistePropos(std::vector<std::vector<std::pair<Cliente,int>>> propos){            
    for(unsigned int j=0; j<propos[p_loja].size(); j++){
        if(propos[p_loja][j].second==0){            
            p_cliente = propos[p_loja][j].first.GetId();
            return 1;
        }
    }            
    return -1;
}