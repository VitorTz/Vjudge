#include <cstddef>
#include <iostream>


std::size_t table[62][62];


std::size_t dp(const int n, const std::size_t back) {
    std::size_t sum = 1;

    if (n <= 1) {
        return 1;
    } else if (table[n][back] != 0) {
        return table[n][back];
    }
    
    for (int i = 1; i <= back; i++) {
        sum += dp(n-i,back);
    }
    return table[n][back] = sum;
}

int main() {
    int a, b;
    int nTestCase = 1;
    while (std::cin >> a >> b && a <= 60) {
        std::cout << "Case " << nTestCase++ << ':' << ' ' << dp(a,b) << '\n';
    }
}