
#include <iostream>
#include <string>
#include <fstream>
#include <errno.h>
#include <sstream>

using namespace std;


// void conta_colunas (const string & arq) {




        int main(int argc, char *argv[]) {

            ifstream arq("/home/wagner/CLionProjects/2022_1/copia_csv/CopiaCSV/data/casos_sc.csv");

            if (!arq.is_open()) {
                perror("Ao abrir /etc/hosts");
                return errno;
            }

            // função que descobre quantas linhas tem
            string virgula = ",";
            string line;
            int pos = 0;
            int cont_colunas = 0;
            int cont_linha = 0;

            while (getline(arq, line)) {
                cont_linha++;
            }
            cout << "linhas:" << cont_linha << endl;

            ifstream arq1("/home/wagner/CLionProjects/2022_1/copia_csv/CopiaCSV/data/casos_sc.csv");

            // funçao que ddescobre quantas colunas tem
            getline(arq1, line);
            while (true) {
                int pos1 = line.find(virgula, pos);
                if (pos1 == string::npos)break;
                pos = pos1 + virgula.size();
                cont_colunas++;
            }
            cout << "colunas: " << cont_colunas << endl;

            ifstream arq2("/home/wagner/CLionProjects/2022_1/copia_csv/CopiaCSV/data/casos_sc.csv");


            //escolhe quais as colunas serao utilizadas
            int coluna1, coluna2;
            cout << " digite as colunas desejadas " << endl;
            cin >> coluna1;
            cin >> coluna2;
            pos = 0;
            cont_colunas = 0;
            string string_coluna1, string_coluna2;
            string aux;
            int cont = 0;
            while (getline(arq2, line)) {

                while (true) {
                    int pos1 = line.find(virgula, pos);
                    if (pos1 == string::npos)break;
                    if (cont_colunas == coluna1 || cont_colunas == coluna2) {

                        if (cont == 0) {
                            string_coluna1 = line.substr(pos1 + 1, pos);
                            cont++;
                        } else
                            string_coluna2 = line.substr(pos1 + 1, pos);
                    }

                    pos = pos1 + pos+1;
                    cont_colunas++;
                }
                cout << string_coluna1 << ", " << string_coluna2 << endl;
            }

        }