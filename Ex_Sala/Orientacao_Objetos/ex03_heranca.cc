#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno {
    protected:
        string nome;
        string matricula;
        string curso;
    public:
    Aluno(string n, string m, string c) {
        nome = n;
        matricula = m;
        curso = c;
    };
    ~Aluno(){};
    string getNome() { return nome; };
    string getMatricula() { return matricula; };
    string getCurso() { return curso; };
};


class AlunoGraduacao : public Aluno {
    private:
        int periodo;
    public:
        AlunoGraduacao(string n, string m, string c, int p) : Aluno(n, m, c) {
            periodo = p;
        };
        ~AlunoGraduacao(){};
        void setPeriodo(int p) {
            if (p > 0) {
                periodo = p;
            }
        };
        int getPeriodo() { return periodo; };
};

int main() {

    vector<AlunoGraduacao> alunos;
    

    alunos.push_back(Aluno("Joao", "123", "Computacao", 3));
    alunos.push_back(Aluno("Maria", "456", "Engenharia",1));

    for (int i = 0; i < alunos.size(); i++) {
        cout << alunos[i].getNome() << " " <<  alunos[i].getMatricula() << " " <<  alunos[i].getCurso() << " " <<  static_cast<AlunoGraduacao*>(&alunos[i])->getPeriodo() ;
    }
    return 0;
}

