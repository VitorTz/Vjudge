#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


constexpr int MAX{1001};


int V[MAX], L[MAX], P[MAX], n, gpe;
std::vector<int> G[MAX];


inline int findset(const int v) {
    if (P[v] != -1 && P[v] != v)
        return P[v] = findset(P[v]);
    return v;
}


inline void unionset(const int x, const int y) {
    int a = findset(x), b = findset(y);
    if (a < b) std::swap(a,b);
    P[b] = a;
}


void dfs(int u, int v) {
    V[v] = L[v] = ++gpe;
    
    for(int i = 0; i < G[v].size(); i++) {
        int w = G[v][i];
        if (!V[w]) {
            dfs(v, w);
            L[v] = std::min(L[v], L[w]);
            if (L[w] > V[v]) {
                unionset(v, w);
            }
        } else if(w != u) { 
            L[v] = std::min(L[v], V[w]);
        }
    }
}

int main() {
    int m, q;

    while(std::cin >> n >> m >> q, n|m|q) {
        memset(G, 0, sizeof(std::vector<int>) * (n + 1));
        memset(V, 0, sizeof(int)*(n+1));
        memset(L, 0, sizeof(int)*(n+1));
        memset(P, -1, sizeof(int)*(n+1));
        gpe = 0;

        for (int i = 0; i < m; i++) {
            int a, b; 
            std::cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for (int i = 0; i < n; i++)
            if (!V[i])
                dfs(i, i);

        for (int i = 0; i < q; i++) {
            int a, b; 
            std::cin >> a >> b;
            std::cout << (findset(a) == findset(b) ? 'Y' : 'N') << '\n';
        }

        std::cout << '-' << '\n';
    }
}