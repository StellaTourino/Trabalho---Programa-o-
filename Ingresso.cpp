#include "Alocacao.cpp"

class Ingresso{
    private:
        string tipoIng;
        float valor;
        Alocacao alocacao;
    public:
        Ingresso(){
            tipoIng = "";
            valor = 0.0;
        }
        void registrarVenda(vector<Ingresso>& vendas, vector<Alocacao>& alocacoes){
            Ingresso ingresso;
            Alocacao alocacao;
            string nomeFilme;
            int numSala;
            int tipo;

            cout<<"Digite o nome do filme: "<<endl;
            cin.ignore();
            getline(cin, nomeFilme);
            bool filmeEncontrado = false;
            for (auto a : alocacoes) {
                if (a.getFilme().getNome() == nomeFilme) {
                    alocacao = a;
                    filmeEncontrado = true;
                    break;
                }
            }
            if (!filmeEncontrado) {
                cout<<"Filme nao alocado!"<<endl;
                return;
            }
            cout<<"Digite o numero da sala: "<<endl;
            cin>>numSala;
            if (alocacao.getSala().getNumSala() != numSala){
                cout<<"Numero da sala nao corresponde ao filme!"<<endl;
                return;
            }
            cout<<"Digite o tipo de ingresso (1 para inteiro, 2 para meia): "<<endl;
            cin>>tipo;
            if (tipo == 1) {
                tipoIng = "inteiro";
                valor = 40.0;
            } else if (tipo == 2) {
                tipoIng = "meia";
                valor = 20.0;
            } else {
                cout<<"Opçao invalida!"<<endl;
                return;
            }
            ingresso.setAlocacao(alocacao);
            ingresso.setTipoIng(tipoIng);
            ingresso.setValor(valor);
            vendas.push_back(ingresso);
            cout<<"Venda registrada com sucesso!"<<endl;
        }
        void listarVendas(vector<Ingresso>& vendas){
            for (auto venda : vendas) {
                cout<<"-----------------------"<<endl;
                venda.imprimirIngresso();
            }
        }
        void imprimirIngresso(){
            cout<<"Tipo de Ingresso: "<<getTipoIng()<<endl;
            cout<<"Valor do Ingresso: "<<getValor()<<endl;
            cout<<"Informacoes sobre a Alocacao: "<<endl;
            alocacao.imprimirAlocacao();
        }
        string getTipoIng(){
            return tipoIng;
        }
        void setTipoIng(string tipoIng){
            this->tipoIng;
        }
        float getValor(){
            return valor;
        }
        void setValor(int valor){
            this->valor = valor;
        }
        Alocacao getAlocacao(){
            return alocacao;
        }
        void setAlocacao(Alocacao alocacao){
            this->alocacao = alocacao;
        }
};
