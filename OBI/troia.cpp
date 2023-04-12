#include <iostream>
#include <list>
#include <vector>

using namespace std;


vector<vector<int>> adjs;
vector<bool> mk;


int main() {
    int vertices, linhas;
    cin >> vertices >> linhas;
    
    adjs = vector<vector<int>> (vertices);
    mk = vector<bool> (vertices);

    int u, v;
    for (int i = 0; i < linhas; i++) {
        cin >> u >> v; u--; v--;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }

    int res = 0;
    
    // Componentes conexos
    for (int i = 0; i < vertices; i++) {
        if (!mk[i]) {
            mk[i] = true;
            res += 1;
            list<int> queue = list<int>{}; queue.push_back(i);

            while (!queue.empty()) {
                int v = queue.front(); queue.pop_front();
                for (int u : adjs[v]) {
                    if (!mk[u]) {
                        mk[u] = true;
                        queue.push_back(u);
                    }
                }
            }
        }
    }
    cout << res << endl;
}