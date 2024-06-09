#pragma once
#include <string>
#include <iostream>

using namespace std;

class Salas{
    protected:
        int numSala, capacidade;
        string tipo;
    public:
        Salas(){
            numSala = 0, capacidade = 0;
            tipo = "";
        }
        void imprimirSalas(){
            cout<<"Numero da Sala: "<<getNumSala()<<endl;
			cout<<"Capacidade: "<<getCapacidade()<<endl;
			cout<<"Tipo da Sala: "<<getTipo()<<endl;
        }
        int getNumSala(){
            return numSala;
        }
        void setNumSala(int numSala){
            this->numSala = numSala;
        }
        int getCapacidade(){
            return capacidade;
        }
        void setCapacidade(int capacidade){
            this->capacidade = capacidade;
        }
        string getTipo(){
            return tipo;
        }
        void setTipo(string tipo){
            this->tipo = tipo;
        }
};
