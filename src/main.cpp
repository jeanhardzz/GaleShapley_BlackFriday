#include <iostream>

#include "fila/headers/tipoitem.h"
#include "fila/headers/fila_encadeada.h"
#include "headers/sistema_pref.h"
#include "headers/matching.h"


int main(){
  SistemaPref sistema;  

  sistema.Leitura();
  sistema.CalculaTicket();  
  sistema.OrdenaPrefLojas();
  sistema.OrdernaPrefClientes();
  //sistema.ImprimeLojas();  
  //sistema.ImprimeClientes();

  Matching match(sistema.Getlojas(),sistema.GetPrefLojas(),sistema.GetPrefClientes());
  //match.Imprime();
  match.GaleShapley();











  /*
  std::vector<Cliente> pref;
  pref = sistema.GetPrefLojas();
  std::vector<Cliente>::iterator iter = pref.begin();
  for (; iter != pref.end(); iter++)
    {
        std::cout <<iter->GetId()<<" |";
    }
  */


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
