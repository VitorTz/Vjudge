#include <ios>
#include <iostream>
#include <limits>
#include <string>



int main() {
    int n;

    std::cin >> n;
    std::string s{};

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (n--) {

        while (std::getline(std::cin, s)) {
            std::cout << s << '\n';
        }
    
        std::cout << '\n';

    }

    return 0;
}