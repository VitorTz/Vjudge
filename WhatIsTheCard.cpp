#include <iostream>


int main() {
    int T, pos, current, Y;
    char cards[52][3];
    std::cin >> T;    

    for (int t = 1; t <= T; ++t) {
        Y = 0;
        pos = 52 - 25;
        for (int i = 0; i < 52; ++i) {
            std::cin >> cards[i];            
        }
        std::cout << "Case " << t << ':' << ' ' << cards[32] << '\n';
    }
    return 0;
}