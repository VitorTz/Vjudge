#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>


int matrix[105][105];

int main() {
	int tc;
	int n, e, t, m, u, v, w;
    
    std::cin >> tc;

	while (tc--) {
        std::cin >> n >> e >> t >> m;		
		memset(matrix, 63, sizeof matrix);
		n++;

		for (int i = 0; i < m; i++) {
            std::cin >> u >> v >> w;			
			matrix[u][v] = w;
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = std::min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

		int r = 0;
		for (int i = 0; i < n; i++) {
			if (matrix[i][e] <= t || (i == e))
				r++;
        }

		printf("%d\n", r);

		if (tc) {
			printf("\n");
        }
	}

	return 0;
}