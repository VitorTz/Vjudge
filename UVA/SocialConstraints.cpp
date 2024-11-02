#include <algorithm>
#include <iostream>


int find(int p, int arr[]) {
	int i;
	for (i = 0; i < 8; i++) {
		if (arr[i] == p)
			break;
	}
	return i;
}


int main() {
	int n, m;
	int constraints[20][3];

	while (std::cin >> n >> m, n || m) {
		for (int i = 0; i < m; i++) {
            std::cin >> constraints[i][0] >> constraints[i][1] >> constraints[i][2];			
		}

		int arr[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };

		int ans = 0;
		do {
			bool sat = true;
			for (int i = 0; i < m; i++) {
				int pos1 = find(constraints[i][0], arr);
				int pos2 = find(constraints[i][1], arr);
				if (constraints[i][2] > 0) {
					if (abs(pos1 - pos2) > constraints[i][2]) {
						sat = false;
						break;
					}
				}
				if (constraints[i][2] < 0) {
					if (abs(pos1 - pos2) < (-constraints[i][2])) {
						sat = false;
						break;
					}
				}
			}

			if (sat)
				ans++;
		} while (std::next_permutation(arr, arr + n));

        std::cout << ans << '\n';		
	}

	return 0;
}