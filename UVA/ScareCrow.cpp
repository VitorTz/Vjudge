#include <iostream>
#include <string>


int main(void) {	

	int n;
	std::cin >> n;

	for (int t = 1; t <= n; ++t) {
		int size;
		std::string str;
		std::cin >> size >> str;

		int numScareCrows = 0;
		for (int i = 0; i < size; ++i) {
			if (str[i] == '#') {
				continue;
            }
			i += 2;
			numScareCrows++;
		}

		std::cout << "Case " << t << ':' << ' ' << numScareCrows << '\n';
	}

	return 0;
}