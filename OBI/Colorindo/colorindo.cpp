#include <iostream>
#include <vector>
#include <list>
#include <set>

int linhas, colunas;
std::vector<std::vector<bool>> mk;
int x, y; // Ponto de inicio da pintura

std::vector<std::pair<int, int>> vizinhos = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {-1, -1},
    {-1, 1},
    {1, 1},
    {1, -1},
};


int colorir() {
    int cont = 1;
    std::list<std::pair<int, int>> stack;
    stack.push_back({x, y});
    mk[x][y] = true;

    while (!stack.empty()) {
        std::pair<int, int> p = stack.back(); stack.pop_back();
        
        for (std::pair<int, int>& delta : vizinhos) {
            int i, j;
            i = p.first + delta.first;
            j = p.second + delta.second;
            if (
                i >= 0 && i < linhas &&
                j >= 0 && j < colunas &&
                !mk[i][j]
            ) {
                stack.push_back({i, j});
                mk[i][j] = true;
                cont += 1;
            }
        }
    }

    return cont;
}

int main() {
    int qtd_quadrados_cheios;
    std::cin >> linhas >> colunas >> x >> y >> qtd_quadrados_cheios;
    x--; y--;
    mk = std::vector<std::vector<bool>> (linhas, std::vector<bool> (colunas, false));
    
    for (int i = 0; i < qtd_quadrados_cheios; i++) {
        int u, v;
        std::cin >> u >> v;
        mk[u-1][v-1] = true;
    }

    std::cout << colorir() << std::endl;

    return 0;
}