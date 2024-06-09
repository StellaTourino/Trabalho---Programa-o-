#include "Ingresso.cpp"

int main(){
    vector<Filmes> filmes;
    vector<Alocacao> alocacoes;
    vector<Ingresso> vendas;
    Filmes f;
    Alocacao a;
    Ingresso i;
    int opcao;
    
    SalaVIP salaVIP;
    SalaComum salaComum;
    salaVIP.lerSalaVIP("SalaVIP.txt");
    salaComum.lerSalaComum("SalaComum.txt");

    do{
        cout<<"---------Menu---------"<<endl;
        cout<<"1. Gerenciar Filmes"<<endl;
        cout<<"2. Alocar Filme"<<endl;
        cout<<"3. Gerenciar Vendas"<<endl;
        cout<<"4. Listar Salas em Arquivo"<<endl;
        cout<<"5. Pesquisar Filme"<<endl;
        cout<<"6. Sair"<<endl;
        cout<<"----------------------"<<endl;
        cin>>opcao;

        switch (opcao){
            case 1:
                int opcaoFilmes;
                cout<<"1. Adicionar filme"<<endl;
                cout<<"2. Remover filme"<<endl;
                cout<<"3. Listar filmes"<<endl;
                cout<<"Digite uma opcao: "<<endl;
                cin>>opcaoFilmes;
                switch (opcaoFilmes){
                    case 1:
                        f.adicionarFilme(filmes);
                        break;
                    case 2:
                        f.removerFilme(filmes);
                        break;
                    case 3:
                        f.listarFilmes(filmes);
                        break;
                    default:
                        cout<<"Opcao invalida!"<<endl;
                        break;
                }
                break;
            case 2:
                a.alocarFilme(filmes, alocacoes);
                break;
            case 3:
                int opcaoVendas;
                cout<<"1. Registrar uma venda"<<endl;
                cout<<"2. Listar vendas"<<endl;
                cout<<"Digite uma opcao: "<<endl;
                cin>>opcaoVendas;
                switch (opcaoVendas){
                    case 1:
                        i.registrarVenda(vendas, alocacoes);
                        break;
                    case 2:
                        i.listarVendas(vendas);
                        break;
                    default:
                        cout<<"Opcao invalida!"<<endl;
                        break;
                }
                break;
            case 4:
                int opcaoSalas;
                cout<<"1. Imprimir Sala VIP"<<endl;
                cout<<"2. Imprimir Sala Comum"<<endl;
                cout<<"Digite uma opcao: "<<endl;
                cin>>opcaoSalas;
                switch (opcaoSalas){
                    case 1:
                        salaVIP.imprimirSalaVIP("SalaVIP.txt");
                        break;
                    case 2:
                        salaComum.imprimirSalaComum("SalaComum.txt");
                        break;
                    default:
                        cout<<"Opcao invalida!"<<endl;
                        break;
                }
                break;
            case 5: {
                string nomeFilme;
                cout << "Digite o nome do filme a ser pesquisado: " << endl;
                cin.ignore();
                getline(cin, nomeFilme);
                f.pesquisarFilme(nomeFilme);
                break;
            }
            case 6:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    } while (opcao != 6);

    return 0;
}
