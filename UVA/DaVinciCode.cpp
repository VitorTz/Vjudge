#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <climits>


std::map <int, int> m{};


int main() {	
	int tc;
	int n, lo, key, cind;
	int e[110];
	char str[110];
	std::string s;
	int id = 0;
	m[1] = id++;
	m[2] = id++;

	unsigned long long a = 1;
	unsigned long long b = 2;

	while(a + b < (unsigned long long) INT_MAX){
		key = a + b;
		m[key] = id++;
		a = b;
		b = key;
	}

	std::cin >> tc;	

	while(tc--) {
		std::cin >> n;		
		for(int i = 0; i < n; i++) {
			std::cin >> e[i];			
		}		
		std::getline(std::cin,s);
		std::getline(std::cin, s);
		std::memset(str, ' ', sizeof str);
		lo = 0;

		int ind = -1;
		int minind = 100;
		for (int i = 0; i < s.size() && lo < n; i++) {
			if(std::isupper(s[i])){
				cind = m[e[lo++]];
				str[cind] = s[i];
				ind = std::max(ind, cind);
				minind = std::min(cind, minind);
			}
		}

		for(int i = 0; i <= ind;i++) {
			std::cout << str[i];			
		}
		std::cout << '\n';
	}
	return 0;
}