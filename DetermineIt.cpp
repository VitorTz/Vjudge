#include <cstddef>
#include <iostream>
#include <algorithm>
#include <array>


#define TABLE_SIZE 21


int main(){
	int n, k;

	while (std::cin >> n >> k) {
        std::array<std::array<std::size_t, TABLE_SIZE>, TABLE_SIZE> table{};

		table[n][1] = k;

		int i, j;

		for (i = n; i >= 1; i--) {
			for (j = 1; j <= n; j++) {
				if (i == n && j == 1) {
					continue;
                } 
                
                std::size_t max{};

                if (i >= j) {					
					for ( k = i+1, max = 0; k <= n; k++) {
						max = std::max(max, table[k][1] + table[k][j]);
                    }
					table[i][j] += max;
					for ( k = 1, max = 0; k < j; k++) {
						max = std::max(max, table[i][k] + table[n][k]);
                    }
					table[i][j] += max;
                    continue;
				}

                for (k = i, max = 0; k < j; k++) {
                    max = std::max(max, table[i][k] + table[k + 1][j]);
                }
                table[i][j] += max;
            }
        }

        std::cout << table[1][n] << '\n';
	}
	return 0;
}
