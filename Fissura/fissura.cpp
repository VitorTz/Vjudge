// https://olimpiada.ic.unicamp.br/pratique/p2/2020/f1/fissura/
#include <iostream>
#include <vector>
#include <string>
#include <list>

#define START_X 0
#define START_Y 0

using namespace std;

vector<string> m;
vector<pair<int, int>> vizinhos = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};
int linhas, colunas, F;


void recebeEntrada() {
    cin >> linhas >> F;
    colunas = linhas;
    m = vector<string> (linhas);
    for (int i = 0; i < linhas; i++)
        cin >> m[i];
}

void simulaCaminhoLava() {
    if (m[START_X][START_Y] - '0' > F) return;
    
    list<pair<int, int>> queue;
    queue.push_back({START_X, START_Y});
    m[START_X][START_Y] = '*';

    while (!queue.empty()) {
        pair<int, int> p =  queue.front(); queue.pop_front();
        int i, j;
        for (pair<int, int> delta : vizinhos) {
            i = p.first + delta.first;
            j = p.second + delta.second;
            if (
                i >= 0 && i < linhas &&
                j >= 0 && j < colunas &&
                m[i][j] != '*' &&
                m[i][j] - '0' <= F
            ) {
                m[i][j] = '*';
                queue.push_back({i, j});
            }
        }
    }
}

void mostraResultado() {
    for (string s : m) 
        cout << s << '\n';
}

int main() {
    recebeEntrada();
    simulaCaminhoLava();
    mostraResultado();
    return 0;
}