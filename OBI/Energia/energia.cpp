#include <iostream>
#include <list>
#include <vector>
// https://br.spoj.com/problems/ENERGIA/


using namespace std;

int n_teste = 1;
vector<vector<int>> adjs;
vector<bool> mk;

void receberGrafo(int E) {
    for (int i = 0; i < E; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
}

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

template<typename T>
bool find(vector<T> v, T u) {
    for (T e : v) {
        if (e == u)
            return false;
    }
    return true;
}

void mostrarResultado(int n_teste) {
    bool falha = find(mk, false);
    cout << "Teste " << n_teste << '\n';
    if (falha) cout << "normal\n";
    else cout << "falha\n";
}

int main() {
    int E, L;
    cin >> E >> L;
    while (E != 0) {
        adjs = vector<vector<int>> (E);
        mk = vector<bool> (E, false);
        receberGrafo(L);
        bfs(0);
        mostrarResultado(n_teste);
        n_teste++;
        cin >> E >> L;
    }

}
