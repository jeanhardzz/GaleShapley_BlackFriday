#include "headers/cliente.h"

Cliente::Cliente(){

}

Cliente::Cliente(int id, std::string estado,std::string pagamento,int idade, int x,int y){
    this->id = id;
    this->estado = estado;
    this->pagamento = pagamento;
    this->idade = idade;
    this->x = x;
    this->y = y;  
    this->ticket = 0;  
}

int Cliente::GetId(){
    return this->id;
}
void Cliente::SetId(int id){
    this->id = id;
}

std::string Cliente::GetEstado(){
    return this->estado;
}
void Cliente::SetEstado(std::string estado){
    this->estado = estado;
}

std::string Cliente::GetPagamento(){
    return this->pagamento;
}
void Cliente::SetPagamento(std::string pagamento){
    this->pagamento = pagamento;
}

int Cliente::GetIdade(){
    return this->idade;
}
void Cliente::SetIdade(int idade){
    this->idade = idade;
}

int Cliente::GetX(){
    return this->x;
}
void Cliente::SetX(int x){
    this->x = x;
}

int Cliente::GetY(){
    return this->y;
}
void Cliente::SetY(int y){
    this->y = y;
}

float Cliente::GetTicket(){
    return this->ticket;
}
void Cliente::SetTicket(float ticket){
    this->ticket = ticket;
}

void Cliente::CalculaTicket(){
    int a,est,pag;

    if(estado=="MG"){
        est = 0;
    }
    if(estado=="PR"){
        est = 10;
    }
    if(estado=="SP"){
        est = 20;
    }
    if(estado=="SC"){
        est = 30;
    }
    if(estado=="RJ"){
        est = 40;
    }
    if(estado=="RN"){
        est = 50;
    }
    if(estado=="RS"){
        est = 60;
    }

    if(pagamento=="DINHEIRO"){
        pag = 1;
    }
    if(pagamento=="DEBITO"){
        pag = 2;
    }
    if(pagamento=="CREDITO"){
        pag = 3;
    }
    
    a = 60 - idade;
    a = abs(a);
    
    ticket = a + est;
    ticket = ticket / pag;
}

int Cliente::CalculaDistancia(int a, int b){
    /*Para calcular o menor caminho entre dois pontos em um grid
    * basta pegar o modulo da diferença entre as linhas e as colunas
    * entre os pontos analisados. Depois pegue o maior valor diferente
    * de 0 e subtraia 1. Essa sera a menor distancia entre os pontos.
    */

    int linha = 0; //diferença entre linhas
    int col = 0; //diferença entre colunas

    linha = a - x;
    col = b - y;

    linha = abs(linha);
    col = abs(col);

    if(linha >= col && linha!=0){
        return linha-1;
    }
    if(col >= linha && col!=0){
        return col-1;
    }
    else{
        return 0;
    }


}