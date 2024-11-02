#include <iostream>
#include <algorithm>


int main() {
    int L, N;
    std::pair<int, int> P[10000];
    
    while (true) {
        std::cin >> L >> N;
        
        if (L == 0) {
            break;
        }
        
        for (int i = 0; i < N; ++i){
            int x, r;
            std::cin >> x >> r;            
            P[i] = {x - r,x + r};
        }
        
        std::sort(P,P + N);
        
        int current_pos = 0;
        int j;
        int i = 0;
        int ans = N;
        
        while (current_pos < L) {
            j = current_pos;
            
            while (i < N && P[i].first <= current_pos)
                j = std::max(j,P[i++].second);
            
            if (j == current_pos) {
                break;
            }
        
            current_pos = j;
            --ans;
        }

        if (current_pos < L) {
            std::cout << '-' << '1' << '\n';
        } else {
            std::cout << ans << '\n';
        }        
    }
    
    return 0;
}