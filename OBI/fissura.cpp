#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int n;
vector<string> map;
vector<vector<bool>> mk;


void bfs(int f) {

    if (map[0][0] - '0' > f) return;

    list<pair<int, int>> q;
    q.push_back({0, 0});
    mk[0][0] = true;

    vector<pair<int, int>> vizinhos = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop_front();
        map[u.first][u.second] = '*';
        for (pair<int, int>& vizinho : vizinhos) {
            int ui, uj;
            ui = u.first + vizinho.first;
            uj = u.second + vizinho.second;
            if (
                ui >= 0 && 
                ui < n &&
                uj >= 0 &&
                uj < n &&
                !mk[ui][uj] &&
                map[ui][uj] - '0' <= f
            ) {
                mk[ui][uj] = true;
                q.push_back({ui, uj});
            }
        }

    }

}


int main() {
    int f;
    cin >> n >> f;
    
    map = vector<string> (n);
    mk = vector<vector<bool>> (n, vector<bool> (n, false));

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    bfs(f);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == -1) cout << '*';
            else cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}