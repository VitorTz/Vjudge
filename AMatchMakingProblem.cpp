#include <algorithm>
#include <iostream>
#include <limits>


int main() {
    int n, m;
    int numCases = 0;
    int B[10005];
    int S[10005];

    while (std::cin >> n >> m) {
        
        if (n == 0 && m == 0) {
            break;
        }

        int mn = std::numeric_limits<int>::max();
        int i;

        for (i = 0; i < n; i++) {
            std::cin >> B[i];
            mn = std::min(mn, B[i]);
        }

        for (i = 0; i < m; i++) {
            std::cin >> S[i];            
        }

        if (n <= m) {
            std::cout << "Case " << ':' << ++numCases << ' ' << '0' << '\n';            
        } else {
            std::cout << "Case " << ++numCases << ' ' << n - m << ' ' << mn << '\n';            
        }
    }
    return 0;
}