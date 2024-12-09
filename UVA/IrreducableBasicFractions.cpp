#include <iostream>
#include <array>


int main() {
    int n, i, j, a, b;
    std::array<char, 32767> m{};
    int arr[5500];
    int aux = 0;
    
    // sieve
    for (i = 2; i < 32767; i++)
        if(!m[i]) {
            arr[aux++] = i;
            for(j = i + i; j < 32767; j += i)
                m[j] = 1;
        }

    while (std::cin >> n && n) {
        a = 1;
        b = n;
        for (i = 0; i < aux && arr[i] * arr[i] <= n; i++) {
            if (n % arr[i] == 0) {
                n /= arr[i];
                b /= arr[i];
                a *= arr[i] - 1;
                while(n % arr[i] == 0) {
                    n /= arr[i];
                }
            }
        }
        if (n != 1) {
            a *= n-1, b /= n;
        }
        
        std::cout << a * b << '\n';
    }

    return 0;
}