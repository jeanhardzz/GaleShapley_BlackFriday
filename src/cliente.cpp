#include "headers/cliente.h"

Cliente::Cliente(){

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
void Cliente::SetPagamento(std::string pagaemento){
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

int Cliente::GetScore(){
    return this->score;
}
void Cliente::SetScore(int score){
    this->score = score;
}