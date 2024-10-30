#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


static const int MAX_PRICE = 10000;

int main() {  
    int T;
    std::cin >> T;

    while (T--) {
        int p, n;
        std::cin >> p >> n;
        std::vector<int> coins(n);
        
        for (int i = 0; i < n; ++i) {
            std::cin >> coins[i];
        }
    
        std::vector<int> dp(MAX_PRICE + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = MAX_PRICE; j >= 0; --j) {
                if (dp[j]  && j + coins[i] <= MAX_PRICE) {
                    if (dp[j + coins[i]] == 0) {
                        dp[j + coins[i]] = dp[j] + 1;
                    } else {
                        dp[j + coins[i]] = std::min(dp[j + coins[i]], dp[j] + 1);
                    }                    
                }
            }
            
            if (dp[coins[i]] == 0) {
                dp[coins[i]] = 1;
            }
        }

        std::vector<int>::iterator iter(
            find_if(dp.begin() + p, 
            dp.end(),
            std::bind(std::greater<int>(), 0))
        );

        std::cout << iter - dp.begin() << " " << *iter << '\n';
    }
    return 0;
}