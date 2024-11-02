#include <iostream>
#include <algorithm>



int main(void) {
	int n, m;	
	int vec[500][500];

	while (std::cin >> n >> m && n || m) {

        for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cin >> vec[i][j];
            }
		}

		int q;
		std::cin >> q;

		while (q--) {
			int a;
			int b;
			std::cin >> a >> b;

			int largestSide = 0;	
            
			for (int i = 0; i < n; ++i) {
				int minPosition = std::lower_bound(vec[i], vec[i] + m, a) - vec[i];				
				for (int j = largestSide; j < n; ++j) {
					if (
                        n <= i + j || 
                        m <= minPosition + j || 
                        b < vec[i + j][minPosition + j]
                    ) {
						break;    
                    }
					largestSide = std::max(largestSide, j + 1);
				}
			}

			std::cout << largestSide << '\n';
		}
		std::cout << '-' << '\n';
	}

	return 0;	
}