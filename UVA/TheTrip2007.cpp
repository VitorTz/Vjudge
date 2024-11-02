#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    int n, v, aux, maxNum, i;

    while(std::cin >> n && n) {
        
        std::vector<int> bags(n, 0);
        
        for (i = 0; i < n; i++) {
            std::cin >> bags[i];
        }

        std::sort(bags.begin(), bags.end());
        
        maxNum = 1;
        aux = 1;

        for (i = 1; i < bags.size(); i++){
            if (bags[i] == bags[i-1]) {
                aux++;
            } else {
                aux = 1;
            }
            maxNum = std::max(aux,maxNum);
        }
        
        std::cout << maxNum << '\n';

        for (i = 0; i < maxNum; i++) {
            std::cout << bags[i];
            for (int j = i + maxNum; j < n; j += maxNum) {
                std::cout << ' ' << bags[j];
            }
            std::cout << '\n';
        }
    }
    return 0;
}