// https://leetcode.com/problems/course-schedule-ii/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

private:
    vector<vector<int>> adjs;
    vector<bool> mk;
    vector<bool> onStack;
    vector<int> postOrder;
    bool temCiclo;
    
    bool dfs(int u) {
        this->mk[u] = true;
        this->onStack[u] = true;
        for (int v : this->adjs[u]) {
            if (this->temCiclo) return;
            if (!this->mk[v])
                this->dfs(v);
            else if (this->onStack[v]) {
                this->temCiclo = true;
                return;
            }
        }
        this->postOrder.push_back(u);
        this->onStack[u] = false;
    }

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        this->onStack = vector<bool>(numCourses, false);
        this->adjs = vector<vector<int>>(numCourses);
        this->mk = vector<bool>(numCourses, false);
        this->temCiclo = false;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            this->adjs[u].push_back(v);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!this->mk[i]) {
                this->dfs(i);
            }
        }
        
        if (this->temCiclo) return {};
        vector<int> revPosOrdem(this->postOrder);
        reverse(revPosOrdem.begin(), revPosOrdem.end());
        return revPosOrdem;
    }

};

int main() {

    Solution s;
    int numCourses = 5;
    vector<vector<int>> preRequisites = {
        {1, 0},
        {2, 1},
        {4, 2},
        {0, 4},
        {3, 1}
    };
    vector<int> postOrder = s.findOrder(numCourses, preRequisites);

    return 0;
}