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

void FilaEncadeada::Enfileira(Cliente cliente) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->cliente = cliente;
    tras->prox = nova;
    tras = nova;
    tamanho++;
}

Cliente FilaEncadeada::Desenfileira() {
    TipoCelula *p;
    Cliente aux;
    if (tamanho == 0)
        throw "Fila está vazia!";
    aux = frente->prox->cliente;
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
    Cliente c;
    for(int i=0;i<tamanho;i++){
        c = Desenfileira();
        std::cout<<c.GetId()<<" : "<<c.GetTicket() << " | ";
        Enfileira(c);
    }
}