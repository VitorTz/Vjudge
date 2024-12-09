#include <unordered_map>
#include <iostream>


int main() {
    int Z, I, M, L;
    int lenght;
    int n = 1;
    std::unordered_map<int, int> l_counter;

    while(true) {
        std::cin >> Z >> I >> M >> L;
        if (Z == 0 && I == 0 && M == 0 && L == 0) {
            break;
        }        
        l_counter[L] = 1;
        lenght = 2;
        int aux;
        while (true) {
            aux = (Z * L + I) % M;
            if (l_counter[aux]) {
                std::cout << "Case " << n++ << ':' << ' ' << lenght - l_counter[aux] << '\n';                
                break;
            } else {
                L = aux;
                l_counter[aux] = lenght++;
            }
        }
        l_counter.clear();
    }

    return 0;
}
