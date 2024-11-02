#include <array>
#include <iostream>


int n;
std::array<std::pair<int, bool>, 105> stones{};
std::array<bool, 105> hitStone{};


int calcule_min_dist() {
    int minDist = stones[0].first;

    for (int i = 0; i < n; ++i) {
        hitStone[i] = true;        
        if (!stones[i + 1].second) {
            minDist = std::max(minDist, stones[i + 1].first - stones[i].first);
        } else {
            minDist = std::max(minDist, stones[i + 2].first - stones[i].first);
            i++;
        }
    }
    
    for (int i = n; i > 0; --i) {
        if (!hitStone[i - 1] || !stones[i - 1].second) {
            minDist = std::max(minDist, stones[i].first - stones[i - 1].first);
        } else {
            minDist = std::max(minDist, stones[i].first - stones[i - 2].first);
            i--;
        }
    }
    return minDist;
}

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int D;
        std::cin >> n >> D;

        for (int i = 0; i < n; ++i) {
            char type, sep;
            std::cin >> type >> sep >> stones[i].first;
            stones[i].second = (type == 'S');
            
            hitStone[i] = false;
        }
        
        stones[n].second = false;
        stones[n].first = D;
        hitStone[n] = false;    
        const int minD = calcule_min_dist();
        std::cout << "Case " << t << ": " << minD << '\n';
    }
    
    return 0;
}