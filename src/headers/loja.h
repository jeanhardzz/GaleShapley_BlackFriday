#ifndef LOJA
#define LOJA

class Loja{
    private:
        int id;
        int capacidade;
        int x,y;
    public:
        Loja();
        int GetId();
        void SetId(int id);
        int GetCapacidade();
        void SetCapacidade(int capacidade);
        int GetX();
        void SetX(int x);
        int GetY();
        void SetY(int y);

};

#endif