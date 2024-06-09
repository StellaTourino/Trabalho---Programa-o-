#include <fstream>
#include <vector>
#include "Data.cpp"

class Filmes{
    private:
        string nome;
        int classificacao, duracao;
        Data data;
    public:
        Filmes(){
            nome = "";
            classificacao = 0, duracao = 0;
        }
        void adicionarFilme(vector<Filmes>& filmes){
            Filmes filme;
            string nome;
            int classificacao, duracao, dia, mes, ano;
            Data data;

            cout<<"Digite o nome do filme: "<<endl;
            cin.ignore();
            getline(cin, nome);
            cout<<"Digite a classificacao indicativa: "<<endl;
            cin>>classificacao;
            cout<<"Digite a duracao do filme (em minutos): "<<endl;
            cin>>duracao;
            cout<<"Digite a data de lancamento (dia mes ano): "<<endl;
            cin>>dia>>mes>>ano;

            data.setDia(dia);
            data.setMes(mes);
            data.setAno(ano);

            filme.setNome(nome);
            filme.setClassificacao(classificacao);
            filme.setDuracao(duracao);
            filme.setData(data);

            filmes.push_back(filme);
            cout<<"Filme adicionado com sucesso!"<<endl;
            salvarFilme(filme);
        }
        void removerFilme(vector<Filmes>& filmes){
            string nome;
            cout<<"Digite o nome do filme a ser removido: "<<endl;
            cin.ignore();
            getline(cin, nome);

            for (auto it = filmes.begin(); it != filmes.end(); ++it) {
                if (it->getNome() == nome) {
                    filmes.erase(it);
                    cout<<"Filme removido com sucesso!"<<endl;
                    return;
                }
            }
            cout<<"Filme nao encontrado!"<<endl;
        }
        void listarFilmes(vector<Filmes>& filmes) {
            for (auto filme : filmes) {
                cout<<"-----------------------"<<endl;
                filme.imprimirFilmes();
            }
        }
        void salvarFilme(Filmes filme) {
            string fileName = filme.getNome() + ".txt";
            ofstream arquivo(fileName.c_str());

            if (!arquivo) {
                cout<<"Impossivel abrir arquivo!"<<endl;
                return;
            }

            arquivo<<"Titulo: "<<filme.getNome()<<endl;
            arquivo<<"Classificacao Indicativa: "<<filme.getClassificacao()<<endl;
            arquivo<<"Duracao do Filme: " << filme.getDuracao()<<endl;
            arquivo<<"Data de Lancamento: "<<filme.getData().getDia()<<"/"<<filme.getData().getMes()<<"/"<<filme.getData().getAno()<<endl;

            arquivo.close();
            cout<<"Filme salvo em arquivo com sucesso!"<<endl;
        }
        void pesquisarFilme(string nomeFilme) {
            string fileName = nomeFilme + ".txt";
            ifstream arquivo(fileName.c_str());

            if (!arquivo) {
                cout<<"Arquivo do filme nao encontrado!"<<endl;
                return;
            }
            string linha;
            while (getline(arquivo, linha)) {
                cout << linha << endl;
            }
            arquivo.close();
        }
        void imprimirFilmes(){
            cout<<"Titulo: "<<getNome()<<endl;
			cout<<"Classificacao Indicativa: "<<getClassificacao()<<endl;
			cout<<"Duracao do Filme: "<<getDuracao()<<endl;
			cout<<"Data de Lancamento: "<<data.getDia()<<"/"<<data.getMes()<<"/"<<data.getAno()<<endl;
        }
        string getNome(){
            return nome;
        }
        void setNome(string nome){
            this->nome = nome;
        }
        int getClassificacao(){
            return classificacao;
        }
        void setClassificacao(int classificacao){
            this->classificacao = classificacao;
        }
        int getDuracao(){
            return duracao;
        }
        void setDuracao(int duracao){
            this->duracao = duracao;
        }
        Data getData(){
            return data;
        }
        void setData(Data data){
            this->data = data;
        }
};
