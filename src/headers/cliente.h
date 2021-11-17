#ifndef CLIENTE
#define CLIENTE

#include <string>

class Cliente{
    private:
        int id;
        std::string estado; 
        std::string pagamento;
        int idade;
        int x,y;
        int score;

    public:
        Cliente();
        Cliente(int id, std::string estado,std::string pagamento,int idade, int x,int y);

        int GetId();
        void SetId(int id);

        std::string GetEstado();
        void SetEstado(std::string estado);

        std::string GetPagamento();
        void SetPagamento(std::string pagamento);

        int GetIdade();
        void SetIdade(int idade);

        int GetX();
        void SetX(int x);

        int GetY();
        void SetY(int y);

        int GetScore();
        void SetScore(int score);

};

#endif