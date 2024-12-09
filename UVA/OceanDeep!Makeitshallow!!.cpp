#include <iostream>


int main() {
    char c;

    while (std::cin >> c) {
        int n = c - '0';
        while (std::cin >> c && c != '#') {
            n = n * 2 + (c - '0');
            n %= 131071;
        }
        if (n % 131071 == 0) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
    return 0;
}