#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>


int main() {
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::less<int>> p{};
    
    for (int i = 0; i < n; i++) {
        int b;
        std::cin >> b;
        p.push(b);
    }
    
    int count = 0;

    while (p.empty() == false) {
        int a = p.top();
        p.pop();
        std::cout << a << '\n';
    }
    

    return 0;
}