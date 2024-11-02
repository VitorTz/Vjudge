#include <iostream>
#include <array>


int main() {
    int n, k, m;
    std::array<std::array<long long, 64>, 64> arr{};

    while (std::cin >> n >> k >> m) {
        
        for (auto& v : arr) {
            v.fill(0);
        }        

        for (int unit = 1; unit <= n && unit <= m; unit++) {
            arr[1][unit] = 1;
        }
                
        for (int bar = 2; bar <= k; ++bar) {
            for (int unit = bar; unit <= n; ++unit) {
                for (int wide = 1; wide <= m && unit > wide; wide++) {
                    arr[bar][unit] += arr[bar - 1][unit - wide];
                }
            }
        }
        
        std::cout << arr[k][n] << '\n';
    }
    return 0;
}