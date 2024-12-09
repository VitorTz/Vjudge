#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


int type_1(const std::string& p, const std::string& a) {
    int r = 0;
    int i = 0;
    i = a.find(p);
    while(i != -1) {
        r++;
        i = a.find(p, i + 1);
    }
    return r;
}


int main() {
    std::string p, a;
    std::vector<std::string> aux;
    const std::string dna{"ATCG"};

    while(std::cin >> p && p != "0" && std::cin >> a) {
        std::cout << type_1(p, a) << ' ';
        int total;

        // 2
        aux.clear();
        total = 0;        

        for (int i = 0; i < p.size(); i++) {
            std::string temp = p;
            temp.erase(i,1);
            aux.push_back(temp);
        }

        std::sort(aux.begin(), aux.end());
        aux.resize(std::distance(aux.begin(), std::unique(aux.begin(), aux.end())));

        for (const std::string& s : aux) {
            total += type_1(s, a);
        }

        std::cout << total << ' ';        

        // 3
        aux.clear();
        total = 0;

        for (int i = 0; i < p.size() + 1; i++) {
            for (int j = 0; j < 4; j++) {
                std::string temp = p;
                temp.insert(i, 1, dna[j]);
                aux.push_back(temp);
            }
        }

        std::sort(aux.begin(), aux.end());
        aux.resize(std::distance(aux.begin(), std::unique(aux.begin(), aux.end())));
        
        for (const std::string& s : aux) {
            total += type_1(s, a);
        }

        std::cout << total << '\n';
    }
}