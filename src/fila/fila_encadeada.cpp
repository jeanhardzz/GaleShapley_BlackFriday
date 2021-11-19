#include "headers/fila_encadeada.h"

FilaEncadeada::FilaEncadeada() : Fila()
{
    frente = new TipoCelula; // Célula cabeça;
    tras = frente;
}

FilaEncadeada::~FilaEncadeada(){
    Limpa();
    delete frente;
}

void FilaEncadeada::Enfileira(Loja loja) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->loja = loja;
    tras->prox = nova;
    tras = nova;
    tamanho++;
}

Loja FilaEncadeada::Desenfileira() {
    TipoCelula *p;
    Loja aux;
    if (tamanho == 0)
        throw "Fila está vazia!";
    aux = frente->prox->loja;
    p = frente;
    frente = frente->prox;
    delete p;
    tamanho--;
    return aux;
}

void FilaEncadeada::Limpa(){
    TipoCelula *p;
    p = frente->prox;
    while(p!=0){
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }
    tamanho = 0;
    tras = frente;
}

void FilaEncadeada::Imprimir(){
    Loja c;
    //std::cout<<"\nTamanho da FILA: " << this->tamanho<<"\n";
    for(int i=0;i<tamanho;i++){
        c = Desenfileira();
        std::cout<<c.GetId()<< " | ";
        Enfileira(c);
    }
    //std::cout<<"\nTamanho da FILA: " << this->tamanho<<"\n";
}