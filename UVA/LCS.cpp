#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cmath>


int LCS(const std::string& s1, const std::string& s2) {
    const std::size_t s1Size = s1.size();
    const std::size_t s2Size = s2.size();

 	int i, j;
 	int lcs[s1Size + 1][s2Size + 1];

 	for (i = 0; i <= s1Size; i++) {
        for (j = 0; j <= s2Size; j++) {
            if(i == 0 || j == 0) {
                lcs[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    return lcs[s1Size][s2Size];
}
 

int main() { 
	std::string str, s;
    while(getline(std::cin,str)) {
        getline(std::cin,s);    
        std::cout << LCS(str, s) << '\n';
    }
    return 0;
}