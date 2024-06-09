#include <fstream>
#include "Salas.cpp"

class SalaVIP : public Salas{
    private:
        bool assentosReclinaveis;
    public:
        SalaVIP() : Salas(){
            assentosReclinaveis = false;
        }
        void escreverSalaVIP(string nomeArquivo){
            ofstream arquivo;
            arquivo.open(nomeArquivo.c_str(), ios::app);
            if (!arquivo) {
                cout<<"Impossivel abrir arquivo!"<<endl;
                return;
            }
            arquivo<<"Numero da Sala: "<<getNumSala()<<endl;
            arquivo<<"Capacidade: "<<getCapacidade()<<endl;
            arquivo<<"Tipo: "<<getTipo()<<endl;
            arquivo<<"Assentos Reclinaveis: "<<(assentosReclinaveis ? "Sim" : "Nao")<<endl;
            arquivo<<"-----------------------"<<endl;
            arquivo.close();
        }
        void lerSalaVIP(string nomeArquivo){
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
                } else if (linha.find("Assentos Reclinaveis: ") != string::npos){
                    assentosReclinaveis = (linha.substr(21) == "Sim");
                }
            }
            arquivo.close();
        }
        void imprimirSalaVIP(string nomeArquivo){
            ifstream arquivo(nomeArquivo);
            string linha;
            while (getline(arquivo, linha)){
                cout<<linha<<endl;
            }
            arquivo.close();
        }
        bool getAssentosReclinaveis(){
            return assentosReclinaveis;
        }
        void setAssentosReclinaveis(bool assentosReclinaveis){
            this->assentosReclinaveis = assentosReclinaveis;
        }
};
