// https://olimpiada.ic.unicamp.br/pratique/p2/2008/f2/frete/
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, std::pair<int, int>> estrada;

std::vector<estrada> arestas;


int mst(std::vector<estrada>& v, int N) {
    std::vector<int> id (N);
    // Union find
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }

    int res = 0;
    for (int i = 0; i < v.size(); i++) {

    }
}


int main() {

    int E, W;
    std::cin >> E >> W;
    
    for (int i = 0; i < W; i++) {
        int u, v, custo;
        std::cin >> u >> v >> custo;
        arestas.push_back({custo, {u, v}});
    }

    std::sort(arestas.begin(), arestas.end());
    std::cout << mst(arestas, E) << '\n';

    return EXIT_SUCCESS;
}