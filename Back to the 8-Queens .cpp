#include <cmath>
#include <iostream>
#include <algorithm>
#include <limits>


int t[9];
int n[9];
int mn;


bool verify_move(int r,int c) {
    for (int i = 1; i < c; i++) {
        if (r == n[i] || std::abs(r - n[i]) == std::abs(c - i)) {
            return false;
        }
    }
    return true;
}


void backtracing(int col){
    for (int i = 1; i < 9; i++){
        if (verify_move(i, col)) {
            n[col] = i;
            if (col == 8) {
                int newmin = 0;
                for (int j = 1; j < 9; j++){
                    newmin += (t[j]!= n[j]);
                }
                mn = std::min(mn, newmin);
            } else {
                backtracing(col + 1);
            }
        }
    }
}


int main() {
    int cs = 1;    
    while(scanf("%d %d %d %d %d %d %d %d", &t[1],&t[2],&t[3],&t[4],&t[5],&t[6],&t[7],&t[8]) == 8){        
        mn = std::numeric_limits<int>::max();
        backtracing(1);
        std::cout << "Case " << cs++ << ':' << ' ' << mn << '\n';        
    }
	return 0;
}