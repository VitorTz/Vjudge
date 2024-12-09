#include <iostream>


int arr[5500];
int aux = 0;


bool solve_for(const int n, int m) {
    int i;
    for (i = 0; i < aux && arr[i] * arr[i] <= m; i++) {
        if (m % arr[i] == 0) {
            int c = 0;
            while (m % arr[i] == 0) {
                c++, m /= arr[i];
            }

            long long tmp = arr[i];
            long long c2 = 0;
            
            while (tmp <= n) {
                c2 += n / tmp;
                tmp *= arr[i];
            }
            if (c2 < c) {  
                return false;
            }
        }
    }
    if (m != 1) {
        if(n < m) {
            return false;
        }
    }
    return true;
}


int main() {
    int n, m, i, j;
    int mark[50000];

    // sieve
    for (i = 2; i < 50000; i++)
        if(mark[i] == 0) {
            arr[aux++] = i;
            for(j = i + i; j < 50000; j += i)
                mark[j] = 1;
        }
    
    while(std::cin >> n >> m) {
        if(solve_for(n, m)) {
            std::cout << m << ' ' << "divides " << n << '!' << '\n';
        } else {
            std::cout << m << ' ' << "does not divide " << n << '!' <<  '\n';
        }
    }
    return 0;
}