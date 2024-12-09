#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>


int main() {
    unsigned long long fib[100];
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2 ; i <= 50 ; i++) {
		fib[i] = fib[i-1] + fib[i-2];
    }

    int tc;
	std::cin >> tc;
    
    while(tc--) {
    	int n ;
    	std::cin >> n;
    	
    	unsigned long long ar[n + 10];
        
    	for (int i = 0 ; i < n ; i++) {
            std::cin >> ar[i];
        }

    	getchar();
    	std::string str{};
		
		std::cin >> str;
 
    	std::string s ;
    	for (int i = 0 ; i <= 50 ; i++) {
    		s.push_back('*');
        }

    	int pos = 0;
    	int j = 0;
    	for (int i = 0; i < n ; i++) {
    		for ( ; j < str.size() ; j++) {
    			if (str[j] >= 'A' && str[j] <= 'Z') {
    				for (int k = 1 ; k < 50 ; k++) {
    					if (fib[k] == ar[i]) {
    						pos = std::max(pos,k);
    						s[k] = str[j];
    						break;
    					}
    				}
    				j++;
    				break;
    			}
    		}
    	}
    	
    	for (int i = 1; i <= pos ; i++ ) {
    		if(s[i] == '*') {
    			std::cout << " ";
            } else {
    			std::cout << s[i];
            }
    	}
    	std::cout << "\n";
    }

    return 0;
}