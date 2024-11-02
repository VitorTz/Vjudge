#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int cnt;

void dfs(int idx, std::string& cur, std::vector<std::pair<char, std::string>>& encode, std::string& t){
    if (idx == t.length()) {
        cnt++;
        std::cout << cur << '\n';
        return;
    }

    while ( idx < t.length() && t[idx] == '0') idx++;
    if ( idx >= t.length()) return;

    for(const auto& p : encode) {
        if (p.second.length() > t.length() - idx) {
            continue;
        }
        bool valid = true;

        for (int i = 0; i < p.second.length() && valid; i++) {
            if (t[i+idx] != p.second[i]) valid = false;
        }
        if (valid) {
            cur += p.first;
            dfs(idx + p.second.length(), cur, encode, t);
            cur.pop_back();
        }
        if (cnt >= 100) return;
    }
}

int main() {
    int n,v, tc = 1;
    char c;
    std::string t;
    while (std::cin >> n,n) {
        std::string cur = "";
        std::vector<std::pair<char, std::string>> encode;
        for (int i = 0; i < n; i++) {
            std::cin >> c >> v;
            encode.push_back({c,std::to_string(v)});
        }
        std::cin >> t;
        std::sort(encode.begin(), encode.end());
        cnt = 0;
        std::cout << "Case #" << tc++ << '\n';        
        dfs(0,cur,encode,t);
        std::cout << '\n';
    }
}