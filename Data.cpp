#include <iostream>

using namespace std;

class Data{
	private:
		int dia, mes, ano;
	public:
		int getDia(){
			return dia;
		}
		void setDia(int dia){
			this->dia = dia;
		}
		int getMes(){
			return mes;
		}
		void setMes(int mes){
			this->mes = mes;
		}
		int getAno(){
			return ano;
		}
		void setAno (int ano){
			this->ano = ano;
		}
};
