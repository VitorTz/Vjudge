#include <iostream>
#include <vector>



bool fill(const std::vector<int> &vesselVec, int m, int min_capacity) {
    int container = 1;
    int capacity = min_capacity;

    for (int i = 0; i < vesselVec.size(); ++i) {
        if (vesselVec[i] > min_capacity) {
            return false;
        }

        if (vesselVec[i] > capacity) {            
            if (container == m) {
                return false;
            }
            container++;
            capacity = min_capacity;
        }
        capacity -= vesselVec[i];
    }

    return true;
}


int main() {  
    int n, m;

    while (std::cin >> n >> m) {
        std::vector<int> vesselVec(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> vesselVec[i];
        }
        
        int bottom = 1;  
        int top = 1000000000;
        int min_capacity = 0;

        while (bottom <= top) {
            int mid = (bottom + top) / 2;
            if (fill(vesselVec, m, mid)) {
                min_capacity = mid;
                top = mid - 1;
            } else {
                bottom = mid + 1;
            }
        }

        std::cout << min_capacity << '\n';
    }
    return 0;
}