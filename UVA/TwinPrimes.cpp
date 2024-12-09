#include <algorithm>
#include <array>
#include <iostream>


std::array<bool, 20000020> arr{};
std::array<int, 20000020> tw_arr{};


int main() {    
    int i, j, n;
    std::fill(arr.begin(), arr.end(), true);    

    for (i = 4; i <= 20000000; i += 2) {
        arr[i]=false;
    }
    
    for (i = 3; i * i <= 20000000; i += 2) {
        if (arr[i] == true) {
            for (j = i * i; j <= 20000000; j += i + i) {
                arr[j]=false;
            }
        }
    }

    j = 1;
    for (int i = 3; i <= 20000000; i++) {
        if (arr[i] && arr[i + 2]) {
            tw_arr[j++] = i;
        }
    }

    while (std::cin >> n) {
        std::cout << '(' << tw_arr[n] << ',' << ' ' << tw_arr[n]+2 << ')' << '\n';
    }     

   return 0;
}