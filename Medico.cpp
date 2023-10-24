#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Medico {
public:
    Medico(const string& nome, const string& cpf, const string& dataNascimento, const string& crm, const string& especialidade) {
        this->nome = nome;
        this->cpf = cpf;
        this->dataNascimento = dataNascimento;
        this->crm = crm;
        this->especialidade = especialidade;
    }

    const string& getNome() const { return nome; }
    void setNome(const string& novoNome) { nome = novoNome; }

    const string& getCpf() const { return cpf; }
    void setCpf(const string& novoCpf) { cpf = novoCpf; }

    const string& getDataNascimento() const { return dataNascimento; }
    void setDataNascimento(const string& novaDataNascimento) { dataNascimento = novaDataNascimento; }

    const string& getCrm() const { return crm; }
    void setCrm(const string& novoCrm) { crm = novoCrm; }

    const string& getEspecialidade() const { return especialidade; }
    void setEspecialidade(const string& novaEspecialidade) { especialidade = novaEspecialidade; }

    void imprimirDados() const {
        cout << "Nome: " << nome << ", CPF: " << cpf << ", Data de Nascimento: " << dataNascimento << endl;
        cout << "CRM: " << crm << ", Especialidade: " << especialidade << endl;
    }

private:
    string nome;
    string cpf;
    string dataNascimento;
    string crm;
    string especialidade;
};

vector<Medico> medicos;

void incluirMedico() {
    string nome, cpf, dataNascimento, crm, especialidade;
    cout << "Nome do medico: ";
    cin >> nome;
    cout << "CPF do medico: ";
    cin >> cpf;
    cout << "Data de Nascimento do medico (DD/MM/AAAA): ";
    cin >> dataNascimento;
    cout << "CRM do medico: ";
    cin >> crm;
    cout << "Especialidade do medico: ";
    cin >> especialidade;

    Medico medico(nome, cpf, dataNascimento, crm, especialidade);
    medicos.push_back(medico);

    cout << "Medico incluido com sucesso." << endl;
}

void excluirMedico() {
    string crm;
    cout << "CRM do medico a ser excluido: ";
    cin >> crm;

    for (auto it = medicos.begin(); it != medicos.end(); ++it) {
        if (it->getCrm() == crm) {
            medicos.erase(it);
            cout << "Medico excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Medico nao encontrado." << endl;
}

void alterarMedico() {
    string crm;
    cout << "CRM do medico a ser alterado: ";
    cin >> crm;

    for (auto& medico : medicos) {
        if (medico.getCrm() == crm) {
            cout << "Deseja alterar o nome? (S/N): ";
            char escolha;
            cin >> escolha;

            if (escolha == 'S' || escolha == 's') {
                string novoNome;
                cout << "Novo Nome: ";
                cin >> novoNome;
                medico.setNome(novoNome);
                cout << "Nome do medico alterado com sucesso." << endl;
            }

            cout << "Deseja alterar o CPF? (S/N): ";
            cin >> escolha;

            if (escolha == 'S' || escolha == 's') {
                string novoCpf;
                cout << "Novo CPF: ";
                cin >> novoCpf;
                medico.setCpf(novoCpf);
                cout << "CPF do medico alterado com sucesso." << endl;
            }

            cout << "Deseja alterar a data de nascimento? (S/N): ";
            cin >> escolha;

            if (escolha == 'S' || escolha == 's') {
                string novaData;
                cout << "Nova Data de Nascimento (DD/MM/AAAA): ";
                cin >> novaData;
                medico.setDataNascimento(novaData);
                cout << "Data de Nascimento do medico alterada com sucesso." << endl;
            }

            cout << "Deseja alterar a especialidade? (S/N): ";
            cin >> escolha;

            if (escolha == 'S' || escolha == 's') {
                string novaEspecialidade;
                cout << "Nova Especialidade: ";
                cin >> novaEspecialidade;
                medico.setEspecialidade(novaEspecialidade);
                cout << "Especialidade do medico alterada com sucesso." << endl;
            }

            return;
        }
    }

    cout << "Medico nao encontrado." << endl;
}

void listarMedicos() {
    for (const auto& medico : medicos) {
        medico.imprimirDados();
    }
}

void localizarMedico() {
    string crm;
    cout << "CRM do medico a ser localizado: ";
    cin >> crm;

    for (const auto& medico : medicos) {
        if (medico.getCrm() == crm) {
            medico.imprimirDados();
            return;
        }
    }
    cout << "Medico nao encontrado." << endl;
}

int main() {
    int escolha;

    while (true) {
        cout << "\nMENU DE MEDICOS\n";
        cout << "1. Incluir Medico\n";
        cout << "2. Excluir Medico\n";
        cout << "3. Alterar Medico\n";
        cout << "4. Listar Medicos\n";
        cout << "5. Localizar Medico\n";
        cout << "0. Sair\n";
        cout << "Escolha a opcao: ";
        cin >> escolha;

        if (escolha == 0) {
            break;
        } else if (escolha == 1) {
            incluirMedico();
        } else if (escolha == 2) {
            excluirMedico();
        } else if (escolha == 3) {
            alterarMedico();
        } else if (escolha == 4) {
            listarMedicos();
        } else if (escolha == 5) {
            localizarMedico();
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
