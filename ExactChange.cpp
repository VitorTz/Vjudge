#include <iostream>
#include <vector>
#include <algorithm>


constexpr int MAX_PRICE = 10000;


int main() {  
    int nCases;
    std::cin >> nCases;

    while (nCases--) {
        int p, n;
        std::cin >> p >> n;
        std::vector<int> coins(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> coins[i];
        }
        
        std::vector<int> table(MAX_PRICE + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = MAX_PRICE; j >= 0; --j) {
                if (table[j] && j + coins[i] <= MAX_PRICE) {
                    if (table[j + coins[i]] == 0) {
                        table[j + coins[i]] = table[j] + 1;
                    } else {
                        table[j + coins[i]] = std::min(table[j + coins[i]], table[j] + 1);
                    }                    
                }
            }
            if (table[coins[i]] == 0) {
                table[coins[i]] = 1;
            }
        }

        std::vector<int>::iterator iter(
            std::find_if(
                table.begin() + p,
                table.end(),
                [](const int x) { return x > 0; }                
            )
        );
        std::cout << iter - table.begin() << " " << *iter << '\n';
    }
    return 0;
}