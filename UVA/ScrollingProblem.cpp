#include <iostream>
#include <string>


int main(){    
    int tc;
    std::cin >> tc;

    while (tc--) {
        int k, w;
        std::cin >> k >> w;
        std::string str;
        std::string min_letters{};
        std::string aux{"000000000000000"};

        for (int n = 0; n < w; n++) {
            std::cin >> str ;
            if (str == aux) {
                continue;
            }
            aux = str;

            if (min_letters.empty() ) { 
                min_letters += str;
                continue; 
            }
            
        
            std::string temp{};
            int j = 0;

            for (int i = min_letters.size() - k; i < min_letters.size(); i++) {
                temp = min_letters.substr(i);
                if (str.rfind(temp, 0) == 0) {
                    break;
                }
                j++;
            }
            
            for (int i = k - j; i < k; i++) {
                min_letters += str[i];
            }

        }
        std::cout << min_letters.size() << '\n';    
    }        

}