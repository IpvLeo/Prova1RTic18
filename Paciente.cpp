#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente {
private:
    string nome;
    string cpf;
    string dataNascimento;

public:
    Paciente(const string& nome, const string& cpf, const string& dataNascimento) {
        this->nome = nome;
        this->cpf = cpf;
        this->dataNascimento = dataNascimento;
    }

    string getNome() const {
        return nome;
    }

    string getCpf() const {
        return cpf;
    }

    string getDataNascimento() const {
        return dataNascimento;
    }

    void setNome(const string& novoNome) {
        nome = novoNome;
    }

    void setCpf(const string& novoCpf) {
        cpf = novoCpf;
    }

    void setDataNascimento(const string& novaData) {
        dataNascimento = novaData;
    }

    void imprimirDados() const {
        cout << "Nome: " << nome << ", CPF: " << cpf << ", Data de Nascimento: " << dataNascimento << endl;
    }
};

vector<Paciente> pacientes;

void incluirPaciente() {
    string nome, cpf, dataNascimento;
    cout << "Nome do paciente: ";
    cin >> nome;
    cout << "CPF do paciente: ";
    cin >> cpf;
    cout << "Data de Nascimento do paciente (DD/MM/AAAA): ";
    cin >> dataNascimento;

    Paciente novoPaciente(nome, cpf, dataNascimento);
    pacientes.push_back(novoPaciente);

    cout << "Paciente incluido com sucesso." << endl;
}

void excluirPaciente() {
    string cpf;
    cout << "CPF do paciente a ser excluido: ";
    cin >> cpf;

    for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
        if (it->getCpf() == cpf) {
            pacientes.erase(it);
            cout << "Paciente excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Paciente nao encontrado." << endl;
}

void alterarPaciente() {
    string cpf;
    cout << "CPF do paciente a ser alterado: ";
    cin >> cpf;

    for (auto& paciente : pacientes) {
        if (paciente.getCpf() == cpf) {
            cout << "Deseja alterar o nome? (S/N): ";
            char escolha;
            cin >> escolha;

            if (escolha == 'S' || escolha == 's') {
                string novoNome;
                cout << "Novo Nome: ";
                cin >> novoNome;
                paciente.setNome(novoNome);
                cout << "Nome alterado com sucesso." << endl;
            }

            cout << "Deseja alterar a data de nascimento? (S/N): ";
            cin >> escolha;

            if (escolha == 'S' || escolha == 's') {
                string novaData;
                cout << "Nova Data de Nascimento (DD/MM/AAAA): ";
                cin >> novaData;
                paciente.setDataNascimento(novaData);
                cout << "Data de Nascimento do paciente alterada com sucesso." << endl;
            }

            return;
        }
    }

    cout << "Paciente nao encontrado." << endl;
}

void listarPacientes() {
    for (const auto& paciente : pacientes) {
        paciente.imprimirDados();
    }
}

void localizarPaciente() {
    string cpf;
    cout << "CPF do paciente a ser localizado: ";
    cin >> cpf;

    for (const auto& paciente : pacientes) {
        if (paciente.getCpf() == cpf) {
            paciente.imprimirDados();
            return;
        }
    }
    cout << "Paciente nao encontrado." << endl;
}

int main() {
    int escolha;

    while (true) {
        cout << "\nMENU DE PACIENTES\n";
        cout << "1. Incluir Paciente\n";
        cout << "2. Excluir Paciente\n";
        cout << "3. Alterar Paciente\n";
        cout << "4. Listar Pacientes\n";
        cout << "5. Localizar Paciente\n";
        cout << "0. Sair\n";
        cout << "Escolha a opcao: ";
        cin >> escolha;

        if (escolha == 0) {
            break;
        } else if (escolha == 1) {
            incluirPaciente();
        } else if (escolha == 2) {
            excluirPaciente();
        } else if (escolha == 3) {
            alterarPaciente();
        } else if (escolha == 4) {
            listarPacientes();
        } else if (escolha == 5) {
            localizarPaciente();
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
