// https://leetcode.com/problems/course-schedule/ 
#include <iostream>
#include <vector>

using namespace std;


class Solution {

private:
    vector<vector<int>> adjs;
    vector<bool> mk;
    vector<bool> onStack;
    
    bool dfs(int u) {
        this->onStack[u] = true;
        for (int v : this->adjs[u]) {
            if (!this->mk[v]) {
                if (!this->dfs(v))
                    return false;
            } else if (this->onStack[v]) {
                return false;
            }
        }
        this->onStack[u] = false;
        return true;
    }

public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        this->adjs = vector<vector<int>>(numCourses);
        this->mk = vector<bool>(numCourses, false);
        this->onStack = vector<bool>(numCourses, false);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            this->adjs[u].push_back(v);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!this->mk[i]) {
                if (!this->dfs(i)) {
                    return false;
                }
            }
        }

        return true;
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
    cout << s.canFinish(numCourses, preRequisites) << '\n';
    return 0;
}