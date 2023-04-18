#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
// https://olimpiada.ic.unicamp.br/pratique/pj/2017/f3/onibus

class Graph {
    private:
        int v;
        int e;
        std::vector<std::vector<int>> adjs;
    public:
        Graph(int v) {
            this->v = v;
            this->e = 0;
            this->adjs = std::vector<std::vector<int>> (this->v);
        }

        void addEdge(int u, int v) {
            this->adjs[u].push_back(v);
            this->adjs[v].push_back(u);
            this->e += 1;
        }

        std::vector<int>* adj(int u) { return &this->adjs[u]; }

        int getV() { return this->v; }
        int getE() { return this->e; }
        
};


class BfsPaths {
    private:
        int origem;
        std::vector<bool> mk;
        std::vector<int> pai;
        std::vector<int> distance;
        
        void bfs(Graph* g) {    
            int dist = 0;
            std::list<int> queue; queue.push_front(this->origem);

            this->distance[this->origem] = dist;
            this->pai[this->origem] = this->origem;
            this->mk[this->origem] = true;

            while (!queue.empty()) {
                int u = queue.front(); queue.pop_front();
                for (int& v : *g->adj(u)) {
                    if (!this->mk[v]) {
                        this->mk[v] = true;
                        this->pai[v] = u;
                        this->distance[v] = this->distance[u] + 1;
                        queue.push_front(v);
                    }
                }
            }
        }

    public:
        BfsPaths(Graph* g, int origem) {
            this->origem = origem;
            this->mk = std::vector<bool> (g->getV(), false);
            this->pai = std::vector<int> (g->getV());
            this->distance = std::vector<int> (g->getV(), INT32_MAX);
            this->bfs(g);
        }

        bool hasPathTo(int u) { return this->mk[u]; }
        
        std::vector<int> minPathTo(int u) {
            std::vector<int> path = std::vector<int>{};
            if (this->hasPathTo(u)) {
                for (int x = u; x != this->origem; x = this->pai[x]) {
                    path.push_back(x);
                }
                std::reverse(path.begin(), path.end());
            }
            return path;
        }
        
        int minDistanceTo(int u) { return this->distance[u]; }
};


int main() {
    int linhas, start, end;
    std::cin >> linhas >> start >> end;
    start--; end--;
    Graph* g = new Graph(linhas);

    for (int i = 0; i < linhas-1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        g->addEdge(u, v);
    }

    std::cout << BfsPaths(g, start).minDistanceTo(end) << std::endl;
    delete g;
    return 0;
}
