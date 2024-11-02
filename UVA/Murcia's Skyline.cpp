#include <iostream>


int main() {
    int t,  n,  i,  j;
    int nCases = 0;
    
    std::cin >> t;
    
    while (t--) {
        std::cin >> n;
        
        int h[10000];
        int w[10000];
        int table1[10000];
        int table2[10000];

        for (i = 0; i < n; i++) {
            std::cin >> h[i];
        }

        for (i = 0; i < n; i++) {
            std::cin >> w[i];
            table1[i] = table2[i] = w[i];
        }

        for (i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                if(h[i] < h[j] && table1[i] + w[j] > table1[j]) {
                    table1[j] = table1[i] + w[j];
                }
                if(h[i] > h[j] && table2[i] + w[j] > table2[j]) {
                    table2[j] = table2[i] + w[j];
                }
            }
        }

        int A = 0;
        int B = 0;
        for (i = 0; i < n; i++) {
            if(table1[i] > A) A = table1[i];
            if(table2[i] > B) B = table2[i];
        }

        if (B <= A) {
            std::cout << "Case " << ++nCases << ". Increasing (" << A << "). Decreasing (" << B << ").\n";
        } else {
            std::cout << "Case " << ++nCases << ". Decreasing (" << B << "). Increasing (" << A << ").\n";            
        }
    }
    return 0;
}