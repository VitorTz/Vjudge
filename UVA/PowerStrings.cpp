#include <iostream>
#include <string>



int main() {
    std::string s{};    

    while(std::cin >> s && s.empty() == false && s[0] != '.') {
        const int str_size = s.size();
        bool is_valid = true;
        int i;
        for(i = 1; i < str_size - 1; i++) {
            if(str_size % i != 0) continue;
            
            for(int j = i; j < str_size; j++)
                if(s[j] != s[j % i]){
                    is_valid = false;
                    break;
                }
            if(is_valid) break;
            is_valid = true;
        }

        if (is_valid) {
            std::cout << str_size / i << '\n';
        } else {
            std::cout << str_size << '\n';
        }
    }
    
    return 0;
}