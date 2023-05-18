// https://olimpiada.ic.unicamp.br/pratique/p2/2015/f1/real/
#include <iostream>
#include <vector>


std::vector<std::vector<int>> filhos;
std::vector<bool> foramNaFesta;
std::vector<int> totalGeracao, foramGeracao;


/**
 * @param u Pessoa com grau de parentesco com o Rei
 * @param distanciaOrigem Distância até o Rei (gerações)
 * @return null
*/
void dfs(int u, int distanciaOrigem) {
    totalGeracao[distanciaOrigem] += 1;

    if (foramNaFesta[u]) 
        foramGeracao[distanciaOrigem] += 1;

    for (int v : filhos[u])
        dfs(v, distanciaOrigem + 1);
    
}


int main() {
    int N, M;
    std::cin >> N >> M;
    
    filhos = std::vector<std::vector<int>> (N+1);
    for (int i = 1; i <= N; i++) {
        int v; std::cin >> v;
        filhos[v].push_back(i);
    }

    foramNaFesta = std::vector<bool> (N+1, false);
    for (int i = 0; i < M; i++) {
        int v; std::cin >> v;
        foramNaFesta[v] = true;
    }

    totalGeracao = std::vector<int> (N+1, 0);
    foramGeracao = std::vector<int> (N+1, 0);

    dfs(0, 0);

    for (int k = 1; k <= M; k++) {
        if (totalGeracao[k] == 0) break;
        std::cout << foramGeracao[k] / (float) totalGeracao[k] * 100.0 << '\n';
        // std::cout << 100.0 * foramGeracao[k] / totalGeracao[k] * 100.0 << '\n';
    }
        
    return 0;
}