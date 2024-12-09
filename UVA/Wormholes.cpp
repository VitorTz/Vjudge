#include <iostream>
#include <vector>


constexpr int INF = 1e9;
constexpr int MAX_STARTS{1001};


std::vector<std::pair<int, int>> nedges[MAX_STARTS];
int distances[MAX_STARTS];


int main() {
    int tc;
    std::cin >> tc;
    
    while (tc--) {
        int N, E;
        std::cin >> N >> E;
        
        for (int i = 0; i < N; ++i) {
            nedges[i].clear();
            distances[i] = INF;
        }
        
        std::pair<int, int> e{};
        while (E--) {
            int x;
            std::cin >> x >> e.first >> e.second;
            nedges[x].push_back(e);
        }
        
        for (int t = 0; t < N - 1; t++) {
            for (int j = 0; j < N; j++) {
                for (int e = 0; e < nedges[j].size(); e++) {
                    distances[nedges[j][e].first] = std::min(distances[nedges[j][e].first], distances[j] + nedges[j][e].second);
                }
            }
        }
        
        bool is_possible = false;
        
        for (int j = 0; j < N; j++) {
            for (int e = 0; e < nedges[j].size(); e++) {
                is_possible |= distances[nedges[j][e].first] > distances[j] + nedges[j][e].second;
            }
        }
        if (is_possible) {
            std::cout << "possible\n";
        } else {
            std::cout << "not possible\n";
        }        
    }
}