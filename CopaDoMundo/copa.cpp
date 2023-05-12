// https://olimpiada.ic.unicamp.br/pratique/p2/2014/f1/copa/
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, std::pair<int, int>> aresta;

int N, F, R;
std::vector<aresta> g;
std::vector<int> id;


void make_set() {
    for (int i = 0; i < N; i++) 
        id.push_back(i);
}


int find(int u) {
    if (id[u] != u) {
        id[u] = find(id[u]);
    }
    return id[u];

}


void unir(int id_u, int id_v) {

}


int mst() {
    make_set();
    int c = 0;
    int i = 0, k = 0;
    while (k < N-1 && i < F+R) {
        int x = g[i].second.first;
        int y = g[i].second.second;
        int z = g[i].first;

        int id_x = find(x);
        int id_y = find(y);

        if (id_x != id_y) {
            unir(id_x, id_y);
            c+= z;
            k++;
        }

        i++;
    }
    return c;
}


int main() {
    std::cin >> N >> F >> R;
    g = std::vector<aresta> (F+R);
    
    int A, B, C;    
    for (int i = 0; i < F; i++) {
        std::cin >> A >> B >> C;
        A--;B--;
        g[i] = {C, {A, B}};
    }
    
    for (int j = F; j < F+R; j++) {
        std::cin >> A >> B >> C;
        A--;B--;
        g[j] = {C, {A, B}};
    }
    
    std::sort(g.begin(), g.begin()+F);
    std::sort(g.begin()+F, g.end());
    
    std::cout << mst() << '\n';
    
    return EXIT_SUCCESS;
}