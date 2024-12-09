#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>



#define INF 0x3f3f3f3f

typedef struct node {
    std::string left;
    std::string right;
    std::string value;
} node_t;


int main() {
    int M;
    std::string start, end;
    node_t temp, temp2;

    int dist[2020];
    bool done[2020];

    while (std::cin >> M && M) {
        std::cin >> start >> end;
        std::vector<node_t> graph;
        std::vector<std::pair<int, int>> adj[2020]{};

        memset(dist,63,sizeof dist);
        memset(done,0,sizeof done);

        for (int i = 0 ; i < M; i++) {
            std::cin >> temp.left >> temp.right >> temp.value;
            graph.push_back(temp);
        }

        for (int i = 0 ; i < M; i++)
            for (int j = i+1 ; j < M; j++) {
                temp = graph[i];
                temp2 = graph[j];
                if (temp.left == temp2.left || temp.left == temp2.right || temp.right == temp2.left || temp.right == temp2.right) {
                    if (temp.value[0] != temp2.value[0]) {
                        adj[i].push_back({j, temp2.value.size()});
                        adj[j].push_back({i, temp.value.size()});
                    }
                }
            }

        for (int i = 0 ; i < M; i++) {
            temp = graph[i];
            if (temp.left == start || temp.right == start) {
                adj[2015].push_back({i, temp.value.size()});
            }
            if (temp.left == end || temp.right == end) {                
                adj[i].push_back({2016, 0});
            }
        }

        dist[2015] = 0;
        done[2015] = true;
        std::queue<int> buff{};
        buff.push(2015);
        int top;
        std::pair<int, int> next{};
        
        while(!buff.empty()) {
            top = buff.front();
            buff.pop();
            done[top] = false;
            for (int i = 0 ; i < adj[top].size(); i++) {
                next = adj[top][i];
                if (dist[top] + next.second < dist[next.first]) {
                    dist[next.first] = dist[top] + next.second;
                    if (!done[next.first]) {
                        buff.push(next.first);
                        done[next.first] = true;
                    }
                }
            }
        }

        if (dist[2016] == INF) {
            std::cout<<"impossivel" << '\n';

        } else {
            std::cout << dist[2016] << '\n';
        }
    }
}