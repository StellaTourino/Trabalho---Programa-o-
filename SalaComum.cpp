#include <fstream>
#include "Salas.cpp"

class SalaComum : public Salas{
    private:
        bool assentosComuns;
    public:
        SalaComum() : Salas(){
            assentosComuns = false;
        }
        void escreverSalaComum(string nomeArquivo){
            ofstream arquivo;
            arquivo.open(nomeArquivo.c_str(), ios::app);
            if (!arquivo) {
                cout<<"Impossivel abrir arquivo!"<<endl;
                return;
            }
            arquivo<<"Numero da Sala: "<<getNumSala()<<endl;
            arquivo<<"Capacidade: "<<getCapacidade()<<endl;
            arquivo<<"Tipo: "<<getTipo()<<endl;
            arquivo<<"Assentos Comuns: "<<(assentosComuns ? "Sim" : "Nao")<<endl;
            arquivo<<"-----------------------"<<endl;
            arquivo.close();
        }
        void lerSalaComum(string nomeArquivo) {
            ifstream arquivo;
            arquivo.open(nomeArquivo.c_str(), ios::in);
            string linha;
            while (getline(arquivo, linha)) {
                if (linha.find("Numero da Sala: ") != string::npos){
                    setNumSala(stoi(linha.substr(16)));
                } else if (linha.find("Capacidade: ") != string::npos){
                    setCapacidade(stoi(linha.substr(12)));
                } else if (linha.find("Tipo: ") != string::npos) {
                    setTipo(linha.substr(6));
                } else if (linha.find("Assentos Comuns: ") != string::npos){
                    assentosComuns = (linha.substr(16) == "Sim");
                }
            }
            arquivo.close();
        }
        void imprimirSalaComum(string nomeArquivo){
            ifstream arquivo(nomeArquivo);
            string linha;
            while (getline(arquivo, linha)){
                cout<<linha<<endl;
            }
            arquivo.close();
        }
        bool getAssentosComuns(){
            return assentosComuns;
        }
        void setAssentosComuns(bool assentosComuns){
            this->assentosComuns = assentosComuns;
        }
};
