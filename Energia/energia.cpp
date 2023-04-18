#include <iostream>
#include <list>
#include <vector>
// https://br.spoj.com/problems/ENERGIA/


using namespace std;

int n_teste = 1;  // Quantidade de testes rodados até o momento
vector<vector<int>> adjs;
vector<bool> mk;

/**
 * Recebe as adjacencias presentes no grafo
 * @param E quantidade de adjacencias
*/
void recebeEntrada(int E) {
    for (int i = 0; i < E; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
}

/**
 * Tem como objetivo preencher a matriz de marcação do grafo
 * com base na origem S
 * @param S vertice inicial
*/
void bfs(int S) {
    list<int> queue;
    queue.push_back(S);
    mk[S] = true;

    while (!queue.empty()) {
        int u = queue.front(); queue.pop_front();
        for (int uu : adjs[u]) {
            if (!mk[uu]) {
                mk[uu] = true;
                queue.push_back(uu);
            }
        }
    }
}

/**
 * Procura por um elemento dentro de um vetor
 * @param v vetor 
 * @param u elemento para buscar dentro do vetor v
 * @return true caso encontre
 * @return false caso não encontre
*/
template<typename T>
bool find(vector<T> v, T e) {
    for (T ee : v) {
        if (ee == e)
            return true;
    }
    return false;
}

void mostrarResultado(int n_teste) {
    bool falhaEncontrada = find(mk, false);
    cout << "Teste " << n_teste << '\n';
    if (!falhaEncontrada) cout << "normal\n";
    else cout << "falha\n";
}

int main() {
    int E, L;
    cin >> E >> L;
    while (E != 0) {
        adjs = vector<vector<int>> (E);
        mk = vector<bool> (E, false);
        recebeEntrada(L);
        bfs(0);
        mostrarResultado(n_teste);
        n_teste++;
        cin >> E >> L;
    }

}
