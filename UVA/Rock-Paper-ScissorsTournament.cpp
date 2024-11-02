#include <iostream>
#include <cstdio>


int main(void) {	
	int n, k, p1, p2;	
	int t = 0;
	char m1[9];
	char m2[9];
	float win[101];
	float lose[101];

	while (std::cin >> n && n) {
		if (t++) {
			std::cout << "\n";
        }
		std::cin >> k;

		k = k * (n - 1) * n >> 1;
	
		for (int i = 0; i <= n; ++i) {
			win[i] = 0.0;
			lose[i] = 0.0;
		}		
		while (k--) {
			std::cin >> p1 >> m1 >> p2 >> m2;			
			switch(m1[0]) {
				case 's':
					if(m2[0] == 'p') {
						++win[p1];
						++lose[p2];
					}
					else if(m2[0] == 'r') {
						++win[p2];
						++lose[p1];
					}
				    break;
				case 'p':
					if(m2[0] == 's') {
						++win[p2];
						++lose[p1];
					} else if(m2[0] == 'r') {
						++win[p1];
						++lose[p2];
					}
				    break;
				default:
					if(m2[0] == 'p') {
						++win[p2];
						++lose[p1];
					} else if(m2[0] == 's') {
						++win[p1];
						++lose[p2];
					}
                    break;
			}
		}
        		
		for (int i = 1; i <= n; ++i) {
			float q = win[i] + lose[i];
			if (q) {
				std::cout << std::fixed;
                std::printf("%.3f\n", win[i] / q);				
			} else {
				std::cout << "-\n";
            }
		}
	}
	return 0;
}