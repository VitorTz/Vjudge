#include <vector>
#include <cstdio>
#include <cmath>
#include <limits>
#include <iostream>


constexpr double MIN_VALUE = 1e-9;


double calcule_npv(const std::vector<double>& CF, int T, double IRR) {
    double npv = CF[0];
    for (int i = 1; i <= T; ++i) {
        npv += CF[i] / std::pow(1.0 + IRR, i);
    }
    return npv;
}


int main() {  
    int T;

    while (std::cin >> T, T != 0) {
        std::vector<double> CF(T + 1);

        for (int i = 0; i <= T; ++i) {
            std::cin >> CF[i];
        }

        double L = -0.99;
        double U = std::numeric_limits<double>::max();
        double IRR = -1.0;

        while (L <= U + MIN_VALUE) {
            double M = (L + U) / 2.0;
            double npv = calcule_npv(CF, T, M);

            if (std::abs(npv) <= MIN_VALUE) {
                IRR = M;
                break;
            }
            
            if (npv > MIN_VALUE) {
                L = M;
            } else {
                U = M;
            }
        }      

        if (std::abs(IRR + 1.0) <= MIN_VALUE) {
            std::printf("No\n");            
        } else {
            std::printf("%.2f\n", IRR);
        }
    }

    return 0;
}