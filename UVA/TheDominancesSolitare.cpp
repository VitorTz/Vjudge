#include <iostream>
#include <bitset>


int m;
std::bitset<14> used;
std::pair<int, int> pieces[14];


bool findSolution(int size, std::pair<int, int> values) {
	if (!size) {
		return (values.first == values.second);
    }
	
    if(size == 1) {
		for(int i = 0; i  < m; ++i) {
			if(!used[i]) {
				if((pieces[i].first == values.first && pieces[i].second == values.second) ||
					(pieces[i].first == values.second && pieces[i].second == values.first))
					return true;
			}
		}
		return false;
	}
	
	bool possible = false;

	for(int i = 0; i  < m && !possible; ++i) {
		if(!used[i]) {
			std::pair<int, int> temp;
			
			if(pieces[i].first == values.first) {
				temp.first = pieces[i].second;
            } else if(pieces[i].second == values.first) {
				temp.first = pieces[i].first;
            } else {
				continue;
            }
			
			used[i] = true;
			for(int j = 0; j < m && !possible; ++j) {
				if(!used[j]) {
					if(pieces[j].first == values.second)
						temp.second = pieces[j].second;
					else if(pieces[j].second == values.second)
						temp.second = pieces[j].first;
					else
						continue;

					used[j] = true;
					possible = findSolution(size - 2, temp);
					used[j] = false;		
				}
			}
			used[i] = false;
		}
	}	

	return possible;
}

int main(void) {
	int n;
	while(std::cin >> n && n) {
		int ignore;
		std::pair<int, int> values;

		std::cin >> m;
		std::cin >> ignore >> values.first;
		std::cin >> values.second >> ignore;

		for(int i = 0; i < m; ++i) {
			std::cin >> pieces[i].first >> pieces[i].second;
        }
	
		if(findSolution(n, values)) {
			std::cout << "YES\n";

        } else {
			std::cout << "NO\n";
        }
	}

	return 0;
}