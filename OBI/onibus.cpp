#include <iostream>
#include <vector>

using namespace std;


#define INF 10001

int END;
vector<vector<int>> adjs;
vector<bool> mk;


int dfs(int u) {
    if (u == END) return 0;

    mk[u] = true;

    for (int v : adjs[u]) {
        if (!mk[v]) {
            int distancia = dfs(v);
            if (distancia < INF) {
                return distancia + 1;
            }
        }
    }
    return INF;
}

int main() {
    int vertices, start;
    cin >> vertices >> start >> END;
    start--; END--;
    adjs = vector<vector<int>> (vertices);
    mk = vector<bool> (vertices);

    int v, u;
    for (int i = 0; i < vertices-1; i++) {
        cin >> v >> u; v--; u--;
        adjs[v].push_back(u);
        adjs[u].push_back(v);
    }

    cout << dfs(start) << endl;
    return  0;
}
