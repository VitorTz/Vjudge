#include <iostream>


int main() {
    int table[1000];
	int N;
    int i;

	while(std::cin >> N && N) {	
        int subSequence[1000];
        int j = 0;

		for (i = 0; i < N; i++) {
            std::cin >> table[i];			
			if (table[i] > 0)
				subSequence[j++] = table[i];
		}

		if (j == 0) {
            std::cout << '0' << '\n';            
        } else {
			for(i = 0; i < j-1; i++) {
                std::cout << subSequence[i] << ' ';				
            }
            std::cout << subSequence[i] << '\n';			
		}
	} 
    return 0;
}