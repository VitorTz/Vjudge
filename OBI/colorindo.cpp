#include <iostream>
#include <vector>
#include <list>


using namespace std;

vector<vector<bool>> mk;
int delta[][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {-1, -1},
    {-1, 1},
    {1, 0},
    {1, -1},
    {1, 1},
};


int main() {
    int linhas, colunas, x, y, n_quadrados_cheios;

    cin >> linhas >> colunas >> x >> y >> n_quadrados_cheios;
    mk = vector<vector<bool>> (linhas, vector<bool> (colunas));

    // Recebe os quadrados cheois
    int q1, q2;
    for (int i = 0; i < n_quadrados_cheios; i++) {
        cin >> q1 >> q2;
        mk[q1][q2] = true;
    }

    int qtd_quadrados_validos = 1;
    // Inicia a lista que receberá quadrados válidos para pintar
    list<int[2]> queue = list<int[2]>{};
    
    // Start
    queue.push_back({x, y});
    
    // Percorre todos os quadrados válidos partindo da posição {x, y}
    int a, b;
    while (!queue.empty()) {
        int* u = queue.front(); queue.pop_front();
        mk[u[0]][u[1]] = true;
        qtd_quadrados_validos += 1;
        for (int i = 0; i < 8; i++) {
            a = u[0] + delta[i][0];
            b = u[1] + delta[i][1];
            if (!mk[a][b]) {
                queue.push_back({a, b});
            }
        }
    }

    return 0;
}