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

  Matching match(sistema.Getlojas(),sistema.GetPrefLojas(),sistema.GetPrefClientes());  
  match.GaleShapley();
  match.ImprimirMatching();

  return 0;
}
