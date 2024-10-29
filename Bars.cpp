#include <iostream>
#include <array>


int main(){
	int t;
    std::cin >> t;
	
	while (t--) {

		int n, m;
		int W[20];
		std::array<bool, 1001> DP{};
        
        std::cin >> n >> m;		
		for (int i = 0; i < m; i++) {
            std::cin >> W[i];
        }

		DP[0] = true;
		for (int i = 0; i < m; i++) {
			for (int j = n; j - W[i] >= 0; j--) {
				DP[j] |= DP[j - W[i]];
            }
        }

        if (DP[n]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }

	}
	return 0;
}