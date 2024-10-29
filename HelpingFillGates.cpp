#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


int main(void) {
	
	char c;
	int i = 0;
	std::vector<int> index[257];

	while (std::cin.read(&c, 1) and c != '\n') {
		index[c].push_back(i++);
    }

	int q;
	std::cin >> q;

	while(q--) {
		std::string str;
		std::cin >> str;

		int first = 0;
		int last = -1;
		bool matched = true;
		int length = str.length();

		for(i = 0; i < length; ++i) {
			std::vector<int>::iterator j = std::upper_bound(index[str[i]].begin(), index[str[i]].end(), last);
			
			if (j == index[str[i]].end()) {
				matched = false;
				break;
			}
			
            last = *j;
			if (!i) {
				first = last;
            }
		}

		if (matched) {
			std::cout << "Matched " << first << " " << last << "\n";
        } else {
            std::cout << "Not matched\n";
        }
	}

	return 0;
}