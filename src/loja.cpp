#include "headers/loja.h"

Loja::Loja(){

}

Loja::Loja(int id, int capacidade, int x, int y){
    this-> id = id;
    this-> capacidade = capacidade;
    this-> x = x;
    this-> y = y;
}

int Loja::GetId(){
    return this->id;
}
void Loja::SetId(int id){
    this->id = id;
}

int Loja::GetCapacidade(){
    return this->capacidade;
}
void Loja::SetCapacidade(int capacidade){
    this->capacidade = capacidade;
}

int Loja::GetX(){
    return this->x;
}
void Loja::SetX(int x){
    this->x = x;
}

int Loja::GetY(){
    return this->y;
}
void Loja::SetY(int y){
    this->y = y;
}

void Loja::OcupaVaga(){
    capacidade = capacidade - 1;

}

void Loja::LiberaVaga(){
    capacidade = capacidade + 1;

}
