#include <iostream>

#include "fila/headers/tipoitem.h"
#include "fila/headers/fila_encadeada.h"
#include "headers/sistema_pref.h"


int main(){
  SistemaPref sistema;
  sistema.Leitura();
  sistema.CalculaTicket();  
  sistema.ImprimeLojas();  
  sistema.ImprimeClientes();
  sistema.OrdenaPrefLojas();
  sistema.OrdernaPrefClientes();


  /* TESTE FILA ENCADEADA
  FilaEncadeada F;
  TipoItem X;
  
  for(int i=0; i<10; i++){
        X.SetChave(i);
        F.Enfileira(X);
  }

  while(!F.Vazia()){
        X=F.Desenfileira();
        X.Imprime();
  }
  */

  return 0;
}
