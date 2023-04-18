// https://br.spoj.com/problems/DUENDE/
#include <iostream>
#include <vector>
#include <list>

#define SALAO_COM_SAIDA 0  // Salão com saida para o exterior
#define SALAO_LIVRE 1  // Salão livre para entrar mas não tem saida para o exterior
#define SALAO_CRISTAL 2  // Salão onde o duende não pode entrar
#define DUENDE 3  // Representa o Duende
#define INF INT32_MAX 

using namespace std;

vector<vector<int>> m; // Matriz da caverna
vector<vector<bool>> mk; // Matriz de marcações
vector<vector<int>> d; // Matriz das distâncias minimas
pair<int, int> start; // Posição inicial do duende
vector<pair<int, int>> vizinhos = { // Auxilia a encontrar os vizinhos de uma posição
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

/**
 * Prepara as matrizes m (matriz da caverna), mk (matriz de marcação)
 * e d (matriz das distâncias) para responder o problema.
 * @param linhas quantidade de linhas da caverna
 * @param colunas quantidade de colunas da caverna
 * 
*/
void recebeEntrada(int linhas, int colunas) {
    m = vector<vector<int>> (linhas);
    mk = vector<vector<bool>> (linhas, vector<bool> (colunas, false));
    d = vector<vector<int>> (linhas, vector<int> (colunas, INF));
    int salao;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> salao;
            m[i].push_back(salao);
            if (salao == DUENDE) {
                start = {i, j};
                d[i][j] = 0; // Posição inicial do Duende tem distância 0
            }
            else if(salao == SALAO_CRISTAL)
                mk[i][j] = true; // Marca como true para não visitar
        }
    }
}

/**
 * Calcula o menor caminho para sair da caverna sem passar por nenhum salão de vidro
 * @param linhas quantidade de linhas da matriz da caverna
 * @param colunas quantidade de colunas da matriz da caverna
 * @return a menor distância caso encontre um caminho e INF caso não encontre
*/
int calculaMenorCaminho(int linhas, int colunas) {
    if (m[start.first][start.second] == SALAO_LIVRE) return 0;

    list<pair<int, int>> queue;
    queue.push_back(start);
    mk[start.first][start.second] = true;

    while (!queue.empty()) {
        pair<int, int> p = queue.front(); queue.pop_front();
        int i, j;
        for (pair<int, int> delta : vizinhos) {
            i = p.first + delta.first;
            j = p.second + delta.second;
            if (
                i >= 0 && i < linhas &&
                j >= 0 && j < colunas &&
                !mk[i][j]
            ) {
                queue.push_back({i, j});
                mk[i][j] = true;
                d[i][j] = d[p.first][p.second] + 1;
                if (m[i][j] == SALAO_COM_SAIDA)
                    return d[i][j];
            }
        }
    }
    return INF;  // Nenhum caminho válido foi encontrado
}


int main() {
    int linhas, colunas;
    cin >> linhas >> colunas;
    recebeEntrada(linhas, colunas);
    cout << calculaMenorCaminho(linhas, colunas) << endl;
    return 0;
}