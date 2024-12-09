#include <iostream>


int arr[2][2] = {1,1,1,0};
long long tmp_arr[2][2] = {1,1,1,0};


void matrix_p (const int b, const int mod) {
    if (b == 1) {
        return;
    }

    matrix_p (b / 2, mod);

    long long temp[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            long long sum = 0;
            for (int k = 0; k < 2; k++) {
            sum += (tmp_arr[i][k] * tmp_arr[k][j]) % mod;
        }
        temp[i][j] = sum % mod;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp_arr[i][j] = temp[i][j];
        }
    }

    if (b % 2 == 1) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
            long long sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += (temp[i][k] * arr[k][j]) %mod;
            }
            tmp_arr[i][j] = sum % mod;
            }
        }
    }
}


int main () {
    int n, m, mod;

    while (std::cin >> n >> m) {
        if (n == 0 || m == 0) {
            std::cout << '0' << '\n';
            continue;
        } else if (n == 1 || n == 2) {
            std::cout << '1' << '\n';
            continue;
        }

        mod = 1;
        while (m--) {
            mod *= 2;
        }
        matrix_p (n-2, mod);
        std::cout << (tmp_arr[0][0] + tmp_arr[0][1]) % mod << '\n';
        tmp_arr[0][0] = 1;
        tmp_arr[0][1] = 1;
        tmp_arr[1][0] = 1;
        tmp_arr[1][1] = 0;
    }
   return 0;
}