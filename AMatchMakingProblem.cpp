#include <iostream>


int main() {
    int n, m, tc;

    while (std::cin >> n >> m){

        if (n == 0 && m == 0) {
            break;
        }

        int threshold = 61;
        int age;

        for (int i = 0; i < n; i++) {            
            std::cin >> age;            
            threshold = std::min(threshold, age);
        }

        for (int i = 0; i < m; i++) {        
            std::cin >> age;        
        }

        std::cout << "Case " << ++tc << ':' << ' ';
        
        if (n <= m) {
            std::cout << '0' << '\n';            
        } else {
            std::cout << n - m << ' ' << threshold << '\n';            
        }
    }
    return 0;
}